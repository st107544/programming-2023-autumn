#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
void customSort(std::vector<T>& arr) {
    try {
        if (arr.empty()) {
            throw std::invalid_argument("Vector is empty. Cannot sort.");
        }

        std::sort(arr.begin(), arr.end());

        if (arr.size() > 1000) {
            throw std::length_error("Vector size is too large. Maximum size allowed is 1000.");
        }


    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    }
    catch (const std::length_error& e) {
        std::cerr << "Length error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

int main() {
    std::vector<int> intVec = { 64, 34, 25, 12, 22, 11, 90 };

    try {
        customSort(intVec);

        for (const auto& num : intVec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
