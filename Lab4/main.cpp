/*
 * Riley Heike
 *
 * COEN 79 Lab 4
 *
 * 2/1/2024
 *
 */

#include "keyed_bag.h"
#include <iostream>

using namespace std;
using namespace coen79_lab4;


//Insert an element into the keyed_bag and print a statement
void Insert(const int val, const string& key, keyed_bag& kb){

	kb.insert(val, key);
	cout << "Inserting " << val << " with key " << key << endl;
}

//Erase an element from the keyed_bag based on a value passed in and print
void Erase(const string& key, keyed_bag& kb){

	kb.erase(key);
	cout << "Erasing " << key << endl;

}

//Retrive a value from a key and print it
void Get(const string& key, const keyed_bag& kb){

	cout << "Value for " << key << ": " << kb.get(key) << endl;
	

}

//Check if the bag contains a certain key and print result
void Has(const string& key, const keyed_bag& kb){

	cout << "Has " << key << ": ";
	if(kb.has_key(key)) cout << "1" << endl;
	else cout << "0" << endl;

}

//Count the number of occurunces a value has in the bag
void Count(const int val, const keyed_bag& kb){

	cout << "Number of " << val << "s in the bag: " << kb.count(val) << endl;

}

//Print the size of the keyed_bag
void bSize(const keyed_bag& kb){

	cout << "Bag size: " << kb.size() << endl;

}

//Test functions for the keyed_bag
int main(){

	keyed_bag kb1;
	keyed_bag kb2;
	keyed_bag kb3;

	Insert(5, "five", kb1);
	Insert(3, "three", kb1);
	Insert(1, "one", kb1);

	Get("one", kb1);
	Get("three", kb1);
	Get("five", kb1);

	Has("five", kb1);
	Has("two", kb1);

	bSize(kb1);
	Erase("five", kb1);
	bSize(kb1);

	Has("five", kb1);
	Has("three", kb1);

	Insert(-8, "neg_eight", kb1);
	bSize(kb1);
	Has("neg_eight", kb1);
	Get("neg_eight", kb1);
	
	Count(9, kb1);
	Count(1, kb1);

	Insert(1, "ONE", kb1);
	Count(1, kb1);
	Insert(7, "seven", kb1);
	Insert(9, "nine", kb1);
	Insert(11, "eleven", kb1);

	bSize(kb1);
	Erase("eleven", kb1);
	bSize(kb1);
	Erase("ONE", kb1);
	bSize(kb1);
		
	Insert(1, "1", kb2);
	Insert(2, "2", kb2);
	Insert(3, "3", kb2);
	Insert(4, "4", kb2);
	Insert(5, "5", kb2);

	kb3 = kb1 + kb2;
	bSize(kb3);

	Has("1", kb3);
	Has("one", kb3);
	Has("turkey", kb3);
	
	Count(1, kb3);
	Count(9, kb3);
	Count(-5, kb3);
	
	Get("three", kb3);
	cout << "Erasing all of kb2." << endl;
	kb2.erase();

	bSize(kb2);

	Insert(22, "I'm feelin", kb2);
	Get("I'm feelin", kb2);
}




