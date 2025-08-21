class Solution {
    private:
    bool isposs(int mid, vector<int>& arr, int k) {
        int count = 1;  // place first element
        int f = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - f >= mid) {
                count++;
                f = arr[i];
            }
        }
        return count >= k;
    }
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int ans = 0;
        sort(arr.begin(), arr.end());
        int l = 0, high = arr[n-1] - arr[0];
        while (l <= high) {
            int mid = l + (high - l) / 2;
            if (isposs(mid, arr, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
