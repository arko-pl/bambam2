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
#include "gamesettings.hpp"

#include <QHash>
#include <QString>
#include <QVariant>
#include "iscalingpolicy.hpp"
#include "settingsreader.hpp"

GameSettings::GameSettings() :
    m_settingsMap()
{
    SettingsReader reader(*this);
    reader.readSettings();
}

GameSettings::~GameSettings() = default;

GameSettings& GameSettings::getInstance() {
    static GameSettings settings;
    return settings;
}

QVariant GameSettings::getSubOption(const OptionsMap::const_iterator& it,
                                    const QString& group,
                                    const QString& name) const
{
    const auto sit = it->find(group);

    Q_ASSERT(sit != it->cend());

    const auto options = sit->toHash();
    const auto oit = options.find(name);

    Q_ASSERT(oit != options.cend());

    return *oit;
}

void GameSettings::setSubOption(const OptionsMap::iterator& it,
                                const QString& group,
                                const QString& name,
                                const QVariant& value)
{
    const auto sit = it->find(group);

    Q_ASSERT(sit != it->cend());

    auto& options = *static_cast<QHash<QString, QVariant>*>(sit->data());
    const auto oit = options.find(name);

    Q_ASSERT(oit != options.cend());
    *oit = value;
}


QVariant GameSettings::getDataProvidersOption(const QString& group,
                                              const QString& name) const {
    const auto it = m_settingsMap.find(Options::DataProviders);

    Q_ASSERT(it != m_settingsMap.cend());

    return getSubOption(it, group, name);
}

QVariant GameSettings::getScalingPolicyOption(const QString& group,
                                              const QString& name) const {
    const auto it = m_settingsMap.find(Options::ScalingPolicy);

    Q_ASSERT(it != m_settingsMap.cend());

    return getSubOption(it, group, name);
}

QVariant GameSettings::getGeneralOption(const QString& name) const {
    const auto it = m_settingsMap.find(Options::General);

    Q_ASSERT(it != m_settingsMap.cend());

    const auto sit = it->find(name);

    Q_ASSERT(sit != it->cend());

    return *sit;
}

QVariant GameSettings::getOption(const Options& option) const {
    const auto it = m_settingsMap.find(option);

    Q_ASSERT(it != m_settingsMap.cend());

    return *it;
}

void GameSettings::setGeneralOption(const QString& name, const QVariant& value)
{
    const auto it = m_settingsMap.find(Options::General);

    Q_ASSERT(it != m_settingsMap.cend());

    const auto sit = it->find(name);

    Q_ASSERT(sit != it->cend());

    *sit = value;
}

void GameSettings::setScalingPolicyOption(const QString& group,
                                          const QString& name,
                                          const QVariant& value)
{
    const auto it = m_settingsMap.find(Options::ScalingPolicy);

    Q_ASSERT(it != m_settingsMap.cend());

    setSubOption(it, group, name, value);
}

void GameSettings::setDataProvidersOption(const QString& group,
                                          const QString& name,
                                          const QVariant& value)
{
    const auto it = m_settingsMap.find(Options::DataProviders);

    Q_ASSERT(it != m_settingsMap.cend());

    setSubOption(it, group, name, value);
}
