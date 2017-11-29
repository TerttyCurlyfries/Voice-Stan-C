#include <pebble.h>

//Speech global? Idk
static DictationSession *voice;
static char s_last_text[512];

//Voice window vars
static Window *s_voice_window;
static BitmapLayer *s_background_layer;
static GBitmap *s_background_bitmap;

//D-bug voice stuff
static void dictation_session_callback(DictationSession *session, DictationSessionStatus status,
                                       char *transcription, void *context) {
  // Print the results of a transcription attempt
  APP_LOG(APP_LOG_LEVEL_INFO, "Dictation status: %d", (int)status);
}

static void voice_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  window_set_background_color(s_voice_window, GColorFromRGB(96,223,229));
  
  s_background_layer = bitmap_layer_create(bounds);
  
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));
  
  voice = dictation_session_create(sizeof(s_last_text), dictation_session_callback, NULL);
  
  dictation_session_start(voice);
  
}

static void voice_window_unload(Window *window) {
}