class Solution {
   public:
   bool ok(int x, vector <int> &nums, int th){
      int sum = 0;
      for(int i = 0; i < nums.size(); i++){
         sum += ceil((double)nums[i]/(double)x);
      }
      return sum<=th;
   }
   int smallestDivisor(vector<int>& nums, int th) {
      int low = 1;
      int high = 1e7;
      while(low < high){
         int mid = low + (high - low)/2;
         if(ok(mid, nums, th)){
            high = mid;
         }else low = mid + 1;
      }
      return high;
   }
};
