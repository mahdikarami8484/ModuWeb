#include "userController.h"
#include <json/json.h>  // Json::Value

using namespace drogon;

// Add definition of your processing function here

void UserController::createUser(const drogon::HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value json;
    json["message"] = "Hello World!";
    json["success"] = true;
    json["count"] = 123;

    auto resp = drogon::HttpResponse::newHttpJsonResponse(json); // این خودش Content-Type: application/json می‌ذاره
    callback(resp);
}
