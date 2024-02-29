// FILE: company.cpp
// CLASS implemented: company (see company.h for documentation)
/*
 * Riley Heike
 *
 * CSEN 79 Lab 7
 *
 * Invariants of the comapny class:
 * 	company_name is the name of the company for the class object
 * 	head_ptr points to the first node in the list of items in the class object
 *	tail_ptr points to the last node in the list of items in the class object
 */

#include <cassert>
#include "company.h"

//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif

namespace coen79_lab7
{
    // Class constructor
    company::company() {
        this->company_name = "";
        this->head_ptr = NULL;
        this->tail_ptr = NULL;
    }
    
    // Class constructor with arguments
    company::company(const std::string& company_name) {
        assert(company_name.length() > 0);
	this->company_name = company_name;
	this->head_ptr = NULL;
	this->tail_ptr = NULL;
    }
    
    // Copy Constructor
    company::company(const company &src) {
        Debug("Company copy constructor..." << std::endl);
	this->company_name = src.company_name;
	list_copy(src.get_head(), this->head_ptr, this->tail_ptr);
        
    }

    // Assignment operator
    company& company::operator= (const company &src) {
        Debug("Company assignemnt operator..." << std::endl);
	this->company_name = src.company_name;
	list_copy(src.get_head(), this->head_ptr, this->tail_ptr);
	return *this;
    }
    
    // Destructor
    company::~company() {
        list_clear(head_ptr);
    }
    
    // Getters + Setters
    std::string company::get_name() const {
        return company_name;
    }
    
    const node *company::get_head() const {
        return head_ptr;
    }
    
    const node *company::get_tail() const {
        return tail_ptr;
    }
    
    node* company::get_head() {
        return head_ptr;
    }
    
    node* company::get_tail() {
        return tail_ptr;
    }
    
    void company::print_items() {
        list_print(head_ptr);
    }
    
    // Insert a product of name product_name and price into the linked list
    bool company::insert(const std::string& product_name, const float& price) {
        
        assert(product_name.length() > 0);

        if (list_contains_item(head_ptr, product_name)) {
            return false;
        }
        
        if (head_ptr == NULL) {
            list_init(head_ptr, tail_ptr, product_name, price);
        }
        else {
            list_tail_insert(tail_ptr, product_name, price);
        }
        
        return true;
    }

    // Erase an item of product_name from the list
    bool company::erase(const std::string& product_name) {
        assert(product_name.length() > 0);

        node* cursor = head_ptr;
	node* tailer = head_ptr;
	while(cursor != NULL && cursor->getName() != product_name){
		tailer = cursor;
		cursor = cursor->getLink();
	}
	if(cursor == NULL) return false;
	if(tailer == cursor){
		head_ptr = head_ptr->getLink();
		delete cursor;
	}
	tailer->setLink(cursor->getLink());
	delete cursor;
	return true;
    }
    
    
}
