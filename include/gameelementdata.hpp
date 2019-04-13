#ifndef GAMEELEMENTDATA_H
#define GAMEELEMENTDATA_H

#include "igameelementdata.hpp"
#include "pimpl.hpp"

class QString;
class GameElementDataImpl;

/**
 * @brief Game Element Data
 *
 * This class represents data model used in game.
 */
class GameElementData : public IGameElementData {
public:
    /**
     * @brief The default constructor.
     *
     */
    explicit GameElementData();
    /**
     * @brief The constructor.
     *
     * @param name Game Element name.
     */
    explicit GameElementData(const QString& name);
    /**
     * @brief The destructor.
     *
     */
    ~GameElementData();
    /**
     * @brief Set image path.
     *
     * @param path Path to the image file.
     */
    void setImagePath(const QString&) override;
    /**
     * @brief Set sound path.
     *
     * @param path Path to the sound file.
     */
    void setSoundPath(const QString&) override;
    /**
     * @brief Set the translation @p word in specific @p language.
     *
     * @param language Language symbol.
     * @param word Translation in @p language.
     */
    void setTranslation(const QString& language, const QString& word) override;
    /**
     * @brief Set the element name.
     *
     * @param name Game Element name.
     */
    void setName(const QString&) override;

    /**
     * @brief Get the Game Element name.
     *
     * @return const QString Game Element name.
     */
    const QString& name() const override;
    /**
     * @brief Get path to the image file.
     *
     * @return const QString Path to the image file.
     */
    const QString& imagePath() const override;
    /**
     * @brief Get path to the sound file.
     *
     * @return const QString Path to the sound file.
     */
    const QString& soundPath() const override;
    /**
     * @brief Get translation for @p language.
     *
     * Returns translation for the given @p language. If no translation exists
     * returns the name of Game Element.
     *
     * @param language Language code.
     * @return const QString Translated name.
     */
    const QString& translation(const QString& language) const override;
private:
    GameElementData(const GameElementData&) = delete;
    GameElementData& operator=(const GameElementData&) = delete;
    /**
     * @brief Create private implementation class.
     *
     * Helper for creating GameElementDataImpl.
     *
     * @param name Game Element name.
     */
    void makeImpl(const QString&);

    PImpl<GameElementDataImpl> pImpl; /**< Pointer to the implementation. */
};

#endif // GAMEELEMENTDATA_H
