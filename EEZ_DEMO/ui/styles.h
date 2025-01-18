#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: pageTitle
lv_style_t *get_style_page_title_MAIN_DEFAULT();
void add_style_page_title(lv_obj_t *obj);
void remove_style_page_title(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/