class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ret;
        int sum=0;
        
        for (auto query:queries) {
            if (ret.size() == 0) {
                A[query[1]] = query[0] + A[query[1]];
                for (int a:A) if (a%2 == 0) sum += a;
            }
            else {
                if (A[query[1]] % 2 == 0) sum -= A[query[1]];
                A[query[1]] = query[0] + A[query[1]];
                if (A[query[1]] % 2 == 0) sum += A[query[1]];                
            }
            
            ret.push_back(sum);
        }
        
        return ret;
    }
};