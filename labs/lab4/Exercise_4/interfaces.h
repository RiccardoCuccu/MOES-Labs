#ifndef INTERFACE_H
#define INTERFACE_H

enum color{RED, YELLOW, GREEN};

struct car_if: virtual public sc_interface {
	virtual void wait_for_car()=0;
};

struct light_if: virtual public sc_interface {
	virtual void set_main(color)=0;
	virtual void set_sec(color)=0;
};

struct timer_if: virtual public sc_interface {
	virtual void wait_for_sec(unsigned int)=0;
};

#endif
