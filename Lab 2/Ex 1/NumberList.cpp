#include <iostream>
#include <algorithm>
#include "NumberList.h"

void NumberList::Init() {            // count will be 0
    for (int i = 0; i < 10; i++)
        numbers[i] = 0;
    count = 0;
}

bool NumberList::Add(int x) {     // adds X to the numbers list and increase the data member count.
    if (count >= 10)              // if count is bigger or equal to 10, the function will return false
        return false;
    numbers[count] = x;
    count++;
    return true;
}

void NumberList::Sort() {          // will sort the numbers vector
    std::sort(numbers, numbers + count);
}

void NumberList::Print() {         // will print the current vector
    for (int i = 0; i < count; i++)
        std::cout << numbers[i] << " ";
    std::cout << '\n';
}