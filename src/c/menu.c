#include <pebble.h>

#define NUM_MENU_SECTIONS 2
#define NUM_FIRST_MENU_ITEMS 4

//Menu Vars
static Window *s_menu_window;
MenuLayer *menu_layer;
static SimpleMenuLayer *s_simple_menu_layer;
static SimpleMenuSection s_menu_sections[NUM_MENU_SECTIONS];
static SimpleMenuItem s_first_menu_items[NUM_FIRST_MENU_ITEMS];
static GBitmap *s_menu_icon_image;

static bool s_special_flag = false;
static int s_hit_count = 0;

static void menu_select_callback(int index, void *ctx) {
  s_first_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(s_simple_menu_layer));
}

static void menu_window_load(Window *window) {
  
  // Although we already defined NUM_FIRST_MENU_ITEMS, you can define
  // an int as such to easily change the order of menu items later
  int num_a_items = 0;

  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Hello",
    .subtitle = "Say hello!",
    .callback = menu_select_callback,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "What time is it?",
    .subtitle = "What time IS it??",
    .callback = menu_select_callback,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "Weather",
    .subtitle = "Is it hot in here?",
    .callback = menu_select_callback,
    .icon = s_menu_icon_image,
  };
  s_first_menu_items[num_a_items++] = (SimpleMenuItem) {
    .title = "IFTTT",
    .subtitle = "Fire and IFTTT recipe",
    .callback = menu_select_callback,
    .icon = s_menu_icon_image,
  };

  s_menu_sections[0] = (SimpleMenuSection) {
    .title = "Commands",
    .num_items = NUM_FIRST_MENU_ITEMS,
    .items = s_first_menu_items,
  };

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  s_simple_menu_layer = simple_menu_layer_create(bounds, window, s_menu_sections, NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(s_simple_menu_layer));
  
}

static void menu_window_unload(Window *window) {
  simple_menu_layer_destroy(s_simple_menu_layer);
  }

