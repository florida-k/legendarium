#include "HashTable.h"
#include "Trie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

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
    // 1. load the 100k spells from the CSV into vector
    vector<Spell> spells;
    ifstream file("spells.csv");

    if (!file.is_open()) {
        cout << "Error: Could not open spells.csv" << endl;
        return 1;
    }

    string header, line;
    getline(file, header); // skip the first header row

    cout << "Loading 100k spells from file...please wait." << endl;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string name, element, magicStr, damageStr;

        getline(ss, name, ',');
        getline(ss, element, ',');
        getline(ss, magicStr, ',');
        getline(ss, damageStr, ',');

        int magic = stoi(magicStr);
        int damage = stoi(damageStr);

        Spell spell = {name, element, magic, damage};
        spells.push_back(spell);
    }
    file.close();
    cout << "Loaded " << spells.size() << " spells successfully!" << endl;

    // 2. build our two custom data structures from vector
    HashTable ht(150000);
    Trie trie;

    for (auto s : spells) {
        ht.insert(s);
        trie.insert(s.name);
    }

    // 3. user interaction menu
    int choice = 0;
    while (choice != 5) {
        menu();
        cin >> choice;
        cin.ignore(); // clean up input buffer

        if (choice == 1) {
            string searchName;
            cout << "Enter spell name to search: ";
            getline(cin, searchName);

            Spell* result = ht.search(searchName);
            if (result != nullptr) {
                cout << "\nFound Spell Details:" << endl;
                cout << "  Name:    " << result->name << endl;
                cout << "  Element: " << result->element << endl;
                cout << "  Magic:   " << result->magic << endl;
                cout << "  Damage:  " << result->damage << endl;
            } else {
                cout << "Spell not found." << endl;
            }
        }
        else if (choice == 2) {
            string prefix;
            cout << "Enter prefix for autocomplete: ";
            getline(cin, prefix);

            vector<string> results = trie.startsWith(prefix);
            cout << "\nFound " << results.size() << " match(es):" << endl;

            // only show the first 15 matches so the terminal doesn't explode
            int limit = 15;
            if (results.size() < limit) limit = results.size();

            for (int i = 0; i < limit; i++) {
                cout << "  - " << results[i] << endl;
            }
        }
        else if (choice == 3) {
            string targetElement;
            cout << "Enter element to filter by (Ice, Darkness, Storm): ";
            getline(cin, targetElement);

            cout << "\nSpells with element '" << targetElement << "':" << endl;
            int matches = 0;

            for (auto s : spells) {
                if (s.element == targetElement) {
                    matches++;
                    if (matches <= 15) { // only print the first 15 rows
                        cout << "  - " << s.name << " (Damage: " << s.damage << ")" << endl;
                    }
                }
            }
            cout << "Total matching spells found: " << matches << endl;
        }
        else if (choice == 4) {
            string benchmark;
            cout << "Enter a single spell name to benchmark: ";
            getline(cin, benchmark);

            cout << "\n--- Performance Timing ---" << endl;

            // hash table timing
            auto startHash = high_resolution_clock::now();
            ht.search(benchmark);
            auto endHash = high_resolution_clock::now();
            auto durationHash = duration_cast<microseconds>(endHash - startHash).count();
            cout << "Hash Table Look-up: " << durationHash << " microseconds" << endl;

            // trie timing
            auto startTrie = high_resolution_clock::now();
            trie.search(benchmark);
            auto endTrie = high_resolution_clock::now();
            auto durationTrie = duration_cast<microseconds>(endTrie - startTrie).count();
            cout << "Trie Tree Look-up:  " << durationTrie << " microseconds" << endl;
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

// test from emy