#pragma once
#include <iostream>
#include <string>
using namespace std;


//create student struct
struct Student {
	string firstname;
	string lastname;
	int id;
	float gpa;
};

class ListHead {
public:
	int key;
	Student* student;
	ListHead *next;
	ListHead(int key, Student* student) {
		this->key = key;
		this->student = student;
		this->next = NULL;
	}
};


class HashTable {
public:
	HashTable();
	~HashTable();
	int hashFunc(int key);
	void insertStudent(int key, Student* student);
	Student* searchStudent(int key);
	void printStudent();
	void remove(int key);
	//pointer to
	int studnum;
private: 
	ListHead **ht;

};

//have a student list
//when you need to increase the size of hashtable:
// 1. Allocate new array. How many members? studnum * 2
// 2. Delete old array.
// 3. this->studnum *= 2
// 4. this->arr = new array