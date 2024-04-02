#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
void applyOperation(std::vector<int>& numbers, std::function<int(int)> operation) {
    for (int& num : numbers) {
        num = operation(num);
    }
}

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    std::function<int(int)> add = [](int x) { return x + 10; };
    applyOperation(numbers, add);

    std::cout << "After adding 10 to each element: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::function<int(int)> multiply = [](int x) { return x * 2; };
    applyOperation(numbers, multiply);

    std::cout << "After multiplying each element by 2: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::function<int(int)> square = [](int x) { return x * x; };
    applyOperation(numbers, square);

    std::cout << "After squaring each element: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::function<int(int)> inverse = [](int x) { return (x != 0) ? 1 / x : 0; };
    applyOperation(numbers, inverse);

    std::cout << "After computing inverse of each element: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << "Sum of all elements: " << sum << std::endl;

    double average = static_cast<double>(sum) / numbers.size();
    std::cout << "Average of all elements: " << average << std::endl;

    int max_element = *std::max_element(numbers.begin(), numbers.end());
    int min_element = *std::min_element(numbers.begin(), numbers.end());
    std::cout << "Max element: " << max_element << std::endl;
    std::cout << "Min element: " << min_element << std::endl;

    std::vector<int> even_numbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(even_numbers), [](int x) { return x % 2 == 0; });
    std::cout << "Even numbers: ";
    for (int num : even_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted list in ascending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(numbers.rbegin(), numbers.rend());
    std::cout << "Sorted list in descending order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
