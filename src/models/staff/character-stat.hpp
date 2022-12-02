//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CHARACTER_STAT_HPP
#define GAME_BACKEND_CHARACTER_STAT_HPP

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class CharacterStat : public oatpp::DTO {

    DTO_INIT(CharacterStat, DTO /* Extends */);
    DTO_FIELD(Int32 , maximum);     // Message field
    DTO_FIELD(Int32 , current);     // Message field

};

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //GAME_BACKEND_CHARACTER_STAT_HPP
