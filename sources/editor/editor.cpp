#include <iostream>
#include "../../headers/editor/mapa_editor.h"
#include <SDL.h>
#include <SDL_image.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/SDLImage.hh>
#include <SDL2pp/Window.hh>
#include <SDL2pp/Renderer.hh>
#include <SDL2pp/Texture.hh>
#include <SDL2pp/Surface.hh>
#include <string>
using namespace SDL2pp;

int sdl() {
    SDL sdl(SDL_INIT_VIDEO);
	SDLImage image(IMG_INIT_PNG); // optional
	Window window("libSDL2pp demo: fill", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
	Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    Surface surf(std::string("crate.png"));
	Texture sprite(render, std::string("crate.png"));
    // offset
    SDL2pp::Point offset(0,0);
    while (1) { // TODO more RAII
		SDL_Event event;
        std::vector<SDL_Event> events;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT 
                || (event.type == SDL_KEYDOWN 
                    && (event.key.keysym.sym == SDLK_ESCAPE 
                        || event.key.keysym.sym == SDLK_q)))
				return 0;
            if(event.type == SDL_MOUSEBUTTONDOWN) {
                events.push_back(event);
            }
        }
        //get click
		// Clear screen
		render.SetDrawColor(255, 255, 255);
		render.Clear();
        // if mouse click was detected
        if(!events.empty()) {
            offset.SetX(events[0].button.x);
            offset.SetY(events[0].button.y);
        }
		render.FillCopy(
            sprite, NullOpt, 
            Rect(32, 32, window.GetWidth() - 64, window.GetHeight() - 64), 
            offset, 
            SDL_FLIP_HORIZONTAL);
		render.Present();

		// Frame limiter
		SDL_Delay(1);
	}
}
int main() {
    sdl();
    MapaEditor m(5,5);
    m.imprimir();
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);
    std::cout << m.centro_construccion();

    coordenada_t construccion2 = {4,1};
    m.colocar_centro_construccion(construccion2);
    std::cout << m.centro_construccion() << std::endl;
    std::vector<coordenada_t> celdas_montania;
    celdas_montania.push_back({3,3});
    celdas_montania.push_back({3,4});
    m.poner_terreno(celdas_montania, "montania");
    m.imprimir();
}
