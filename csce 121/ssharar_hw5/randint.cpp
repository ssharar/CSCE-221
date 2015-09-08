//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 14th, 2014
//hw5pr1.cpp
//randint.cpp

//#include "std_lib_facilities_4.h"
#include "randint.h"
#include <chrono>

using namespace std::chrono;

//linear congruential pseudorandom number generator
int randint()
{
        //use the clock for an initial pseudorandom number
        static long x = time_point_cast<microseconds>(system_clock::now())
				.time_since_epoch().count();
        
		//calculate the next pseudorandom number
		//parameters from glibc(?)
        x = (1103515245 * x + 12345) & 0x7fffffff;    
        
		return x;
}
