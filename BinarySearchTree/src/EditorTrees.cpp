#include <algorithm>

#include "EditorTrees.h"

BinaryNode::BinaryNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

int BinaryNode::height() {
    return 1 + std::max(left != nullptr ? left->height() : 0, right != nullptr ? right->height() : 0);
}
        
BinaryNode* BinaryNode::remove(int data, bool* success) {
    //successful removal
    if (this->data == data) {
        *success = true;

        if (left == nullptr && right == nullptr) return nullptr; 
        else if (left != nullptr && right == nullptr) return left;
        else if (left == nullptr && right != nullptr) return right;
        else {
            BinaryNode* maxOfLeft = left;
            while (left->right != nullptr) left = left->right;
            maxOfLeft->right = right;
            return left;
        }
    }
    else if (data > this->data) {
        right = right->remove(data, success);
        return this;
    }
    else {
        left = left->remove(data, success);
        return this;
    }
}
        
bool BinaryNode::insert(int data) {
    if (data > this->data) {
        if (right == nullptr) {
            right = new BinaryNode(data);
            return true;
        }
        else return right->insert(data);
    } 
    else if(data < this->data) {
        if (left == nullptr) {
            left = new BinaryNode(data);
            return true;
        }
        else return left->insert(data);
    }
    else return false;
}

std::string BinaryNode::toString() {
    std::string out = (left != nullptr ? left->toString() : "");
    out += std::to_string(data);
    out += " ";
    out += (right != nullptr ? right->toString() : "");

    return out;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
}

BinaryTree::BinaryTree() {
    root = nullptr;
}

bool BinaryTree::insert(int data) {
    if (isEmpty()) root = new BinaryNode(data);
    if (root->insert(data)) {
        internalSize++;
        return true;
    }
    
    return false;
}

bool BinaryTree::remove(int data) {
    if (isEmpty()) return false;

    bool success = false;

    root = root->remove(data, &success);

    if (success) internalSize--;

    return success;
}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

int BinaryTree::height() {
    if (isEmpty()) return 0;

    return root->height();
}

int BinaryTree::size() {
    return internalSize;
}

std::string BinaryTree::toString() {
    if (isEmpty()) return "";

    return root->toString();
}

BinaryTree::~BinaryTree() {
    delete root;
}