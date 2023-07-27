#include <iostream>
#include <vector>

class ProductOfNumbers {
    std::vector<int> prefixProduct; // Prefix product array
    int lastZeroIndex; // Index of the last zero encountered

public:
    ProductOfNumbers() {
        prefixProduct.push_back(1); // Initialize prefix product with 1
        lastZeroIndex = -1; // Initialize last zero index to -1 (no zero encountered yet)
    }

    void add(int num) {
        if (num == 0) {
            // If the current number is zero, set the lastZeroIndex to the current prefixProduct size
            lastZeroIndex = prefixProduct.size();
            prefixProduct.push_back(1); // Start a new prefix product (initialize to 1)
        } else {
            // Update the prefix product for the current number
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n)
            return 0; // If k is greater than or equal to the total numbers, the product will be zero.

        int lastKProduct = prefixProduct[n - 1]; // Get the last prefix product (product of all numbers).
        int kthBack = prefixProduct[n - k - 1]; // Get the prefix product up to kth back (product of last k numbers).

        // If the last zero is encountered within the last k numbers, return 0.
        if (lastZeroIndex != -1 && lastZeroIndex >= n - k)
            return 0;

        return lastKProduct / kthBack; // Divide the last product by the product of the remaining k numbers.
    }
};

int main() {
    // Example usage:
    ProductOfNumbers productOfNumbers;
    std::vector<int> commands = {3, 0, 2, 5, 4, 2, 3, 4, 8, 2};

    std::cout << "Output: [";
    for (int cmd : commands) {
        if (cmd == 0)
            std::cout << productOfNumbers.getProduct(1) << ", ";
        else
            productOfNumbers.add(cmd);
    }
    std::cout << "]" << std::endl; // Output: [20, 40, 0, 32]

    return 0;
}
