//
// Created by alexi on 21/09/2022.
//

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/data/stream/FileStream.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "ManaState.hpp"
#include "GoldState.hpp"

#ifndef GAME_BACKEND_STATE_HPP
#define GAME_BACKEND_STATE_HPP

#include OATPP_CODEGEN_BEGIN(DTO)

class State : public oatpp::DTO {
    DTO_INIT(State, DTO /* Extends */)

    DTO_FIELD(Object<ManaState>, mana);   // Status code field
    DTO_FIELD(Object<GoldState>, gold);     // Message field
    DTO_FIELD(String, description);     // Message field

public:

    static void setState(const std::shared_ptr<oatpp::web::protocol::http::incoming::Request> request) {
        oatpp::data::stream::FileOutputStream fileOutputStream("C:/Users/alexi/CLionProjects/game-backend/src/assets/state/state.json");
        request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
    }

private:
};

#endif //GAME_BACKEND_STATE_HPP
