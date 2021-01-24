#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "Node.hpp"
#include <string>
class HashTable {
    private:
        const int TABLE_SIZE = 85009;
        Node** table;
    public:
        HashTable();
        ~HashTable();
};
#endif
