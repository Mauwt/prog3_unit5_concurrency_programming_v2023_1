//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_MERGE_SORT_H
#define PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_MERGE_SORT_H
#include <vector>
#include <thread>
using namespace std;

// cntto merge two sorted sub vectors into a single sorted subarray
template<typename Container, typename T = typename Container::value_type>
void merge(Container& cnt, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> left_cnt(n1);
    vector<T> right_cnt(n2);

    for (int i = 0; i < n1; ++i) {
        left_cnt[i] = cnt[left + i];
    }

    for (int j = 0; j < n2; ++j) {
        right_cnt[j] = cnt[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (left_cnt[i] <= right_cnt[j]) {
            cnt[k] = left_cnt[i];
            ++i;
        } else {
            cnt[k] = right_cnt[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        cnt[k] = left_cnt[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        cnt[k] = right_cnt[j];
        ++j;
        ++k;
    }
}

template<typename Container, typename T = typename Container::value_type>
void concurrent_merge_sort(Container& cnt, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Divide the work into two subtasks
        thread left_thread(concurrent_merge_sort<Container>, ref(cnt), left, mid);
        thread right_thread(concurrent_merge_sort<Container>, ref(cnt), mid + 1, right);

        // Wait for both subtasks to finish
        left_thread.join();
        right_thread.join();

        // Merge the sorted sub vectors
        merge(cnt, left, mid, right);
    }
}

#endif //PROG3_UNIT5_CONCURRENCY_PROGRAMMING_V2023_1_MERGE_SORT_H
