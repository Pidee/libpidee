/**
 * Example libpidee app which prints changes to the button
 */

#include <unistd.h>
#include "../src/pidee.h"

void my_interupt( pidee_feature feature ) {
	int value = pidee_feature_read( &pidee_feature_button );
	printf("%s\n", value ? "button pressed" : "button released" );
}

int main() {

	wiringPiSetupSys(); // Needs to be called 

	pidee_feature_setup( &pidee_feature_button );
	pidee_feature_enable_interupt( &pidee_feature_button );

	pidee_feature_button.interupt_handler = &my_interupt;

	for (;;) {
        sleep(1000);
    }

 	return 0;
}