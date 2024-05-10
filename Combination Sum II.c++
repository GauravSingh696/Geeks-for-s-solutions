// 10-05-2024

class Solution{
public:
    set<vector<int>> st;
    
    void solve(vector<int> &arr, int n, int k, int i, vector<int> &temp)
    {
        if(k<0)
            return ;
        
        if(i==n)
        {
            if(k==0)
                st.insert(temp);
            return ;
        }
        
        temp.push_back(arr[i]);
        
        solve(arr, n, k-arr[i], i+1, temp);
        
        temp.pop_back();
        
        solve(arr, n, k, i+1, temp);
    }

    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        
        vector<vector<int>> result;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        
        solve(arr, n, k, 0, temp);
        
        for(auto it : st)
        {
            result.push_back(it);
        }
        
        return result;
    }
};
