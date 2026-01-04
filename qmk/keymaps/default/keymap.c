#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
       KC_1, KC_2, KC_3, KC_4
    )
};


#define RGB1_R_PIN GP8
#define RGB1_B_PIN GP9
#define RGB1_G_PIN GP10

#define RGB2_R_PIN GP18
#define RGB2_B_PIN GP19
#define RGB2_G_PIN GP20

#define LED1_RED    1
#define LED1_GREEN  0
#define LED1_BLUE   0

#define LED2_RED    0
#define LED2_GREEN  1
#define LED2_BLUE   0

void keyboard_post_init_user(void) {
    gpio_set_pin_output(RGB1_R_PIN);
    gpio_set_pin_output(RGB1_G_PIN);
    gpio_set_pin_output(RGB1_B_PIN);

    gpio_set_pin_output(RGB2_R_PIN);
    gpio_set_pin_output(RGB2_G_PIN);
    gpio_set_pin_output(RGB2_B_PIN);

    gpio_write_pin(RGB1_R_PIN, !LED1_RED);
    gpio_write_pin(RGB1_G_PIN, !LED1_GREEN);
    gpio_write_pin(RGB1_B_PIN, !LED1_BLUE);

    gpio_write_pin(RGB2_R_PIN, !LED2_RED);
    gpio_write_pin(RGB2_G_PIN, !LED2_GREEN);
    gpio_write_pin(RGB2_B_PIN, !LED2_BLUE);
}

bool led_update_kb(led_t led_state) {
    led_update_user(led_state);
    return true;
}
