#include "src/helpers/GradientHelper.hpp"

#include <QMetaEnum>


class PresetGradiensInitializer {
public:
    PresetGradiensInitializer()
        : m_metaEnum{QMetaEnum::fromType<QGradient::Preset>()}
    {
        initPresetGradients();
    }

    QGradient::Preset getPresetGradient(const QString &presetName)
    {
        auto enumValue = m_metaEnum.keyToValue(presetName.toStdString().c_str());
        return static_cast<QGradient::Preset>(enumValue);
    }

    QStringList getPresetGradientsList()
    {
        return m_presetGradients;
    }

    QString getPresetGradientString(QGradient::Preset presetEnum)
    {
        return m_metaEnum.valueToKey(static_cast<int>(presetEnum));
    }

private:
    void initPresetGradients()
    {
        auto nofEnumValues = m_metaEnum.keyCount();

        m_presetGradients.reserve(nofEnumValues);

        for (auto i = 0; i < nofEnumValues; ++i)
            m_presetGradients << QLatin1String{m_metaEnum.key(i)};
    }

    QStringList m_presetGradients;
    QMetaEnum m_metaEnum;
};

static PresetGradiensInitializer s_presetGradiensInitializer;

QGradient::Preset Helper::getPresetGradient(const QString &presetName)
{
    return s_presetGradiensInitializer.getPresetGradient(presetName);
}

QStringList Helper::getPresetGradientsList()
{
    return s_presetGradiensInitializer.getPresetGradientsList();
}

QString Helper::getPresetGradientString(QGradient::Preset presetEnum)
{
    return s_presetGradiensInitializer.getPresetGradientString(presetEnum);
}
