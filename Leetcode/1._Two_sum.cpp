#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        
    unordered_map < int, int > numMap;

    for (int i = 0; i < nums.size(); i++ ) {

        int complement = target - nums[i];
        if ( numMap.find(complement) != numMap.end() )
            return { numMap[complement], i};

        numMap[nums[i]] = i;
    }

    return {};

}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);
    
    cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    return 0;
}