#pragma once
#include "Spell.h"
#include <list>
#include <vector>

class HashTable {
    int tableSize; // # buckets in ht
    vector<list<Spell>> table; // linked list of spells (sep chaining collision handling)
    int hashFunction(string key); // converts spell name to table index
public:
    HashTable(int size); // constructor
    void insert(Spell spell);
    Spell* search(string name); // ret ptr to spell if found
    void display();
    int getTableSize(); // total # buckets in ht
};