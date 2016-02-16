/**
 * Example libpidee app which flashes the pidee LEDS
 */

#include "../src/libpidee.h"

// Sequence position
int frame = 0;

int main() {

    wiringPiSetupSys(); // Needs to be called 

    pidee_feature_setup( &pidee_feature_led_red );
    pidee_feature_setup( &pidee_feature_led_green );
    pidee_feature_setup( &pidee_feature_led_yellow );

    for (;;)
    {
        frame++;
        if ( frame > 3 ) { 
            frame = 0;
        };

        pidee_feature_write( &pidee_feature_led_yellow, frame == 0 ? 1 : 0 );
        pidee_feature_write( &pidee_feature_led_red, frame == 1 ? 1 : 0 );
        pidee_feature_write( &pidee_feature_led_green, frame == 2 ? 1 : 0 );

        delay( 500 );
    }

    return 0;
}