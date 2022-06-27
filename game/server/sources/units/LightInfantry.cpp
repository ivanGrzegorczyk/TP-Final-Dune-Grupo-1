#include "../../headers/units/LightInfantry.h"

LightInfantry::LightInfantry(int id, coordenada_t coord) : Unit(
        playerId, id, LIGHT_INFANTRY_HP, LIGHT_INFANTRY_RANGE,
        LIGHT_INFANTRY_SPEED, UNIT_LIGHT_INFANTRY, coord) {}
