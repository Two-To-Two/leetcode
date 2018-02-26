/*
 * 1. Two Sum
 */
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSumMySolution(std::vector<int>& nums, int target) {
        // using vType = remove_reference_t<decltype(nums)>::size_type;
        // unordered_map<int,vType> m ;

        std::unordered_map<int, int> hash_map;
        std::vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            hash_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int added = target - nums[i];
            auto added_idx = hash_map.find(added);
            if (added_idx != hash_map.end() && added_idx->second != i) {
                ret.push_back(i); ret.push_back(added_idx->second);
                return ret;
            }
        }
        return ret;
    }

    vector<int> twoSum3msSolution(vector<int>& nums, int target) {
        using SizeType = remove_reference_t<decltype(nums)>::size_type;
        using ValueToIndexMapType = unordered_map<int, SizeType>;
        ValueToIndexMapType map;
        vector<int> indices(2);
        for (SizeType index = 0; index < nums.size(); ++index)
        {
            const auto foundIterator = map.find(target - nums[index]);
            if (foundIterator != end(map) && foundIterator->second != index)
                return vector<int>{ index, foundIterator->second };
            else
                map.emplace(nums[index], index);
        }
        throw std::runtime_error("Solution not found");
    }
};

