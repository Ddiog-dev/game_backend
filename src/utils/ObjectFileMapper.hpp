//
// Created by alexi on 30/09/2022.
//

#ifndef GAME_BACKEND_OBJECTFILEMAPPER_HPP
#define GAME_BACKEND_OBJECTFILEMAPPER_HPP
#include <string>
#include <iostream>
#include <fstream>
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

using namespace std;

namespace ObjectFileMapper {

    template <typename T>

    oatpp::data::mapping::type::DTOWrapper<T> readFromFile(const string &path){

        /* create json ObjectMapper with default configs */
        auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
        ifstream stateFile(path);

        /* read file */
        string wholeText;
        if (stateFile.is_open()) {
            char c;
            while (stateFile.get(c)){
                wholeText.push_back(c);
            }
        }
        /* Map to type T*/
        try {
            auto cloneOfUser = jsonObjectMapper->readFromString<oatpp::Object<T>>(wholeText);
            return cloneOfUser;
        } catch (oatpp::parser::ParsingError &parsingError){
            std::cout << parsingError.getMessage().operator std::string();
            throw oatpp::parser::ParsingError(parsingError);
        }
    }
}

#endif //GAME_BACKEND_OBJECTFILEMAPPER_HPP
