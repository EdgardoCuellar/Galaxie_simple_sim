#ifndef SDL2_TEST_POINT_H
#define SDL2_TEST_POINT_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>

class Point {
    float posX;
    float posY;
    int radius;
    int color;

protected:
    inline void movePosX(float x) noexcept {posX += x;}
    inline void movePosY(float y) noexcept {posY += y;}

public:
    // Constructeur
    Point() noexcept;
    Point(float x, float y, int radius) noexcept;
    Point(float x, float y, int radius, int c) noexcept;
    // GETTER SETTER
    float getPosX() const noexcept {return posX;}
    float getPosY() const noexcept {return posY;}
    int getPosR() const noexcept {return radius;}
    int getColor() const noexcept {return color;}
    virtual inline int getMass() noexcept = 0;

    // Dynamics things
    virtual void move(std::vector<Point*> blackH) noexcept = 0;
    std::vector<std::array<int, 2>> getPoint() const noexcept;

    // Destructeur
    virtual ~Point() noexcept = default;
};


#endif //SDL2_TEST_POINT_H
