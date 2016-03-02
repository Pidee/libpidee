/**
 * Example libpidee app which print the dip value
 */

#include "../src/libpidee.h"

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

    int dip_1_value = pidee_feature_read( &pidee_feature_dip_1 );
    int dip_2_value = pidee_feature_read( &pidee_feature_dip_2 );
    int dip_3_value = pidee_feature_read( &pidee_feature_dip_3 );
    int dip_4_value = pidee_feature_read( &pidee_feature_dip_4 );
    int dip_5_value = pidee_feature_read( &pidee_feature_dip_5 );
    int dip_6_value = pidee_feature_read( &pidee_feature_dip_6 );
    int dip_7_value = pidee_feature_read( &pidee_feature_dip_7 );
    int dip_8_value = pidee_feature_read( &pidee_feature_dip_8 );

    printf( "|-----|-------|\n" );
    printf( "| Switch | Value |\n" );
    printf( "|-----|-------|\n" );
    printf( "|  %d  |   %d   | \n", 1, dip_1_value );
    printf( "|  %d  |   %d   | \n", 2, dip_2_value );
    printf( "|  %d  |   %d   | \n", 3, dip_3_value );
    printf( "|  %d  |   %d   | \n", 4, dip_4_value );
    printf( "|  %d  |   %d   | \n", 5, dip_5_value );
    printf( "|  %d  |   %d   | \n", 6, dip_6_value );
    printf( "|  %d  |   %d   | \n", 7, dip_7_value );
    printf( "|  %d  |   %d   | \n", 8, dip_8_value );
    printf( "|-----|-------|\n" );

    return 0;
}
