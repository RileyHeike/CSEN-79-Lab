/*
 * Riley Heike
 *
 * CSEN 79 Lab
 *
 * 2/8/2024
 *
 *
 * Ivariants of the mystring class
 * 	char *characters points to a array of char elements on heap memory
 * 	size_t allocated keeps track of the current allocated memory on heap
 * 	size_t current_length keeps track of the current number of elements stored
 *
 */

#include "mystring.h"
#include <cassert>
#include <iostream>
#include <cstring>


namespace coen79_lab5 {

	//Constructor for char array argument
	string::string(const char str[ ]){
		current_length = strlen(str);
		allocated = current_length + 1;
		characters = new char[allocated];
		strncpy(characters, str, allocated);
	}

	//Constructor for character argument
	string::string(char c){
		current_length = 1;
		allocated = current_length + 1;
		characters = new char[allocated];
		characters[0] = c;
		characters[1] = '\0';
	}

	//Constructor for string argument
	string::string(const string& source){
		current_length = source.current_length;
		allocated = source.allocated;
		characters = new char[current_length];
		strncpy(characters, source.characters, current_length);
	}

	//Destructor
        string::~string( ){
		delete [] characters;
		current_length = 0;
		allocated = 0;
	}

        
        //+= operator overloard for string parameter
        void string::operator +=(const string& addend){
		current_length = current_length + addend.current_length;
		allocated = current_length + 1;
		reserve(allocated);
		strncat(characters, addend.characters, addend.current_length);
	}

	//+= operator overload for char array parameter
        void string::operator +=(const char addend[ ]){	
		current_length = current_length + strlen(addend);
		allocated = current_length + 1;
		reserve(allocated);
		strncat(characters, addend, strlen(addend));
	}

	//+= operator overload for char parameter
        void string::operator +=(char addend){
		current_length++;
		allocated = current_length + 1;
		reserve(allocated);
		characters[current_length] = addend;
	}

	//reserve function to adjust string size
        void string::reserve(size_t n){
		char* temp = new char[n];
		if(current_length != 0){
			
			strncpy(temp, characters, current_length);
			delete [] characters;
				
		}
	
		characters = temp;
	
	}

	//= operator overload for two strings
        string& string::operator =(const string& source){
		this->dlt(0, current_length);
		if(current_length != source.current_length){
			reserve(source.allocated);
			allocated = source.allocated;
		}
		strncpy(characters, source.characters, source.current_length);
		current_length = source.current_length;
		return *this;
	}

	//insert function to place character passed in at position passed in
        void string::insert(const string& source, unsigned int position){
		assert(position <= current_length);
		if(allocated < current_length + source.current_length) reserve(current_length + source.current_length);
		for(unsigned int i = current_length; i > position; i--) characters[i] = characters[i-1];
		for(unsigned int i = 0; i < source.current_length; i++) characters[position+i] = source.characters[i];
		current_length = current_length + source.current_length;
	}

	//delete num elements from the string starting at position passed in
        void string::dlt(unsigned int position, unsigned int num){
		assert(current_length >= position + num);
		for(unsigned int i = position; i < current_length; i++) characters [i] = characters[i+num];
		current_length -= num;
	}

	//replace element at position passed in with the character passed in
        void string::replace(char c, unsigned int position){
		assert(position < current_length);
		characters[position] = c;
	
	}

	//replace element at position pased in with string passed in
        void string::replace(const string& source, unsigned int position){
		assert(position + source.current_length < current_length);
		strncpy(characters + position, source.characters, source.current_length);
	}
        
        // CONSTANT MEMBER FUNCTIONS
	//
	// [] operator overload to allow random access
        char string::operator [ ](size_t position) const{
		assert(position < current_length);
		return characters[position];
	}

	//search function to return position of character passed in
        int string::search(char c) const {
		for(unsigned int i = 0; i < length(); i++){
			if(characters[i] == c)
				return i;
		}
		return -1;
	}

	//search for a substring passed in and return position of first occurence
        int string::search(const string& substring) const{
		char* t = strstr(characters, substring.characters);
		if(t) return t[0] - characters[0];
		return -1;
	}

	//count the occurrences of a character passed in
        unsigned int string::count(char c) const{
		unsigned int cnt = 0;
		for(unsigned int i = 0; i < current_length; i++){
			if(characters[i] == c) cnt++;
		}
		return cnt;
	}
        
   	// NON-MEMBER FUNCTIONS for the string class
  	//
    	// + operator overload to add two strings and return a string
   	string operator +(const string& s1, const string& s2){
		string ret;
		ret.reserve(s1.length() + s2.length() + 1);
		ret += s1;
		ret += s2;
		return ret;
	}

	//+ operator overload to add a character to a strng 
   	string operator +(const string& s1, const char addend[ ]){
		string ret;
		ret.reserve(s1.length() + strlen(addend)+1);
		ret += s1;
		ret += addend;
		return ret;
	}

	// >> operator overload to allow input to a string
   	std::istream& operator >> (std::istream& ins, string& target){
		char* buffer = new char[50];
		while(ins && isspace(ins.peek())) ins.ignore();
		ins >> buffer;	
		target = string(buffer);
		return ins;
	}

	// << operator overload to allow the writing of strings
        std::ostream& operator <<(std::ostream& outs, const string& source){
		outs << source.characters;
		return outs;
	}

	// == operator overload to allow the comparison of two strings
        bool operator ==(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) == 0);
	}

	// != operator to allow the comparison of two strings
        bool operator !=(const string& s1, const string& s2){	
		return (strcmp(s1.characters, s2.characters) != 0);
	}

	// > operator to allow the comparison of two strings
        bool operator > (const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) > 0);
	}

	// < operator to allow the comparison of two strings
        bool operator < (const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) < 0);
	}

	// >= operator to allow the comparison of two strings
        bool operator >=(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) >= 0);
	}

	// <= operator to allow the comparison of two strings
        bool operator <=(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) <= 0);
	}

}
