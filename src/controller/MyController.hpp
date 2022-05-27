//
// Created by alexi on 27/05/2022.
//

#ifndef GAME_BACKEND_MYCONTROLLER_HPP
#define GAME_BACKEND_MYCONTROLLER_HPP

#include "../dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
public:
    /**
     * Constructor with object mapper.
     * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
     */
    MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : oatpp::web::server::api::ApiController(objectMapper)
    {}
public:

    ENDPOINT("GET", "/hello", root) {
        auto dto = MessageDto::createShared();
        dto->statusCode = 200;
        dto->message = "Hello World!";
        return createDtoResponse(Status::CODE_200, dto);
    }

    ENDPOINT("GET", "/failure", arg) {
        auto dto = MessageDto::createShared();
        dto->statusCode = 500;
        dto->message = "server internal error";
        return createDtoResponse(Status::CODE_500, dto);
    }


    // TODO Insert Your endpoints here !!!

};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen

#endif //GAME_BACKEND_MYCONTROLLER_HPP
