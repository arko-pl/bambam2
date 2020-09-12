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
#include "settingshelpers.hpp"

#include <QHash>

#include "settings_common.hpp"

const QHash<const QString&, Settings::General::Language>
SettingsHelpers::m_languageMap =
{
    { Settings::General::Languages::ENGLISH,
      Settings::General::Language::English },
    { Settings::General::Languages::POLISH,
      Settings::General::Language::Polish },
};

const QHash<const QString&, Settings::ScalingPolicy::Type>
SettingsHelpers::m_scalingPolicyTypeMap =
{
    { Settings::ScalingPolicy::Types::FIT_TO_SIZE,
      Settings::ScalingPolicy::Type::FitToSize },
    { Settings::ScalingPolicy::Types::NO_SCALING,
      Settings::ScalingPolicy::Type::NoScaling },
};

const QHash<const QString&,
            Settings::DataProviders::ConfigBased::RetrievalPolicy>
SettingsHelpers::m_retrievalPolicyMap =
{
    { Settings::DataProviders::ConfigBased::RetrievalPolicies::CHAR_BASED,
      Settings::DataProviders::ConfigBased::RetrievalPolicy::CharBased },
    { Settings::DataProviders::ConfigBased::RetrievalPolicies::RANDOM,
      Settings::DataProviders::ConfigBased::RetrievalPolicy::Random },
};

const QHash<const QString&, Settings::DataProviders::Type>
SettingsHelpers::m_dataProvidersTypeMap =
{
    { Settings::DataProviders::Types::CONFIG_BASED,
      Settings::DataProviders::Type::ConfigBased },
    { Settings::DataProviders::Types::TEXT,
      Settings::DataProviders::Type::Text },
};

Settings::General::Language SettingsHelpers::toLanguage(const QString& language)
{
    auto it = m_languageMap.find(language);
    if (it != m_languageMap.cend()) {
        return *it;
    }
    return Settings::Default::Language;
}

Settings::ScalingPolicy::Type
SettingsHelpers::toScalingPolicyType(const QString& type)
{
    auto it = m_scalingPolicyTypeMap.find(type);
    if (it != m_scalingPolicyTypeMap.cend()) {
        return *it;
    }
    return Settings::Default::ScalingPolicy;
}

Settings::DataProviders::Type
SettingsHelpers::toDataProviderType(const QString& type)
{
    auto it = m_dataProvidersTypeMap.find(type);
    if (it != m_dataProvidersTypeMap.cend()) {
        return *it;
    }
    return Settings::DataProviders::Type::Text;
}

Settings::DataProviders::ConfigBased::RetrievalPolicy
SettingsHelpers::toRetrievalPolicy(const QString& policy)
{
    auto it = m_retrievalPolicyMap.find(policy);
    if (it != m_retrievalPolicyMap.cend()) {
        return *it;
    }
    return Settings::Default::RetrievalPolicy;
}

const QString& SettingsHelpers::fromLanguage(
        Settings::General::Language language)
{
    auto it = m_languageMap.constKeyValueBegin();
    while (it != m_languageMap.constKeyValueEnd()) {
        if ((*it).second == language) {
            return (*it).first;
        }
        ++it;
    }
    return Settings::General::Languages::ENGLISH;
}

const QString& SettingsHelpers::fromScalingPolicyType(
        Settings::ScalingPolicy::Type type)
{
    auto it = m_scalingPolicyTypeMap.constKeyValueBegin();
    while (it != m_scalingPolicyTypeMap.constKeyValueEnd()) {
        if ((*it).second == type) {
            return (*it).first;
        }
        ++it;
    }
    return Settings::ScalingPolicy::Types::FIT_TO_SIZE;
}

const QString& SettingsHelpers::fromDataProviderType(
        Settings::DataProviders::Type type)
{
    auto it = m_dataProvidersTypeMap.constKeyValueBegin();
    while (it != m_dataProvidersTypeMap.constKeyValueEnd()) {
        if ((*it).second == type) {
            return (*it).first;
        }
        ++it;
    }
    return Settings::DataProviders::Types::TEXT;
}

const QString& SettingsHelpers::fromRetrievalPolicy(
        Settings::DataProviders::ConfigBased::RetrievalPolicy policy)
{
    auto it = m_retrievalPolicyMap.constKeyValueBegin();
    while (it != m_retrievalPolicyMap.constKeyValueEnd()) {
        if ((*it).second == policy) {
            return (*it).first;
        }
        ++it;
    }
    return Settings::DataProviders::ConfigBased::RetrievalPolicies::RANDOM;
}
