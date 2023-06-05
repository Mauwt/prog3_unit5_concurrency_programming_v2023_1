//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_FACTORIAL_H
#define PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_FACTORIAL_H

#include <vector>
#include <thread>
#include <numeric>
using namespace std;

// Function to calculate the factorial of a number
template<typename T>
T factorial(unsigned int n) {
    T result = 1;
    for (auto i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate the factorial in parallel
template<typename T>
T parallelFactorial(unsigned int n, unsigned int numThreads) {
    vector<thread> threads;
    vector<T> results(numThreads, 1);

    // Divide the work among the threads
    for (unsigned int i = 0; i < numThreads; ++i) {
        unsigned int start = (n / numThreads) * i + 1;
        unsigned int end = (i == numThreads - 1) ? n : (n / numThreads) * (i + 1);

        threads.emplace_back([start, end, &results, i]() {
            for (unsigned int j = start; j <= end; ++j) {
                results[i] *= j;
            }
        });
    }

    // Wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }

    // Combine the results from all threads
    T result = accumulate(begin(results), end(results), 1, multiplies<T>());

    return result;
}


#endif //PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_FACTORIAL_H
