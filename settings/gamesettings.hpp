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
#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

#include <QStringList>
#include <QHash>

class QByteArray;
template <typename T>
class QList;
class QVariant;

namespace DataProvider {
    enum class Provider;
}

enum class Options {
    General,
    ScalingPolicy,
    DataProviders
};

using OptionType = QHash<QString, QVariant>;
using OptionsMap = QHash<Options, OptionType>;

/**
 * @brief Calculate hash for the Options enum class
 * @param key Option
 * @param seed Seed
 * @return
 */
inline uint qHash(Options key, uint seed)
{
    return ::qHash(static_cast<std::underlying_type<Options>::type>(key), seed);
}

/**
 * @brief The Game Settings Class
 * This class contains all game settings.
 */
class GameSettings
{
public:
    friend class SettingsReader;
    friend class SettingsWriter;

    /**
     * @brief Get GameSettings instance
     * @return GameSettings instance
     */
    static GameSettings& getInstance();
    /**
     * @brief Get value for Data Providers option
     * @param group Data Providers subgroup
     * @param name Option name
     * @return Option value
     */
    QVariant getDataProvidersOption(const QString& group,
                                    const QString& name) const;
    /**
     * @brief Get value for Scaling Policy option
     * @param group Scaling Policy subgroup
     * @param name Option name
     * @return Option value
     */
    QVariant getScalingPolicyOption(const QString& group,
                                    const QString& name) const;
    /**
     * @brief Get value for General Option
     * @param name Option name
     * @return Option value
     */
    QVariant getGeneralOption(const QString& name) const;
    /**
     * @brief Get Options Map
     * @param option Option
     * @return Hash map for specified @p option
     */
    QVariant getOption(const Options& option) const;
    /**
     * @brief Set General Option value
     * @param name Option name
     * @param value Option value
     */
    void setGeneralOption(const QString& name, const QVariant& value);
    /**
     * @brief Set Scaling Policy option value
     * @param group Scaling Policy subgroup
     * @param name Option name
     * @param value Option value
     */
    void setScalingPolicyOption(const QString& group, const QString& name,
                                const QVariant& value);
    /**
     * @brief Set Data option value
     * @param group Scaling Policy subgroup
     * @param name Option name
     * @param value Option value
     */
    void setDataProvidersOption(const QString& group, const QString& name,
                                const QVariant& value);
private:
    explicit GameSettings();
    ~GameSettings();

    GameSettings(const GameSettings&) = delete;
    GameSettings& operator=(const GameSettings&) = delete;

    /**
     * @brief Get option @p name value from subgroup @p group
     * @param it Options map iterator
     * @param group Subgroup name
     * @param name Option name
     * @return Option value
     */
    QVariant getSubOption(const OptionsMap::const_iterator& it, const QString& group,
                          const QString& name) const;
    /**
     * @brief Set @p value for option @p name from subgroup @p group
     * @param it Options map iterator
     * @param group Subgroup name
     * @param name Option name
     * @param value Option value
     */
    void setSubOption(const OptionsMap::iterator& it, const QString& group,
                      const QString& name, const QVariant& value);

    OptionsMap m_settingsMap; /**< Options map */
};

#endif // GAMESETTINGS_HPP
