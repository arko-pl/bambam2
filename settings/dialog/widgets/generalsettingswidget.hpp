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
#ifndef GENERALSETTINGSWIDGET_H
#define GENERALSETTINGSWIDGET_H

#include <QWidget>
#include "pimpl.hpp"
#include "settings/settings_common.hpp"
#include "settings/dialog/igeneralsettings.hpp"

class GeneralSettingsWidgetImpl;
class QStandardItem;
/**
 * @brief Widget with general settings
 */
class GeneralSettingsWidget : public QWidget, public IGeneralSettings
{
    Q_OBJECT
public:
    explicit GeneralSettingsWidget(QWidget *parent = nullptr);
    ~GeneralSettingsWidget();

    /**
     * @brief Update widget content
     */
    void update();

    /**
     * @brief Get language for the game items
     * @return Lanuage
     */
    Settings::General::Language getLanguage() const override;
    /**
     * @brief Get scaling policy for the game items
     * @return  Scaling policy
     */
    Settings::ScalingPolicy::Type getScalingPolicy() const override;
    /**
     * @brief Get data providers for the game
     * @return Data providers
     */
    QList<Settings::DataProviders::Type> getDataProviders() const override;

private:
    GeneralSettingsWidget(const GeneralSettingsWidget&) = delete;
    const GeneralSettingsWidget& operator=(const GeneralSettingsWidget&) =
            delete;

    /**
     * @brief Fill supported languages ComboBox
     */
    void fillLanguages();
    /**
     * @brief Fill scaling policies ComboBox
     */
    void fillScalingPolicies();
    /**
     * @brief Fill data providers list
     */
    void fillDataProviders();
    /**
     * @brief Insert single data provider into list
     * @param name Data provider name
     * @param type Data provider type
     */
    void insertProvider(const QString& name,
                        Settings::DataProviders::Type type);
    /**
     * @brief Take single data item from the available list
     * The item will be removed from the list.
     * @param provider Data provider type
     * @return
     */
    QStandardItem* getItemFromAvailable(
            Settings::DataProviders::Type provider);

    PImpl<GeneralSettingsWidgetImpl> pImpl;
    /**< Pointer to the implementation. */

};

#endif // GENERALSETTINGSWIDGET_H
