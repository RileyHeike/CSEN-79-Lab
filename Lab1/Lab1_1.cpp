//Riley Heike, 1/11/2024

//Include statements

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	
	//Get user input
	
	string input;
	cout << "Input: ";
	getline(cin, input);
	int len = input.length();
	
	//Initialize counters
	
	int countA = 0;
	int countB = 0;
	
	//For loop to iterate through input
	
	for(int i = 0; i <= len-1; i++) {
	
		//Check if alphanumeric, add to alphanumeric count

		if(isalnum(input[i])){
			countA += 1;
		}

		//Check if not space, add to non-alphanumeric count

		else if(!isspace(input[i])){
			countB += 1;
		}
		
	}

	//Print totals

	cout << "The input has " << countA << " alphanumeric characters.\n";
	cout << "The input has " << countB << " non-alphanumeric characters.\n";

return 0;
}
