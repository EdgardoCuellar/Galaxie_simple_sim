#include "Screen.hpp"

using namespace std;

Screen::Screen() noexcept = default;

Screen::~Screen() noexcept {
    for (auto & point : points) {
        delete point;
    }
}

void Screen::init(const char *title, int xpos, int ypos, int wigth, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "All is init" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, wigth, height, flags);
        if (window){
            cout << "Window created" << endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
            cout << "Renderer create" << endl;
        }

        isRunning = true;
    } else{
        isRunning = false;
    }
}

void Screen::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    startAll();
                    cout << "STARTED" << endl;
                    break;
            }
            break;
    }
}
void Screen::update(){
    if (isStart){
        for (auto & point : points) {
            point->move(points);
        }
    }
}

void Screen::render(){
    // Background
    SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
    SDL_RenderClear(renderer);
    // Display all point
    displayPoint();
    SDL_RenderPresent(renderer);
}

void Screen::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "All clean up" << endl;
}

void Screen::createPoints(int nb) noexcept{
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> rdW(static_cast<int>(WITDH/centered), static_cast<int>((WITDH*(centered-1))/centered));
    uniform_real_distribution<double> rdH(static_cast<int>(HEIGHT/centered), static_cast<int>((HEIGHT*(centered-1))/centered));
    uniform_real_distribution<double> rdS(sizeStars[0], sizeStars[1]);
    for (int i = 0; i < nb; ++i) {
        int tmp = rdS(mt);
        points.push_back(new Stars(rdW(mt), rdH(mt), tmp, tmp+1));
    }
}

void Screen::displayPoint() noexcept {
    for (auto & point : points) {
        SDL_SetRenderDrawColor(renderer, COLORS[point->getColor()][0], COLORS[point->getColor()][1], COLORS[point->getColor()][2], 255);
        vector<array<int, 2>> tmp = point->getPoint();
        for (int i = 0; i < tmp.size()/2; ++i) {
            SDL_RenderDrawLine(renderer, tmp[i*2][0], tmp[i*2][1], tmp[(i*2)+1][0], tmp[(i*2)+1][1]);
        }
        SDL_RenderDrawLine(renderer, static_cast<int>(point->getPosX())-point->getPosR(), static_cast<int>(point->getPosY()),
                           static_cast<int>(point->getPosX())+point->getPosR(), static_cast<int>(point->getPosY()));
    }
}



