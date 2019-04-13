#ifndef DATAPROVIDER_COMMON_HPP
#define DATAPROVIDER_COMMON_HPP

class QString;

namespace DataProvider {

/**
 * @brief Enumeration with supported data providers.
 *
 * Supported providers:
 * - configuration based provider - data provided are read from configuration
 *   files
 * - text based provider - provides character representation of pressed key
 * - unknown - placeholder for incorrect data read from configuration
 */
enum class Provider {
    ConfigBased,
    Text,
    Unknown
};

extern const QString ConfigBasedProvider; /**< String for configuration
    based provider. */
extern const QString TextProvider; /**< String for text based provider. */

/**
 * @brief Convert string provider @p name to Provider.
 *
 * @param name Name of provider.
 * @return Provider Enumerated provider.
 */
Provider fromString(const QString& name);

}


#endif // DATAPROVIDER_COMMON_HPP
