#include "HashTable.h"

HashTable::HashTable(int size) {
    tableSize = size;
    table.resize(tableSize);
}

int HashTable::hashFunction(string key) {
    int hash = 0;
    for (char c : key) {
        // https://www.geeksforgeeks.org/java/why-does-javas-hashcode-in-string-use-31-as-a-multiplier/
        hash = hash * 31 + c;
    }
    return abs(hash % tableSize);
}


void HashTable::insert(Spell spell) {
    int index = hashFunction(spell.name);
    table[index].push_back(spell);
}

Spell* HashTable::search(string name) {
    int index = hashFunction(name);

    for (auto& spell : table[index]) {
        if (spell.name == name) {
            return &spell;
        }
    }
    return nullptr;
}

int HashTable::getTableSize() {
    return tableSize;
}