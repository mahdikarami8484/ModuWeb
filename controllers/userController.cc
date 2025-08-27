#include "userController.h"
#include <json/json.h>  // Json::Value
#include "responses/userResponse.hpp"

using namespace drogon;

// Add definition of your processing function here

void UserController::registerUser(const drogon::HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    UserResponse response;
    response.type = UserResponseType::REGISTER;
    response.status = "success";
    response.username = "exampleUser";
    response.age = 25;
    response.data["message"] = "User registered successfully";

    auto resp = drogon::HttpResponse::newHttpJsonResponse(response.toJson()); // این خودش Content-Type: application/json می‌ذاره
    callback(resp);
}
