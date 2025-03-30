[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** Jackson Scott  
### **Student ID:** 129967055  

---

## **1. Project Overview**
This game is a simple RPG where you are dropped in the middle of a forest and you have to find your way home. You are faced with binary decisions along the way that affect the path your story will take. It does this by using a txt file to read in the events and their keys, they are then turned into story objects that become nodes in the tree. The it starts the game which reads in the root node, and displays the description stored in that node. From the descirption the users are given two options and are prompted to enter 1 or 2 and depending on what they pick it traverses the tree based off the decisions. This allows for re-playability since they can pick a new path down the tree everytime.  

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → The main.cpp files function is the commands to execute the code to set up and run the game, it allows the user to run the game all in one click
- **`GameDecisionTree.h`** → The game decision tree file holds the game decision tree class which creates the decision tree which is like the skeleton of the game. It also contains the associated functions to read in the text file to create the nodes and fill in the tree, and the function to run the game using the decision tree, allowing user input to make choices.
- **`Node.h`** → This file contains the node class, the node is made to take in the story class from the Story.h file so those objects can be made into the tree, the nodes hold all the needed values including the event key, the children event keys, and the event description from each story object. These nodes are used to build the tree so the user can easily traverse through the tree.
- **`Story.h`** → The story.h file has the Story class, the story class is where the text is converted into the node keys and the description and held in the story objects. The story objects are to be implemented into nodes where they can build the decision tree. 
- **`story.txt`** → The story.txt file holds the game events, where each event is a line, with in each line is a 3 integer values and a description all seperated by the delimiter "|", this delimiter allows the text to be read in and split into the correct parts, the event number, description, and its two child nodes event number. This is used in the game decision tree file to build the Story objects to make the tree nodes. 

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
You wake up alone in a forest, with no memory of how you got there. All you know is that you have to get home in time for dinner. (1) Follow down the stream (2) Walk deeper into the forest
Option 1 or 2: 1
You follow down the stream and you see a bear fishing in the river. (1) Calmly walk past (2) Run away
Option 1 or 2: 1
You keep walking and the bear doesn’t react. You then see a boat downstream, but also some people having a picnic in the forest. (1) Try to get the boat’s attention (2) Go to the people
Option 1 or 2: 2
The people having a picnic turn out to be vampires and they come at you. You see a knife and a stick on the ground. (1) Pick up the stick (2) Pick up the knife
Option 1 or 2: 2
The knife doesn’t affect the vampires, and they bite you and take all your blood.
Game Over :(

Process finished with exit code 0

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)`  
- **Searching for an event in the tree** → `O(?)`  
- **Game traversal efficiency** → `O(?)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
