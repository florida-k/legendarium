#include "HashTable.h"
#include "Trie.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "\n=== Legendarium ===" << endl;
    cout << "1. Search Spell" << endl;
    cout << "2. Autocomplete Spell" << endl;
    cout << "3. Filter by Element" << endl;
    cout << "4. Compare Search Performance" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    menu();

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

    // Testing Trie
    Trie t;
    t.insert("Dark Spiral");
    t.insert("Shadow Hand");
    t.insert("Ice Shard");

    cout << "\nPrefix search for 'Da':" << endl;
    vector<string> results = t.startsWith("Da");

    for (auto& s : results)
        cout << s << endl;

    return 0;
}
