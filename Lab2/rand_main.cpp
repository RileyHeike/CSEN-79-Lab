// FILE: rand_main.cpp
//
//  COEN 79
//  Riley Heike
//
//   Main file to test functionality of the rand_gen class

#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;
using namespace coen79_lab2;

	//Prints the first ____  instances of a sequence given an object and number of instances
	void printNumbers(rand_gen& rg, int number){

		for(int i = 0; i < number; i++){	
			rg.print_info();
			cout << "Next: " << rg.next() << "\n";
		}
		cout << "\n";
	
	}


	//Tests the rand_gen class and prints the results through printNumbers
	int main(void){
	
		rand_gen rg1(1, 40, 725, 729);
		printNumbers(rg1, 5);

		rg1.set_seed(1);
		printNumbers(rg1, 5);

		rg1.set_seed(15);
		printNumbers(rg1, 5);

		rand_gen rg2(14, 85, 637, 1947);
		printNumbers(rg2, 5);

		rg2.set_seed(14);
		printNumbers(rg2, 5);

		return 0;
	
	}

	




