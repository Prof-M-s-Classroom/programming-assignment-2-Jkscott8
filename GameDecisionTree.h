#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {
        root = nullptr;
    }

    void insert(Story s, Node<T>* tempNode) {
        Node<T>* insertNode = new Node<T>(s);
        if (insertNode->key == tempNode->key-1) {
            Node<T>* tempNode2 = tempNode->left;
            Node<T>* tempNode3 = tempNode->right;
            tempNode2->right = insertNode;
            tempNode3->left = insertNode;
            return;
        }
        if(insertNode->key == tempNode->leftkey) {
            tempNode -> left = insertNode;
            return;
        }
        if(insertNode->key == tempNode->rightkey) {
            tempNode -> right = insertNode;
            return;
        }
        if (insertNode->key > tempNode->key) {
            insert(s, tempNode->right);
        }
        else {
            insert(s, tempNode->left);
        }
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        string line;
        string event, decription, left, right;
        ifstream file (filename);
        int length = 0;
        if (file.is_open())
        {
            while (getline(file, line)) {
                length++;
            }
            file.close();
            file.open(filename);
            getline(file, event, delimiter);
            getline(file, decription, delimiter);
            getline(file, left, delimiter);
            getline(file, right, delimiter);
            int eventnum = stoi(event);
            int leftnum = stoi(left);
            int rightnum = stoi(right);
            Story rootStory = Story(decription, eventnum, leftnum, rightnum);
            Node<Story>* rootNode = new Node<T>(rootStory);
            root = rootNode;
            for (int i = 0; i < length-1; i++) {
                getline(file, event, delimiter);
                getline(file, decription, delimiter);
                getline(file, left, delimiter);
                getline(file, right, delimiter);
                int eventnum = stoi(event);
                int leftnum = stoi(left);
                int rightnum = stoi(right);
                Story s = Story(decription, eventnum, leftnum, rightnum);
                insert(s, root);
            }
            file.close();
        }
        else cout << "Unable to open file";

    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        cout << "Welcome to the RPG" << endl;
        Node<Story>* gameNode = root;
        int input;
        while (gameNode != nullptr) {
            if (gameNode->leftkey == -1 && gameNode->rightkey == -1) {
                cout << gameNode->desc << endl;
                cout << "Game Over :(" << endl;
                return;
            }
            if (gameNode->leftkey == 0 && gameNode->rightkey == 0) {
                cout << gameNode->desc << endl;
                cout << "You Win!" << endl;
                return;
            }
            cout << gameNode -> desc << endl;
            cout << "Option 1 or 2: ";
            cin >> input;
            cout << input << endl;
            if (input == 1) {
                gameNode = gameNode -> left;
            }
            else if (input == 2) {
                gameNode = gameNode -> right;
            }
            else {
                gameNode = gameNode -> left;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H
