#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index1 = 0, index2 = 0;
		while (index2 < n) {
			if (nums2[index2] <= nums1[index1]) {
				nums1.insert(nums1.begin() + index1, nums2[index2]);
				nums1.pop_back();
				index2++;
			}
			else if (index1 >= m + index2) {
				nums1.insert(nums1.begin() + index1, nums2[index2]);
				nums1.pop_back();
				index2++;
			}
			index1++;
		}
	}
};

int main() {
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	vector<int> nums2 = { 2, 5, 6 };
	int m = 3, n = 3;

	Solution solu;
	solu.merge(nums1, m, nums2, n);
	for (int i = 0; i < nums1.size(); ++i) {
		printf("%d, ", nums1[i]);
	}
	return 0;
}