#ifndef SETTINGSREADER_HPP
#define SETTINGSREADER_HPP

class GameSettings;

// TODO: Document this class
class SettingsReader
{
public:
    explicit SettingsReader(GameSettings&);
    bool readSettings();
private:
    GameSettings& m_settings;
};

#endif // SETTINGSREADER_HPP
