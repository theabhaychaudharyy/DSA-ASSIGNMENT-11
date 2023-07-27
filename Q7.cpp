#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements that are out of the current window from the front of the deque
        while (!window.empty() && window.front() < i - k + 1) {
            window.pop_front();
        }

        // Remove elements that are smaller than the current element from the back of the deque
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }

        // Add the current element's index to the back of the deque
        window.push_back(i);

        // The front of the deque contains the index of the maximum element within the current window
        if (i >= k - 1) {
            result.push_back(nums[window.front()]);
        }
    }

    return result;
}

int main() {
    // Example usage:
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = maxSlidingWindow(nums, k);
    std::cout << "Output: [";
    for (int num : result) {
        std::cout << num << ", ";
    }
    std::cout << "]" << std::endl; // Output: [3, 3, 5, 5, 6, 7]

    return 0;
}
