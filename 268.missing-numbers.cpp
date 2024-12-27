#include <numeric>
#include <vector>
#include <execution>
#include <ranges> // For std::views
#include <iostream> // For std::cout

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        int xors = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        int range_xor = std::reduce(std::execution::seq, std::views::iota(0, n + 1).begin(), std::views::iota(0, n + 1).end(), 0, std::bit_xor<int>());
        return xors ^ range_xor; // Crucial: XOR the two results
    }
};

void testMissingNumber(std::vector<int> nums, int expected) {
    Solution solution;
    int result = solution.missingNumber(nums);
    std::cout << "Test with input: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\nExpected: " << expected << ", Got: " << result << "\n";
    std::cout << (result == expected ? "PASS" : "FAIL") << "\n\n";
}

int main() {
    // Test cases
    testMissingNumber({3, 0, 1}, 2); // Expected output: 2
    testMissingNumber({0, 1}, 2); // Expected output: 2
    testMissingNumber({9,6,4,2,3,5,7,0,1}, 8); // Expected output: 8
    testMissingNumber({0}, 1); // Expected output: 1
    testMissingNumber({}, 0); // Expected output: 0

    return 0;
}
