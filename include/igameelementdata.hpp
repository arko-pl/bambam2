#ifndef IGAMEELEMENTDATA_HPP
#define IGAMEELEMENTDATA_HPP

class QString;
namespace Translations {
enum class Language;
}

/**
 * @brief Game Element Data Interface.
 *
 */
class IGameElementData {
public:
    /**
     * @brief The virtual destructor.
     *
     */
    virtual ~IGameElementData() {}

    /**
     * @brief Set @p path to the image file.
     *
     * @param path Path to the image file.
     */
    virtual void setImagePath(const QString& path) = 0;
    /**
     * @brief Set the game element @p name.
     *
     * @param name Game Element name.
     */
    virtual void setName(const QString& name) = 0;
    /**
     * @brief Set @p path to the sound file.
     *
     * @param path Path to the sound file.
     */
    virtual void setSoundPath(const QString& path) = 0;
    /**
     * @brief Set the translation @p word in specific @p language.
     *
     * @param language Language symbol.
     * @param word Translation in @p language.
     */
    virtual void setTranslation(const QString& language,
                                const QString& word) = 0;

    /**
     * @brief Get the Game Element name.
     *
     * @return const QString Game Element name.
     */
    virtual const QString& name() const = 0;
    /**
     * @brief Get path to the image file.
     *
     * @return const QString Path to the image file.
     */
    virtual const QString& imagePath() const = 0;
    /**
     * @brief Get path to the sound file.
     *
     * @return const QString Path to the sound file.
     */
    virtual const QString& soundPath() const = 0;
    /**
     * @brief Get translation for @p language.
     *
     * Returns translation for the given @p language. If no translation exists
     * returns the name of Game Element.
     *
     * @param language Language code.
     * @return const QString Translated name.
     */
    virtual const QString& translation(Translations::Language language) const = 0;
};

#endif // IGAMEELEMENTDATA_HPP
