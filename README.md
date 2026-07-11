# Legendarium
Team Name: **The Trix**\
<img src="https://github.com/user-attachments/assets/fd2df60a-1db8-4b00-bdfb-a980ecec319e" align = "right" alt="image" width="300" />
Course: COP 3530 Data Structures and Algorithm

The **Legendarium** is a powerful, dark magical spellbook introduced in Season 6 of _Winx Club_.
Created by the evil wizard Acheron, it has the ability to bring myths and fictional creatures into reality.
It serves as a major source of conflict throughout the season.

### Problem: What problem are we trying to solve?
Large databases require efficient methods for storing, searching, and retrieving information quickly. Our project aims to solve the problem of efficiently searching through and organizing a large spellbook containing over 100,000 spell entries. We will compare different data structures to determine which provides faster and more effective search and autocomplete functionality.

### Motivation: Why is this a problem?
Modern applications rely on efficient data retrieval to quickly search through large amounts of information. As datasets grow larger, slower search methods become less effective and reduce performance. We can better understand how data organization impacts speed and efficiency by comparing different data structures.

### Features: When do we know that we have solved the problem?
We’ll know we’ve solved the problem once our program can load a dataset of over 100,000 spells, insert them into both a Trie and a Hash Table and let the user perform fast searches  using both structures. The system will support exact searches for names, autocomplete spell names, filter spells by different categories, for different data structures compare the runtime performance, show the results through a menu-driven interface.

### Data: Public data set or schema of randomly generated data
Schema of randomly generated data is chosen to allow full control over the structure, scalability, and Winx Club-themed attributes of the spell archive while ensuring the dataset exceeds 100,000 entries.

### Strategy: Preliminary algorithms or data structures you may want to implement and how would you represent the data
Our strategy is to implement a Trie for prefix-based searching and a Hash Table for fast lookups. The Trie will take care of prefix searching, autocomplete, effective string retrieval. The Hash Table will give us fast name searches and effective insertion and lookup operations. The two structures we are using are different so we will compare performance analysis with search speed, insertion speed, memory efficiency, and autocomplete performance . The spells will be stored as an object or struct containing all the spell attributes. Spell records will be loaded from a CSV file into both data structures for comparison.

### Tools: Programming languages or any tools/frameworks we will be using
C++, GitHub, CSV files, Clion.

## How to Build and Run the Program

### IMPORTANT: Data File Placement
For the program to run successfully, it requires `spells.csv` (containing the 100,000 spells) to be located in the **exact same directory where the compiled binary executable runs**. 

### Using CLion / IDE (Recommended)
1. Open the project folder in **CLion**.
2. Let CLion automatically load and configure the `CMakeLists.txt` file.
3. Move `spells.csv` into the `cmake-build-debug` directory as mentioned in the setup step above.
4. Click the green **Run** button at the top right of the IDE to execute `main.cpp`.
