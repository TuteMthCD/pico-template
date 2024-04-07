#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdlib.h>

#define TIMER_FASTPRESED_DEFAULT 300

class Button {
    public:
    Button(uint8_t);
    Button(uint8_t, uint16_t);
    void handle(void);
    void onFalling(void (*ptrFnt)());
    void onPress(void (*ptrFnt)());
    void onRelease(void (*ptrFnt)());
    void onLongPress(void (*ptrFnt)());
    absolute_time_t getTimePressed(void);


    private:
    absolute_time_t timePressed = 0;
    absolute_time_t timeInit = 0;
    bool pressed = false;

    uint16_t fastPressed = TIMER_FASTPRESED_DEFAULT;

    uint8_t pin;

    void (*p_onFalling)();
    void (*p_onPress)();
    void (*p_onRelease)();
    void (*p_onLongPress)();
};
