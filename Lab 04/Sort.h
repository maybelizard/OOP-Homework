#pragma once
#include <initializer_list>
#include <iostream>

class Sort {
    int number, array[100];
public:
    Sort(int n, int mini, int maxi);
    Sort(std::initializer_list<int> list);
    Sort(int v[], int n);
    Sort(int n, ...);
    Sort(const char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};