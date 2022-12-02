//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CAPACITY_EFFECT_HPP
#define GAME_BACKEND_CAPACITY_EFFECT_HPP

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class CapacityEffect : public oatpp::DTO {

    DTO_INIT(CapacityEffect, DTO /* Extends */);
    DTO_FIELD(String, description);

};

#endif //GAME_BACKEND_CAPACITY_EFFECT_HPP
