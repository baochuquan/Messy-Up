
#ifndef CLASS_H_
#define CLASS_H_
#include <iostream>
#include <cstring>

class Remote;

class Tv
{
public:
	friend class Remote;
	enum {Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, VCR};

	Tv(int s = Off, int mc = 100) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV){}
	void onoff(){state = (state == On) ? Off : On;}
	bool ison()const {return state == On;}
	//undefine
	bool volup();//
	bool voldown();//
	void chanup();//
	void chandown();//
	void set_mode(){mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input(){input = (input == TV) ? VCR : TV;}
	void settings()const;//
	void set_state(Remote & r);
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
 };

class Remote
{
public:
	friend class Tv;
private:
	int mode;
	int state;
public:
	enum {Normal, Interact};

	Remote(int m = Tv::TV) : mode(m), state(Normal){}
	bool volup(Tv & t) {return t.volup();}
	bool voldown(Tv & t) {return t.voldown();}
	void onoff(Tv & t) {return t.onoff();}
	void chanup(Tv & t) {return t.chanup();}
	void chandown(Tv & t) {return t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}//**
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
	void set_state() { state = (state == Normal ? Interact : Normal);}
	void show()const;//
};
#endif
