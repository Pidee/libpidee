/**
 * Example libpidee app which print the dip value
 */
 
#include "../src/pidee.h"

int main() {

    wiringPiSetupSys(); // Needs to be called 

    pidee_feature_setup( &pidee_feature_dip_1 );
    pidee_feature_setup( &pidee_feature_dip_2 );
    pidee_feature_setup( &pidee_feature_dip_3 );
    pidee_feature_setup( &pidee_feature_dip_4 );
    pidee_feature_setup( &pidee_feature_dip_5 );
    pidee_feature_setup( &pidee_feature_dip_6 );
    pidee_feature_setup( &pidee_feature_dip_7 );
    pidee_feature_setup( &pidee_feature_dip_8 );

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

    printf("%d\n", value);

    return 0;
}