#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <fstream>
#include <sstream>
#include <iostream>
#include "HashNode.hpp"
class HashTable {
    private:
        const int TABLE_SIZE = 85009;
        HashNode** table;
        int hashUserId(std::string userId);
                void insertNode(std::string userId, std::string password);
    public:
        HashTable();
        ~HashTable();
        void importData(std::string inputFileName);
        HashNode* searchNode(std::string userId);
};
#endif
