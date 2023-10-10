#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool verify(int r, int c, int n){
    if(r<0 || c<0 || r>=n || c>=n){
        return false;
    }
    return true;
}

int main() {
    vector<vector<int>> board;
    queue<pair<int,int>> pos; //참가자 위치
    //상, 하, 좌, 우
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int n, m, k, exitR, exitC, totalDistance=0;

    cin>>n>>m>>k;

    //초기화
    board.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int r, c;
        cin>>r>>c;

        pos.push({r-1,c-1}); //참가자 위치
    }

    //출구 위치
    cin>>exitR>>exitC;

    exitR -= 1;
    exitC -= 1;

    //k초
    for(int t=0; t<1; t++){
        //참가자 이동
        queue<pair<int,int>> temp;
        while(!pos.empty()){
            int r = pos.front().first;
            int c = pos.front().second;
            //이동하지 못할 수도 있음.
            int finalNextR = r;
            int finalNextC = c;
            for(int k=0; k<4; k++){
                int nextR = r+dr[k];
                int nextC = c+dc[k];

                //참가자가 이동하는 경우
                if(verify(nextR, nextC, n) && board[nextR][nextC]==0 && abs(nextR-exitR)+abs(nextC-exitC)<abs(r-exitR)+abs(c-exitC)){
                    finalNextR = nextR;
                    finalNextC = nextC;
                }
            }
            pos.pop();
            totalDistance += abs(r-finalNextR)+abs(c-finalNextC);
            if(!(finalNextR==exitR && finalNextC==exitC)){ //출구에 도달하지 못한 경우
                temp.push({finalNextR, finalNextC});
            }
        }

        while(!temp.empty()){
            pos.push({temp.front().first, temp.front().second});
            temp.pop();
        }
        
        if(pos.empty()){ //참가자가 다 나간 경우
            break;
        }

        //미로 회전
        //1. 가장 작은 정사각형 구하기
        //출구와 가장 거리가 가깝고, 좌상단에 있는 참가자 위치 구하기
        int minLength = n; //한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형의 한 변의 길이
        int minLengthPersonR=n-1, minLengthPersonC=n-1;
        for(int i=0; i<pos.size(); i++){
            if(minLength>=max(abs(pos.front().first-exitR), abs(pos.front().second-exitC))+1){
                
                minLength = max(abs(pos.front().first-exitR), abs(pos.front().second-exitC))+1;
                
                int r = pos.front().first;
                int c = pos.front().second;
                
                if(r<minLengthPersonR){
                    minLengthPersonR = r;
                    minLengthPersonC = c;
                }
                else if(r==minLengthPersonR && c<minLengthPersonC){
                    minLengthPersonR = r;
                    minLengthPersonC = c;
                }
            }
            pos.push({pos.front().first, pos.front().second});
            pos.pop();
        }

        cout<<minLength<<'\n';
        cout<<minLengthPersonR<<' '<<minLengthPersonC<<'\n';
        cout<<exitR<<' '<<exitC<<'\n';
        //2. 회전할 사각형 모서리 좌표 구하기
        //모서리 좌표 구하기
        int luR = min(minLengthPersonR, exitR);
        int luC = min(minLengthPersonC, exitC);
        int ruR = min(minLengthPersonR, exitR);
        int ruC = max(minLengthPersonC, exitC);
        int ldR = max(minLengthPersonR, exitR);
        int ldC = min(minLengthPersonC, exitC);
        int rdR = max(minLengthPersonR, exitR);
        int rdC = max(minLengthPersonC, exitC);

        //참가자와 출구가 이루는 사각형이 정사각형이 아닌 경우
        if(abs(minLengthPersonR-exitR)>abs(minLengthPersonC-exitC)){
            //세로>가로
            if(rdC-minLength+1>=0){
                luC = rdC-minLength+1;
                ldC = rdC-minLength+1;
            }
            else{
                luC = 0;
                ldC = 0;
                ruC = minLength;
                rdC = minLength;
            }
        }
        else if(abs(minLengthPersonR-exitR)<abs(minLengthPersonC-exitC)){
            //세로<가로
            if(rdR-minLength+1>=0){
                luR = rdR-minLength+1;
                ruR = rdR-minLength+1;
            }
            else{
                luR = 0;
                ruR = 0;
                ldR = minLength;
                rdR = minLength;
            }
        }
        cout<<"lu "<<luR<<' '<<luC<<" ru "<<ruR<<' '<<ruC<<'\n';
        cout<<"ld "<<ldR<<' '<<ldC<<" rd "<<rdR<<' '<<rdC<<'\n';
        //3. 시계 방향 90도 회전 - 좌표 변화 및 벽 내구도-1
        //윗 변 -> 오른쪽 변
        //오른쪽 변 -> 아랫 변
        //아랫 변 -> 왼쪽 변
        //왼쪽 변 -> 윗쪽 변

        //board 값 변경
        //exitR, exitC 변경
        //참가자 좌표 변경
        for(int i=minLength; i>1; i-=2){
            vector<int> rightTemp; //오른쪽 변 값 저장
            for(int j=ruR+(minLength-i)/2; j<=rdR-(minLength-i)/2; j++){
                rightTemp.push_back(board[ruC+(minLength-i)/2][j]);
            }
            //윗쪽 변 -> 오른쪽 변
            for(int j=luC+(minLength-i)/2; j<=ruC-(minLength-i)/2; j++){
                cout<<"j "<<j<<'\n';
                if(board[luR+(minLength-i)/2][j]>0)
                    board[ruR+j-luC][ruC-(minLength-i)/2] = board[luR+(minLength-i)/2][j]-1;
                cout<<"board["<<ruR+j-luC<<"]["<<ruC-(minLength-i)/2<<"] = board["<<luR+(minLength-i)/2<<"]["<<j<<"] "<<board[luR+(minLength-i)/2][j]<<'\n';
            }
            //왼쪽 변 -> 윗쪽 변
            for(int j=luR+(minLength-i)/2; j<=ldR-(minLength-i)/2; j++){
                if(board[j][luC+(minLength-i)/2]>0)
                    board[luR+(minLength-i)/2][luC+j-luR] = board[j][luC+(minLength-i)/2]-1;
            }
            //아랫쪽 변 -> 왼쪽 변
            for(int j=ldC+(minLength-i)/2; j<=rdC-(minLength-i)/2; j++){
                if(board[ldR-(minLength-i)/2][j]>0)
                    board[luC+(minLength-i)/2][luR+j-ldC] = board[ldR-(minLength-i)/2][j]-1;
                cout<<"board["<<luC+(minLength-i)/2<<"]["<<luR+j-ldC<<"] = board["<<ldR+(minLength-i)/2<<"]["<<j<<"] "<<board[ldR-(minLength-i)/2][j]<<'\n';
            }
            //오른쪽 변 -> 아랫쪽 변
            for(int j=0; j<rightTemp.size(); j++){
                if(rightTemp[j]>0)
                    board[rdR-(minLength-i)/2][ruC-(minLength-i)/2-j] = rightTemp[j]-1;
            }
        }

        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                cout<<board[a][b]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';
            
        //참가자 좌표 회전
        

    }

    
    
    return 0;
}