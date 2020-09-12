#include "textdataprovider.hpp"

#include <QString>
#include "gameelementdata.hpp"

class TextDataProviderImpl {
public:
    TextDataProviderImpl() {}
    friend class TextDataProvider;
private:
    GameElementData m_gameElement;
};


TextDataProvider::TextDataProvider() {
    pImpl = std::make_unique<TextDataProviderImpl>();
}

IGameElementData* TextDataProvider::getDataElement(const QString &key)
{
    pImpl->m_gameElement.setName(key);
    return &pImpl->m_gameElement;
}
