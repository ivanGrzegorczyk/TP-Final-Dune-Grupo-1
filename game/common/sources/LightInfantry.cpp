#include "../headers/LightInfantry.h"
#include "../headers/Constantes.h"

LightInfantry::LightInfantry(int id, coordenada_t coord) : Units(
        id, LIGHT_INFANTRY_HP, LIGHT_INFANTRY_RANGE,
        LIGHT_INFANTRY_SPEED, UNIT_LIGHT_INFANTRY, coord) {}
