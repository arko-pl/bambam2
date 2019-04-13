#ifndef SETTINGSWRITER_HPP
#define SETTINGSWRITER_HPP

class GameSettings;

// TODO: Document this class
class SettingsWriter
{
public:
    explicit SettingsWriter(const GameSettings&);

    void saveSettings() const;
};

#endif // SETTINGSWRITER_HPP
