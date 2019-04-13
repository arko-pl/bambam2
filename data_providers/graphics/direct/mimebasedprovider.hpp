#ifndef MIMEBASEDPROVIDER_HPP
#define MIMEBASEDPROVIDER_HPP

#include "iimageprovider.hpp"
#include <QString>

/**
 * @brief MIME Type based image provider class.
 *
 * This class is responsible for creating QGraphicsImage
 * from files with images. The file parser is selected by
 * its MIME Type.
 */
class MimeBasedProvider : public IImageProvider
{
public:
    /**
     * @brief The constructor.
     *
     * @param path Path to image file.
     */
    explicit MimeBasedProvider(const QString &path);
    /**
     * @brief The destructor.
     *
     */
    ~MimeBasedProvider();

    // IDataProvider interface
    /**
     * @brief Create QGraphicsItem.
     *
     * Creates QGraphicsImage instance using the reader selected by image type.
     *
     * @return QGraphicsItem
     */
    QGraphicsItem* makeItem() override;

private:
    MimeBasedProvider(const MimeBasedProvider&) = delete;
    MimeBasedProvider& operator=(const MimeBasedProvider&) = delete;

    // This class should only contain path, there is no need for
    // private implementation. Keep it simple and don't add
    // unnecessary overhead.
    QString m_path; /**< Image path. */
};


#endif // MIMEBASEDPROVIDER_HPP
