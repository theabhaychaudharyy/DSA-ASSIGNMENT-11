#include <iostream>
#include <stack>
#include <vector>

class StockSpanner {
    std::stack<std::pair<int, int>> priceStack;

public:
    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!priceStack.empty() && priceStack.top().first <= price) {
            span += priceStack.top().second;
            priceStack.pop();
        }

        priceStack.push({price, span});
        return span;
    }
};

int main() {
    // Example usage:
    StockSpanner stockSpanner;
    std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    std::cout << "Output: [";
    for (int price : prices) {
        std::cout << stockSpanner.next(price) << ", ";
    }
    std::cout << "]" << std::endl; // Output: [1, 1, 1, 2, 1, 4, 6]

    return 0;
}
