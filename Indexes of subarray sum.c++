class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        vector<int>ans;
        for(int start=0;start<arr.size();start++)
         {
             int currsum=0;
             for(int end=start;end<arr.size();end++)
              {
                  currsum+=arr[end];
                  if(currsum==target)
                   {
                       ans.push_back(start+1);
                       ans.push_back(end+1);
                       return ans;
                   }
              }
         }
         ans.push_back(-1);
         return ans;
    }
};
