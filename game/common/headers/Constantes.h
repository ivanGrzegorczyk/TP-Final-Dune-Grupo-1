#ifndef TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H
#define TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H

#include <utility>

typedef std::pair<int, int> coordenada_t;
// CONSTANTES DESPUES VAN EN EL YAML

//units
#define UNIT_LIGHT_INFANTRY 10  // cambiar a UNIT_LIGHT_INFANTRY
#define UNIT_HEAVY_INFANTRY 11
#define UNIT_FREMEN 12
#define UNIT_SARDAUKAR 13

//vehicles
#define VEHICLE_TRIKE 14
#define VEHICLE_SONIC_TANK 15
#define VEHICLE_RAIDER 16
#define VEHICLE_DIVERTER 17
#define VEHICLE_TANK 18
#define VEHICLE_DEVASTATOR 19
#define VEHICLE_HARVESTER 20

//buildings
#define BUILDING_CONSTRUCTION_CENTER 21
#define BUILDING_LIGHT_FACTORY 22
#define BUILDING_HEAVY_FACTORY 23
#define BUILDING_AIR_TRAP 24
#define BUILDING_REFINERY 25
#define BUILDING_SILO 26
#define BUILDING_BARRACKS 27
#define BUILDING_PALACE 28

//protocol
#define REPOSITION_EVENT 1
#define CREATE_BUILDING_EVENT 2
#define CREATE_UNIT_EVENT 3

//light infantry data
#define LIGHT_INFANTRY_RANGE 3
#define LIGHT_INFANTRY_SPEED 16
#define LIGHT_INFANTRY_HP 50

//harvester data
#define HARVESTER_RANGE 0
#define HARVESTER_SPEED 12
#define HARVESTER_COST 300
#define HARVESTER_HP 600

//barracks data
#define BARRACKS_ENERGY 100
#define BARRACKS_COST 300
#define BARRACKS_POINTS 300

//terrain
#define TERRAIN_SAND 0
#define TERRAIN_DUNES 1
#define TERRAIN_ROCKS 2
#define TERRAIN_TOPS 3
#define TERRAIN_CLIFFS 4

//houses
#define HOUSE_ATREIDES 0
#define HOUSE_HARKONNEN 1
#define HOUSE_ORDOS 2

#define GAME_LOOP_RATE (1.0 / 30.0)

#endif //TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H
