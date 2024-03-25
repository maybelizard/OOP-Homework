#include <iostream>
#include "Sort.h"

int main() {
    Sort v1(10, 40, 983);
    Sort v2 = { 3, 6, 1, 356, 34, 8, 7 };
    int v[] = { 2, 6, 243, 6, 3 };
    Sort v3(v, 5);
    Sort v4(8, 42, 456, 2, 675, 8, 0, -9, -4);
    Sort v5("40,23,76,934,652,1,3");
    std::cout << v1.GetElementsCount() << " numbers: ";
    v1.Print();
    std::cout << v2.GetElementsCount() << " numbers: ";
    v2.Print();
    std::cout << v3.GetElementsCount() << " numbers: ";
    v3.Print();
    std::cout << v4.GetElementsCount() << " numbers: ";
    v4.Print();
    std::cout << v5.GetElementsCount() << " numbers: ";
    v5.Print();
    std::cout << '\n';

    v1.InsertSort(true);
    v1.Print();

    v2.QuickSort(true);
    v2.Print();

    v3.BubbleSort(true);
    v3.Print();

    v4.InsertSort();
    v4.Print();

    v5.QuickSort();
    v5.Print();

    Sort v6(5, 1, 10);
    v6.BubbleSort();
    v6.Print();

    std::cout << '\n' << v4.GetElementFromIndex(5) << " " << v6.GetElementFromIndex(2) << " " << v3.GetElementFromIndex(0);
}