#pragma once
#include <bits/stdc++.h>

//A basic implementation of a hash table with open addressing linear probing
//The key is the string from the text file and the value
//is the frequency of the string
class HashNode{
public:
	std::string key;
	int value;
	HashNode(std::string key, int value);
};



class HashTable{
	int capacity;
	int size;
	HashNode** hash_table;
public:
	HashTable(int);
	~HashTable();
	int hashing_index(std::string);
	void insert(std::string);
	std::string getValue(std::string);
	void display();
	bool isEmpty() const;
	int getSize() const;
};