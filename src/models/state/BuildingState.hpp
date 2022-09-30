//
// Created by alexi on 21/09/2022.
//

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "../Tier.hpp"

#ifndef GAME_BACKEND_BUILDINGSTATE_HPP
#define GAME_BACKEND_BUILDINGSTATE_HPP

#include OATPP_CODEGEN_BEGIN(DTO)

namespace BuildingStateRepresentation {

    class BuildingSimplified : public oatpp::DTO  {
        DTO_INIT(BuildingSimplified, DTO /* Extends */)

        DTO_FIELD(String , name);   // Status code field
        DTO_FIELD(Object<Tier>, tier);     // Message field
    };

    class BuildingState : public oatpp::DTO {
        DTO_INIT(BuildingState, DTO /* Extends */)
        DTO_FIELD(List<Object<BuildingSimplified>>, buildings);   // Status code field
    };
}
#endif //GAME_BACKEND_BUILDINGSTATE_HPP
