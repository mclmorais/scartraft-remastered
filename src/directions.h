#pragma once

#include <iostream>
#include <map>

enum Direction
{
    DOWN_LEFT,
    DOWN_RIGHT,
    UP_LEFT,
    UP_RIGHT
};
extern std::map<Direction, std::string> directions;
