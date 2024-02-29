//FILE: sequence.cpp
//CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
//
//  Riley Heike
//
//  COEN 79
// 
//
//
//INVARIANT for the sequence class
//  1. The number of items in the sequence is stored in the member variable "many_nodes"
//
//  2. For an empty sequence, we do not care what is stored in any of data and head_ptr
//      and tail_ptr point to NULL; for a non-empty sequence, the items stored in the
//      sequence can be accessed using head_ptr and tail_ptr and we don't care what is
//      stored in the rest of the data.
//
//  3. If there is a current item, then it lies in *cursor; if there is no
//     current item, then cursor* equals NULL.
//
//  4. If there is a previous item, then it lies in precursor*.  If there is no previous
//       item, then precursor equals NULL.


#include <iostream>
#include <algorithm> //provides copy function
#include <cassert> //for assert function
#include "sequence.h" //header file for class
#include "node.h" // provides node class

using namespace std; //For copy function

namespace coen79_lab6
{
    // Default private member variable initialization function.
    void sequence::init()
    {
        //Initializing pointers to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        //Initializiing many_nodes (or our counter) to 0
        many_nodes = 0;
    }

    //CONSTRUCTOR IMPLEMENTATION for default constructor
    sequence :: sequence ()
    {
        init();
    }

    //Copy Constructor
    sequence :: sequence(const sequence& source)
    {
        init();
        *this = source;
    }
	// Sequence destructor
	sequence::~sequence(){
		list_clear(head_ptr);
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		many_nodes = 0;
	}	

	// Move the cursor to the start of the list
	void sequence::start(){
		cursor = head_ptr;
		precursor = NULL;
	}

	// Move the cursor to the end of the list
	void sequence::end(){

		if(many_nodes == 0) return;
		cursor = tail_ptr;
		if(head_ptr == tail_ptr) precursor = NULL;
		else precursor = list_locate(head_ptr, many_nodes-1);
	}

	// Move the cursor forwards in the list
	void sequence::advance(){
		assert(is_item());
		precursor = cursor;
		cursor = cursor->link();
	}
    
	// Insert a new element with value entry 
	void sequence::insert(const value_type& entry){
		if(!is_item() || precursor == NULL){
			list_head_insert(head_ptr, entry);
			if(tail_ptr == NULL) tail_ptr = head_ptr;
			cursor = head_ptr;
			precursor = NULL;
			many_nodes++;
		}
		else{
			list_insert(precursor, entry);
			cursor = precursor->link();
			many_nodes++;

		}

	}

	// Insert a new element at the end of the sequence
	void sequence::attach(const value_type& entry){

		if(head_ptr == NULL){
			list_head_insert(head_ptr, entry);
			tail_ptr = cursor = head_ptr;
			precursor = NULL;
		}
		else if(cursor == NULL){
			list_insert(tail_ptr, entry);
			cursor = tail_ptr->link();
			precursor = tail_ptr;
			tail_ptr = cursor;
		}
		else{
			list_insert(cursor, entry);
			precursor = cursor;
			cursor = cursor->link();
			if(cursor->link() == NULL) tail_ptr = cursor;

		}
		many_nodes++;

	}

	// Enable the comparison operator for the list class
	void sequence::operator=(const sequence& source){
		if(this == &source) return;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		start();
		node *tmp = source.head_ptr;
		while(tmp != source.cursor){
			advance();
			tmp = tmp->link();
		}

	}

	// Remove the element the cursor is pointing to
	void sequence::remove_current(){
		assert(is_item());
		if(cursor == head_ptr){
			if(head_ptr == tail_ptr){
				list_head_remove(head_ptr);
				head_ptr = NULL;
				tail_ptr = NULL;
				cursor = NULL;
				precursor = NULL;
			}
			else{
				list_head_remove(head_ptr);	
				cursor = head_ptr;
				precursor = NULL;
			}
		}
		else if(cursor == tail_ptr){
			list_remove(precursor);
			tail_ptr = precursor;
			cursor = NULL;
		}
		else{
			cursor = cursor->link();
			list_remove(precursor);

		}
		many_nodes--;
	}

	// Return the size of the sequence
	sequence::size_type sequence::size() const {
		return many_nodes;
	}

	// Return whether the cursor is currently poiting to an item or not
	bool sequence::is_item() const{
		return(cursor != NULL);
	}

	// Return the value of the item pointed to by cursor	
	sequence::value_type sequence::current() const{
		assert(is_item());
		return cursor->data();
	}
}
