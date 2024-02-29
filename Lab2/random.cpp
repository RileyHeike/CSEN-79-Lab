// FILE: random.cpp
//
//  COEN 79
//  Riley Heike
//
//   (function definitions for random.h class member functions)
//   This class is part of the namespace coen79_lab2

#include <iostream>
#include <cassert>
#include "random.h"

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2 {


	//constructor for rand_gen class object
	rand_gen::rand_gen(int inSeed, int inMultiplier, int inIncrement, int inModulus){
	
		this->seed = inSeed;
		this->multiplier = inMultiplier;
		this->increment = inIncrement;
		this->modulus = inModulus;

	}

	//set seed method
	void rand_gen::set_seed(int new_seed){
	
		seed = new_seed;
	
	}	

	//next method to move seed to next number in sequence using provided formula
	int rand_gen::next(){
	
		seed = (multiplier * seed + increment) % modulus;
		return seed;
	
	}

	//print info line by line through private member variables
	void rand_gen::print_info(){
	
		cout << "Seed: " << seed << "\n";
		cout << "Multiplier: " << multiplier << "\n";
		cout << "Increment: " << increment << "\n";
		cout << "Modulus: " << modulus << "\n";
	}


}
