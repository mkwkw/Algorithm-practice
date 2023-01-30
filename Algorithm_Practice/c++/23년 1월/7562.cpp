#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//나이트가 갈 수 있는 8가지 방향
int dx[8]={-2,-1,1,2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

//범위 체크
bool verify(int x, int y, int n){
    if(x>=n || x<0){
        return false;
    }
    else if(y>=n || y<0){
        return false;
    }

    return true;
}  

int main(){
    int t, n, startX, startY, endX, endY, cnt;
    vector<vector<bool>> visited;

    cin>>t;

    for(int i=0; i<t; i++){
        queue<pair<int,pair<int, int>>> knight; //{이동한 횟수, {x좌표, y좌표}}
        cin>>n>>startX>>startY>>endX>>endY;

        if(startX==endX && startY==endY){
            cout<<"0\n";
            continue;
        }

        visited.assign(n, vector<bool>(n,false)); //방문 배열 초기화

        knight.push({0,{startX, startY}});
        visited[startX][startY]=true;

        bool flag = false;
        while(!knight.empty()){
        
            //큐에서 하나씩 빼서 8가지 방향으로 이동했을 때 좌표 구하고 조건 체크 후, 큐에 넣기
            for(int j=0; j<8; j++){
                
                int nextX = knight.front().second.first + dx[j];
                int nextY = knight.front().second.second + dy[j];
                cnt = knight.front().first+1;

                if(nextX==endX && nextY==endY){
                    flag = true;
                    break;
                } 
                
                if(verify(nextX, nextY, n) && !visited[nextX][nextY]){
                    //cout<<"x: "<<knight.front().second.first<<" y: "<<knight.front().second.second<<" nextX: "<<nextX<<" nextY: "<<nextY<<" cnt: "<<cnt<<'\n';
                    visited[nextX][nextY]=true;
                    knight.push({cnt,{nextX, nextY}});
                }

            }

            knight.pop();

            if(flag){
                break;
            }

        }

        cout<<cnt<<'\n';

    }
}