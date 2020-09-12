/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a mapping such that each pair is the target - value -> indices.
        std::unordered_map<int, int> maps;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto val = nums[i];
            if (maps.count(val) > 0)
            {
                return std::vector<int>{maps[val], static_cast<int>(i)};
            }
            maps[target - val] = i;
        }
        return std::vector<int>();
    }
};

