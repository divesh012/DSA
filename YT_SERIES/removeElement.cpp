#include <iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int removeElement(vector<int>&nums , int val){
        int k = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


int main() {
    Solution sol;
    vector<int>nums= {3,1,2,3,4};
    int val = 2;  //This is Remove Index Element 
    
    cout<<"My Array: ";
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
        cout<<endl;

    int result =sol.removeElement(nums,val);
    cout<<"K(This is count): "<<result<<endl;
    cout<<"After Removal: ";
    
    for(int i =0;i<result;i++){
        cout<<nums[i]<<" ";
    }
    
    return 0;
}
