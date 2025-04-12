#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int x, int y, int oldColor, int newColor){
    if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y] != oldColor){
        return;
    }
    image[x][y] = newColor;

    dfs(image, x+1, y, oldColor, newColor);
    dfs(image, x-1, y, oldColor, newColor);
    dfs(image, x, y+1, oldColor, newColor);
    dfs(image, x, y-1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    if(image[sr][sc] == newColor){
        return image;
    }

    int oldColor = image[sr][sc];
    dfs(image, sr, sc, oldColor, newColor);
    return image;
}
int main(){
    vector<vector<int>> image = {{1,1,1,0},{0,1,1,1},{1,0,1,1}};
    int sr=1, sc=2;
    int newColor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    for(auto &row : result){
        for(auto &pixel : row){
            cout<<pixel<<" ";
        }
        cout<<endl;
    }
    return 0;
}