#include <iostream>
#include <vector>
#include <stack>

int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    std::stack<int> st; // Stack to store indices of bars
    int maxArea = 0;

    for (int i = 0; i <= n; ++i) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = std::max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    // Example usage:
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleArea(heights);
    std::cout << "Output: " << result << std::endl; // Output: 10

    return 0;
}
