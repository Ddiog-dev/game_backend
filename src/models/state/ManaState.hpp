//
// Created by alexi on 04/07/2022.
//
#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/server/api/ApiController.hpp"

#ifndef GAME_BACKEND_MANASTATE_HPP
#define GAME_BACKEND_MANASTATE_HPP

#include OATPP_CODEGEN_BEGIN(DTO)

class ManaState : public oatpp::DTO {
    DTO_INIT(ManaState, DTO /* Extends */)

    DTO_FIELD(Int32, amount);   // Status code field
    DTO_FIELD(Int32 , income);     // Message field
public:

private:
};

#endif //GAME_BACKEND_MANASTATE_HPP
