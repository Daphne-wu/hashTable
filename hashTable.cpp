#pragma warning(disable : 4996)
#include "hashTable.h"
using namespace std;



HashTable::HashTable() {
	studnum = 100;
	ht = new ListHead*[studnum];
	for (int i = 0; i < studnum; i++) {
		ht[i] = NULL;
	}
}

int HashTable::hashFunc(int key) {
	return key % studnum;
}

void HashTable::insertStudent(int key, Student* student) {
	int hash_v = hashFunc(key);
	if (ht[hash_v] == NULL) {
		cout << "i'm inserting " << student->firstname << " w key " << key << " " << hash_v << endl;
		ht[hash_v] = new ListHead(key, student);
		cout << "my new ht[hash_v] head is " << ht[hash_v]->student->firstname << endl;
		return;
	}
	else {
		ListHead *end = ht[hash_v];
		cout << "my ht[hash_v] head is " << ht[hash_v]->student->firstname << endl;
		while (end->next != NULL) {
			end = end->next;
		}
		end->next = new ListHead(key, student);	
	}
	return;
}


Student* HashTable::searchStudent(int key) {
	int hash_v = hashFunc(key);
	//if the student at the key value is null return error
	if (ht[hash_v] == NULL) {
		return NULL;
	}
	else {
		ListHead *end = ht[hash_v];
		while (end != NULL && end->student->id != key) {
			end = end->next;
		}
		if (end == NULL) {
			return NULL;
		}
		else {
			return end->student;
		}
	}
}


void HashTable::printStudent() {
	//if the student at the key value is null return error
	for (int hash_v = 0; hash_v < studnum; hash_v++) {
		ListHead *end = ht[hash_v];
		if (end != NULL) {
			cout << end->student->firstname << " " << end->student->lastname << ", " << end->student->id << ", " << end->student->gpa << endl;
			end = end->next;
		}
		else {
			end = end->next;
		}
	}
}

// void HashTable::printStudent() {
// 	int hash_v = 0;
// 	//if the student at the key value is null return error
// 	if (ht[hash_v] == NULL) {
// 		cout << "NULL cuz empty" << endl;

// 	}
// 	else {
// 		ListHead *end = ht[hash_v];
// 		while (end != NULL) {
// 			cout << end->student->firstname << " " << end->student->lastname << ", " << end->student->id << ", " << end->student->gpa << endl;
// 			end = end->next;
// 		}
// 		if (end == NULL) {
// 			cout << "NULL cuz no student" << endl;
// 		}
// 	}
// }

void HashTable::remove(int key) {
	int hash_v = hashFunc(key);
     if (ht[hash_v] != NULL) {
        ListHead *end = ht[hash_v];
        ListHead *previous = NULL;
        while (end != NULL && end->student->id != key) {
           previous = end;
           end = end->next;
        }
        if (end->student->id != key) {
           if (previous == NULL) {
           	  ListHead *next= end->next;
              delete end;
              ht[hash_v] = next;
           }
           else {
              ListHead *next = end->next;
              delete end;
              previous->next = next;
           }
        }
     }
  }

HashTable::~HashTable() {
	delete[] ht;
}

//pinter to the student from the id