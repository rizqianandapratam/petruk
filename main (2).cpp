#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[minIdx], arr[i]);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for(int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j < high; ++j) {
        if(arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for(int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::vector<int> bubbleArr = arr;
    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleArr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> bubbleDuration = end - start;
    std::cout << "Bubble Sort: ";
    printArray(bubbleArr);
    std::cout << "Time taken: " << bubbleDuration.count() << " μs" << std::endl;

    std::vector<int> insertionArr = arr;
    start = std::chrono::high_resolution_clock::now();
    insertionSort(insertionArr);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> insertionDuration = end - start;
    std::cout << "Insertion Sort: ";
    printArray(insertionArr);
    std::cout << "Time taken: " << insertionDuration.count() << " μs" << std::endl;

    std::vector<int> selectionArr = arr;
    start = std::chrono::high_resolution_clock::now();
    selectionSort(selectionArr);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> selectionDuration = end - start;
    std::cout << "Selection Sort: ";
    printArray(selectionArr);
    std::cout << "Time taken: " << selectionDuration.count() << " μs" << std::endl;

    std::vector<int> mergeArr = arr;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> mergeDuration = end - start;
    std::cout << "Merge Sort: ";
    printArray(mergeArr);
    std::cout << "Time taken: " << mergeDuration.count() << " μs" << std::endl;

    std::vector<int> quickArr = arr;
    start = std::chrono::high_resolution_clock::now();
    quickSort(quickArr, 0, quickArr.size() - 1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> quickDuration = end - start;
    std::cout << "Quick Sort: ";
    printArray(quickArr);
    std::cout << "Time taken: " << quickDuration.count() << " μs" << std::endl;

    return 0;
}
