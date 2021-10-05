#ifndef SDL2_TEST_SCREEN_HPP
#define SDL2_TEST_SCREEN_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Point.h"
#include "Stars.h"
#include <random>

// OPTION
int const WITDH = 1000;
int const HEIGHT = 1000;
int const COLORS[2][3] = {{255,255,255}, {0,0,0}};
int const sizeStars[2] = {0, 3};
int const centered = 3;
int const nbStars = 500;

class Screen{
    bool isRunning{};
    SDL_Window *window{};
    SDL_Renderer *renderer{};
    std::vector<Point*> points;
    bool isStart = false;

public:
    Screen () noexcept;
    ~Screen() noexcept;

    void init(const char* title, int xpos, int ypos, int wigth, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    void createPoints(int nb) noexcept;
    inline void displayPoint() noexcept;
    void inline startAll() noexcept {isStart = true;}

    bool running() const {return isRunning; };
};

#endif //SDL2_TEST_SCREEN_HPP
