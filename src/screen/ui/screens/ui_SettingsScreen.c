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

    ui_ConfigurationOverlayPanel = lv_obj_create(ui_SettingsScreen);
    lv_obj_set_width(ui_ConfigurationOverlayPanel, 760);
    lv_obj_set_height(ui_ConfigurationOverlayPanel, 411);
    lv_obj_set_x(ui_ConfigurationOverlayPanel, -132);
    lv_obj_set_y(ui_ConfigurationOverlayPanel, -21);
    lv_obj_set_align(ui_ConfigurationOverlayPanel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ConfigurationOverlayPanel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ConfigurationOverlayPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ConfigurationOverlayPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ConfigurationOverlayPanel, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ConfigurationOverlayPanel, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ConfigurationOverlayPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsTitleLabel = lv_label_create(ui_ConfigurationOverlayPanel);
    lv_obj_set_width(ui_SettingsTitleLabel, lv_pct(100));
    lv_obj_set_height(ui_SettingsTitleLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SettingsTitleLabel, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SettingsTitleLabel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SettingsTitleLabel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_label_set_text(ui_SettingsTitleLabel, "Settings");
    lv_obj_set_style_text_align(ui_SettingsTitleLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SettingsTitleLabel, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SettingsOptionsContainer = lv_obj_create(ui_ConfigurationOverlayPanel);
    lv_obj_remove_style_all(ui_SettingsOptionsContainer);
    lv_obj_set_height(ui_SettingsOptionsContainer, 339);
    lv_obj_set_width(ui_SettingsOptionsContainer, lv_pct(95));
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
    lv_obj_set_style_text_font(ui_WifiConfigurationButtonLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExitToMainScreenSymbol = lv_btn_create(ui_SettingsScreen);
    lv_obj_set_width(ui_ExitToMainScreenSymbol, 210);
    lv_obj_set_height(ui_ExitToMainScreenSymbol, 10);
    lv_obj_set_align(ui_ExitToMainScreenSymbol, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ExitToMainScreenSymbol, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ExitToMainScreenSymbol, LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExitToMainScreenSymbol, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExitToMainScreenSymbol, lv_color_hex(0xD9D9D9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExitToMainScreenSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExitToMainScreenSymbol, lv_color_hex(0xD9D9D9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExitToMainScreenSymbol, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExitToMainScreenSymbol, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ExitToMainScreenSymbol, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ExitToMainScreenSymbol, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_WifiConfigurationButton, ui_event_WifiConfigurationButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ExitToMainScreenSymbol, ui_event_ExitToMainScreenSymbol, LV_EVENT_ALL, NULL);

}
