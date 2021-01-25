#include "HashTable.hpp"
int HashTable::hashUserId(std::string userId) {
    unsigned long hash = 7;
    for (int i = 0; i < userId.size(); i++) {
        hash = 31 * hash + userId[i];
    }
    return hash % TABLE_SIZE;
}
HashTable::HashTable() {
    table = new HashNode*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* currentNode = table[i];
        while (currentNode != nullptr) {
            HashNode* previousNode = currentNode;
            currentNode = currentNode->getNextNode();
            delete previousNode;
        }
    }
    delete[] table;
}
void HashTable::importData(std::string inputFileName) {
    std::ifstream inFile(inputFileName);
    if (inFile.is_open()) {
            std::string line;
            while (getline(inFile, line)) {
                std::stringstream ss(line);
                std::string userId;
                std::string password;
                ss >> userId >> password;
                insertNode(userId, password);
            }
        inFile.close();
    } else {
        std::cout << inputFileName << " could not be opened." << std::endl;
        exit (EXIT_FAILURE);
    }
}
void HashTable::insertNode(std::string userId, std::string password) {
    int hash = hashUserId(userId);
    HashNode* currentNode = table[hash];
    HashNode* previousNode = nullptr;
    while (currentNode != nullptr) {
        previousNode = currentNode;
        currentNode = currentNode->getNextNode();
    }
    currentNode = new HashNode(userId, password);
    if (previousNode == nullptr) {
        table[hash] = currentNode;
    } else {
        previousNode->setNextNode(currentNode);     
    }
}
HashNode* HashTable::searchNode(std::string userId) {
    int hash = hashUserId(userId);
    HashNode* currentNode = table[hash];
    while (currentNode != nullptr) {
        if (currentNode->getUserId() == userId) {
            return currentNode;
        }
        currentNode = currentNode->getNextNode(); 
    }
    return nullptr;
}
