#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <QDateTime>

#include <string>

struct Project
{
    QDateTime   created{};
    QDateTime   updated{};
    std::string coverImage{};
    std::string name{};
    std::string description{};
};

#endif // PROJECT_HPP
