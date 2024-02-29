// FILE: node.cpp
//
//
//  COEN 79
//  Riley Heike
//
//
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
//
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream>

using namespace std;

namespace coen79_lab6
{
    // Return the length of the list
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    // Insert a node at the head of the list
    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }

    //Insert a node at a specified location passed in by a pointer
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    // Search the list for a value and return pointer to location
    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    // Const version of list_search
    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    // Return the node at position passed in to function
    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    // Const version of the list_locate function
    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    // Remove the head of the list
    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    // Remove the node at the position following the pointer passed into the function
    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    // Clear the lsit of all entries
    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    // Copy the list into a new list with head and tail pointers passed in
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }

    // Copy a portion of the source list into list with head and tail passed in 
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr) {
        head_ptr=NULL;
        tail_ptr=NULL;

        if (start_ptr==NULL || start_ptr==end_ptr) {
            return;
        }
	list_head_insert(head_ptr, start_ptr->data());
	tail_ptr = head_ptr;

	while(start_ptr->link() != end_ptr){
		start_ptr = start_ptr->link();
		list_insert(tail_ptr, start_ptr->data());
		tail_ptr = tail_ptr->link();	
	}
        
    }
    // Return the number of occurences in the list for a value passed in
    size_t list_occurrences(node* head_ptr, const node::value_type& target){
    
    	const node *cursor;
	size_t count = 0;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		 count++;

    	return count;
    
    }

    // Insert a node at a position passed into the function
    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position){
   	if(head_ptr == NULL || position == 1){
		list_head_insert(head_ptr, entry); 
    		return;
	}
	node* cursor = head_ptr;
    	for (size_t i = 1; (i < position-1) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

	list_insert(cursor, entry);
    
    }

    // Remove a node at a position passed in and return node value
    node::value_type list_remove_at(node*& head_ptr, size_t position){
  	
	node::value_type ret;
    	node* cursor = head_ptr;
    	for (size_t i = 1; (i < position-1) && (cursor != NULL); i++)
    	    cursor = cursor->link( );
   	ret = cursor->link()->data();	
	list_remove(cursor);
 	return ret;
    }

    // Copy a segment of the list from start to finish into head_ptr
    node* list_copy_segment(node* head_ptr, size_t start, size_t finish){
	assert(start >=1 && start <= finish);    

	node* headcpy;
	node* tailcpy;

	if(head_ptr == NULL) return NULL;
	
	list_piece(list_locate(head_ptr, start), list_locate(head_ptr, finish+1), headcpy, tailcpy);
	return headcpy;
    
    }

    // Print the contents of the list
    void list_print (const node* head_ptr){
    	while(head_ptr != NULL){
		if(head_ptr->link() != NULL) cout << head_ptr->data() << ", ";	
		else cout << head_ptr->data() << endl;
		head_ptr = head_ptr->link();
	}
	cout << endl;
    
    }

    // Remove the duplicates from the list
    void list_remove_dups(node* head_ptr){
    

	node* cursor;
	while(head_ptr != NULL){
		cursor = head_ptr;
		while(cursor->link() != NULL){
			if(cursor->data() == head_ptr->data()){
				node* del = cursor;
				list_remove(del);	
			}
			else cursor = cursor->link();
		}
	head_ptr = head_ptr->link();
	}
    
    }

    // Detect loops in the list and return the starting point of the loop
    node* list_detect_loop (node* head_ptr){
	node* slow;
	node* fast;
	slow = fast = head_ptr;
	while(fast != NULL || fast->link() != NULL){
		slow = slow->link();
		fast = fast->link()->link();
		if(slow == fast) break;
	} 
	if(fast == NULL || fast->link() == NULL) return NULL;
	slow = head_ptr;
	while(slow != fast){
		slow = slow->link();
		fast = fast->link();
	}
    	return fast;
    }
    
}
