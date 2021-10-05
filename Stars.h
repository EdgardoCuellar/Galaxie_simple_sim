//
// Created by edgar on 18-01-21.
//

#ifndef SDL2_TEST_STARS_H
#define SDL2_TEST_STARS_H

#include "Point.h"
#include <vector>

class Stars: public Point {

    double speedX = 0;
    double speedY = 0;
    int mass{};

public:
    // Constructeur
    Stars() noexcept = default;
    Stars(float x, float y, int radius, int m) noexcept;

    inline int getMass() noexcept override {return mass;}
    void move(std::vector<Point*> blackH) noexcept override;

    // Destructeur
    ~Stars() noexcept override = default;

};


#endif //SDL2_TEST_STARS_H
