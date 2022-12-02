//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CHARACTER_INVENTORY_HPP
#define GAME_BACKEND_CHARACTER_INVENTORY_HPP
#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "capacity-effect.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class CharacterInventory : public oatpp::DTO {

    DTO_INIT(CharacterInventory, DTO /* Extends */);
    DTO_FIELD(String, helmet);
    DTO_FIELD(String, neck);
    DTO_FIELD(String, back);
    DTO_FIELD(String, torso);
    DTO_FIELD(String, hand);
    DTO_FIELD(String, leg);
    DTO_FIELD(String, feet);
    DTO_FIELD(String, left_hand);
    DTO_FIELD(String, right_hand);
    DTO_FIELD(String, ring_1);
    DTO_FIELD(String, ring_2);
};

#endif //GAME_BACKEND_CHARACTER_INVENTORY_HPP
