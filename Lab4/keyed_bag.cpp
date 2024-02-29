/*
 * Author: Riley Heike
 *
 * Date: 2/4/2024
 *
 * COEN 79 Lab 4
 *
 *
 *
 * Invariants of the keyed_bag class:
 *
 * 	used: variable of type size_type that keeps track of the elements in the array keys[] and data[]
 * 		we only care about elements in the arrays from at the indexes used to CAPACITY
 * 	data[]: array that keeps track of the values associated with keys in the array keys[]
 * 	key[]: array of type string that holds keys corresponding to a value in data[]
 *
 *
 */

#include <iostream>
#include <cassert>
#include "keyed_bag.h"

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4{

	//Constructor
	keyed_bag::keyed_bag(){
		
		used = 0;
	
	}

	//Reset bag, remove all contents
	void keyed_bag::erase(){
	
		used = 0;
	
	}
	
	//Remove an element of specified key
	void keyed_bag::erase(const key_type& key){
	
		keyed_bag::size_type i = 0;
		
		//Find index of item with specified key
		while(keys[i] != key){
		
			i++;
		
		}

		//If key was found, shift all elements 1 spot towards the front
		if(i != used){
			
			while(i < used){
			
				keys[i] = keys[i+1];
				data[i] = data[i+1];
				i++;
			}

			used--;

		}

	}

	//Add an element and key to their respective arrays
	void keyed_bag::insert(const value_type& entry, const key_type& key){
		
		assert(used < CAPACITY);

		data[used] = entry;
		keys[used++] = key;
	
	
	}

	//Copy the key and data arrays from addend to the arrays of the object using the copy function
	void keyed_bag::operator+=(const keyed_bag& addend){
	
		assert(used + addend.size() <= CAPACITY);

		copy(addend.data, addend.data + addend.used, data + used);
		copy(addend.keys, addend.keys + addend.used, keys + used);

		used += addend.used;	
	
	}

	//Check if there is an element in the bag with the key passed into the function
	bool keyed_bag::has_key(const key_type& key) const{
	
		for(keyed_bag::size_type i = 0; i < used; i++){
		
			if(key == keys[i]) return true;
		
		}

		return false;
	
	}

	//Get the value of the element with the specified key
	keyed_bag::value_type keyed_bag::get(const key_type& key) const{
	

		for(keyed_bag::size_type i = 0; i < used; i++){
		
			if(key == keys[i]) return data[i];
		
		}

		return -1;
	}

	//Check if two bags have overlapping keys
	bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{
	
		for(keyed_bag::size_type i = 0; i < used; i++){
		
			if(otherBag.has_key(keys[i])){
			
				return true;
			
			}
		
		}	

		return false;
	
	}

	//Return the amount of elements stored in the arrays
	keyed_bag::size_type keyed_bag::size() const{
	
		return used;
	
	}

	//Count the amount of times a specified value is in the array data[]
	keyed_bag::size_type keyed_bag::count(const value_type& target) const{
	
		keyed_bag::size_type count = 0;
		for(keyed_bag::size_type i = 0; i < used; i++){
		
			if(target == data[i]) count++;
		
		}

		return count;
	
	}

	//Allow the addition of two bags using + operator overloading	
	keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2){
	
		assert(b1.size() + b2.size() <= keyed_bag::CAPACITY);

		keyed_bag ret;
		ret += b1;
		ret += b2;
		return ret;
	}
}
