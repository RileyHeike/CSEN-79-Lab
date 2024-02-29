// FILE: database.cpp
// CLASS implemented: database (see database.h for documentation)
//
// Riley Heike
//
// CSEN 79 Lab 7
//
// INVARIANT for the database ADT:
//   1. The items in the database are stored in a dynamic array, where each entry of the array includes
//      a company name, a pointer to the head of the linked list of products, and a
//      a pointer to the tail of the linked list of products
//   2. The number of slots in the array of companies is stored in member varibale aloc_slots
//   3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"


//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif


namespace coen79_lab7
{
    // Constructor
    database::database(const size_type& initial_capacity) {
        used_slots = 0;
        aloc_slots = initial_capacity;
        company_array = new company[aloc_slots];
    }
    
    // Copy Constructor
    database::database(const database &src) {
        Debug("Copy constructor..." << std::endl);
	
	aloc_slots = src.aloc_slots;
	used_slots = src.used_slots;
	company_array = new company[aloc_slots];
    }
    
    // Assignment operator
    database& database::operator= (const database &rhs) {
        Debug("Assignment operator..." << std::endl);

	if(this == &rhs) return *this;
	delete [] company_array;
	company_array = new company[rhs.aloc_slots];
	std::copy(rhs.company_array, rhs.company_array + rhs.used_slots, company_array);
	used_slots = rhs.used_slots;
	aloc_slots = rhs.aloc_slots;
	return *this;
    }
    
    // Destructor
    database::~database() {
    	aloc_slots = used_slots = 0;
	delete [] company_array;
    }
    
    // Allocate more memory to store array elements
    void database::reserve(size_type new_capacity) {
        Debug("Reserve..." << std::endl);

        if (new_capacity == aloc_slots)
            return; // The allocated memory is already the right size.
        
        if (new_capacity < used_slots)
            new_capacity = used_slots; // Canít allocate less than we are using.
    
	company* new_array = new company[new_capacity];
	std::copy(company_array, company_array+used_slots, new_array);
	aloc_slots = new_capacity;
	delete [] company_array;
	company_array = new_array;   
    }
    
    // Add a new company to the array
    bool database::insert_company(const std::string &entry) {
        
        Debug("Insert company..." << std::endl);

        assert(entry.length() > 0);
        
        int pos = search_company(entry);
        
        // If you find a company that is false, because there are duplicates
        if (pos != COMPANY_NOT_FOUND) {
            return false;
        }

	if(aloc_slots == used_slots) reserve(used_slots + 1);
        company in = company(entry);
	company_array[used_slots++] = in;
    	return true;
    }
    
    // Insert a new product for a specified company
    bool database::insert_item(const std::string &company, const std::string &product_name, const float &price) {
        Debug("Insert item..." << std::endl);

        assert(company.length() > 0 && product_name.length() > 0);

        int position = search_company(company);
	if(position == COMPANY_NOT_FOUND) return false;
	
	company_array[position].insert(product_name, price);
	return true;
        
    }
    
    // Erase a company from the list
    bool database::erase_company(const std::string &company) {
	int position = search_company(company);
	if(position == COMPANY_NOT_FOUND) return false;

	if(used_slots == 1) used_slots--;
	else company_array[position] = company_array[--used_slots];    
    	return true;
    }
    
    // Erase a product from a specified company's list
    bool database::erase_item(const std::string& cName, const std::string& pName) {
        
        assert(cName.length() > 0 && pName.length() > 0);

        int position = search_company(cName);
	if(position == COMPANY_NOT_FOUND) return false;

	return company_array[position].erase(pName);
    }
    
    // Search for the index of a specified company in the array
    database::size_type database::search_company(const std::string& company) {
        assert(company.length() > 0);
	
	for(size_type i = 0; i < used_slots; i++){
		if(company_array[i].get_name() == company) return i;
	}
	return COMPANY_NOT_FOUND;
    }
    
    // Print the items in a company's linked list
    bool database::print_items_by_company(const std::string& cName) {
        assert(cName.length() > 0);

        int c_index = search_company(cName);
        
        if (c_index == COMPANY_NOT_FOUND) {
            return false;
        }
        
        std::cout << "Printing the products of " << cName << ":"<< std::endl;
        company_array[c_index].print_items();
        std::cout << std::endl;
        
        return true;
    }
    
    // Print the companies in the array
    void database::print_companies() {
        
        std::cout << "Company List" << std::endl;
        for (size_type i = 0; i < used_slots; i++) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }
}

#endif
