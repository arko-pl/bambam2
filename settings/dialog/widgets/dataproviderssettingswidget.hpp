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
#ifndef DATAPROVIDERSSETTINGSWIDGET_HPP
#define DATAPROVIDERSSETTINGSWIDGET_HPP

#include <QWidget>
#include "pimpl.hpp"
#include "settings/settings_common.hpp"
#include "settings/dialog/idataprovidersettings.hpp"

class DataProvidersSettingsWidgetImpl;
class QComboBox;

/**
 * @brief Widget with settings for data providers.
 * Will be split into smaller parts in future
 */

class DataProvidersSettingsWidget : public QWidget,
        public IDataProviderSettings
{
    Q_OBJECT
public:
    explicit DataProvidersSettingsWidget(QWidget *parent = nullptr);
    ~DataProvidersSettingsWidget();

    /**
     * @brief Update widget content
     */
    void update();

    // IDataProviderSettings interface
    /**
     * @brief Get retrieval policy for external data provider
     * @return Retrieval policy
     */
    Settings::DataProviders::ConfigBased::RetrievalPolicy
    getRetrievalPolicy() const override;

private:
    DataProvidersSettingsWidget(const DataProvidersSettingsWidget&) = delete;
    const DataProvidersSettingsWidget& operator=(
            const DataProvidersSettingsWidget&) = delete;

    void setUpComboBox(QComboBox& comboBox);

    PImpl<DataProvidersSettingsWidgetImpl> pImpl;
    /**< Pointer to the implementation. */
};

#endif // DATAPROVIDERSSETTINGSWIDGET_HPP
