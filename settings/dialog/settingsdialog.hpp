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
#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "pimpl.hpp"

class SettingsDialogImpl;
class IGeneralSettings;
class IScalingPolicySettings;
class IDataProviderSettings;

/**
 * @brief Settings Dialog
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SettingsDialog(QDialog *parent = nullptr);
    ~SettingsDialog();

    /**
     * @brief Get general settings interface
     * @return Pointer to General Settings Interface
     */
    const IGeneralSettings* getGeneralSettings() const;
    /**
     * @brief Get scaling policy settings interface
     * @return Pointer to Scaling Policy Settings Interface
     */
    const IScalingPolicySettings* getScalingPolicySettings() const;
    /**
     * @brief Get data provider settings interface
     * @return Pointer to Data Provider Settings Interface
     */
    const IDataProviderSettings* getDataProviderSettings() const;
private:
    SettingsDialog(const SettingsDialog&) = delete;
    SettingsDialog& operator=(const SettingsDialog&) = delete;

    PImpl<SettingsDialogImpl> pImpl; /**< Pointer to the implementation */
};

#endif // SETTINGSDIALOG_H
