#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];
		map<int, int> m;
		for (auto n : nums)
		{
			if (m.find(n) == m.end())
			{
				m.insert(pair<int, int>(n, n));
			}
			else
			{
				m.erase(n);
			}
		}
		return m.begin()->first;
	}
};

class Solution2{
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int num : nums)
		{
			result ^= num;
		}
		return result;
	}
};