#ifndef GAME_BACKEND_DTOS_HPP
#define GAME_BACKEND_DTOS_HPP

#include <oatpp/core/Types.hpp>
#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class MessageDto : public oatpp::DTO {

    DTO_INIT(MessageDto, DTO /* Extends */)

    DTO_FIELD(Int32, statusCode);   // Status code field
    DTO_FIELD(String, message);     // Message field

};

/* TODO - Add more DTOs here */

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)

#endif //GAME_BACKEND_DTOS_HPP
