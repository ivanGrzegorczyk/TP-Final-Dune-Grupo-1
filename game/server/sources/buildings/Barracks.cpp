#include "../../headers/buildings/Barracks.h"

Barracks::Barracks(int id, coordenada_t coord) :
Building(id, BARRACKS_POINTS, BUILDING_BARRACKS, coord, BARRACKS_ENERGY, BARRACKS_COST) {}