//
// Created by alexi on 27/05/2022.
//

#ifndef GAME_BACKEND_MYAPITESTCLIENT_HPP
#define GAME_BACKEND_MYAPITESTCLIENT_HPP

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin Api Client code generation */
#include OATPP_CODEGEN_BEGIN(ApiClient)

/**
 * Test API client.
 * Use this client to call application APIs.
 */
class MyApiTestClient : public oatpp::web::client::ApiClient {

API_CLIENT_INIT(MyApiTestClient)

    API_CALL("GET", "/", getRoot)

    // TODO - add more client API calls here

};

/* End Api Client code generation */
#include OATPP_CODEGEN_END(ApiClient)


#endif //GAME_BACKEND_MYAPITESTCLIENT_HPP
