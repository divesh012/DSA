#include <iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    void rotate(vector<int>&nums,int k){
        int n = nums.size();
        
        k = k % n;
        vector<int>temp(n);
        
        for(int i  = 0;i<n;i++){
            temp[(i+k) % n] = nums[i];
        }
        nums = temp;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums,k);
    cout<<"Value of K= "<<k<<endl;
    cout<<"Rotated Array: ";
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    

    return 0;
}
