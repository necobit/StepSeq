// 4.23.2 0x7c190750
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_alternate_theme_images_widgets_button_icon_rounded_micro_fill_action[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_FILL_ACTION_ID = 0, Size: 36x36 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_icon_rounded_micro_outline_active[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUNDED_MICRO_OUTLINE_ACTIVE_ID = 1, Size: 36x36 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_action[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_TINY_ROUNDED_ACTION_ID = 2, Size: 110x50 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_TINY_ROUNDED_ACTIVE_ID = 3, Size: 110x50 pixels
extern const unsigned char image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_pressed[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_TINY_ROUNDED_PRESSED_ID = 4, Size: 110x50 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_filler_large[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_FILLER_LARGE_ID = 5, Size: 400x10 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_round_light[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_ROUND_LIGHT_ID = 6, Size: 32x32 pixels
extern const unsigned char image_alternate_theme_images_widgets_slider_horizontal_thick_track_large[]; // BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_SLIDER_HORIZONTAL_THICK_TRACK_LARGE_ID = 7, Size: 400x10 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_alternate_theme_images_widgets_button_icon_rounded_micro_fill_action, 0, 36, 36, 2, 2, 32, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 32, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_icon_rounded_micro_outline_active, 0, 36, 36, 31, 7, 4, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_action, 0, 110, 50, 5, 0, 100, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_active, 0, 110, 50, 5, 0, 100, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_button_regular_height_50_tiny_rounded_pressed, 0, 110, 50, 5, 0, 100, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 50, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_filler_large, 0, 400, 10, 5, 0, 390, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_round_light, 0, 32, 32, 5, 5, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 22, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_alternate_theme_images_widgets_slider_horizontal_thick_track_large, 0, 400, 10, 5, 0, 390, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 10, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
