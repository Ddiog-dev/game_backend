//
// Created by alexi on 09/06/2022.
//

#include <string>
#include "nlohmann/json.hpp"
#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"


#include "../Tier.hpp"
#include <fstream>

#ifndef GAME_BACKEND_BUILDING_H
#define GAME_BACKEND_BUILDING_H
#include OATPP_CODEGEN_BEGIN(DTO)
using namespace std;
using json = nlohmann::json;

namespace Building_Informations {
    enum Building_Type {
        TAVERN,
        FORUM
    };

    class Building : public oatpp::DTO {
        DTO_INIT(Building, DTO /* Extends */)
        DTO_FIELD(Int32, level);   // Status code field
        DTO_FIELD(String, name);     // Message field
        DTO_FIELD(String, description);     // Message field
        DTO_FIELD(Object<Tier>, tier);     // Message field
        DTO_FIELD(List<Object<TierList>>, allTier);     // Message field
    public:
        void getBuilding(Building_Type building) {
            switch (building) {
                case TAVERN:
                    this->readBuildingJSON("src/assets/buildings/tavern.json");
                    break;
                case FORUM:
                    this->readBuildingJSON("C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/forum.json");
                    break;
                default:;
            }
        };

    private:
        void readBuildingJSON(const string &path) {
            std::ifstream i(path);
            json buildingJSON;
            i >> buildingJSON;
            /* create json ObjectMapper with default configs */
            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
            auto cloneOfUser = jsonObjectMapper->readFromString<oatpp::Object<Building_Informations::Building>>(buildingJSON.dump());
            this->name = cloneOfUser-> name;
            this->level = cloneOfUser -> level;
            this->description = cloneOfUser -> description;
            this->tier = cloneOfUser -> tier;
            this->allTier = cloneOfUser -> allTier;

        };
    };
}
/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)
#endif //GAME_BACKEND_BUILDING_H
