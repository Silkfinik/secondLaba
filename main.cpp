#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    std::cout << "Enter vector elements (0 to end): ";
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        vec.push_back(n);
    }
    int vec_size = vec.size();
    int* vec_ptr = vec.data();
    int sum = 0;
    _asm {
        mov esi, vec_ptr
        mov ecx, vec_size
        mov eax, 0
        loop_start:
            add eax, [esi]
            add esi, 4
            loop loop_start
        mov sum, eax
    }
    std::cout << "Vector elements: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << "\nSum of vector elements: " << sum << std::endl;
}