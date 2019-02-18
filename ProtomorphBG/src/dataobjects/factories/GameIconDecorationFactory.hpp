#ifndef GAMEICONDECORATIONFACTORY_HPP
#define GAMEICONDECORATIONFACTORY_HPP

#include "src/dataobjects/factories/IDataObjectDecorationFactory.hpp"

namespace Dataobject
{
class GameIconDecorationFactory : public IDataObjectDecorationFactory
{
public:
    GameIconDecorationFactory();
    virtual ~GameIconDecorationFactory() override;

private:
    // IDataObjectDecorationFactory interface
    virtual ComponentDecoration *createDecoration(const QVariantMap &decorationData) const override;
};
}
#endif // GAMEICONDECORATIONFACTORY_HPP
