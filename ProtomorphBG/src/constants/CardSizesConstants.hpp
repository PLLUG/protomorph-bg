#ifndef CARDSIZESCONSTANTS_HPP
#define CARDSIZESCONSTANTS_HPP

#include <array>

//mesurement in mm
struct CardSize {
    double width;
    double height;
};

const std::array<CardSize, 25> sizes{
    CardSize{41, 63},
    CardSize{43, 65},
    CardSize{45, 68},
    CardSize{49, 93},
    CardSize{50, 75},
    CardSize{54, 80},
    CardSize{55, 80},
    CardSize{56, 87},
    CardSize{57, 89},
    CardSize{57.5, 89},
    CardSize{59, 92},
    CardSize{61, 103},
    CardSize{61, 112},
    CardSize{63.5, 88},
    CardSize{63.5, 92},
    CardSize{65, 100},
    CardSize{65, 110},
    CardSize{70, 70},
    CardSize{70, 110},
    CardSize{70, 120},
    CardSize{75, 105},
    CardSize{80, 120},
    CardSize{80, 80},
    CardSize{87, 112},
    CardSize{88, 125}
};

#endif // CARDSIZESCONSTANTS_HPP
