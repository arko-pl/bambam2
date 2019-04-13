#include "gamesettings.hpp"

#include <QString>
#include "iscalingpolicy.hpp"
#include "settingsreader.hpp"
#include "data_providers/dataprovider_common.hpp"
#include "data_providers/graphics/policies/scalingpolicy_common.hpp"
#include "data_providers/graphics/factories/scalingpolicyfactory.hpp"

GameSettings::GameSettings() :
    m_scalingPolicy(nullptr),
    m_dataProviders()
{
    SettingsReader reader(*this);
    reader.readSettings();
}

GameSettings::~GameSettings() {
    if (m_scalingPolicy != nullptr)
        delete m_scalingPolicy;
}

GameSettings& GameSettings::getInstance() {
    static GameSettings settings;
    return settings;
}

QList<DataProvider::Provider> GameSettings::getDataProviders() const {
    QList<DataProvider::Provider> providers;
    for (const auto& provider : m_dataProviders) {
        providers.push_back(DataProvider::fromString(provider));
    }
    return providers;
}

const QString& GameSettings::getLanguage() const
{
    return m_language;
}

const QString& GameSettings::getRetrievalPolicy() const {
    return m_retrievalPolicy;
}

IScalingPolicy* GameSettings::getScalingPolicy() const {
    return m_scalingPolicy;
}

void GameSettings::setScalingPolicy(const QString& name,
                                    const QByteArray& data) {
    if (m_scalingPolicy != nullptr) {
        delete m_scalingPolicy;
    }

    // TODO: map from settings view (temporary container)
    QString policy = name;

    ScalingPolicyFactory spf;
    m_scalingPolicy = spf.makePolicy(ScalingPolicy::fromString(policy), data);
}

void GameSettings::setDataProviders(const QStringList& providers) {
    m_dataProviders.clear();
    for (const auto& provider : providers) {
        // TODO: validate and convert
        m_dataProviders.push_back(provider);
    }
}

void GameSettings::setLanguage(const QString& language) {
    m_language = language;
}
