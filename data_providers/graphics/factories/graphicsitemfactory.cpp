/*
 * Copyright (C) 2020  Arkadiusz Bubała <arek2407066@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "graphicsitemfactory.hpp"

#include <QVariant>

#include "igameelementdata.hpp"
#include "iscalingpolicy.hpp"
#include "randomizer.hpp"
#include "translationmanager.hpp"
#include "data_providers/graphics/decorators/graphicsitemdecorator.hpp"
#include "data_providers/graphics/decorators/scaledecorator.hpp"
#include "data_providers/graphics/direct/circleitemprovider.hpp"
#include "data_providers/graphics/direct/mimebasedprovider.hpp"
#include "data_providers/graphics/direct/textitemprovider.hpp"

#include "data_providers/graphics/policies/scalingpolicy_common.hpp"
#include "data_providers/graphics/factories/scalingpolicyfactory.hpp"
#include "settings/gamesettings.hpp"
#include "settings/settings_common.hpp"

// FIXME: settings are set before the game starts, load the settings only once

/**
 * @brief Graphics Item Factory Implementation.
 *
 */
class GraphicsItemFactoryImpl {
public:
    GraphicsItemFactoryImpl(IScalingPolicy* scalingPolicy) :
        m_randomizer(),
        m_defaultProvider(m_randomizer),
        m_scalingPolicy(scalingPolicy)
    {}
    friend class GraphicsItemFactory;
private:
    Randomizer m_randomizer; /**< Graphics randomizer. */
    CircleItemProvider m_defaultProvider; /**< Default provider. */
    IScalingPolicy* m_scalingPolicy; /**< Scaling policy. */
};

GraphicsItemFactory::GraphicsItemFactory() {
    const GameSettings& settings = GameSettings::getInstance();
    auto policy =
            qvariant_cast<Settings::ScalingPolicy::Type>(
                settings.getGeneralOption(
                    Settings::General::SELECTED_SCALING_POLICY));
    ScalingPolicyFactory spf;

    IScalingPolicy* scalingPolicy = spf.makePolicy(
                ScalingPolicy::fromSettings(policy));
;
    pImpl = std::make_unique<GraphicsItemFactoryImpl>(scalingPolicy);
}

GraphicsItemFactory::~GraphicsItemFactory() {
    if (pImpl->m_scalingPolicy != nullptr) {
        delete pImpl->m_scalingPolicy;
    }
}

QGraphicsItem* GraphicsItemFactory::makeItem(const IGameElementData* element) {
    QGraphicsItem* item = nullptr;
    if (element == nullptr) {
        return pImpl->m_defaultProvider.makeItem();
    }
    if (!element->imagePath().isEmpty()) {
        const auto language =
                qvariant_cast<Settings::General::Language>(
                    GameSettings::getInstance().getGeneralOption(
                        Settings::General::LANGUAGE));
        IImageProvider* itemProvider =
                new GraphicsItemDecorator(
                    new ScaleDecorator(
                        new MimeBasedProvider(element->imagePath()),
                        pImpl->m_scalingPolicy),
                    element->translation(Translations::fromSettings(language)));
        item = itemProvider->makeItem();
        delete itemProvider;
    }
    if (item == nullptr && !element->name().isEmpty()) {
        TextItemProvider textProvider(element->name(), pImpl->m_randomizer);
        item = textProvider.makeItem();
    }
    if (item == nullptr) {
        item = pImpl->m_defaultProvider.makeItem();
    }
    return item;
}
