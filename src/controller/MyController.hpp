//
// Created by alexi on 27/05/2022.
//

#ifndef GAME_BACKEND_MYCONTROLLER_HPP
#define GAME_BACKEND_MYCONTROLLER_HPP

#include "../dto/DTOs.hpp"
#include "../dto/buildings/Building.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"
#include "oatpp/core/data/stream/FileStream.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen
#include "dto/state/GoldState.hpp"

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
public:
    /**
     * Constructor with object mapper.
     * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
     */
    explicit MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper)
    {
        objectMapper->re
    }
public:




    ENDPOINT("GET", "/building/{id}", building,  PATH(Int32 , id)) {
        auto dto = BuildingDto::createShared();
        dto->building = Building_Informations::Building::getBuilding(id);
        std::shared_ptr<OutgoingResponse> response = createDtoResponse(Status::CODE_200, dto);
        MyController::add_response(response);
        return response;
    }

    ADD_CORS(state);
    ENDPOINT("POST", "/game/state", state, REQUEST(std::shared_ptr<IncomingRequest>, request)) {

        oatpp::data::stream::FileOutputStream fileOutputStream("C:\\Users\\alexi\\CLionProjects\\game-backend\\src\\assets\\state\\state.json");
        request->transferBodyToStream(&fileOutputStream); // transfer body chunk by chunk
        auto response = createResponse(Status::CODE_200, "OK");
        MyController::add_response(response);
        return response;
    }

    // TODO Insert Your endpoints here !!!

private:
    static void add_response(std::shared_ptr<OutgoingResponse> &response){
        response->putHeaderIfNotExists("Access-Control-Allow-Methods", "GET, POST, PUT, OPTIONS, DELETE");
        response->putHeaderIfNotExists("Access-Control-Allow-Origin", "*");
        response->putHeaderIfNotExists("Access-Control-Max-Age", "1728000");
    }
};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //GAME_BACKEND_MYCONTROLLER_HPP
