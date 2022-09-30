//
// Created by alexi on 09/06/2022.
//

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#ifndef GAME_BACKEND_TIER_H
#define GAME_BACKEND_TIER_H

#include OATPP_CODEGEN_BEGIN(DTO)

class Tier : public oatpp::DTO {
    DTO_INIT(Tier, DTO /* Extends */)

    DTO_FIELD(String, description);     // Message field
    DTO_FIELD(Int32, income);   // Status code field
    DTO_FIELD(String, incomeType);     // Message field
    DTO_FIELD(Int32, cost);   // Status code field
};

#include OATPP_CODEGEN_END(DTO)

#endif //GAME_BACKEND_TIER_H
