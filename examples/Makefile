.PHONY: all
all: bin/watch-dip bin/watch-button bin/flash-leds bin/print-dip bin/print-dip-table

bin/watch-dip: watch-dip.c
	gcc -Wall -o bin/watch-dip watch-dip.c -lwiringPi

bin/watch-button: watch-button.c
	gcc -Wall -o bin/watch-button watch-button.c -lwiringPi

bin/flash-leds: flash-leds.c
	gcc -Wall -o bin/flash-leds flash-leds.c -lwiringPi

bin/print-dip: print-dip.c
	gcc -Wall -o bin/print-dip print-dip.c -lwiringPi

bin/print-dip-table: print-dip-table.c
	gcc -Wall -o bin/print-dip-table print-dip-table.c -lwiringPi

.PHONY: clean
clean:
	rm bin/*
