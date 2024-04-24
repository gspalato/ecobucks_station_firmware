// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"


// COMPONENT BackIcon1

lv_obj_t * ui_BackIcon1_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_BackIcon1;
    cui_BackIcon1 = lv_img_create(comp_parent);
    lv_obj_set_width(cui_BackIcon1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_BackIcon1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_BackIcon1, 0);
    lv_obj_set_y(cui_BackIcon1, 2);
    lv_obj_set_align(cui_BackIcon1, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_BackIcon1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_BackIcon1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_BACKICON1_NUM);
    children[UI_COMP_BACKICON1_BACKICON1] = cui_BackIcon1;
    lv_obj_add_event_cb(cui_BackIcon1, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_BackIcon1, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_BackIcon1_create_hook(cui_BackIcon1);
    return cui_BackIcon1;
}

