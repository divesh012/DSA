//Leet code problem 
//Roated Sorted Array Search
#include<iostream>
#include<vector>
using namespace std;  

class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0 , end = A.size()-1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(A[mid] == tar){
                return mid;
            }
            
            if(A[st]<=A[mid]){ //left sorted
                if(A[st] <= tar && tar <= A[mid]){
                    end = mid - 1;
                }else{
                    st = mid+1;
                }
            }else{ //right sorted
                if(A[mid]< tar && tar <=A[end]){
                    st = mid + 1;

                }else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};

int main(){
vector<int> arr = {1,2,3,5,6,0,4};
    int tar = 0;
    Solution sol;
     int index =sol.search(arr,tar);
     cout<<"Index of targeted element is: "<<index<<endl;
    
    return 0;
}