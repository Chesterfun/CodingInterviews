#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		int startIndex = 0, endIndex = nums.size() - 1;
		while (endIndex - startIndex >= 0) {
			if (startIndex == endIndex && target == nums[startIndex]) {
				return startIndex;
			}
			if (target == nums[(endIndex - startIndex) / 2 + startIndex]) {
				return (endIndex - startIndex) / 2 + startIndex;
			}
			else if (target > nums[(endIndex - startIndex) / 2 + startIndex]) {
				startIndex = (endIndex - startIndex) / 2 + startIndex + 1;
			}
			else {
				endIndex = (endIndex - startIndex) / 2 + startIndex - 1;
			}
		}
		return -1;
	}
};

int main() {
	vector<int> nums1 = { -1, 0, 3, 5, 9, 12};
	int target1 = 13;
	vector<int> nums2 = { -1, 8, 9, 14, 15};
	int target2 = 15;

	Solution solu;
	int search1 = solu.search(nums1, target1);
	int search2 = solu.search(nums2, target2);
	printf("search1: %d, search2: %d", search1, search2);
	return 0;
}