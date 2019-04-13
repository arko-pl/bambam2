#ifndef GAMESETTINGS_HPP
#define GAMESETTINGS_HPP

class QByteArray;
template <typename T>
class QList;
namespace DataProvider {
    enum class Provider;
}

#include <QStringList>

class IScalingPolicy;
// TODO: Document this class
class GameSettings
{
public:
    static GameSettings& getInstance();
    friend class SettingsReader;
    friend class SettingsWriter;

    QList<DataProvider::Provider> getDataProviders() const;
    const QString& getLanguage() const;
    const QString& getRetrievalPolicy() const;
    IScalingPolicy* getScalingPolicy() const;
    void setScalingPolicy(const QString& name, const QByteArray& data);
    void setDataProviders(const QStringList&);
    void setLanguage(const QString&);

private:
    explicit GameSettings();
    ~GameSettings();

    GameSettings(const GameSettings&) = delete;
    GameSettings& operator=(const GameSettings&) = delete;

    // FIXME: settings shouldn't keep view data, build this at game startup
    IScalingPolicy* m_scalingPolicy;

    QStringList m_dataProviders;
    QString m_language;
    QString m_retrievalPolicy; //FIXME: provider specific configuration
};

#endif // GAMESETTINGS_HPP
