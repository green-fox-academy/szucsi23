#include <iostream>
#include <SDL.h>
#include <cmath>

#define PI 3.14159265

struct pont
{
    double x;
    double y;
    
};

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

//Draws geometry on the canvas
void draw(pont&, int);
void drawflake(pont&, int);

pont line(pont, int, int);

void koch(pont&, int, int, int);
void kochflake(pont &, int , int, int);

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window *gWindow = nullptr;

//The window renderer
SDL_Renderer *gRenderer = nullptr;


bool init()
{
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create window
    gWindow = SDL_CreateWindow("Rainbow box function", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                               SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == nullptr) {
        std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close()
{
    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    SDL_Quit();
}


int main(int argc, char *args[])
{
    //Start up SDL and create window
    if (!init()) {
        std::cout << "Failed to initialize!" << std::endl;
        close();
        return -1;
    }

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while (!quit) {
        //Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        pont p;
        p.x = 500;
        p.y = 100;

        //draw(p, 3);

        drawflake(p, 3);

        //Update screen
        SDL_RenderPresent(gRenderer);
    }

    //Free resources and close SDL
    close();

    return 0;
}

void draw(pont &p, int n)
{
    int size = 10;
    int angle = 0;
    koch(p, size, angle, n);
}

void drawflake(pont &p, int n)
{
    int size = 10;
    int angle = 0;
    kochflake(p, size, angle, n);
}

pont line(pont pold, int c, int angle)
{
    pont pnew;
    pnew.x = pold.x + (c * cos((angle) * (PI / 180)));
    pnew.y = pold.y - (c * sin((angle) * (PI / 180)));

    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(gRenderer, pold.x, pold.y, pnew.x, pnew.y);

    pont p;
    p.x = pnew.x;
    p.y = pnew.y;
    return p;
}

void koch(pont &p, int c, int angle, int n)
{
    if (n == 0) {
        p = line(p, c, angle);
    } else {
        koch(p, c, angle, n - 1);
        angle += 60;
        koch(p, c, angle, n - 1);
        angle -= 120;
        koch(p, c, angle, n - 1);
        angle += 60;
        koch(p, c, angle, n - 1);
    }
}

void kochflake(pont &p, int c, int angle, int n)
{
    koch(p, c, angle, n);
    angle -= 120;
    koch(p, c, angle, n);
    angle -= 120;
    koch(p, c, angle, n);
    angle -= 120;
}