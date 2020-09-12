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
#ifndef SETTINGS_COMMON_HPP
#define SETTINGS_COMMON_HPP

#include <QObject>

class QString;
class QSize;

namespace Settings {

Q_NAMESPACE

    extern const QString GENERAL_OPTIONS;
    extern const QString SCALING_POLICY_OPTIONS;
    extern const QString DATA_PROVIDERS_OPTIONS;

// General options
namespace General {

Q_NAMESPACE

/**
 * @brief The Language enumeration
 */
enum class Language {
    English,
    Polish
};
Q_ENUM_NS(Language);

namespace Languages {
    extern const QString ENGLISH; /**< String representation of English language
                                    in the settings file */
    extern const QString POLISH; /**< String representation of Polish language
                                   in the settings file */
} // Languages

    extern const QString LANGUAGE; /**< Language general option string */
    extern const QString SELECTED_SCALING_POLICY; /**< Selected Scaling Policy
                                                    general option string */
    extern const QString SELECTED_PROVIDERS; /**< Selected Providers general
                                               option string */
} // General

namespace ScalingPolicy {

Q_NAMESPACE

/**
 * @brief Scaling Policy type enumeration
 */
enum class Type {
    FitToSize,
    NoScaling
};
Q_ENUM_NS(Type);

namespace Types {
    extern const QString FIT_TO_SIZE; /**< String representation of "Fit to
                                         size" policy in the settings file */
    extern const QString NO_SCALING; /**< String representation of "No scaling"
                                       policy in the settings file */
} // Types

namespace FitToSize {
    extern const QString SUBGROUP; /**< String representation of "Fit to size"
                                     subgroup in options */
    extern const QString SIZE; /**< String representation of "Size" option in
                                 "Fit to size" subgroup */
} // FitToSize
} // ScalingPolicy

namespace DataProviders {

Q_NAMESPACE

/**
 * @brief The Data Provider Type enumeration
 */
enum class Type {
    ConfigBased,
    Text
};
Q_ENUM_NS(Type);

namespace Types {
    extern const QString CONFIG_BASED; /**< String representation of external
                                         data provider in the settings file */
    extern const QString TEXT; /**< String representation of text data provider
                                 in the settings file */
} // Types

namespace ConfigBased {

    Q_NAMESPACE

    extern const QString SUBGROUP; /**< String representation of "External data
                                     provider subgroup in options */
    extern const QString RETRIEVAL_POLICY; /**< String representation of
                                             "Retrieval Policy" option in the
                                             "External data provider" subgroup
                                            */

    /**
     * @brief The Retrieval Policy enumeration
     */
    enum class RetrievalPolicy {
        Random,
        CharBased
    };
    Q_ENUM_NS(RetrievalPolicy);

namespace RetrievalPolicies {
    extern const QString RANDOM; /**< String representation of "random"
                                   retrieval policy in the settings file */
    extern const QString CHAR_BASED; /**< String representation of "character
                                       based" retrieval policy in the settings
                                       file */
} // RetrievalPolicies
} // ConfigBased
} // DataProviders

namespace Default {
    extern const QString Name; /**< Setting file name */
    extern const ScalingPolicy::Type ScalingPolicy; /**< Default scaling policy
                                                     */
    extern const DataProviders::ConfigBased::RetrievalPolicy RetrievalPolicy;
    /**< Default retrieval policy */
    extern const General::Language Language; /**< Default language */
    extern const QList<DataProviders::Type> DataProviders; /**< Default data
                                                             providers list */
    extern const QSize Size; /**< Default size for "Fit to size" option */
} // Default
}

#endif // SETTINGS_COMMON_HPP
