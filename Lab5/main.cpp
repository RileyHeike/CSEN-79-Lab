/*
 * Author: Riley Heike
 *
 * CSEN 79 Lab
 *
 * Date: 2/8/2024
 *
 */

#include "mystring.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using coen79_lab5::string;

std::string boolString(bool in){
	if(in) return "true";
	return "false";
}

int main(){

	//Slide 1
	string s1;
	string s2("Hello World!");
	string s3(s2);
	cout << "s1: " << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;

	cout << "*** += Operator Tests ***" << endl;

	cout << "s1 length: "<< s1.length() << endl;
	s1 += string("A");
	cout << "s1: " << s1 << endl;
	cout << "sl length: " << s1.length() << endl;

	s1 += "B";
	cout << "s1: " << s1 << endl;
	cout << "s1 length: " << s1.length() << endl;

	s1 += "C";
	cout << "s1: " << s1 << endl;
	cout << "s1 length: " << s1.length() << endl;

	//Slide 2
	cout << "*** [] Operator Tests ***" << endl;
	cout << "s1[0]: " << s1[0] << endl;	
	cout << "s1[1]: " << s1[1] << endl;
	cout << "s1[2]: " << s1[2] << endl;

	cout << "*** = Operator Tests ***" << endl;
	s2 = string("= Test 1 Success");
	cout << "s2: " << s2 << endl;
	s2 = string("= Test 2 Success");
	cout << "s2: " << s2 << endl;

	//Slide 3
	cout << "*** Logical Operator Tests ***" << endl;
	string A('A');
	string B('B');
	cout << "A == A: " << boolString(A==A) << endl;	
	cout << "A == B: " << boolString(A==B) << endl;
	cout << "A != A: " << boolString(A!=A) << endl;
	cout << "A != B: " << boolString(A!=B) << endl;
	cout << "A > A: " << boolString(A>A) << endl;
	cout << "A > B: " << boolString(A>B) << endl;
	cout << "B > A: " << boolString(B>A) << endl;
	cout << "A >= A: " << boolString(A>=A) << endl;
	cout << "A >= B: " << boolString(A>=B) << endl;
	cout << "B >= A: " << boolString(B>=A) << endl;
	cout << "A < A: " << boolString(A<A) << endl;
	cout << "A < B: " << boolString(A<B) << endl;
	cout << "B < A: " << boolString(B<A) << endl;
	cout << "A <= A: " << boolString(A<=A) << endl;
	cout << "A <= B: " << boolString(A<=B) << endl;
	cout << "B <= A: " << boolString(B<=A) << endl;

	cout << "*** + operator tests ***" << endl;
	cout << "A + B: " << A + B << endl;
	cout << "A + C: " << A + 'C' << endl;
	cout << "B + A: " << B + A << endl;

	cout << "*** >> operator tests ***" << endl;
	cout << "Please enter a word: " << endl;
	cin >> s1;
	cout << "You entered: " << s1 << endl;

	//Slide 4
	cout << "*** Single Character Constructor Tests ***" << endl;
	string C('C');
	cout << "C: " << C << endl;

	s1 = "ABCD";
	cout << "s1: " << s1 << endl;
	s1.insert("-", 0);	
	cout << "s1: " << s1 << endl;
	s1.insert("*", 3);
	cout << "s1: " << s1 << endl;
	s1.insert(".", s1.length());
	cout << "s1: " << s1 << endl;

	//Slide 5
	cout << "*** Dlt Tests ***" << endl;	
	s1 = "1112233445555";
	s1.dlt(0, 3);
	cout << "s1: " << s1 << endl;
	s1.dlt(2, 2);
	cout << "s1: " << s1 << endl;
	s1.dlt(s1.length()-4, 4);
	cout << "s1: " << s1 << endl;
	
	cout << "*** Replace Tests" << endl;
	s1 = "abc";
	cout << "s1: " << s1 << endl;
	s1.replace('z', 0);
	cout << "s1: " << s1 << endl;
	s1.replace('y', 1);
	cout << "s1: " << s1 << endl;
	s1.replace('x', 2);
	cout << "s1: " << s1 << endl;
	
	//Slide 6
	cout << "*** Count tests ***" << endl;
	s1 = "ABBCCCDDDD";
	cout << "s1: " << s1 << endl;
	cout << "Count A: " << s1.count('A') << endl;
	cout << "Count B: " << s1.count('B') << endl;
	cout << "Count C: " << s1.count('C') << endl;
	cout << "Count D: " << s1.count('D') << endl;
	cout << "Count E: " << s1.count('E') << endl;

	//Slide 7
	cout << "*** Search Tests ***" << endl;
	cout << "s1: " << s1 << endl;
	cout << "First A: " << s1.search('A') << endl;
	cout << "First B: " << s1.search('B') << endl;
	cout << "First C: " << s1.search('C') << endl;
	cout << "First D: " << s1.search('D') << endl;
	cout << "First E: " << s1.search('E') << endl;
		
	s1 = "ABCDEFGHIJKLMNOP";
	cout << "s1: " << s1 << endl;
	cout << "First ABC: " << s1.search("ABC") << endl;
	cout << "First GHI: " << s1.search("GHI") << endl;
	cout << "First NOP: " << s1.search("NOP") << endl;
	cout << "First XYZ: " << s1.search("XYZ") << endl;	
}
