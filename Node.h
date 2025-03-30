#ifndef NODE_H
#define NODE_H
using namespace std;
#include <string>

template <typename T>
class Node {
public:
    T data;
    string desc;
    int key;
    int leftkey;
    int rightkey;
    Node* left;
    Node* right;

    Node(T value) : data(value),left(nullptr), right(nullptr) {
        key = value.eventNumber;
        leftkey = value.leftEventNumber;
        rightkey = value.rightEventNumber;
        desc = value.description;
        this -> left = nullptr;
        this-> right = nullptr;

    }

};

#endif // NODE_H
