#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Fish{
    int r;
    int c;
    int d;
};
struct Pos{
    int r;
    int c;
    int d;
};

int dr[4] = {-1,0,0,1};
int dc[4] = {0,-1,1,0};

bool verify(int r, int c, int n){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }
    return true;
}

bool comp(const Fish &a, const Fish &b){
    if(a.r==b.r){
        return a.c<b.c;
    }
    return a.r<b.r;
}

int main(){
    vector<vector<int>> board;
    int n, sharkR, sharkC, sharkSize = 2, eatenFishCnt = 0;
    int time = 0;

    cin>>n;

    board.assign(n, vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];

            if(board[i][j]==9){
                sharkR = i;
                sharkC = j;
            }
        }
    }

    while(true){

        //cout<<"shark size "<<sharkSize<<" eatenCnt "<<eatenFishCnt<<'\n';
        //1. 아기상어가 먹을 수 있는 물고기 찾기
        vector<Fish> fish;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(1<=board[i][j] && board[i][j]<=6 && board[i][j]<sharkSize){
                    fish.push_back({i,j,n*n});
                }
            }
        }

        //1-1. 먹을 수 있는 물고기가 없는 경우 - 결과 출력
        if(fish.size()==0){
            break;
        }
        else{ //2-2. 먹을 수 있는 물고기가 있는 경우
            int fishR, fishC;
            int minDist = n*n+1;

            if(fish.size()==1){ //1마리
                fishR = fish[0].r;
                fishC = fish[0].c;

                vector<Fish>  candidate;
                vector<vector<bool>> visited;
                visited.assign(n, vector<bool>(n, false));
                queue<Pos> pos;
                pos.push({sharkR, sharkC, 0});
                while(!pos.empty()){
                    int r = pos.front().r;
                    int c = pos.front().c;
                    int d = pos.front().d;
                    //cout<<"r "<<r<<" c "<<c<<" d "<<d<<'\n';

                    if(r==fishR && c==fishC){
                        minDist = d;
                        //cout<<"d "<<d<<'\n';
                        candidate.push_back({r,c,d});
                        break;
                    }
                    for(int k=0; k<4; k++){
                        int nextR = r+dr[k];
                        int nextC = c+dc[k];

                        if(verify(nextR, nextC, n) && !visited[nextR][nextC] && board[nextR][nextC]<=sharkSize){
                            pos.push({nextR, nextC, d+1});
                            visited[nextR][nextC] = true;
                        }
                    }

                    pos.pop();
                }

                while(!pos.empty()){
                    pos.pop();
                }

                if(candidate.size()==0){
                    break;
                }
            }
            else{ //여러마리 - 정렬 - 최단 거리, 가장 위쪽, 가장 왼쪽
                
                vector<Fish>  candidate;

                //아기 상어 ~ 물고기 - 최단 거리 구하기
                for(int i=0; i<fish.size(); i++){
                    vector<vector<bool>> visited;
                    visited.assign(n, vector<bool>(n, false));

                    queue<Pos> pos;

                    pos.push({sharkR, sharkC, 0});

                    while(!pos.empty()){
                        int r = pos.front().r;
                        int c = pos.front().c;
                        int d = pos.front().d;
                        //cout<<"r "<<r<<" c "<<c<<" d "<<d<<'\n';

                        if(r==fish[i].r && c==fish[i].c){
                            fish[i].d = d;
                            minDist = min(minDist, d);
                            //cout<<"minDist "<<minDist<<'\n';
                            break;
                        }
                        for(int k=0; k<4; k++){
                            int nextR = r+dr[k];
                            int nextC = c+dc[k];

                            if(verify(nextR, nextC, n) && !visited[nextR][nextC] && board[nextR][nextC]<=sharkSize){
                                pos.push({nextR, nextC, d+1});
                                visited[nextR][nextC] = true;
                            }
                        }

                        pos.pop();
                    }

                    while(!pos.empty()){
                        pos.pop();
                    }             
                }

                for(int i=0; i<fish.size(); i++){
                    if(fish[i].d == minDist){
                        candidate.push_back(fish[i]);
                    }
                }

                //정렬
                if(candidate.size()>=1){
                    if(candidate.size()>1)
                        sort(candidate.begin(), candidate.end(), comp);
                    fishR = candidate[0].r;
                    fishC = candidate[0].c;    
                }
                else if(candidate.size()==0){
                    break;
                }
                
            }

            //한 마리 먹기
            eatenFishCnt += 1;
            board[fishR][fishC] = 0;
            time += minDist; //이동 거리
            board[sharkR][sharkC] = 0;
            sharkR = fishR;
            sharkC = fishC;
            board[sharkR][sharkC] = 9;

            if(sharkSize==eatenFishCnt){
                sharkSize += 1;
                eatenFishCnt = 0;
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<board[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<time<<'\n';
    }

    cout<<time;

}