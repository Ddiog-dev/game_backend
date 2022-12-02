//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CAPACITY_HPP
#define GAME_BACKEND_CAPACITY_HPP

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "capacity-effect.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class Capacity : public oatpp::DTO {

    DTO_INIT(Capacity, DTO /* Extends */);
    DTO_FIELD(String , name);     // Message field
    DTO_FIELD(String , description);     // Message field
    DTO_FIELD(Int32 , damage);     // Message field
    DTO_FIELD(Object<CapacityEffect> , effect);     // Message field

};

#endif //GAME_BACKEND_CAPACITY_HPP
