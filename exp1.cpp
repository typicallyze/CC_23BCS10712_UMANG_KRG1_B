#include <vector>

class Solution {
public:
    int triangularSum(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int length = n; length > 1; --length) {
            
            for (int i = 0; i < length - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
  
        return nums[0];
    }
};
