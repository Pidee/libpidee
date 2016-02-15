# libpidee

A basic c library for using Pidee inconjuction with [WiringPi](http://wiringpi.com):

* A global `pidee_feature` struct initialised for each feature (`pidee_feature_dip_1`, `pidee_feature_button`, `pidee_feature_led_red`, etc). These structs contains the name of the feature, the BCM pin number and feature type.
* A `pidee_feature_setup` function for initialising each features without sudo. `wiringPiSetupSys` still needs to be called in your code.
* A `pidee_feature_read` and `pidee_feature_write` functions.
* A `pidee_feature_enable_interupt` function for use with each `pidee_feature`'s `interupt_handler`. The interupt handler will be passed the relevant `pidee_feature` as an argument. This is the purpose of the library. WiringPi interupt functions are not passed any context.


