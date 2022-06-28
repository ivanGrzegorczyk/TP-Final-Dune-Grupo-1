#include <map>
#include "client/headers/BuildingFactory.h"

// TODO this reads from the yaml instead
std::vector<std::shared_ptr<BuildingType>>  BuildingFactory::createBuildingTypes(Renderer &render) {
    std::vector<std::shared_ptr<BuildingType>>  building_types;
    coordenada_t size = {2,2};
    std::ifstream file(DATA_PATH "config.yaml");
    YAML::Node config = YAML::Load(file);

    // todo load cost, energy etc onto Building Type
    for(YAML::Node building : config["buildings"]) {
        std::string texture_name = "Barracks.png";
        Surface surface(std::string(DATA_PATH "/") + texture_name );
        Texture texture(render, surface);
        std::string name (building["name"].as<std::string>());
        std::shared_ptr<BuildingType> type(new BuildingType(1,name,3,4,size, std::move(texture)));
        building_types.push_back(type);
    }
    return building_types;
}


