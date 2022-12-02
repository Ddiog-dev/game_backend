//
// Created by alexi on 10/10/2022.
//

#ifndef GAME_BACKEND_CHARACTER_HPP
#define GAME_BACKEND_CHARACTER_HPP

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "character-stat.hpp"
#include "capacity.hpp"
#include "character-inventory.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

using namespace std;

namespace Character_informations {

    enum Character_Type {
        KNIGHT
    };

    const string filesPaths[] = {
            "C:/Users/alexi/CLionProjects/game-backend/src/assets/characters/knight.json",
    };

/**
 * Message Data-Transfer-Object
 */
    class Character : public oatpp::DTO {

        DTO_INIT(Character, DTO /* Extends */);

        DTO_FIELD(String, name);     // Message field
        DTO_FIELD(Int32,level);
        DTO_FIELD(Object < CharacterStat >, hp);     // Message field
        DTO_FIELD(Object < CharacterStat >, mana);     // Message field
        DTO_FIELD(Object < CharacterStat >, atk);     // Message field
        DTO_FIELD(Object < CharacterStat >, def);     // Message field
        DTO_FIELD(List < Object < Capacity >>, capacities);     // Message field
        DTO_FIELD(Object < CharacterInventory >, inventory);     // Message field

    public:
        static oatpp::data::mapping::type::DTOWrapper<Character> getCharacter(int building) {
            try {
                return ObjectFileMapper::readFromFile<Character>(filesPaths[building]);
            } catch (runtime_error &error) {
                cout << "read file error : " << error.what() << endl;
            }
        };
    };

#endif //GAME_BACKEND_CHARACTER_HPP

}