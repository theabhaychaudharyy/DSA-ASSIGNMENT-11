#include <iostream>
#include <string>
#include <stack>

std::string makeGood(std::string s) {
    std::stack<char> charStack;

    for (char c : s) {
        // Check if the current character forms a bad pair with the top of the stack.
        if (!charStack.empty() && std::abs(c - charStack.top()) == 32) {
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
    std::string s = "leEeetcode";
    std::string result = makeGood(s);
    std::cout << "Output: " << result << std::endl; // Output: "leetcode"

    return 0;
}
