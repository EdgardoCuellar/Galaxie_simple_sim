//
// Created by edgar on 18-01-21.
//

#include "Stars.h"

using namespace std;

Stars::Stars(float x, float y, int radius, int m) noexcept: Point(x, y, radius, 0), mass(m) {}

void Stars::move(std::vector<Point*> stars) noexcept {
    for (auto & star : stars) {
        if (star != this){
            double distX = star->getPosX()-getPosX();
            double distY = star->getPosY()-getPosY();
            double attract = (star->getMass()*getMass()*0.0066743) / (pow(distX, 2) + pow(distY, 2));
            speedX += (distX*attract);
            speedY += (distY*attract);
        }
    }
    movePosX(float(speedX));
    movePosY(float(speedY));
}