cmake_minimum_required(VERSION 4.2)
project(legendarium)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(legendarium
        src/main.cpp
        src/HashTable.cpp
        src/Trie.cpp
        include/Spell.h
        include/HashTable.h
        include/Trie.h)