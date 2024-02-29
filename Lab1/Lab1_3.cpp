//Riley Heike, 1/11/2024

//Include Statements

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

int main(string fileName){


	//Initialize variables to store current word and current character
	
	string curWord;
	char ch;

	//Open file for reading
	
	fstream fin(fileName, fstream::in);

	//While loop to iterate through each character

	while(fin >> noskipws >> ch) {

		//If character, add to current word as uppercase

		if(isalpha(ch)){
		
			curWord += toupper(ch);
		
		}		

		//If space, then check length of current word, and print if over 10

		else if (isspace(ch)){
		
			int len = curWord.length();
			if(len >= 10){
			
				cout << curWord << endl;	
			
			}

			//Reset current word

			curWord = "";
		
		}	
	

	}

	return 0;


}
