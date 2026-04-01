#include "parallelmergeSort.hpp"
#include<thread>
#include<iostream>
#include<algorithm>
ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums){
    this->nums=nums;
}

ParallelMergeSort::~ParallelMergeSort(){};

void ParallelMergeSort::recursiveSort(int left,int right){

        const int THRESHOLD = 50000;
        
          if(left>=right){
            return;
        }
        
        if (right - left < THRESHOLD) {
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }
    

      
        int mid=left+(right-left)/2;       //we avoid (left + right)/2 due to integer overflow.
        std::thread thread_1([this, left, mid] { this->recursiveSort(left, mid); });
        std::thread thread_2([this, mid, right] { this->recursiveSort(mid + 1, right); });

        thread_1.join();
        thread_2.join();

         std::vector<int> result;
        int i=left;
        int j=mid+1;

          while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }

}

    void ParallelMergeSort::sort(){
         if ((*nums).size() == 0) {
        exit(1);
    }

    std::thread thread_1([this] { this->recursiveSort(0, (*nums).size() - 1); });
    thread_1.join();
    }

