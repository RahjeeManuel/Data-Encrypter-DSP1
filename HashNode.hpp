#ifndef HASHNODE_HPP
#define HASHNODE_HPP
#include <string>
class HashNode {
    private:
        std::string userId;
        std::string password;
        HashNode* nextNode;
    public:
        HashNode(std::string userId, std::string password);
        void setUserId(std::string userId);
        void setPassword(std::string password);
        void setNextNode(HashNode* nextNode);
        std::string getUserId();
        std::string getPassword();
        HashNode* getNextNode();
};
#endif