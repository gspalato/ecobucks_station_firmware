#include <ArduinoJson.h>
#include <HTTPClient.h>

#include <e_utils.hpp>

#define E_API_BASE_URL "https://foundation.unreal.sh/"
#define E_API_AUTH_URL E_API_BASE_URL "identity/auth"
#define E_API_ECOBUCKS_DISPOSALS_URL E_API_BASE_URL "upx/ecobucks/me/disposals"

extern char *e_api_token;

typedef enum
{
    RECYCLABLE = 0,
    BATTERY = 1,
    SPONGE = 2,
    ELECTRONIC = 3
} e_api_disposal_type_t;

typedef struct
{
    bool success;
    char *error;
    float credits;
    char *disposal_token;
} e_api_disposal_response_t;