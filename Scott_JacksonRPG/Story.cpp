#include "Story.h"
#include <ios>


Story::Story() : description(""), eventNumber(0), leftEventNumber(-1), rightEventNumber(-1) {
        description = "";
        eventNumber = 0;
        leftEventNumber = -1;
        rightEventNumber = -1;
}


Story::Story(std::string desc, int num, int leftNum, int rightNum)
        : description(desc), eventNumber(num), leftEventNumber(leftNum), rightEventNumber(rightNum) {
        description = desc;
        eventNumber = num;
        leftEventNumber = leftNum;
        rightEventNumber = rightNum;
}