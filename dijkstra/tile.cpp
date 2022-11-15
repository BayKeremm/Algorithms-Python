#include "tile.h"
#include <sstream>
// class Tile
Tile::Tile(int xPosition, int yPosition, float tileWeight) : xPos(xPosition), yPos(yPosition), value(tileWeight)
{
}

std::string Tile::serialize()
{
    std::stringstream res;
    res << xPos << "," << yPos << "," << value;
    return res.str();
}