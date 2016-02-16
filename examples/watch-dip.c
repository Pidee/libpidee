/**
 * Example libpidee app which prints changes to the dip switch
 */

#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#include "../src/libpidee.h"

// See: https://projects.drogon.net/raspberry-pi/wiringpi/functions/#comment-3087
pthread_mutex_t my_interupt_lock;
bool hasChanged = false;
int lastValue = -1;

void my_interupt( pidee_feature feature ) {
    printf( "%s\n", feature.name );
    pthread_mutex_lock(&my_interupt_lock);
    hasChanged = true;
    pthread_mutex_unlock(&my_interupt_lock);
}

uint8_t read_dip_value() {
    int dip_value_1 = pidee_feature_read( &pidee_feature_dip_1 );
    int dip_value_2 = pidee_feature_read( &pidee_feature_dip_2 );
    int dip_value_3 = pidee_feature_read( &pidee_feature_dip_3 );
    int dip_value_4 = pidee_feature_read( &pidee_feature_dip_4 );
    int dip_value_5 = pidee_feature_read( &pidee_feature_dip_5 );
    int dip_value_6 = pidee_feature_read( &pidee_feature_dip_6 );
    int dip_value_7 = pidee_feature_read( &pidee_feature_dip_7 );
    int dip_value_8 = pidee_feature_read( &pidee_feature_dip_8 );

    uint8_t value = 0;
    value = dip_value_1 | 
            (dip_value_2<<1) | 
            (dip_value_3<<2) | 
            (dip_value_4<<3) | 
            (dip_value_5<<4) | 
            (dip_value_6<<5) | 
            (dip_value_7<<6) | 
            (dip_value_8<<7);

    return value;
}

int main() {

    pidee_feature_setup( &pidee_feature_dip_1 );
    pidee_feature_setup( &pidee_feature_dip_2 );
    pidee_feature_setup( &pidee_feature_dip_3 );
    pidee_feature_setup( &pidee_feature_dip_4 );
    pidee_feature_setup( &pidee_feature_dip_5 );
    pidee_feature_setup( &pidee_feature_dip_6 );
    pidee_feature_setup( &pidee_feature_dip_7 );
    pidee_feature_setup( &pidee_feature_dip_8 );

    wiringPiSetupSys(); // Needs to be called after pidee_feature_setup

    pidee_feature_enable_interupt( &pidee_feature_dip_1 );
    pidee_feature_enable_interupt( &pidee_feature_dip_2 );
    pidee_feature_enable_interupt( &pidee_feature_dip_3 );
    pidee_feature_enable_interupt( &pidee_feature_dip_4 );
    pidee_feature_enable_interupt( &pidee_feature_dip_5 );
    pidee_feature_enable_interupt( &pidee_feature_dip_6 );
    pidee_feature_enable_interupt( &pidee_feature_dip_7 );
    pidee_feature_enable_interupt( &pidee_feature_dip_8 );

    pidee_feature_dip_1.interupt_handler = &my_interupt;
    pidee_feature_dip_2.interupt_handler = &my_interupt;
    pidee_feature_dip_3.interupt_handler = &my_interupt;
    pidee_feature_dip_4.interupt_handler = &my_interupt;
    pidee_feature_dip_5.interupt_handler = &my_interupt;
    pidee_feature_dip_6.interupt_handler = &my_interupt;
    pidee_feature_dip_7.interupt_handler = &my_interupt;
    pidee_feature_dip_8.interupt_handler = &my_interupt;

    if ( pthread_mutex_init( &my_interupt_lock, NULL ) != 0 ) {
        printf( "\n mutex init failed\n" );
        return 1;
    }

    for (;;) {
        bool shouldPrint = false;
        pthread_mutex_lock(&my_interupt_lock);
        if ( hasChanged ) {
            shouldPrint = true;
            hasChanged = false;
        }
        pthread_mutex_unlock(&my_interupt_lock);
        if ( shouldPrint ) {
            uint8_t value = read_dip_value();
            if ( value != lastValue ) {
                printf("%d\n", read_dip_value() );
                lastValue = value;
            }
        }
        usleep(100);
    }

    pthread_mutex_destroy(&my_interupt_lock);

    return 0;
}