# libpidee

A basic c library for using Pidee in conjuction with [WiringPi](http://wiringpi.com):

* A global `pidee_feature` struct initialised for each feature (`pidee_feature_dip_1`, `pidee_feature_button`, `pidee_feature_led_red`, etc). These structs contains the name of the feature, the BCM pin number and feature type.
* A `pidee_feature_setup` function for initialising each feature without sudo. `wiringPiSetupSys` needs to be called in your code __after__ all `pidee_feature_setup` functions have been called.
* A `pidee_feature_read` and `pidee_feature_write` function.
* A `pidee_feature_enable_interupt` function for use with each `pidee_feature`'s `interupt_handler`. The interupt handler will be passed the relevant `pidee_feature` as an argument. This is the purpose of the library. WiringPi interupt functions are not passed any context.

## Examples

* __flash-leds__
* __print-dip__
* __print-dip-table__
* __watch-button__
* __watch-dip__

## Getting Started

Clone the repo:

    git clone https://github.com/Pidee/libpidee.git


Building test applications
    
    cd libpidee
    cd examples/
    make

Running a test application

    cd examples/bin/
    ./flash-leds
    

