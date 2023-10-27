#pragma once

#define LGFX_USE_V1
#include <LovyanGFX.hpp>

#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include <driver/i2c.h>

#ifdef __cplusplus
extern "C"
{
#endif

    class LGFX : public lgfx::LGFX_Device
    {
    public:
        lgfx::Bus_RGB _bus_instance;
        lgfx::Panel_RGB _panel_instance;
        lgfx::Light_PWM _light_instance;
        lgfx::Touch_GT911 _touch_instance;

        LGFX();
    };

    static LGFX gfx;

#ifdef __cplusplus
}
#endif