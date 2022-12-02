//
// Created by alexi on 09/06/2022.
//

#include <string>
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
#include "utils/ObjectFileMapper.hpp"

using namespace std;

namespace Building_Informations {


/* create json ObjectMapper with default configs */
    enum Building_Type {
        TAVERN,
        FORUM,
        MINE,
        POTION_SHOP
    };

    const string filesPaths[] = {
            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/tavern.json",
            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/forum.json",
            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/mine.json",
            "C:/Users/alexi/CLionProjects/game-backend/src/assets/buildings/potion-shop.json",
    };



    class Building : public oatpp::DTO {
        DTO_INIT(Building, DTO /* Extends */)

        DTO_FIELD(Int32, level);   // Status code field
        DTO_FIELD(String, name);     // Message field
        DTO_FIELD(String, description);     // Message field
        DTO_FIELD(Object<Tier >, tier);     // Message field
        DTO_FIELD(List<List<Object<Tier>>>, allTiers);     // Message field

    public:
        static oatpp::data::mapping::type::DTOWrapper<Building> getBuilding(int building) {
            try{
                return ObjectFileMapper::readFromFile<Building>(filesPaths[building]);
            } catch (runtime_error &error){
                cout << "read file error : " << error.what() << endl;
            }
        };
    };
}
/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //GAME_BACKEND_BUILDING_H
