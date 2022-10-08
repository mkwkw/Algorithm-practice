#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct point{
    int x;
    int y;
    int cnt;
};

bool valid(int n, int m, int x, int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    else{
        return true;
    }
}


int main(){
    
    vector<string> maze; //미로
    queue<point> near; //인접한 칸 넣을 큐
    vector<vector<bool>> visited;
    //vector<vector<int>> block; //이 지점까지의 최단 거리 저장
    
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int n, m, cnt=0;

    cin>>n>>m;

    visited.assign(n, vector<bool>(m, false));
    //block.assign(n, vector<int>(m,10000));
    for(int i=0; i<n; i++){
        string road;
        cin>>road;
        maze.push_back(road);
    }

    //block[0][0]=1;
    near.push({0,0,1});
    //for(int i=0; i<n; i++){
        //for(int j=0; j<m; j++){
            while(!near.empty()){
                int x = near.front().x;
                int y = near.front().y;
                int cnt = near.front().cnt;
                visited[x][y]=true;

                if(x==n-1 && y==m-1){
                    cout<<cnt;
                    return 0;
                }
                near.pop();

                for(int k=0; k<4; k++){
                    int nextX = x+dx[k];
                    int nextY = y+dy[k];

                    if(valid(n, m, nextX, nextY) && maze[nextX][nextY]=='1' && !visited[nextX][nextY]){
                        visited[nextX][nextY]=true; //방문 체크 여기서도 해주어야 메모리 초과 발생 안함.
                        near.push({nextX, nextY, cnt+1});
                        //cout<<"block[i][j]+1: "<<block[x][y]+1<<" block[nextX][nextY]: "<<block[nextX][nextY]<<'\n';
                        //block[nextX][nextY] = min(block[x][y]+1, block[nextX][nextY]);
                    }

                }   
                
                
            }

        //}

        
    //}

    //cout<<block[n-1][m-1];

}