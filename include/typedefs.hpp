#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

template<typename T1, typename T2>
class QMultiHash;
class IGameElementData;
class QChar;

/**
 * @brief Elements mapping with starting character as a key and
 * IGameElementData pointer as a value.
 *
 */
using GameElementMap = QMultiHash<QChar, IGameElementData*>;

#endif // TYPEDEFS_HPP
