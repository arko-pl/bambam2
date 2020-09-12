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
#include "settings_common.hpp"

#include <QString>
#include <QSize>

namespace Settings {

    const QString GENERAL_OPTIONS = QStringLiteral("gerenal");
    const QString SCALING_POLICY_OPTIONS = QStringLiteral("scaling_policy");
    const QString DATA_PROVIDERS_OPTIONS = QStringLiteral("data_providers");

// General options
namespace General {

namespace Languages {
    const QString ENGLISH = QStringLiteral("en");
    const QString POLISH = QStringLiteral("pl");
} // Languages

    const QString LANGUAGE = QStringLiteral("language");
    const QString SELECTED_SCALING_POLICY = QStringLiteral(
            "selected_scaling_policy");
    const QString SELECTED_PROVIDERS = QStringLiteral("selected_providers");
} // General

namespace ScalingPolicy {

namespace Types {
    const QString FIT_TO_SIZE = QStringLiteral("fit_to_size");
    const QString NO_SCALING = QStringLiteral("no_scaling");
} // Types

namespace FitToSize {
    const QString SUBGROUP = QStringLiteral("fit_to_size");
    const QString SIZE = QStringLiteral("size").arg(SUBGROUP);
} // FitToSize
} // ScalingPolicy

namespace DataProviders {

namespace Types {
    const QString CONFIG_BASED = QStringLiteral("config_based");
    const QString TEXT = QStringLiteral("text");
} // Types

namespace ConfigBased {
    const QString SUBGROUP = QStringLiteral("config_based_provider");
    const QString RETRIEVAL_POLICY =
        QStringLiteral("retrieval_policy").arg(SUBGROUP);

namespace RetrievalPolicies {
    const QString RANDOM = QStringLiteral("random");
    const QString CHAR_BASED = QStringLiteral("char_based");
} // RetrievalPolicies
} // ConfigBased
} // DataProviders

namespace Default {
    const QString Name = QStringLiteral("bambam2");
    const DataProviders::ConfigBased::RetrievalPolicy RetrievalPolicy =
            DataProviders::ConfigBased::RetrievalPolicy::Random;
    const General::Language Language =
            General::Language::English;
    const ScalingPolicy::Type ScalingPolicy =
            ScalingPolicy::Type::FitToSize;
    const QSize Size(512, 512);
    const QList<DataProviders::Type> DataProviders = {
        DataProviders::Type::ConfigBased,
        DataProviders::Type::Text
    };
} // Default
}
