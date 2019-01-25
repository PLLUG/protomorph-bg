#include "src/helpers/GradientHelper.hpp"

#include <QMetaEnum>

static QMetaEnum s_metaEnum{QMetaEnum::fromType<QGradient::Preset>()};

QGradient::Preset Helper::getPresetGradient(const QString &pesetName)
{
    auto enumValue = s_metaEnum.keyToValue(pesetName.toStdString().c_str());
    return static_cast<QGradient::Preset>(enumValue);
}

QStringList Helper::getPresetGradientsList()
{
    auto nofEnumValues = s_metaEnum.keyCount();
    QStringList presetGradients;
    presetGradients.reserve(nofEnumValues);

    for (auto i = 0; i < nofEnumValues; ++i)
        presetGradients << QLatin1String{s_metaEnum.key(i)};

    return presetGradients;
}

QString Helper::getPresetGradientString(QGradient::Preset pesetEnum)
{
    return s_metaEnum.valueToKey(static_cast<int>(pesetEnum));
}
