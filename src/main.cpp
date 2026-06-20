#include "HashTable.h"
#include <iostream>
using namespace std;

int main() {
    cout << "=== LEGENDARIUM ===" << endl;

    // testing hash table
    HashTable ht(100);

    Spell s1 = {"Fire Ball", "Fire", 90,100};
    Spell s2 = {"Water Wave", "Water", 80,90};
    Spell s3 = {"Shadow Hand", "Dark", 50,75};

    ht.insert(s1);
    ht.insert(s2);
    ht.insert(s3);

    Spell* result = ht.search("Shadow Veil");
    if (result != nullptr) {
        cout << "Spell Found:" << endl;
        cout << "Name: " << result->name << endl;
        cout << "Magic: " << result->magic << endl;
        cout << "Damage: " << result->damage << endl;
    } else {
        cout << "Spell not found." << endl;
    }

    return 0;
}