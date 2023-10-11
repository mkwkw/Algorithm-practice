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

        board[r-1][c-1] = -1;
        pos.push({r-1,c-1}); //참가자 위치 - 참가자가 한 칸에 여러명일 수 있음.
    }

    //출구 위치
    cin>>exitR>>exitC;
    board[exitR-1][exitC-1] = -2;

    //k초
    for(int t=0; t<k; t++){
        cout<<"t "<<t+1<<"초"<<'\n';
        //참가자 이동
        //출구 위치 찾기
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==-2){
                    exitR = i;
                    exitC = j;
                }
            }
        }

        if(pos.empty()){
            break;
        }
        
        for(int i=0; i<pos.size(); i++){
            int r = pos.front().first;
            int c = pos.front().second;
            //이동하지 못할 수도 있음.
            int finalNextR = r;
            int finalNextC = c;
            for(int k=0; k<4; k++){
                int nextR = r+dr[k];
                int nextC = c+dc[k];

                //참가자가 이동하는 경우
                if(verify(nextR, nextC, n) && abs(nextR-exitR)+abs(nextC-exitC)<abs(finalNextR-exitR)+abs(finalNextC-exitC)){
                    if(board[nextR][nextC]==0){ //이동한 곳이 출구가 아닌 경우
                        finalNextR = nextR;
                        finalNextC = nextC;
                    }
                    else if(board[nextR][nextC]==-2){ //이동한 곳이 출구인 경우
                        finalNextR = nextR;
                        finalNextC = nextC;
                        break;
                    }
                }
            }
            pos.pop();
            board[r][c] = 0;
            if(board[finalNextR][finalNextC]!=-2){
                board[finalNextR][finalNextC]=-1;
                cout<<"이동 "<<r<<' '<<c<<" to "<<finalNextR<<' '<<finalNextC<<'\n';
                pos.push({finalNextR, finalNextC});
            }
            totalDistance += abs(r-finalNextR)+abs(c-finalNextC);            
        }

        cout<<"이동한 총 거리 "<<totalDistance<<'\n';
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                cout<<board[a][b]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n'; 

        //미로 회전
        //1. 가장 작은 정사각형 구하기
        //출구와 가장 거리가 가깝고, 좌상단에 있는 참가자 위치 구하기
        int minLength = n; //한 명 이상의 참가자와 출구를 포함한 가장 작은 정사각형의 한 변의 길이
        int minLengthPersonR=n-1, minLengthPersonC=n-1;
        for(int i=0; i<pos.size(); i++){
            int r = pos.front().first;
            int c = pos.front().second;
            if(minLength>max(abs(pos.front().first-exitR), abs(pos.front().second-exitC))+1){
            
                minLength = max(abs(pos.front().first-exitR), abs(pos.front().second-exitC))+1;
                
                minLengthPersonR = r;
                minLengthPersonC = c;
            }
            else if(minLength==max(abs(pos.front().first-exitR), abs(pos.front().second-exitC))+1){    

                if(r<minLengthPersonR){
                    minLengthPersonR = r;
                    minLengthPersonC = c;
                }
                else if(r==minLengthPersonR && c<minLengthPersonC){
                    minLengthPersonR = r;
                    minLengthPersonC = c;
                }
            }
            pos.push({r,c});
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
                ruC = minLength-1;
                rdC = minLength-1;
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
                ldR = minLength-1;
                rdR = minLength-1;
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
        
            for(int i=0; i<=minLength/2; i++){
                

                vector<int> rightTemp; //오른쪽 변 값 저장
                for(int j=ruR+i; j<=rdR-i; j++){
                    rightTemp.push_back(board[j][ruC-i]);
                }
                
                //윗쪽 변 -> 오른쪽 변
                for(int j=luC+i; j<=ruC-i; j++){
                    
                    if(board[luR+i][j]>0)
                        board[ruR+j-luC][ruC-i] = board[luR+i][j]-1;
                    else
                        board[ruR+j-luC][ruC-i] = board[luR+i][j];
                }
            //     for(int a=0; a<n; a++){
            //     for(int b=0; b<n; b++){
            //         cout<<board[a][b]<<' ';
            //     }
            //     cout<<'\n';
            // }
            // cout<<'\n';
                //왼쪽 변 -> 윗쪽 변
                for(int j=luR+i; j<=ldR-i; j++){
                    
                    cout<<luR+i<<' '<<ruC-j+luR<<' '<<luC+i<<'\n';
                    if(board[j][luC+i]>0)
                        board[luR+i][ruC-j+luR] = board[j][luC+i]-1;
                    else
                        board[luR+i][ruC-j+luR] = board[j][luC+i];
                }
            //     for(int a=0; a<n; a++){
            //     for(int b=0; b<n; b++){
            //         cout<<board[a][b]<<' ';
            //     }
            //     cout<<'\n';
            // }
            // cout<<'\n';
                //아랫쪽 변 -> 왼쪽 변
                for(int j=ldC+i; j<=rdC-i; j++){
                    cout<<"dtoR "<<luR+j-ldC<<' '<<j<<'\n';
                    
                    if(board[ldR-i][j]>0)
                        board[luR+j-ldC][luC+i] = board[ldR-i][j]-1;
                    else
                        board[luR+j-ldC][luC+i] = board[ldR-i][j];
                }
            //     for(int a=0; a<n; a++){
            //     for(int b=0; b<n; b++){
            //         cout<<board[a][b]<<' ';
            //     }
            //     cout<<'\n';
            // }
            // cout<<'\n';
                //오른쪽 변 -> 아랫쪽 변
                for(int j=0; j<rightTemp.size(); j++){
                    cout<<"rtod "<<rdR-i<<" "<<ruC-i-j<<'\n';
                    
                    if(rightTemp[j]>0)
                        board[rdR-i][ruC-i-j] = rightTemp[j]-1;
                    else   
                        board[rdR-i][ruC-i-j] = rightTemp[j];
                }
                for(int a=0; a<n; a++){
                for(int b=0; b<n; b++){
                    cout<<board[a][b]<<' ';
                }
                cout<<'\n';
            }
            cout<<'\n';

            for(int k=0; k<pos.size(); k++){
                int r = pos.front().first;
                int c = pos.front().second;
                cout<<"r "<<r<<" c "<<c<<'\n';
                board[r][c]=0;
                //위->오른
                if(r==luR+i && luC+i<=c && c<=ruC-i){
                    r = rdR-i-(ruC-i-c);
                    c = ruC-i;
                }
                //왼->위
                else if( luR+i<=r && r<=ldR-i && c==luC+i){
                    c = ruC-i-(r-(luR+i));
                    r = luR+i;
                }
                //아래->왼
                else if(r==ldR-i && luC+i<=c && c<=ruC-i){
                    r = luR+i+(c-(luC+i));
                    c = luC+i;
                }
                //오른->아래    
                else if(ruR+i<=r && r<=rdR-i && c==ruC-i){
                    c = luC+i+(r-(rdR-i));
                    r = rdR-i;
                }
                
                
                board[r][c] = -1;
                pos.push({r,c});
                pos.pop();
                cout<<"new r "<<r<<" new c "<<c<<'\n';
            }
        }
            
        
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                cout<<board[a][b]<<' ';
            }
            cout<<'\n';
        }
        cout<<'\n';   

cout<<totalDistance<<'\n';
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==-2){
                exitR = i+1;
                exitC = j+1;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    cout<<exitR<<' '<<exitC<<'\n';
    }

    
    cout<<"끝";
}