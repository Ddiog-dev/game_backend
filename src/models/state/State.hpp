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
#include "BuildingState.hpp"

#ifndef GAME_BACKEND_STATE_HPP
#define GAME_BACKEND_STATE_HPP

#include OATPP_CODEGEN_BEGIN(DTO)
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class State : public oatpp::DTO {
    DTO_INIT(State, DTO /* Extends */)

    DTO_FIELD(Object<ManaState>, mana);   // Current manastate
    DTO_FIELD(Object<GoldState>, gold);     // Current goldstate
    DTO_FIELD(Object<BuildingStateRepresentation::BuildingState>, building); // state of all buildings

public:

    static void setState(const std::shared_ptr<oatpp::web::protocol::http::incoming::Request> request) {
        oatpp::data::stream::FileOutputStream fileOutputStream("C:/Users/alexi/CLionProjects/game-backend/src/assets/state/state.json");
        request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
    }

    static oatpp::data::mapping::type::DTOWrapper<State> getState(){
        String wholeText ="";
        /* create json ObjectMapper with default configs */
        ifstream stateFile("C:/Users/alexi/CLionProjects/game-backend/src/assets/state/state.json",ios_base::in);
        if (stateFile.is_open()) {
            char c;
            while (stateFile.get(c)){
               wholeText->push_back(c);
            }
        }
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        try {
            auto cloneOfUser = jsonObjectMapper->readFromString<oatpp::Object<State>>(wholeText);
            return cloneOfUser;
        } catch (oatpp::parser::ParsingError parsingError){
            std::cout << parsingError.getMessage().operator std::string();
            throw parsingError;
        }
    }

private:
};

#endif //GAME_BACKEND_STATE_HPP
