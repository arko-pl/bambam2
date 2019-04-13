#ifndef SVGITEMPROVIDER_HPP
#define SVGITEMPROVIDER_HPP

#include "iidataprovider.hpp"
#include <memory>

class SVGItemProviderPrivate;

class SVGItemProvider : public IDataProvider
{
public:
    SVGItemProvider();

    // IDataProvider interface
public:
    GameElement *getDataElement(const QString &key) override;
    QString getProviderName() const override;

private:
    std::unique_ptr<SVGItemProviderPrivate> pImpl;
};

#endif // SVGITEMPROVIDER_HPP
