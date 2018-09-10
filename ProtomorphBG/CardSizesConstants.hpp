#ifndef CARDSIZESCONSTANTS_HPP
#define CARDSIZESCONSTANTS_HPP

#include <array>

//mesurement in mm
struct CardSize {
    double width;
    double height;
};

const std::array<CardSize, 13> sizes{
    CardSize{63.5, 88},
    CardSize{57, 89},
    CardSize{56, 87},
    CardSize{56, 100},
    CardSize{59, 92},
    CardSize{44, 68},
    CardSize{43, 65},
    CardSize{41, 63},
    CardSize{70, 70},
    CardSize{70, 110},
    CardSize{65, 100},
    CardSize{65, 110},
    CardSize{61, 112}
};

#endif // CARDSIZESCONSTANTS_HPP
