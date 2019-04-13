#include "settingswriter.hpp"

#include <QSettings>
#include "gamesettings.hpp"
#include "iscalingpolicy.hpp"

SettingsWriter::SettingsWriter(const GameSettings& settings) {

}

void SettingsWriter::saveSettings() const {
    GameSettings& gs = GameSettings::getInstance();
    IScalingPolicy* scalingPolicy = gs.m_scalingPolicy;
    QByteArray policyData;
    QSettings settings("bambam2.conf", QSettings::IniFormat);
    settings.beginGroup("scaling_policy");
    settings.setValue("name", scalingPolicy->policyName());
    settings.setValue("data", scalingPolicy->policyData(policyData));//.toBase64());
    settings.endGroup();
    settings.beginGroup("data_providers");
    settings.value("enabled_providers", gs.m_dataProviders);
    settings.value("retrieval_policy", gs.m_retrievalPolicy);
    settings.endGroup();
    settings.beginGroup("common");
    settings.value("language", gs.m_language);
    settings.endGroup();
}
