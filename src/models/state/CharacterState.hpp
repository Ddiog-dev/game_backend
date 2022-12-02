//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CHARACTERSTATE_HPP
#define GAME_BACKEND_CHARACTERSTATE_HPP
#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../staff/character.hpp"

class CharacterState : public oatpp::DTO {

    DTO_INIT(CharacterState, DTO /* Extends */);
    DTO_FIELD(List<Object<Character_informations::Character>> , characters);     // Message field

};
#endif //GAME_BACKEND_CHARACTERSTATE_HPP
