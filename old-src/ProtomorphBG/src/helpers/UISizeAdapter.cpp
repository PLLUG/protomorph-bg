#include "src/helpers/UISizeAdapter.hpp"

#include <QApplication>
#include <QScreen>

using namespace Helper;

constexpr double STANDARD_HEIGHT{1366.};
constexpr double STANDARD_WIDTH{768.};

UISizeAdapter *UISizeAdapter::instance()
{
    static UISizeAdapter instance;
    return &instance;
}

UISizeAdapter::UISizeAdapter(QObject *parent)
    : QObject{parent}
    , m_ratio{1.0}
{
    if (auto primaryScreen = QApplication::primaryScreen())
    {
        auto screenGeometry = primaryScreen->geometry();

        const auto screenHeight = qMax(screenGeometry.width(), screenGeometry.height());
        const auto screenWidth = qMin(screenGeometry.width(), screenGeometry.height());

        m_ratio = qMin(screenHeight / STANDARD_HEIGHT,
                      screenWidth / STANDARD_WIDTH);
    }
}

int UISizeAdapter::calculateSize(const int value) const
{
    return static_cast<int>(value * m_ratio);
}
