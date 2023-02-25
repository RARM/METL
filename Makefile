# Temporary Makefile for development.
CXX			= g++
ARFLAGS		= r
SRC			= src/metl.cpp

defautl_target: all

all: bin/libmetl.a bin/libmetl.so

bin/libmetl.a: build/metl.o
	ar $(ARFLAGS) $@ $^

bin/libmetl.so: build/metl.o
	$(CXX) -shared -o $@ $^

build/metl.o:
	$(CXX) -c -o $@ $(SRC)