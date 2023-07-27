#include <iostream>
#include <string>
#include <stack>

std::string removeDuplicates(std::string s) {
    std::stack<char> charStack;

    for (char c : s) {
        // Check if the current character is equal to the top of the stack.
        if (!charStack.empty() && charStack.top() == c) {
            charStack.pop(); // Remove the character from the stack.
        } else {
            charStack.push(c); // Push the character onto the stack.
        }
    }

    // Construct the resulting string from the stack.
    std::string result;
    while (!charStack.empty()) {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}

int main() {
    // Example usage:
    std::string s = "abbaca";
    std::string result = removeDuplicates(s);
    std::cout << "Output: " << result << std::endl; // Output: "ca"

    return 0;
}
