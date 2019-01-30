#include "src/helpers/GameIconsSvgColorsHelper.hpp"

#include <QDomDocument>

static QDomDocument s_domDocument;

QString Helper::modifyGameIconSvgColors(const QString &data)
{
    if (!s_domDocument.setContent(data))
        return data;

    auto elements = s_domDocument.elementsByTagName(QStringLiteral("path"));
    for(auto i = 0; i < elements.size(); ++i)
    {
        auto element = elements.at(i).toElement();
        if(element.isNull())
            continue;

        if(auto fillAttr = element.attributeNode(QStringLiteral("fill")); fillAttr.isNull())
            element.setAttribute(QStringLiteral("fill"), QStringLiteral("none"));
        else
            fillAttr.setValue(QStringLiteral("%1"));
    }

    return s_domDocument.toString();
}
