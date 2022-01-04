class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int noPlatform = 0;
        int currPlatform = 0;
        int arrive = 0;
        int depart = 0;
        
        while (arrive < n && depart < n) {
            if (arr[arrive] <= dep[depart]) {
                currPlatform ++;
                arrive ++;
            } else {
                currPlatform --;
                depart ++;
            }
            noPlatform = max(noPlatform, currPlatform);
        }
        
        return noPlatform;
    }
};
