#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//구현
bool verify(int r, int c, int n){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }
    return true;
}

int main(){
    int n, m, d, s;
    vector<vector<int>> board;
    queue<pair<int,int>> cloudPos;
    vector<vector<bool>> checkCloudPos;
    int dr[8]={0,-1,-1,-1,0,1,1,1};
    int dc[8]={-1,-1,0,1,1,1,0,-1};
    int cloudCnt = 0, answer = 0;

    cin>>n>>m;

    board.assign(n, vector<int>(n, 0));
    checkCloudPos.assign(n, vector<bool>(n, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    //처음 구름 위치
    cloudPos.push({n-2, 0});
    cloudPos.push({n-2, 1});
    cloudPos.push({n-1, 0});
    cloudPos.push({n-1, 1});

    cloudCnt = 4;

    for(int i=0; i<m; i++){
        queue<pair<int,int>> beforeCloudPos;
        cin>>d>>s;

        checkCloudPos.assign(n, vector<bool>(n, false));
        //구름 이동
        //행, 열 이어져있음 주의
        for(int j=0; j<cloudCnt; j++){
            
            //checkCloudPos[cloudPos.front().first][cloudPos.front().second] = false;
            int nextR = cloudPos.front().first + dr[d-1]*s;
            int nextC = cloudPos.front().second + dc[d-1]*s;

            if(nextR>=0){
                nextR %= n;
            }
            else{
                while(nextR<0){
                    nextR += n;
                }
            }

            if(nextC>=n){
                nextC %= n;
            }
            else{
                while(nextC<0){
                    nextC += n;
                }
            }
            beforeCloudPos.push({nextR, nextC});
            //cout<<"R "<<cloudPos.front().first<<" C "<<cloudPos.front().second<<" nextR "<<nextR<<" nextC "<<nextC<<'\n'; 
            cloudPos.pop();
            
            checkCloudPos[nextR][nextC] = true;

            board[nextR][nextC] += 1;
            cloudPos.push({nextR, nextC});
            
        }       

        //주변 바구니 세기
        while(!cloudPos.empty()){
            if(!checkCloudPos[cloudPos.front().first][cloudPos.front().second]){
                cloudPos.pop();
                continue;
            }

            int nearBasketCnt = 0;
            for(int j=1; j<8; j+=2){
                if(verify(cloudPos.front().first+dr[j], cloudPos.front().second+dc[j], n) && board[cloudPos.front().first+dr[j]][cloudPos.front().second+dc[j]]){
                    nearBasketCnt++;
                }
            }

            board[cloudPos.front().first][cloudPos.front().second] += nearBasketCnt;
            
            cloudPos.pop();
        }

        //바구니의 물 양이 2 이상이면 새로운 구름 생성
        cloudCnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!checkCloudPos[i][j] && board[i][j]>=2){
                    cloudCnt++;
                    board[i][j] -= 2;
                    checkCloudPos[i][j] = true;
                    cloudPos.push({i,j});
                }
            }
        }

        while(!beforeCloudPos.empty()){
            //cout<<"구름에서 지우기";
            //cout<<beforeCloudPos.front().first<<' '<<beforeCloudPos.front().second<<'\n';
            checkCloudPos[beforeCloudPos.front().first][beforeCloudPos.front().second] = false;
            beforeCloudPos.pop();
        }         
    }

    for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
            answer += board[j][k];
        }
    }

    cout<<answer;
}