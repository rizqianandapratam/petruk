#include <iostream>
#include <chrono>
#include <vector>

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_dynamic(int n) {
    if (n <= 1)
        return n;
    std::vector<int> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

double measure_execution_time(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

int main() {
    int n_values[] = {10, 25, 30, 40, 50};
    int size = sizeof(n_values) / sizeof(n_values[0]);
    
    std::cout << "Hasil Fibonacci menggunakan pendekatan rekursif:\n";
    for (int i = 0; i < size; ++i) {
        int n = n_values[i];
      
        auto start_recursive = std::chrono::steady_clock::now();
        int result_recursive = fibonacci_recursive(n);
        auto end_recursive = std::chrono::steady_clock::now();
        
        double time_recursive = measure_execution_time(start_recursive, end_recursive);
        
        std::cout << "Fibonacci(" << n << ") = " << result_recursive << " (Time: " << time_recursive << " seconds)\n";
    }
    
    std::cout << "\n";
    
    std::cout << "Hasil Fibonacci menggunakan pendekatan dynamic programming:\n";
    for (int i = 0; i < size; ++i) {
        int n = n_values[i];

        auto start_dynamic = std::chrono::steady_clock::now();
        int result_dynamic = fibonacci_dynamic(n);
        auto end_dynamic = std::chrono::steady_clock::now();
        
        double time_dynamic = measure_execution_time(start_dynamic, end_dynamic);
        
        std::cout << "Fibonacci(" << n << ") = " << result_dynamic << " (Time: " << time_dynamic << " seconds)\n";
    }
    
    return 0;
}
