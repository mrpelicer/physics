#!bin/bash	

.PHONY:	euler	rk2	rk4 boost

all: euler rk2 rk4 boost

euler: 
	g++ ho_euler.cpp -o euler
	./euler

rk2: 
	g++ ho_rk2.cpp -o rk2
	./rk2	
	
rk4: 
	g++ ho_rk4.cpp -o rk4
	./rk4	

boost: 
	g++ ho_boost.cpp -I/usr/include/python3.6m/ -lpython3.6m  -o boost 
	./boost	

