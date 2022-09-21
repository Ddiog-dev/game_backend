//
// Created by alexi on 09/06/2022.
//

#include <string>
#include "nlohmann/json.hpp"
#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "../Tier.hpp"
#include <fstream>
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"



#ifndef GAME_BACKEND_BUILDING_H
#define GAME_BACKEND_BUILDING_H

#include OATPP_CODEGEN_BEGIN(DTO)

using namespace std;
using json = nlohmann::json;

namespace Building_Informations {


/* create json ObjectMapper with default configs */
    enum Building_Type {
        TAVERN,
        FORUM
    };

    class Building : public oatpp::DTO {
        DTO_INIT(Building, DTO /* Extends */)

        DTO_FIELD(Int32, level);   // Status code field
        DTO_FIELD(String, name);     // Message field
        DTO_FIELD(String, description);     // Message field
        DTO_FIELD(Object < Tier >, tier);     // Message field
        DTO_FIELD(List < List < Object < Tier>>>, allTier);     // Message field

    public:

        static oatpp::data::mapping::type::DTOWrapper<Building> getBuilding(int building, shared_ptr<oatpp::data::mapping::ObjectMapper> mapper){
            return mapper->readFromString<oatpp::Object<Building>>(Building::getBuilding(building));
        }

        static string getBuilding(int building) {
            switch (building) {
                case TAVERN:
                    return Building::readBuildingJSON(
                            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/tavern.json");
                case FORUM:
                default:
                    return Building::readBuildingJSON(
                            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/forum.json");

            }
        };

        static void setState(const shared_ptr<oatpp::web::protocol::http::incoming::Request> request) {
            oatpp::data::stream::FileOutputStream fileOutputStream("C:/Users/alexi/CLionProjects/game-backend/src/assets/state/state.json");
            request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
        }

    private:
        static string readBuildingJSON(const string &path) {
            std::ifstream i(path);
            json buildingJSON;
            i >> buildingJSON;
            return buildingJSON.dump();
        }
    };
}
/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //GAME_BACKEND_BUILDING_H
