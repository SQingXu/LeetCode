#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        // First need to get highest bounds for current index of both right and left.
        std::vector<int> leftHighestBounds;
        std::vector<int> rightHighestBounds;
        rightHighestBounds.resize(height.size());
        int leftHighest = 0;
        int rightHighest = 0;
        for (size_t index = 0; index < height.size(); ++index)
        {
            auto lIndex = index;
            auto rIndex = height.size() - 1 - index;
            
            leftHighestBounds.push_back(leftHighest);
            rightHighestBounds[rIndex] = rightHighest;
            
            auto lElement = height[lIndex];
            leftHighest = (lElement > leftHighest) ? lElement : leftHighest;
            
            auto rElement = height[rIndex];
            rightHighest = (rElement > rightHighest) ? rElement : rightHighest;            
        }
        
        int res = 0;
        for (size_t index = 0; index < height.size(); ++index)
        {
            res += std::max(std::min(leftHighestBounds[index], rightHighestBounds[index]) - height[index], 0);
        }
        return res;
    }
};