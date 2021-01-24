#include "HashNode.hpp"
HashNode::HashNode(std::string userId, std::string password) {
    this->userId = userId;
    this->password = password;
    nextNode = nullptr;
}
void HashNode::setUserId(std::string userId) {
    this->userId = userId;  
}
void HashNode::setPassword(std::string password) {
    this->password = password; 
}
void HashNode::setNextNode(HashNode* nextNode) {
    this->nextNode = nextNode;
}
std::string HashNode::getUserId() {
    return userId;
}
std::string HashNode::getPassword() {
   return password; 
}
HashNode* HashNode::getNextNode() {
    return nextNode;
}