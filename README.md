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

- Each line in the txt file represents an event in the story. Each event has a key, description, and it's children node keys all separated by delimiters. The code uses these delimiters to split up the line so each object goes into a variable. It then constructs the Story object with each variable in the correct location.
- First it checks if the current nodes child keys match the insert key, if it does it links it to the spot. If not it uses binary tree creation where if if the insert key is larger than the current key it goes right, if it's smaller it goes left. Then it repeats this process until everything is inserted. There is the special case where it links two events to the same child, to do this the key needs to be one less than the grandparent where it then knows to attach it to both parent nodes instead of just one.  
- If the node has -1 for both children then it denotes game over and a loss, if both children are 0 it denotes a win. I made the endings new story objects instead of just having a -1 end the game so that I could add description detailing why it was a loss or win.  

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- Each story description has an option one and two, clearly labled like (1) option one (2) option two. They just enter a one or a two depending on which one they want. Then it will move down the tree left if it's one and right if it's two.
- I had it so it keep re-prompting the user to select 1 or 2 if the input is different, but the git-hub autograder would run an infinite loop with that code so I changed it to just go left if the input is wrong.
- If a player reaches a leaf node the game ends, it prints the node description which details the ending that the user got. For example: (You hit it in the head; the wolf squeals and runs away. You keep walking and make it out.)
- The special case where multiple events lead to the same outcome works just like the rest of the tree except you can get it from going different paths, in this case there is a potential encounter with a bear and depending on if you run or swim to try and get away, it gets you anyways. 

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- The file is read and parsed using "|" as a delimiter by the code reading in each line and splitting the line into 4 parts and then assigning each part to a variable which then creates a story object.
- To ensure nodes are properly linked, it won't link the node unless the event key matches the left or right child event key for the parent node.
- The main challenge I faced when reading the file was making sure all the lines were formmated correctly otherwise it would cause an error, I also had trouble reading the txt to test the code because it wouldn't work unless the txt file was in the cmakedebug folder. It works like intended though on github, so the issue was something locally.

---

## **6. Debugging Process (Errors & Fixes)**
1. Problem: Wasn’t getting any errors, but the story.txt wasn’t getting read in correctly

- Fix: It was reading in from the cmake-build-debug file so I just moved it there

2. Problem: Delimiter wasn’t working
- Fix: Put it inside the getline() function

3. Problem: error: 'T' does not refer to a value
Fix: I didn’t need the Story<T> just Story

4. Problem: candidate constructor not viable: no known conversion from 'string' (aka 'basic_string<char>') to 'int' for 2nd argument
- Fix: Convert to int by using stoi()

5. Problem: libc++abi: terminating due to uncaught exception of type std::invalid_argument: stoi: no conversion
- Fix: There was no | delimiter at the end so it continued to read into the next line, causing the description to be the first thing for the next story. To fix it I added elmiters to the end of the lines too.

6. Problem:  libc++abi: terminating due to uncaught exception of type std::invalid_argument: stoi: no conversion

- Fix: This came up again because I was reading to the end of the file, but to do that it goes till it reads the last line twice, so instead I just went through it one time to count how many lines then used that instead

7. Problem: Process finished with exit code 139 (interrupted by signal 11:SIGSEGV)
- Fix: My vector insert was wrong, changed from events.instert(s) to events.push_back(s)

8. Problem: no matching constructor for initialization of 'Node<Story>'
- Fix: I tweaked the node code so it held all the values of Story separately \

9. Problem: Sigsev error when recursively calling the insert function
- Fix: I had it move the temp node inside the function call instead of outside, not sure why that fixed it but it works.

10. Problem: 'Story.h' file not found with <angled> include; use "quotes" instead
- Fix: Not sure why that was there, it wasn't in the initial commit so I deleted it.

11. Problem: error: linker command failed with exit code 1
- Fix: Something with the way Clion was compiling it wasn’t working, but it worked in the terminal fine.
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

- **Loading the tree from the file** → `O(N^2)`
- It is Nlog(N) because it goes through the file to check the length so N, then it goes through each line and creates a story object, node, and inserts it which is usually Nlog(N) because it loops N times for each line, and then insert could take as long as the height of the tree which is usally log(n), but could be up to N. So: N + N*N 
- **Searching for an event in the tree** → `O(N)`
- Since the tree is sorted by the key, it could end up just being the height equal to the amount of nodes since there is no balancing methods.
- **Game traversal efficiency** → `O(N)`
- It O(H) where H is the height of the tree, but like mentioned earlier it could be the height equal to N nodes so it's O(N), with this certain text file it is only NlogN. 

---

## **9. Edge Cases & Testing**
I tested what happens if a user inputs something that isn't one or two, and it did re-prompt to enter only one or two, but like I mentioned earlier I had to change it for the github autograder, so instead is just goes to the left if the input isn't one or two.
Another one I tested was what if the file doesn't load right, and it correctly displayed a message telling the user the file didn't work. 

---

## **10. Justification of Additional Features (If Any)**
I added an insert helper function for building the tree, the function recursivley calls itself to check each level till the node is inserted, I could have just made it a loop inside the build tree function, but it was working so I didn't want to mess with anything.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
