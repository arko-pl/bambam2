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
#ifndef SCALINGPOLICYSETTINGSWIDGET_HPP
#define SCALINGPOLICYSETTINGSWIDGET_HPP

#include <QWidget>
#include "pimpl.hpp"
#include "settings/settings_common.hpp"
#include "settings/dialog/iscalingpolicysettings.hpp"

class ScalingPolicySettingsWidgetImpl;
class QStandardItem;
class QSpinBox;

/**
 * @brief Scaling Policy Settings Widget
 */
class ScalingPolicySettingsWidget : public QWidget,
        public IScalingPolicySettings
{
    Q_OBJECT
public:
    explicit ScalingPolicySettingsWidget(QWidget *parent = nullptr);
    ~ScalingPolicySettingsWidget();

    /**
     * @brief Update widget content
     */
    void update();

    /**
     * @brief Get size for the fixed size scaling policy
     * @return Size
     */
    QSize getFixedSize() const override;

private:
    ScalingPolicySettingsWidget(const ScalingPolicySettingsWidget&) = delete;
    const ScalingPolicySettingsWidget& operator=(
            const ScalingPolicySettingsWidget&) = delete;

    /**
     * @brief Set up spin box with the default values
     * @param spinBox reference to QSpinBox to set up
     */
    void setUpSpinBox(QSpinBox& spinBox);
    PImpl<ScalingPolicySettingsWidgetImpl> pImpl;
    /**< Pointer to the implementation. */
};

#endif // SCALINGPOLICYSETTINGSWIDGET_HPP
