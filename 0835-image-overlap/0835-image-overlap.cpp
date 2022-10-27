class Solution {
public:
   int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		vector<pair<int,int>> arr1;
		vector<pair<int,int>> arr2;
       
		for (int i = 0; i < img1.size(); i ++) {
			for (int j = 0; j < img1.size(); j ++) {
				if (img1[i][j] == 1) {
					arr1.push_back({i,j});
				}
				if (img2[i][j] == 1) {
					arr2.push_back({i,j});
				}
			}
		}
       
		int res = 0;
		map<pair<int, int>, int> mp;
       
		for (auto &i: arr1) {
			for (auto &j: arr2) {
				int x = i.first - j.first;
				int y = i.second - j.second;
                
				mp[{x, y}] ++;
				res=max(res, mp[{x,y}]);
			}
		}
       
		return res;
	}
};