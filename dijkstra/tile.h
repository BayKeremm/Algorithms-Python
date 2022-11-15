#ifndef TILE_H_
#define TILE_H_
#include <string>
class Tile
{
public:
    Tile(int xPosition, int yPosition, float tileWeight);
    virtual ~Tile() = default;
    float getValue() const { return value; };
    void setValue(float newValue) { value = newValue; };
    int getXPos() const { return xPos; };
    int getYPos() const { return yPos; };
    void setXPos(int newPos) { xPos = newPos; };
    void setYPos(int newPos) { yPos = newPos; }
    bool operator==(const Tile &other) const
    {
        return (getXPos() == other.getXPos()) && (getYPos() == other.getYPos());
    };
    virtual std::string serialize();

protected:
    int xPos;
    int yPos;
    float value;
};
#endif