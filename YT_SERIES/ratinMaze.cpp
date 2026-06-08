#include <iostream>
#include<vector>
using namespace std;
// Que : Rat in Maze
void helper(vector<vector<int>>&mat,int r,int c,string path,vector<string>&ans,
            vector<vector<bool>>&visit){
    int n =mat.size();
    if(r<0 || c<0 || r>=n||c>=n || mat[r][c] ==0||visit[r][c] == true){
        return;
    }
    if(r==n-1 && c == n-1){ //ans
    ans.push_back(path);
        return ;
    }
    
    visit[r][c] = true;
    
    helper(mat,r+1,c,path+"D",ans,visit); //down
    helper(mat,r-1,c,path+"U",ans,visit); //up
    helper(mat,r,c-1,path+"L",ans,visit); //left
    helper(mat,r,c+1,path+"R",ans,visit); //right
    
    visit[r][c] = false;// backtracking because next path find 
}

vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();
    vector<string>ans;
    string path = "";
    vector<vector<bool>>visit(n,vector<bool>(n,false));
    
    helper(mat,0,0,path,ans,visit);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    
    vector<string> ans = findPath(mat);
    for(string path : ans){
        cout<<path<<endl;
    }
    return 0;
}

//not used two matrix one for maze and one for visit we can use single matrix for both because we can mark visited cell with -1 and unvisited with 1
#include <iostream>
#include<vector>
using namespace std;
// Que : Rat in Maze
void helper(vector<vector<int>>&mat,int r,int c,string path,vector<string>&ans){
    int n =mat.size();
    if(r<0 || c<0 || r>=n||c>=n || mat[r][c] ==0||mat[r][c] == -1){
        return;
    }
    if(r==n-1 && c == n-1){ //ans
    ans.push_back(path);
        return ;
    }
    mat[r][c] = -1;  //visit
    
    helper(mat,r+1,c,path+"D",ans); //down
    helper(mat,r-1,c,path+"U",ans); //up
    helper(mat,r,c-1,path+"L",ans); //left
    helper(mat,r,c+1,path+"R",ans); //right
    
    mat[r][c] =1;// unvisit backtracking because next path find 
}

vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();
    vector<string>ans;
    string path = "";

    helper(mat,0,0,path,ans);
    return ans;
}

int main(){
    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    
    vector<string> ans = findPath(mat);
    for(string path : ans){
        cout<<path<<endl;
    }
    return 0;
}