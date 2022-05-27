//
// Created by alexi on 27/05/2022.
//

#ifndef GAME_BACKEND_MYCONTROLLERTEST_HPP
#define GAME_BACKEND_MYCONTROLLERTEST_HPP


#include "../oatpp/src/oatpp-test/UnitTest.hpp"

class MyControllerTest : public oatpp::test::UnitTest {
public:

    MyControllerTest() : UnitTest("TEST[MyControllerTest]" /* Test TAG for logs */){}
    void onRun() override;

};

#endif //GAME_BACKEND_MYCONTROLLERTEST_HPP
