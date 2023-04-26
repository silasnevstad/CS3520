#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <vector>

// Function to compute the n-th Fibonacci number using recursion
unsigned long long fibonacci(unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to execute the Fibonacci function in parallel using 3 threads and measure execution time
void parallel_execution(const std::vector<unsigned int>& numbers) {
    std::vector<std::future<std::pair<std::thread::id, unsigned long long>>> futures(numbers.size());

    auto start_time = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < numbers.size(); ++i) {
        futures[i] = std::async(std::launch::async, [](unsigned int n) {
            return std::make_pair(std::this_thread::get_id(), fibonacci(n));
        }, numbers[i]);
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        auto result = futures[i].get();
        std::cout << "Thread " << i + 1 << " ID: " << result.first << ", Fibonacci(" << numbers[i] << "): " << result.second << '\n';
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Parallel execution time: " << duration << " milliseconds\n";
}


// Function to execute the Fibonacci function sequentially and measure execution time
void sequential_execution(const std::vector<unsigned int>& numbers) {
    // Record the start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Calculate and print the Fibonacci numbers sequentially
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "Fibonacci(" << numbers[i] << "): " << fibonacci(numbers[i]) << '\n';
    }

    // Record the end time and calculate the duration
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Sequential execution time: " << duration << " milliseconds\n";
}

int main() {
    // Ask the user to input 3 numbers higher than 30
    std::vector<unsigned int> numbers(3);
    std::cout << "Enter 3 numbers higher than 30: ";
    for (unsigned int& number : numbers) {
        std::cin >> number;
    }

    // Call the parallel and sequential execution functions
    parallel_execution(numbers);
    sequential_execution(numbers);

    return 0;
}
