#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>


void DrawCircle();
void DrawFilledCircle();
void drawEmptyRect();
void drawFullRect();

// Dessine le cercle donné
void DrawCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    int new_x = 0;
    int new_y = 0;
    int old_x =  origin_x + radius;
    int old_y = origin_y;
    float step = (M_PI * 2) / 50;

    SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, 255);

    for(float theta = 0; theta <= (M_PI * 2); theta += step){
        new_x = origin_x + (radius * cos(theta));
        new_y = origin_y - (radius * sin(theta));

        SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

        old_x = new_x;
        old_y = new_y;
    }

    new_x = origin_x + radius;
    new_y = origin_y;
    SDL_RenderDrawLine(p_renderer, old_x, old_y, new_x, new_y);

}


// Dessine le cercle donné, rempli
void DrawFilledCircle(SDL_Renderer *p_renderer, int origin_x, int origin_y, int radius, SDL_Color color)
{
    for(double dy = 1; dy <= radius; dy += 1.0){

        double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));

        SDL_SetRenderDrawColor(p_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y + dy - radius, origin_x + dx, origin_y + dy - radius);
        SDL_RenderDrawLine(p_renderer, origin_x - dx, origin_y - dy + radius, origin_x + dx, origin_y - dy + radius);

    }
}

//dessiner le rectangle plein
void drawFullRect(SDL_Surface * surf,int posX, int posY, int width, int length, int R, int G, int B)
{
	SDL_Rect Rect;
	Rect.x = posX;
	Rect.y = posY;
	Rect.w = length-1;
	Rect.h = width-1;

	SDL_FillRect(surf, &Rect, SDL_MapRGB(surf->format, R, G, B));
}

//dessiner le rectangle vide
void drawEmptyRect(SDL_Surface * surf,int posX, int posY, int width, int length, int R, int G, int B)
{
	SDL_Rect ligneHaut;
	ligneHaut.x = posX-1;
	ligneHaut.y = posY-1;
	ligneHaut.w = length;
	ligneHaut.h = 1;

	SDL_FillRect(surf, &ligneHaut, SDL_MapRGB(surf->format, R, G, B));

	SDL_Rect ligneDroite;
	ligneDroite.x = posX+length-1;
	ligneDroite.y = posY-1;
	ligneDroite.w = 1;
	ligneDroite.h = width;

	SDL_FillRect(surf, &ligneDroite, SDL_MapRGB(surf->format, R, G, B));

	SDL_Rect ligneGauche;
	ligneGauche.x = posX-1;
	ligneGauche.y = posY-1;
	ligneGauche.w = 1;
	ligneGauche.h = width;

	SDL_FillRect(surf, &ligneGauche, SDL_MapRGB(surf->format, R, G, B));

	SDL_Rect ligneBas;
	ligneBas.x = posX-1;
	ligneBas.y = posY+width-1;
	ligneBas.w = length;
	ligneBas.h = 1;

	SDL_FillRect(surf, &ligneBas, SDL_MapRGB(surf->format, R, G, B));
}
int main(int argc, char *argv[])
{


    //il n'y a pas la partie qui gère l'affichage, simplement la création des 4 figures.
    return 0;
}
