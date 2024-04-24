// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_SettingsScreen_screen_init(void)
{
    ui_SettingsScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SettingsScreen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_flex_flow(ui_SettingsScreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SettingsScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(ui_SettingsScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SettingsScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SettingsScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SettingsScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_SettingsScreen, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_SettingsScreen, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ConfigurationPanel = lv_obj_create(ui_SettingsScreen);
    lv_obj_set_width(ui_ConfigurationPanel, 760);
    lv_obj_set_height(ui_ConfigurationPanel, 440);
    lv_obj_set_x(ui_ConfigurationPanel, -132);
    lv_obj_set_y(ui_ConfigurationPanel, -21);
    lv_obj_set_align(ui_ConfigurationPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ConfigurationPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ConfigurationPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ConfigurationPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ConfigurationPanel, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ConfigurationPanel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ConfigurationPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ConfigurationPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ConfigurationPanel, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ConfigurationPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsHeader = lv_obj_create(ui_ConfigurationPanel);
    lv_obj_remove_style_all(ui_SettingsHeader);
    lv_obj_set_height(ui_SettingsHeader, 50);
    lv_obj_set_width(ui_SettingsHeader, lv_pct(100));
    lv_obj_set_align(ui_SettingsHeader, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SettingsHeader, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SettingsHeader, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SettingsHeader, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SettingsHeaderBackButton = lv_btn_create(ui_SettingsHeader);
    lv_obj_set_width(ui_SettingsHeaderBackButton, 50);
    lv_obj_set_height(ui_SettingsHeaderBackButton, 50);
    lv_obj_set_x(ui_SettingsHeaderBackButton, -336);
    lv_obj_set_y(ui_SettingsHeaderBackButton, 0);
    lv_obj_set_align(ui_SettingsHeaderBackButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingsHeaderBackButton, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SettingsHeaderBackButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SettingsHeaderBackButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SettingsHeaderBackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SettingsHeaderBackButton, lv_color_hex(0xD9D9D9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SettingsHeaderBackButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SettingsHeaderBackButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SettingsHeaderBackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SettingsHeaderBackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingHeaderBackButtonIcon = lv_img_create(ui_SettingsHeaderBackButton);
    lv_img_set_src(ui_SettingHeaderBackButtonIcon, &ui_img_904781469);
    lv_obj_set_width(ui_SettingHeaderBackButtonIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SettingHeaderBackButtonIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SettingHeaderBackButtonIcon, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_SettingHeaderBackButtonIcon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SettingHeaderBackButtonIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_SettingHeaderBackButtonIcon, 150);

    ui_SettingsHeaderTitle = lv_label_create(ui_SettingsHeader);
    lv_obj_set_width(ui_SettingsHeaderTitle, lv_pct(100));
    lv_obj_set_height(ui_SettingsHeaderTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SettingsHeaderTitle, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SettingsHeaderTitle, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SettingsHeaderTitle, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsHeaderTitle, "Settings");
    lv_obj_set_style_text_align(ui_SettingsHeaderTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingsHeaderTitle, &ui_font_SpaceGroteskBold30, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsOptionsContainer = lv_obj_create(ui_ConfigurationPanel);
    lv_obj_remove_style_all(ui_SettingsOptionsContainer);
    lv_obj_set_height(ui_SettingsOptionsContainer, 339);
    lv_obj_set_width(ui_SettingsOptionsContainer, lv_pct(100));
    lv_obj_set_align(ui_SettingsOptionsContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SettingsOptionsContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SettingsOptionsContainer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SettingsOptionsContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_WifiConfigurationButton = lv_btn_create(ui_SettingsOptionsContainer);
    lv_obj_set_height(ui_WifiConfigurationButton, 43);
    lv_obj_set_width(ui_WifiConfigurationButton, lv_pct(100));
    lv_obj_set_align(ui_WifiConfigurationButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_WifiConfigurationButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_WifiConfigurationButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_WifiConfigurationButton, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_WifiConfigurationButton, lv_color_hex(0x29995A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WifiConfigurationButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_WifiConfigurationButton, lv_color_hex(0xD9D9D9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_WifiConfigurationButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_WifiConfigurationButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_WifiConfigurationButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_WifiConfigurationButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WifiConfigurationButtonLabel = lv_label_create(ui_WifiConfigurationButton);
    lv_obj_set_width(ui_WifiConfigurationButtonLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WifiConfigurationButtonLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WifiConfigurationButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WifiConfigurationButtonLabel, "Setup Wi-Fi");
    lv_obj_set_style_text_color(ui_WifiConfigurationButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_WifiConfigurationButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_WifiConfigurationButtonLabel, &ui_font_SpaceGroteskMedium20,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SettingsHeaderBackButton, ui_event_SettingsHeaderBackButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_WifiConfigurationButton, ui_event_WifiConfigurationButton, LV_EVENT_ALL, NULL);

}
