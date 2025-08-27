#include "baseResponse.hpp"

enum UserResponseType : int {
    LOGIN = 0,
    REGISTER = 1
};

struct UserResponse : public BaseResponse {
    
    UserResponseType type;
    std::string username;
    int age;
    Json::Value data;

    UserResponse(const std::string& username, int age) : username(username), age(age) {
        BaseResponse::type = ResponseType::USER;
    }

    UserResponse() {
        BaseResponse::type = ResponseType::USER;
    }

    Json::Value toJson() const override {
        Json::Value jsonData;
        jsonData["username"] = username;
        jsonData["age"] = age;
        jsonData["data"] = data;

        Json::Value json = BaseResponse::toJson();
        json["data"] = jsonData;
        return json;
    }

    std::unordered_map<UserResponseType, std::string> userTypeToString = {
        {UserResponseType::LOGIN, "login"},
        {UserResponseType::REGISTER, "register"}
    };
};