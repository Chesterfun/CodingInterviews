#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int curMin = prices[0];
		int maxPro = 0;
		for (int i = 0; i < prices.size(); i++) {
			maxPro = max(maxPro, prices[i] - curMin);
			curMin = min(curMin, prices[i]);
		}
		return maxPro;
	}
};

int main() {
	vector<int> nums1 = { 1, 2, 3, 2, 9, 3, 10};
	vector<int> nums2 = { 7, 7, 6, 4 };

	Solution solu;
	int profit1 = solu.maxProfit(nums1);
	int profit2 = solu.maxProfit(nums2);
	printf("profit1: %d, profit2: %d", profit1, profit2);
	return 0;
}