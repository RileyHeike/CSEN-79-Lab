/*
 * Riley Heike
 *
 * CSEN 79 Lab 8
 *
 * deque_test.cpp
 *
 * Testing implementation of the deque and deque_iterator classes
 *
 */

#include <iostream>
#include "deque.h"
#include "deque_iterator.h"

using namespace coen79_lab8;
using namespace std;

int main(){

	deque<int> myDeque1;
	cout << endl << "Test Number: 1" << endl;
	cout << "Testing Constructor..." << endl << "Done!" << endl << endl;

	cout << "Test Number: 2" << endl; 
	cout << "Testing push_back() and back()" << endl;
	for(int i = 0; i < 100; ++i){
		cout << i << " ";
		myDeque1.push_back(i);
	}
	
	cout << myDeque1.back() << endl << endl;
	
	
	cout << "Test Number: 3" << endl; 
	cout << "Testing push_front() and front()" << endl;
	for(int i = 0; i < 100; ++i){
		cout << i << " ";
		myDeque1.push_front(i);
	}

	cout << myDeque1.front() << endl << endl;

	cout << "Test Number: 4" << endl << "Testing Iterator" << endl;
	for(deque<int>::iterator it = myDeque1.begin(); it != myDeque1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;
	
	cout << "Test Number: 5" << endl << "Testing pop_front()" << endl;
	for(int i = 0; i < 100; ++i){
		myDeque1.pop_front();
	}
	cout << "Front is: " << myDeque1.front() << endl;
	cout << "Back is: " << myDeque1.back() << endl << endl;

	cout << "Test Number: 6" << endl << "Testing pop_back()" << endl;
	for(int i = 0; i < 10; ++i){
		myDeque1.pop_back();
	}
	cout << "Front is: " << myDeque1.front() << endl;
	cout << "Back is: " << myDeque1.back() << endl << endl;
	
	cout << "Test Number: 7" << endl << "Testing Iterator" << endl;
	for(deque<int>::iterator it = myDeque1.begin(); it != myDeque1.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "Test Number: 8" << endl << "Testing Assignment Operator" << endl;
	deque<int> myDeque2;
	myDeque2.push_front(3);
	myDeque2.push_front(2);
	myDeque2.push_front(1);
	myDeque2.push_back(4);
	myDeque2.push_back(5);
	myDeque2.push_back(6);
	deque<int> myDeque3 = myDeque2;
	
	for(deque<int>::iterator it = myDeque3.begin(); it != myDeque3.end(); ++it){
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "Test Number: 9" << endl << "Testing Copy Constructor" << endl;
	deque<int> myDeque4(myDeque3);	

	for(deque<int>::iterator it = myDeque4.begin(); it != myDeque4.end(); ++it){
		cout << *it << " ";
	}

	cout << endl << endl;
	cout << "Test Number: 10" << endl << "Iterator Test" << endl;
	deque<int>::iterator it_start = myDeque4.begin();
	deque<int>::iterator it_end = myDeque4.end();
	deque<int>::iterator it2 = it_start;
	while(it2 != it_end){
		*it2 = 950;
		++it2;
	}
	it2 = it_start;
	while(it2 != it_end){
		cout << *it2 << " ";
		it2++;
	}
	cout << endl << endl;
	return 0;
}
