#include "hashing_open.h"
using namespace std;


HashNode::HashNode(string key, int value){
	this->key = key;
	this->value = value;
}

HashTable::HashTable(int capac){
	capacity = capac;
	size = 0;
	hash_table = new HashNode*[capacity];
}

HashTable::~HashTable(){
	delete [] hash_table;
}

//find the sum of the ascii codes and mod 599 
//prime number is used  for less collisions
int HashTable::hashing_index(std::string key){
	int len = key.size();
	int sum = 0;
	const char* string_char = key.c_str();
	for (int i = 0; i < len; i++){
		sum += (int(string_char[i]));
	}
	return sum % 599;
}

bool HashTable::isEmpty() const{
	return size == 0 
}

int HashTable::getSize() const{
	return size;
}

void HashTable::display(){


}

//linear probing is used to find the next free slot
// to insert the value and to avoid collisions
void HashTable::insert(std::string key){
	int index = hashing_index(key);

}