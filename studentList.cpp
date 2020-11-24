#pragma warning(disable : 4996)
#include <vector>
#include <sstream>
#include <cstring>
#include "hashTable.h"
#include <string>
#include <fstream>

using namespace std;


//function prototypes
void addStudent(HashTable hash);
float RandomFloat(float a, float b);
void printstudent(HashTable hash);
void deleteStudent(HashTable hash);

int main() {
	//set variables
	HashTable hash;
	string input;
	int key;
	int value;
	bool validinput = false;
	bool running = true;
	bool keepadding = true;
	string answer;

//while the program is still running do the following
	while (running == true) {
		//tell user the commands
		cout << "What would you like to do?" << endl;
		cout << "Type 'ADD' to create a random new entry for a student." << endl;
		cout << "Type 'PRINT' to print out all the students currently stored." << endl;
		cout << "Type 'DELETE' to delete a student." << endl;
		cout << "Type 'QUIT' to exit." << endl;
		cin >> input;
		validinput = false;

		//ensure that there is the correct input otherwise re ask
		while (input != "ADD" && input != "PRINT" && input != "QUIT" && input != "DELETE" ) {
			cout << "Invalid input of " << input << ", please try again." << endl;
			cin >> input;
		}

//determine what to do depending on the input
		if (input == "ADD") {
			keepadding = true;
			//if the user wants to keep adding, ask again and do again while makig sure the input is valid
			while (keepadding == true) {
				addStudent(hash);
				cout << "Would you like to add another student? Yes or no." << endl;
				cin >> answer;
		  		
					if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y"){
						keepadding = true;
					}
					else if (answer == "no" || answer == "No" || answer == "NO" || answer == "n" || answer == "N") {
						keepadding = false;
						
					}
			
			}
		}
		else if (input == "PRINT") {
			printstudent(hash);
		}
		else if (input == "DELETE") {
			deleteStudent(hash);
		}
		else if (input == "QUIT") {
			cout << "Thanks!" << endl;
			running = false;
		}
		else {
			cout << "turd" << endl;
		}
		
	}
  return 0;
}

//function to add student 
void addStudent(HashTable hash) {
  Student* newstudent = new Student();
  string line;
	int numOfLines = 0;
	//make random number
	int random = rand() % 30;

//get first name at random number
	ifstream File("firstNames.txt");
	while(getline(File, line))
	{
	  ++numOfLines;
	  if(numOfLines == random)
	  {
	    newstudent->firstname = line;
	    //cout << line << endl;

	  }
	}
	File.close();
//get last name at random number
	ifstream myFile("lastNames.txt");
	while(getline(myFile, line))
	{
	  ++numOfLines;
	  if(numOfLines == random)
	  {
	    newstudent->lastname = line;
	    //cout << line << endl;
	  }
	}
	myFile.close();
//create random gpa and id number between 1mil and 0
	newstudent->gpa = RandomFloat(0.0, 4.0);
	newstudent->id = rand() % 1000000 + 1;
  //hash.hashFunc(newstudent->id);
  hash.insertStudent(newstudent->id, newstudent);
}

//function to print student 
 void printstudent(HashTable hash) {
 	 hash.printStudent();
 }

//function to delete student 
void deleteStudent(HashTable hash) {
	int id;
	cout << "Enter id number of student: " << endl;
	cin >> id;
	// string tempId = string(id);
	// int key = 0;
	// for (int i = 0; i < tempId.size(); i++) {
	// 	key += int(tempId[i]);
	// }
	hash.remove(id);
}

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}













