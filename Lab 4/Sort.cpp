#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include <random>
#include <cstring>
#include <iostream>
#include <string>
#include <stdarg.h>

Sort::Sort(int n, int mini, int maxi) {
    number = n;
    for (int i = 0; i < number; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(mini, maxi);
        array[i] = dist(gen);
    }
}

Sort::Sort(std::initializer_list<int> list) {
    number = list.size();
    std::copy(list.begin(), list.end(), array);
}

Sort::Sort(int v[], int n) {
    number = n;
    for (int i = 0; i < number; i++)
        array[i] = v[i];
}

Sort::Sort(int n, ...) {
    number = n;
    va_list args;
    va_start(args, n);
    for (int i = 0; i < number; i++)
        array[i] = va_arg(args, int);
    va_end(args);
}

Sort::Sort(const char* s) {
    char* word = new char[strlen(s)];
    strcpy(word, s);
    char* p = std::strtok(word, ",");
    number = 0;
    while (p != NULL) {
        array[number] = std::stoi(p);
        number++;
        p = std::strtok(NULL, ",");
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < number; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && (array[j] > key) == ascendent)
            array[j + 1] = array[j], j--;
        array[j + 1] = key;
    }
}

void QuickSortAux(int v[], int left, int right, bool ascendent) {
    if (left < right) {
        int m = (left + right) / 2;
        std::swap(v[left], v[m]);
        int i = left, j = right, d = 0;
        while (i < j)
        {
            if ((v[i] > v[j]) == ascendent)
            {
                std::swap(v[i], v[j]);
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSortAux(v, left, i - 1, ascendent);
        QuickSortAux(v, i + 1, right, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortAux(array, 0, number - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < number - 1; i++)
        for (int j = i + 1; j < number; j++)
            if ((array[i] > array[j]) == ascendent)
                std::swap(array[i], array[j]);
}

void Sort::Print() {
    for (int i = 0; i < number; i++)
        std::cout << array[i] << " ";
    std::cout << '\n';
}

int Sort::GetElementsCount() {
    return number;
}

int Sort::GetElementFromIndex(int index) {
    return array[index];
}