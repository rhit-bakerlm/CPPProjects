#pragma once

#include <string>

class BinaryNode {
    public:
        BinaryNode(int data);

        int height();
        BinaryNode* remove(int data, bool* success);
        bool insert(int data);
        std::string toString();
        
        ~BinaryNode();
    
    private:
        int data;

        BinaryNode* left;
        BinaryNode* right;
};

class BinaryTree {
    public:
        BinaryTree();

        bool insert(int data);
        bool remove(int data);
        bool isEmpty();
        int height();
        int size();
        std::string toString();

        ~BinaryTree();

    private:
        BinaryNode* root;
        int internalSize;
};