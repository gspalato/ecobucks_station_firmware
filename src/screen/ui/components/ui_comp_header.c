// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT Header

lv_obj_t * ui_Header_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Header;
    cui_Header = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_Header);
    lv_obj_set_height(cui_Header, 50);
    lv_obj_set_width(cui_Header, lv_pct(100));
    lv_obj_set_align(cui_Header, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Header, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Header, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Header, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_BackButton;
    cui_BackButton = lv_btn_create(cui_Header);
    lv_obj_set_width(cui_BackButton, 50);
    lv_obj_set_height(cui_BackButton, 50);
    lv_obj_set_x(cui_BackButton, -336);
    lv_obj_set_y(cui_BackButton, 0);
    lv_obj_set_align(cui_BackButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_BackButton, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(cui_BackButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cui_BackButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(cui_BackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cui_BackButton, lv_color_hex(0xD9D9D9), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(cui_BackButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(cui_BackButton, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(cui_BackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(cui_BackButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_BackIcon;
    cui_BackIcon = lv_img_create(cui_BackButton);
    lv_img_set_src(cui_BackIcon, &ui_img_904781469);
    lv_obj_set_width(cui_BackIcon, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_BackIcon, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_BackIcon, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_BackIcon, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_BackIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(cui_BackIcon, 150);

    lv_obj_t * cui_Title;
    cui_Title = lv_label_create(cui_Header);
    lv_obj_set_width(cui_Title, lv_pct(100));
    lv_obj_set_height(cui_Title, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(cui_Title, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_Title, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_Title, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_label_set_text(cui_Title, "Setup Wi-Fi");
    lv_obj_set_style_text_align(cui_Title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(cui_Title, &ui_font_SpaceGroteskBold30, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_HEADER_NUM);
    children[UI_COMP_HEADER_HEADER] = cui_Header;
    children[UI_COMP_HEADER_BACKBUTTON] = cui_BackButton;
    children[UI_COMP_HEADER_BACKBUTTON_BACKICON] = cui_BackIcon;
    children[UI_COMP_HEADER_TITLE] = cui_Title;
    lv_obj_add_event_cb(cui_Header, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Header, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Header_create_hook(cui_Header);
    return cui_Header;
}
