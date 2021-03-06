#ifndef TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H
#define TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H

#include <utility>
#define LENGTH_TILE 16

typedef std::pair<int, int> coordenada_t;
// CONSTANTES DESPUES VAN EN EL YAML
#define INVALID_ENTITY_ID 0

#define EVENTS 4
//tipo de respuestas
#define BUILDING 50
#define VEHICLE 60
#define ATTACK 70
#define UNIT 80
#define DEAD 90
#define SPICE 100

//units
#define UNIT_LIGHT_INFANTRY 10
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

//assault rifle data
#define ASSAULT_RIFLE_DAMAGE 2
#define ASSAULT_RIFLE_FREQUENCY 166667

//canyon data
#define CANNON_DAMAGE 7
#define CANNON_FREQUENCY 1000000

//missile launcher data
#define MISSILE_LAUNCHER_DAMAGE 8
#define MISSILE_LAUNCHER_FREQUENCY 1000000

//sound waves data
#define SOUND_WAVES_DAMAGE 4
#define SOUND_WAVES_FREQUENCY 1000000

//canyon22mm data
#define CANNON22MM_DAMAGE 6
#define CANNON22MM_FREQUENCY 166667

//plasma canyon data
#define PLASMA_CANNON_DAMAGE 8
#define PLASMA_CANNON_FREQUENCY 1000000

//protocol
#define REPOSITION_EVENT 1
#define CREATE_BUILDING_EVENT 2
#define CREATE_UNIT_EVENT 3
#define ATTACKING_EVENT 4
#define CREATE_VEHICLE_EVENT 5

//light infantry data
#define LIGHT_INFANTRY_RANGE 3
#define LIGHT_INFANTRY_SPEED 16
#define LIGHT_INFANTRY_HP 50
#define LIGHT_INFANTRY_COST 50

//fremen data
#define FREMEN_RANGE 3
#define FREMEN_SPEED 20
#define FREMEN_HP 50
#define FREMEN_COST 100

//heavy infantry data
#define HEAVY_INFANTRY_RANGE 3
#define HEAVY_INFANTRY_SPEED 12
#define HEAVY_INFANTRY_HP 80
#define HEAVY_INFANTRY_COST 70

//sardaukar data
#define SARDAUKAR_RANGE 3
#define SARDAUKAR_SPEED 12
#define SARDAUKAR_HP 80
#define SARDAUKAR_COST 100

//harvester data
#define HARVESTER_RANGE 0
#define HARVESTER_SPEED 12
#define HARVESTER_COST 300
#define HARVESTER_HP 600

//barracks data
#define BARRACKS_ENERGY 100
#define BARRACKS_COST 300
#define BARRACKS_POINTS 300

//construction center data
#define CONSTRUCTION_CENTER_ENERGY 0
#define CONSTRUCTION_CENTER_COST 0
#define CONSTRUCTION_CENTER_POINTS 3000

//light factory data
#define LIGHT_FACTORY_ENERGY 500
#define LIGHT_FACTORY_COST 800
#define LIGHT_FACTORY_POINTS 500

//air trap data
#define AIR_TRAP_ENERGY 500
#define AIR_TRAP_COST 800
#define AIR_TRAP_POINTS 500

//heavy factory data
#define HEAVY_FACTORY_ENERGY 800
#define HEAVY_FACTORY_COST 1500
#define HEAVY_FACTORY_POINTS 1500

//refinery data
#define REFINERY_ENERGY 400
#define REFINERY_COST 500
#define REFINERY_POINTS 1000
#define REFINERY_CAPACITY 5000

//silo data
#define SILO_ENERGY 100
#define SILO_COST 200
#define SILO_POINTS 200
#define SILO_CAPACITY 1000

//palace data
#define PALACE_ENERGY 800
#define PALACE_COST 2000
#define PALACE_POINTS 1000

//terrain
#define TERRAIN_SAND 0
#define TERRAIN_DUNES 1
#define TERRAIN_ROCKS 2
#define TERRAIN_TOPS 3
#define TERRAIN_CLIFFS 4
#define TERRAIN_SPICE_LOW 5
#define TERRAIN_SPICE_HIGH 6

//houses
#define HOUSE_ATREIDES 0
#define HOUSE_HARKONNEN 1
#define HOUSE_ORDOS 2

#define NAME_ATREIDES "Atreides"
#define NAME_HARKONNEN "Harkonnen"
#define NAME_ORDOS "Ordos"

// 1000000 us / 20
#define GAME_LOOP_RATE 50000

#endif //TP_FINAL_DUNE_GRUPO_1_CONSTANTES_H
