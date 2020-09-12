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
#include "scalingpolicysettingswidget.hpp"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QVBoxLayout>

#include "settings/gamesettings.hpp"

namespace {
const int MIN_FIXED_SIZE = 16;
const int MAX_FIXED_SIZE = 1024;
}

class ScalingPolicySettingsWidgetImpl {
public:
    friend class ScalingPolicySettingsWidget;
    explicit ScalingPolicySettingsWidgetImpl() :
        m_settingsGroup(nullptr),
        m_fixedSizeGroup(nullptr),
        m_widthLabel(nullptr),
        m_widthSpinBox(nullptr),
        m_heightLabel(nullptr),
        m_heightSpinBox(nullptr)
    {}
private:
    QGroupBox* m_settingsGroup;
    QGroupBox* m_fixedSizeGroup;
    QLabel* m_widthLabel;
    QSpinBox* m_widthSpinBox;
    QLabel* m_heightLabel;
    QSpinBox* m_heightSpinBox;
};

ScalingPolicySettingsWidget::ScalingPolicySettingsWidget(QWidget *parent) : QWidget(parent)
{
    pImpl = std::make_unique<ScalingPolicySettingsWidgetImpl>();
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QVBoxLayout* settingsGroupLayout = new QVBoxLayout;
    QHBoxLayout* sizeLayout = new QHBoxLayout;

    pImpl->m_settingsGroup = new QGroupBox(tr("Scaling Policy Settings"));
    pImpl->m_fixedSizeGroup = new QGroupBox(tr("Fixed Size Policy Settings"));
    pImpl->m_widthLabel = new QLabel(tr("Width"));
    pImpl->m_heightLabel = new QLabel(tr("Height"));
    pImpl->m_widthSpinBox = new QSpinBox;
    pImpl->m_heightSpinBox = new QSpinBox;
    setUpSpinBox(*pImpl->m_widthSpinBox);
    setUpSpinBox(*pImpl->m_heightSpinBox);

    sizeLayout->addWidget(pImpl->m_widthLabel);
    sizeLayout->addWidget(pImpl->m_widthSpinBox);
    sizeLayout->addStretch();
    sizeLayout->addWidget(pImpl->m_heightLabel);
    sizeLayout->addWidget(pImpl->m_heightSpinBox);
    sizeLayout->addStretch();
    pImpl->m_fixedSizeGroup->setLayout(sizeLayout);

    settingsGroupLayout->addWidget(pImpl->m_fixedSizeGroup);
    pImpl->m_settingsGroup->setLayout(settingsGroupLayout);
    mainLayout->addWidget(pImpl->m_settingsGroup);

    update();

    setLayout(mainLayout);
}

ScalingPolicySettingsWidget::~ScalingPolicySettingsWidget() = default;

void ScalingPolicySettingsWidget::update()
{
    const auto& settings = GameSettings::getInstance();
    const auto& size = settings.getScalingPolicyOption(
                Settings::ScalingPolicy::FitToSize::SUBGROUP,
                Settings::ScalingPolicy::FitToSize::SIZE).toSize();
    pImpl->m_widthSpinBox->setValue(size.width());
    pImpl->m_heightSpinBox->setValue(size.height());
}


QSize ScalingPolicySettingsWidget::getFixedSize() const
{
    int width = pImpl->m_widthSpinBox->value();
    int height = pImpl->m_heightSpinBox->value();
    return QSize(width, height);
}

void ScalingPolicySettingsWidget::setUpSpinBox(QSpinBox& spinBox)
{
    spinBox.setRange(::MIN_FIXED_SIZE, ::MAX_FIXED_SIZE);
}
