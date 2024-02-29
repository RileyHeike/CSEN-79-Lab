//Riley Heike, 1/11/2024


//Include Statements

#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
using namespace std;

int main(){

	//Strings to print
	
	string res = "1234567890";
	string res2 = "9876543210";

	//Initial whitespace
	
	int w = 15;

	//For loop to iterate 6 times
	
	for(int i = 0; i < 6; i++){

		//Print string1, whitespace, string2, endline, and then increase whitespace

		cout << res2 << setw(w) << res << setw(w) << endl;
		w += 5;	
	
	}
	
return 0;
}
