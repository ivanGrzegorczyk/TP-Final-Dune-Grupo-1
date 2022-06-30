#include "../headers/CeldaUi.h"

CeldaUi::CeldaUi(Texture &texture, std::pair<int, int> coord, Rect dst, Rect area) : coordinate(std::move(coord)),
                                                                                texture(texture), rectangle(dst), area(area){

}

void CeldaUi::render(Renderer &rdr) {
    rdr.Copy(texture, area, rectangle);
}

/*
CeldaUi::CeldaUi() : coordinate(std::make_pair(0, 0)), texture(nullptr){

}
*/
