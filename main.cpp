#include <iostream>


int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "Enter array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Array elements: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    delete[] arr;
}