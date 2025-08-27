#include <string>
#include <chrono>
#include <json/json.h>
#include <unordered_map>
#include <ctime>
#include <drogon/drogon.h>

enum ResponseType : int {
    USER = 0,
};

class BaseResponse {
    public:
    ResponseType type;
    std::string timestamp;
    std::string status;
    std::string id;

    public:
    BaseResponse() {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        timestamp = std::ctime(&now_c);
        id = drogon::utils::getUuid();
    }
    virtual ~BaseResponse() = default;

    virtual Json::Value toJson() const {
        Json::Value json;
        json["type"] = typeToString[type];
        json["timestamp"] = timestamp;
        json["status"] = status;
        json["id"] = id;
        return json;
    }

    private:
    inline static std::unordered_map <ResponseType, std::string> typeToString = {
        {ResponseType::USER, "user"},
    }; 
};