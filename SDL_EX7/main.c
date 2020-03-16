#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <SDL2/SDL.h>



int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* screen= SDL_CreateWindow("My window LUDUS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480,170,NULL);
    //création de la fenêtre
    SDL_Event event;

    int repeat = 0;

    while(!repeat)
    {
        SDL_PollEvent(&event);

        switch(event.type)
            {

            case SDL_QUIT:
                repeat =1;
                break;
            }
    }



    SDL_Quit();
    return 0;
}
