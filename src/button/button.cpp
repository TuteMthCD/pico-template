#include "button.h"

Button::Button(uint8_t _pin) {
    pin = _pin;
    gpio_init(pin);
    gpio_pull_up(pin);
}

Button::Button(uint8_t _pin, uint16_t _fastPress): Button(_pin){
    fastPressed = _fastPress;
}

void Button::handle() {
    bool button = !gpio_get(pin);

    if(button) {
        if(!pressed) {
            timeInit = get_absolute_time();
            pressed = true;
            if(p_onFalling != NULL)
                p_onFalling(); // onfalling se puede llegar a ejecuar 2 a 3 veces
        }
    } else {
        if(pressed) {
            timePressed = absolute_time_diff_us(get_absolute_time(), timeInit);
            pressed = false;
            if(p_onRelease != NULL) p_onRelease();
        }
    }
    if(timePressed > 5 && timePressed != 0) {
        if(timePressed <= fastPressed) {
            if(p_onPress != NULL) p_onPress();
        } else if(timePressed > fastPressed) {
            if(p_onLongPress != NULL) {
                p_onLongPress();
            } else if(p_onPress != NULL) p_onPress();
        }
        timePressed = 0;
    }
}

void Button::onFalling(void (*_ptrFnt)()) {
    p_onFalling = _ptrFnt;
}

void Button::onPress(void (*_ptrFnt)()) {
    p_onPress = _ptrFnt;
}

void Button::onRelease(void (*_ptrFnt)()) {
    p_onRelease = _ptrFnt;
}

void Button::onLongPress(void (*_ptrFnt)()) {
    p_onLongPress = _ptrFnt;
}

absolute_time_t Button::getTimePressed() {
    return timePressed;
}
