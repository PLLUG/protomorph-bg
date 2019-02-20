#ifndef GAMEICONDECORATIONFACTORY_HPP
#define GAMEICONDECORATIONFACTORY_HPP

#include "src/dataobjects/factories/IDataObjectDecorationFactory.hpp"
#include "src/store/factories/IDecorationStoreFactory.hpp"

namespace Dataobject
{
class GameIconDecorationFactory : public IDataObjectDecorationFactory
                                , public IDecorationStoreFactory
{
public:
    GameIconDecorationFactory();
    virtual ~GameIconDecorationFactory() override;

private:
    // IDataObjectDecorationFactory interface
    virtual std::unique_ptr<ComponentDecoration> createDecoration(const QVariantMap &decorationData) const override;

    // IDecorationStoreFactory interface
    virtual std::unique_ptr<DecorationStore> createDecorationStore(ComponentDecoration &componentDecoraton) override;
};
}
#endif // GAMEICONDECORATIONFACTORY_HPP
