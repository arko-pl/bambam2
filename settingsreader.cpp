#include "settingsreader.hpp"

#include <QSettings>

#include "gamesettings.hpp"
#include "iscalingpolicy.hpp"
#include "data_providers/dataprovider_common.hpp"
#include "data_providers/graphics/policies/scalingpolicy_common.hpp"

SettingsReader::SettingsReader(GameSettings& settings) :
    m_settings(settings) {
}

bool SettingsReader::readSettings() {
    QSettings settings("bambam2.conf", QSettings::IniFormat);

    settings.beginGroup("scaling_policy");
    QString name(settings.value("name",
                                ScalingPolicy::getDefault()).toString());
    QByteArray data(settings.value("data", QByteArray()).toByteArray());
    settings.endGroup();

    settings.beginGroup("data_providers");
    QStringList providers(settings.value("enabled_providers",
                          QStringList({ DataProvider::ConfigBasedProvider,
                                        DataProvider::TextProvider,
                                      }))
                          .toStringList());
    QString retrievalPolicy(settings.value("retrieval_policy", "random")
                            .toString());
    settings.endGroup();

    settings.beginGroup("common");
    QString language(settings.value("language", "pl").toString());
    settings.endGroup();

    m_settings.setScalingPolicy(name, data);
    m_settings.setDataProviders(providers);
    m_settings.m_retrievalPolicy = retrievalPolicy;
    m_settings.setLanguage(language);

    return true;
}
