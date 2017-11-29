#include <pebble.h>

//Default settings windows stuff
static Window *s_settingssub_window;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;
static TextLayer *s_settingssub_text;
ActionBarLayer *action_bar;

static void settingssub_window_load(Window *window) {
  
  Layer *window_layer = window_get_root_layer(window);
  window_set_background_color(s_settingssub_window, GColorBlack);
  
  GRect bounds = layer_get_bounds(window_get_root_layer(window));
  
  s_background_layer = bitmap_layer_create(bounds);

// Add to Window
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));
  
  s_settingssub_text = text_layer_create(GRect(-20, 65, 144, 30));
  text_layer_set_text_color(s_settingssub_text, GColorBlack);
  text_layer_set_background_color(s_settingssub_text, GColorClear);
  text_layer_set_text(s_settingssub_text, "Quicklaunch");
  text_layer_set_text_alignment(s_settingssub_text, GTextAlignmentCenter);
  text_layer_set_font(s_settingssub_text, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  // Add to Window
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_settingssub_text));
  
    //Action Bar
  
  // Initialize the action bar:
  action_bar = action_bar_layer_create();
  // Associate the action bar with the window:
  action_bar_layer_add_to_window(action_bar, window);
  // Set the click config provider:
 //action_bar_layer_set_click_config_provider(action_bar,
  //                                           settings_click_config_provider);
}

static void settingssub_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_settingssub_text);
  bitmap_layer_destroy(s_background_layer);
  action_bar_layer_destroy(action_bar);
}