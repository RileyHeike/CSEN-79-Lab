/*
 * Author: Riley Heike
 * 
 * File: main.cpp
 *
 * COEN 79 Lab 3
 *
 * January 28th, 2024
 *
 */

#include <iostream>
#include <cassert>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

	//Print the elements of the sequence passed into the function
	void printSequence(sequence &seq){
	
		//Start at index 0 and iterate through sequence, printing each element
		seq.start();
		for(sequence::size_type i = 0; i < seq.size(); i++){
		
			cout << seq.current() << " ";
			seq.advance();
		
		}
		cout << "\n";
	
	}

	//Print the mean, standard deviation, and sum of the sequence
	void printStats(sequence &seq){
	
		cout << "Mean: " << seq.mean() << "\n";
		cout << "Standard Deviation: " << seq.standardDeviation() << "\n";
		cout << "Sum: " << (seq.mean() * seq.size()) << "\n";
		printSequence(seq);

	
	}

	//Perform test operations with 3 sequence objects
	int main(){
		
		sequence tester1;
		tester1.insert(1);
		tester1.insert(2);
		tester1.insert(3);
		
		cout << "-------------------------\n";
		printStats(tester1);
		cout << "-------------------------\n";

		sequence tester2;
		tester2.insert(2);
		tester2.insert(3);
		tester2.insert(4);
		
		cout << "-------------------------\n";
		printStats(tester2);
		cout << "-------------------------\n";
		
		sequence tester3 = tester1 + tester2;
		
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";
		
		tester3.advance();				
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

		tester3.advance();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

		tester3.remove_front();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

		tester3.advance();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";
		
		tester3.remove_front();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";
	
		tester3.advance();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

		tester3.remove_current();
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

		tester3.attach_back(14);
		cout << "-------------------------\n";
		printStats(tester3);
		cout << "-------------------------\n";

	
		return 0;
	
	}
