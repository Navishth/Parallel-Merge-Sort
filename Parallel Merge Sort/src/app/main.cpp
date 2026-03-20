#include <iostream>
#include "mergeSort.hpp"
#include<chrono>
int main(int argc, char *argv[]){

    const int SIZE=1000;
    std::vector<int> nums(SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        nums[i]=rand()%1000;

    }
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration = end-start;
    std::cout<<"MergeSort Algorithm time taken: "<<mergesortDuration.count()<<" seconds"<<std::endl;

    delete mergesort;
}