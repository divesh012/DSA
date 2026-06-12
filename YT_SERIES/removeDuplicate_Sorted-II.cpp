#include <iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>&nums){
            
            int n = nums.size();
            if(n<2)
            return n;
            
            int k = 2;

        for(int i =2;i<n;i++){
            if(nums[i] != nums[k-2]){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


int main() {
    Solution sol;
    vector<int>nums= {1,1,1,2,2,3}; 

    cout<<"My Array: ";
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
        cout<<endl;

    int result =sol.removeDuplicates(nums);
    cout<<"K(This is count): "<<result<<endl;
    cout<<"After Removal: ";
    
    for(int i =0;i<result;i++){
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
