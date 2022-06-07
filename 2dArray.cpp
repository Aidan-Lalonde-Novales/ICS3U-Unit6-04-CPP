// Copyright (c) 2022 Aidan Lalonde-Novales All rights reserved

// Created by Aidan Lalonde-Novales
// Created on 2022-06-07
// This program generates two arrays and finds the average.

#include <iostream>
#include <iomanip>
#include <random>
#include <array>


template <int rows, int cols>
float FindAverage(int (&passedin2DArray)[rows][cols]) {
    // this function finds the average of numArray

    int total = 0;
    float numQuantity = 0;

    for (size_t rowAdder = 0; rowAdder < rows; ++rowAdder) {
        for (size_t columnAdder = 0; columnAdder < cols; ++columnAdder) {
            total += passedin2DArray[rowAdder][columnAdder];
            numQuantity += 1;
        }
    }

    float average = total / numQuantity;

    return average;
}


int main() {
    // this function generates a row/column array, calls a function to
    // calculate average, then outputs the average

    int randomNum = 0;
    float average = 0;
    const int rows = 3;
    const int cols = 6;
    int numArray[rows][cols];

    // random seed
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne twister
    std::uniform_int_distribution<int> idist(0, 50);  // random from 0 - 50

    std::cout <<
    "This program calculates the average of a 2D array.\n"
    << std::endl;

    // no input is available in c++ for a 2d array

    // process and output
    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for (int colCounter = 0; colCounter < cols; colCounter++) {
            randomNum = idist(rgen);
            numArray[rowCounter][colCounter] = randomNum;
            std::cout << randomNum << " ";
        }
        std::cout << std::endl;
    }

    average = FindAverage(numArray);

    // output
    std::cout << "\nThe average of all numbers is " << std::fixed <<
    std::setprecision(2) << std::setfill('0') << average << "." << std::endl;

    std::cout << "\nDone." << std::endl;
}
