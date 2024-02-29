/*
 * Author: Riley Heike
 * 
 * File: sequence1.cpp
 *
 * COEN 79 Lab 3
 *
 * January 28th, 2024
 *
 */


#include <math.h>
#include <iostream>
#include <cassert>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3 {

	//Constructor initializes index and number of items to 0
	sequence::sequence(){
	
		used = 0;
		current_index = 0;
	
	}

	//Moves index to start of the sequence
	void sequence::start(){
		current_index = 0;
	}
	
	//Moves index to the end of occupied slots the sequence
	void sequence::end(){
		current_index = used-1;
	}
	
	//Moves index to the last slot in the sequence
	void sequence::last(){
		current_index = CAPACITY-1;
	}

	//Moves the index up 1 slot in the sequence (provided it is not already at the end)
	void sequence::advance(){
		if(current_index < CAPACITY - 1) current_index++;
	}
	
	//Moves the index back 1 slot in the sequence (provided it is not already at the beginning)
	void sequence::retreat(){
		if(current_index > 0) current_index--;
	}

	//Insert a value at the location before the index
	void sequence::insert(const value_type& entry){
		
		//Ensure sequence is not full
		assert(used < CAPACITY);
		
		//If there is item at index, shift all elements in the list down one and place at index
		if(is_item()){
		
		
			for(size_type i = used; i > current_index; i--){
			
				data[i] = data[i-1];
			
			}

			data[current_index] = entry;
			used++;
		}
		
		//If there is not item at index, insert at front
		else{
			insert_front(entry);
		}
		
	}
	
	//Insert an element at the beginning of the sequence
	void sequence::insert_front(const value_type& entry){
		
		//Ensure sequence is not full
		assert(used < CAPACITY);
		
		//Shift all elements down one position
		for(size_type i = used; i > 0; i--){
	
			data[i] = data[i-1];
			
		}

		//Insert element at index 0
		data[0] = entry;
		current_index = 0;
		used++;
	}
	
	//Insert element at location following the index
	void sequence::attach(const value_type& entry){
	
		//Ensure sequence is not full	
		assert(used < CAPACITY);

		//Shift elements after index 1 spot
		for(size_type i = used; i > current_index; i--){
			
			data[i] = data[i-1];
			
		}

		//Insert element after after previous index and increment
		data[++current_index] = entry;
		used++;
	}
	
	//Insert element at the end of the sequence
	void sequence::attach_back(const value_type& entry){
	
		//Ensure sequence is not full
		assert(used < CAPACITY);
		
		//Place element at the end of the sequence and move index there
		data[used++] = entry;
		current_index = used-1;

	}
	
	//Remove the element currently at the position of the index
	void sequence::remove_current(){

		//Ensure item is at location
		assert(is_item());
		
		//Shift all elements towards the front 1 position
		for(size_type i = current_index; i < used; i++){
			
			data[i] = data[i+1];
			
		}
		used--;
	}
	
	//Remove the element at the front of the sequence
	void sequence::remove_front(){
	
		//Ensure there is item at front of sequence
		assert(used > 0);
		
		//Shift all elements towards the front 1 position
		for(size_type i = 0; i < used; i++){
			
			data[i] = data[i+1];
			
		}
		used--;
	}

	//Return the number of elements in the sequence
	sequence::size_type sequence::size() const{
		return used;
	}

	//Return whether there is an item at the current index
	bool sequence::is_item(){
	
		return (current() < used && current() >= 0);
	}

	//Return the element at the current index
	sequence::value_type sequence::current() const{
		if(is_item()) return data[current_index];
	}

	//Return the current index
	sequence::size_type sequence::index() const{
		return current_index;
	}

	//Allow the use of the [] operator with objects from this class
	sequence::value_type sequence::operator[](int index) const{
		assert(is_item());
		return data[index];
	}

	//Allow the use of the += operator to attatch sequences together
	sequence operator+=(sequence& lhs, sequence& rhs){
		assert((lhs.size() + rhs.size()) <= CAPACITY)
		for(sequence::size_type i = 0; i < rhs.size(); i++){
		
			lhs.attach_back(rhs[i]);
		
		}

		return lhs;
	
	}

	//Return the mean value of the sequence
	double sequence::mean() const{
		double sum = 0;
		for(size_type i = 0; i < used; i++){
		
			sum += data[i];
		
		}
		return sum / used;
	}

	//Return the standard deviation of the sequence
	double sequence::standardDeviation() const{
	
		double me = mean();
		double s = 0;	

		for(size_type i = 0; i < used; i++){
		
			s += (me - data[i])*(me-data[i]);
		
		}
		return sqrt(s / used);

	}

	//Allow the use of the + operator to add sequences together
    	sequence operator+(sequence& lhs, sequence& rhs){
 
		assert((lhs.size() + rhs.size()) <= CAPACITY)   
		//Iterate through both parameter sequences and add elements to new sequence
    		sequence newS;
		for(sequence::size_type i = 0; i < lhs.size(); i++){
	
			newS.attach_back(lhs[i]);
	
		}

		for(sequence::size_type i = 0; i < rhs.size(); i++){
	
			newS.attach_back(rhs[i]);
	
		}
		return newS;
    
    	}

	//Return the sums of all the items in the sequence
    	sequence::value_type summation(const sequence &s){
    
    		double sum = 0;
		for(sequence::size_type i = 0; i < s.size(); i++){

			sum += s[i];		
			
		}
		return sum;
    
    	}

}
