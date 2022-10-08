#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt=0;
vector<string> board;
vector<vector<bool>> visited;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool valid(int n, int x, int y){
    if(x<0 || x>=n || y<0 || y>=n){
        return false;
    }
    else{
        return true;
    }
}

void connect(int n, int x, int y){

    visited[x][y]=true;

    for(int i=0; i<4; i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(valid(n, nextX, nextY) && board[nextX][nextY]=='1' && !visited[nextX][nextY]){
            cnt++;
            //cout<<"cnt: "<<cnt<<'\n';
            connect(n, nextX, nextY);
        }

    }
}

int main(){
    
    vector<int> cnts;

    int n;
    cin>>n;

    visited.assign(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        board.push_back(s);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cnt=0;
            if(board[i][j]=='1' && !visited[i][j]){
                cnt++;
                //cout<<"i: "<<i<<" j: "<<j<<'\n';
                connect(n, i, j);
                cnts.push_back(cnt);
            }
            
        }
    }

    sort(cnts.begin(), cnts.end());

    cout<<cnts.size()<<'\n';
    for(int i=0; i<cnts.size(); i++){
        cout<<cnts[i]<<'\n';
    }
    
}