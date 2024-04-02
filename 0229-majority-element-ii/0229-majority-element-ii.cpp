class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = nums[0];
        int majority2 = -1; // Initialize majority2 to -1 to indicate no second candidate
        int votes1 = 1;
        int votes2 = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority1) {
                votes1++;
            } else if (votes2 > 0 && nums[i] == majority2) {
                votes2++;
            } else if (votes1 == 0) {
                majority1 = nums[i];
                votes1++;
            } else if (votes2 == 0) {
                majority2 = nums[i];
                votes2++;
            } else {
                votes1--;
                votes2--;
            }
        }

        // Recount to confirm majority (and handle no majority case)
        votes1 = 0;
        votes2 = 0;
        int minCount = (nums.size() / 3) + 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority1) {
                votes1++;
            } else if (nums[i] == majority2) {
                votes2++;
            }
        }

        vector<int> result;
        if (votes1 >= minCount) {
            result.push_back(majority1);
        }
        if (votes2 >= minCount && majority2 != -1) { // Only add majority2 if it's valid
            result.push_back(majority2);
        }

        return result;
    }
};
