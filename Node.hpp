#ifndef NODE_HPP
#define NODE_HPP
#include <string>
class Node {
    private:
        std::string userId;
        std::string password;
        Node* nextNode;
    public:
        Node(std::string userId, std::string password);
        void setUserId(std::string userId);
        void setPassword(std::string password);
        void setNextNode(Node* nextNode);
        std::string getUserId();
        std::string getPassword();
        Node* getNextNode();
};
#endif