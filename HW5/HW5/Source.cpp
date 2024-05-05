#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void customSort(std::vector<T>& vec) {
    try {
        if (vec.empty()) {
            throw std::runtime_error("Vector is empty. Cannot sort.");
        }

        std::sort(vec.begin(), vec.end());

        // Имитация исключения при сортировке
        if (vec.size() > 1 && vec[0] > vec[1]) {
            throw std::runtime_error("Custom exception: Sorting failed.");
        }

        std::cout << "Sorted vector: ";
        for (const auto& elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}

int main() {
    std::vector<int> pusto = { };
    std::vector<int> numbers = {2};

    customSort(pusto);
    customSort(numbers);

    return 0;
}
