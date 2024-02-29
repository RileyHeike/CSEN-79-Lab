/*
 * Riley Heike
 *
 * CSEN 79 Lab 7
 *
 * node.cpp
 *
 * Implementation file for the node class
 *
 * Invariants of the node class:
 * 	name is a string that holds the name of the item stored in the node
 * 	price is a float variable that holds the name of the price of the item in the node
 * 	link is  pointer to the next node in the linked list
 */
#ifndef ITEM_CPP
#define ITEM_CPP

#include "node.h"

namespace coen79_lab7
{
	//Node constructor
    node::node(const std::string &itemName, const float &newPrice, node *nextNode) {
        name = itemName;
        price = newPrice;
        link = nextNode;
    }
    
    // Set the name of an item
    void node::setName(const std::string &newName) {
        name = newName;
    }
    
    // Set the price of an item
    void node::setPrice(const float &newPrice) {
        price = newPrice;
    }
    
    // Change the link of the node
    void node::setLink(node *new_next) {
        link = new_next;
    }
    
    // Retrieve the link of the node
    node* node::getLink() {
        return link;
    }
    
    // Const version
    const node* node::getLink() const {
        return link;
    }
    
    // Retrieve the name of the item in the node
    std::string node::getName() const{
        return name;
    }
    
    // Retrieve the price of the item
    float node::getPrice() const {
        return price;
    }
    
    // Initialize the list
    void list_init(node*& head, node*& tail, const std::string& newName, const float& newPrice) {
        head = new node(newName, newPrice, NULL);
        tail = head;
    }
    
    // Insert a new node at the tail of the list
    void list_tail_insert(node*& tail, const std::string &newName, const float &newPrice) {
	tail->setLink(new node(newName, newPrice, NULL));
	tail = tail->getLink();
    }
    
    // Clear the list
    void list_clear(node*& head) {
	while(head != NULL) list_head_remove(head);
    }

    
    // Copy the list into a new list using new_head and new_tail pointers passed in
    void list_copy(const node *old_head, node* &new_head, node* &new_tail) {
        new_head = NULL;
        new_tail = new_head;
        
        const node *cur = old_head;
        while (cur != NULL) {
            if (new_head == NULL) {
                new_head = new node(cur->getName(), cur->getPrice());
                new_tail = new_head;
            }
            else {
                new_tail->setLink(new node(cur->getName(), cur->getPrice()));
                new_tail = new_tail->getLink();
            }
            cur=cur->getLink();
        }
    }
    
    // Remove the head of the list
    void list_head_remove(node*& head) {
        node* temp = head;
	head = head->getLink();
	delete temp;
    }
    
    // Print the contents of the list
    void list_print(node *head) {
        node *cur = head;
        while (cur != NULL) {
            std::cout << "- " << cur->getName() << ", where the price is $" << cur->getPrice() << std::endl;
            cur = cur->getLink();
        }
    }
    
    // Search for whether the list contains an item name passed in
    bool list_contains_item(node *head_ptr, const std::string& newName) {
        return (list_search(head_ptr, newName) != NULL);
    }
    
    // Search the list for a target name and return a pointer to it if found
    node* list_search(node* head_ptr, const std::string& target)
    {
        node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
    
    // const version
    const node* list_search(const node* head_ptr, const std::string & target)
    {
        const node *cursor;
        
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->getLink( ))
            if (target == cursor->getName( ))
                return cursor;
        return NULL;
    }
    
}

#endif
