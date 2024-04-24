// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_MainScreen_screen_init(void)
{
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_MainScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_MainScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_FlexContainer = lv_obj_create(ui_MainScreen);
    lv_obj_remove_style_all(ui_FlexContainer);
    lv_obj_set_width(ui_FlexContainer, lv_pct(100));
    lv_obj_set_height(ui_FlexContainer, lv_pct(100));
    lv_obj_set_align(ui_FlexContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_FlexContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_FlexContainer, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_FlexContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_row(ui_FlexContainer, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_FlexContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_MainScreenLogo = lv_img_create(ui_FlexContainer);
    lv_img_set_src(ui_MainScreenLogo, &ui_img_ecobuckstextgradient_png);
    lv_obj_set_width(ui_MainScreenLogo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_MainScreenLogo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_MainScreenLogo, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_MainScreenLogo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_MainScreenLogo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_MainScreenLogo, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_MainScreenLogo, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GoToDisposalRegisterScreenButton = lv_btn_create(ui_FlexContainer);
    lv_obj_set_width(ui_GoToDisposalRegisterScreenButton, 150);
    lv_obj_set_height(ui_GoToDisposalRegisterScreenButton, 50);
    lv_obj_set_align(ui_GoToDisposalRegisterScreenButton, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_GoToDisposalRegisterScreenButton, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_GoToDisposalRegisterScreenButton, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_GoToDisposalRegisterScreenButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_GoToDisposalRegisterScreenButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_GoToDisposalRegisterScreenButton, lv_color_hex(0x2A995B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GoToDisposalRegisterScreenButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_GoToDisposalRegisterScreenButton, lv_color_hex(0xD9D9D9),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_GoToDisposalRegisterScreenButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_GoToDisposalRegisterScreenButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_GoToDisposalRegisterScreenButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_GoToDisposalRegisterScreenButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_GoToDisposalRegisterScreenButton, lv_color_hex(0x808080),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_GoToDisposalRegisterScreenButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_GoToDisposalRegisterScreenButtonLabel = lv_label_create(ui_GoToDisposalRegisterScreenButton);
    lv_obj_set_width(ui_GoToDisposalRegisterScreenButtonLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_GoToDisposalRegisterScreenButtonLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_GoToDisposalRegisterScreenButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_GoToDisposalRegisterScreenButtonLabel, "Start!");
    lv_obj_set_style_text_color(ui_GoToDisposalRegisterScreenButtonLabel, lv_color_hex(0x000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_GoToDisposalRegisterScreenButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_GoToDisposalRegisterScreenButtonLabel, &lv_font_montserrat_24,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwipeUpSettings = lv_btn_create(ui_MainScreen);
    lv_obj_set_height(ui_SwipeUpSettings, 60);
    lv_obj_set_width(ui_SwipeUpSettings, lv_pct(100));
    lv_obj_set_x(ui_SwipeUpSettings, 0);
    lv_obj_set_y(ui_SwipeUpSettings, 210);
    lv_obj_set_align(ui_SwipeUpSettings, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SwipeUpSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SwipeUpSettings, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwipeUpSettings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SwipeUpSettings, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_GoToDisposalRegisterScreenButton, ui_event_GoToDisposalRegisterScreenButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwipeUpSettings, ui_event_SwipeUpSettings, LV_EVENT_ALL, NULL);

}
