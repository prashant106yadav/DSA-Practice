// LeetCode #1 — Two Sum

// Question:

// Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.

// You may assume that:

// Each input has exactly one solution.
// You cannot use the same element twice.
// You can return the answer in any order.


// *** Approach 1 :- Brute Force ***


#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size(); i++) {

        for (int j = i + 1; j < nums.size(); j++) {

            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {};
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}





// *** Approach 2 :- Optimal ***

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];

        if (mp.find(needed) != mp.end()) {
            return {mp[needed], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}