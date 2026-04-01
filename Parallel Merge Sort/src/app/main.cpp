#include <iostream>
#include "MergeSort/mergeSort.hpp"
#include "ParallelMergeSort/parallelmergeSort.hpp"
#include<chrono>
int main(int argc, char *argv[]){

    const int SIZE=100000000;
    std::vector<int> nums(SIZE);
     std::vector<int> nums1(SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        nums[i]=rand()% 1000000;
        nums1[i]=nums[i];
 
    }
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration = end-start;
    std::cout<<"MergeSort Algorithm time taken: "<<mergesortDuration.count()<<" seconds"<<std::endl;

    delete mergesort;

    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    end = std::chrono::high_resolution_clock::now();
    mergesortDuration = end-start;
    std::cout<<"Parallel MergeSort Algorithm time taken: "<<mergesortDuration.count()<<" seconds"<<std::endl;

    delete mergesort1;
}