#include <map>
#include "client/headers/BuildingFactory.h"

std::vector<std::shared_ptr<BuildingType>>  BuildingFactory::createBuildingTypes(Renderer &render) {
    std::vector<std::shared_ptr<BuildingType>>  building_types;
    coordenada_t size = {2,2};
    std::ifstream file(DATA_PATH "config.yaml");
    YAML::Node config = YAML::Load(file);

    // todo load cost, energy etc onto Building Type
    for(YAML::Node building : config["buildings"]) {
        std::string texture_name = building["texture"].as<std::string>();
        Surface surface(std::string(DATA_PATH "/") + texture_name );
        Texture texture(render, surface);
        std::string name (building["name"].as<std::string>());
        // TODO everything has a barrack id
        int id = building["id"].as<int>();
        std::cout << texture_name << ":" << id << std::endl;
        std::shared_ptr<BuildingType> type(new BuildingType(1,name,id,3,4,size, std::move(texture)));
        building_types.push_back(type);
    }
    return building_types;
}

std::vector<std::shared_ptr<UnitType>>  BuildingFactory::createUnitTypes(Renderer &render) {
    std::vector<std::shared_ptr<UnitType>>  unit_types;
    coordenada_t size = {2,2};
    std::ifstream file(DATA_PATH "config.yaml");
    YAML::Node config = YAML::Load(file);

    // todo load cost, energy etc onto Building Type
    for(YAML::Node unit : config["units"]) {
        std::string texture_name = "00114a2a.bmp";
        Surface surface(std::string(DATA_PATH "/") + texture_name );
        Texture texture(render, surface);
        std::string name (unit["name"].as<std::string>());
        // TODO everything has a barrack id
        int id = 257;
        std::cout << texture_name << ":" << id << std::endl;
        std::shared_ptr<UnitType> type(new UnitType(name,id,3,4,3,3,3, std::move(texture)));
        unit_types.push_back(type);
    }
    return unit_types;
}


