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

int sdl(MapaEditor& mapa) {
    SDL sdl(SDL_INIT_VIDEO);
	SDLImage image(IMG_INIT_PNG); // optional
	Window window("libSDL2pp demo: fill", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
	Renderer render(window, -1, SDL_RENDERER_ACCELERATED);
    Surface surf(std::string("crate.png"));
	Texture sprite(render, std::string("crate.png"));
    SDL2pp::Point position(0,0);
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
        // offset
        if(!events.empty()) {
            position.SetX(events[0].button.x);
            position.SetY(events[0].button.y);
        }
        SDL2pp::Point map_center = sprite.GetSize() * 5 / 2;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                SDL2pp::Point coordinate(i,j);
                const CeldaEditor& cell = mapa.cell({coordinate.x,coordinate.y});
                coordinate = position - map_center + coordinate * sprite.GetSize();
                if(cell.propiedades.empty()) {
                    if(cell.terreno == "montania") {
                        sprite.SetColorMod(50,50,100);
                    } else {
                        sprite.SetColorMod(255,255,255);
                    }
                } else {
                    sprite.SetColorMod(100,255,0);
                }
                render.Copy(
                        sprite, NullOpt, 
                        Rect(
                            coordinate.GetX(), 
                            coordinate.GetY(), 
                            sprite.GetWidth(), 
                            sprite.GetHeight()));
                
            }
        }
        render.Present();
		// Frame limiter
		SDL_Delay(1);
	}
    return 0;
}
int main() {
    MapaEditor m(5,5);
    coordenada_t construccion = {1,3};
    m.colocar_centro_construccion(construccion);
    std::cout << m.centro_construccion();

    coordenada_t construccion2 = {4,0};
    m.colocar_centro_construccion(construccion2);
    std::cout << m.centro_construccion() << std::endl;
    std::vector<coordenada_t> celdas_montania;
    celdas_montania.push_back({3,3});
    celdas_montania.push_back({3,4});
    m.poner_terreno(celdas_montania, "montania");
    sdl(m);
}
