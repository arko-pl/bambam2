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
#ifndef SETTINGSHELPERS_H
#define SETTINGSHELPERS_H

#include <QHash>
#include <QString>
#include "settings_common.hpp"

/**
 * @brief Settings Helpers Class
 * Helpers to translate settings data from settings file to game data
 * and vice versa.
 */
class SettingsHelpers
{
public:
    /* String to game data converters */
    /**
     * @brief Convert @p language from string representation to enum type
     * @param language Language as string
     * @return Language as enum type
     */
    static Settings::General::Language toLanguage(const QString& language);
    /**
     * @brief Convert scaling policy @p type to enum type
     * @param type Scaling Policy type as string
     * @return Type as ScalingPolicy::Type enum
     */
    static Settings::ScalingPolicy::Type toScalingPolicyType(
            const QString& type);
    /**
     * @brief Convert data providers @p type to enum type
     * @param type Scaling Policy type as string
     * @return Type as ScalingPolicy::Type enum
     */
    static Settings::DataProviders::Type toDataProviderType(
            const QString& type);
    /**
     * @brief Convert retrieval @p policy to enum type
     * @param policy Retrieval Policy type as string
     * @return Type as DataProviders::ConfigBased::RetrievalPolicy
     */
    static Settings::DataProviders::ConfigBased::RetrievalPolicy
        toRetrievalPolicy(const QString& policy);

    /* Game data to string converters */
    /**
     * @brief Convert @p language from enum type to string representation
     * @param language Language as enum
     * @return Language as string
     */
    static const QString& fromLanguage(Settings::General::Language language);
    /**
     * @brief Convert scaling policy @p type to string representation
     * @param type Scaling policy type as enum
     * @return Scaling policy type as string
     */
    static const QString& fromScalingPolicyType(
            Settings::ScalingPolicy::Type type);
    /**
     * @brief Convert data provider @p type to string representation
     * @param type Data provider type as enum
     * @return Data provider type as string
     */
    static const QString& fromDataProviderType(
            Settings::DataProviders::Type type);
    /**
     * @brief Convert retrieval @p policy to string representation
     * @param policy Retrieval policy as enum
     * @return Retrieval policy as string
     */
    static const QString& fromRetrievalPolicy(
            Settings::DataProviders::ConfigBased::RetrievalPolicy policy);
private:
    SettingsHelpers() = delete;
    static const QHash<const QString&, Settings::General::Language>
            m_languageMap; /**< Language map */
    static const QHash<const QString&,
                Settings::ScalingPolicy::Type> m_scalingPolicyTypeMap;
                /**< Scaling policy type map */
    static const QHash<const QString&,
                Settings::DataProviders::Type> m_dataProvidersTypeMap;
                /**< Data provider type map */
    static const QHash<const QString&,
                Settings::DataProviders::ConfigBased::RetrievalPolicy>
        m_retrievalPolicyMap; /**< Retrieval policy map */
};

#endif // SETTINGSHELPERS_H
