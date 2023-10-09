#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

//구현, 정렬, 큐, 맵
//1~3 반복
//1. 행의 개수, 열의 개수 따져서 r연산/c연산 수행
//2. 값이 들어가고 빠지고, 순서도 바뀌고 하므로 큐 사용
//3. r연산/c연산 이후에 큐의 모든 값을 빼고 새로 바뀐 board 기반으로 큐에 다시 새로운 값을 넣기
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(){
    vector<vector<int>> board;
    vector<queue<int>> rowQ(100), colQ(100);
    map<int,int> numAndCnt; //숫자, 등장 횟수
    int r, c, k, rSize, cSize;

    cin>>r>>c>>k;

    board.assign(100, vector<int>(100, 0));
    //초기화
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>board[i][j];
            rowQ[i].push(board[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            colQ[i].push(board[j][i]);
        }
    }

    //처음에 주어진 값이 정답일 때
    if(board[r-1][c-1]==k){
        cout<<0;
        return 0;
    }
    
    rSize = 3;
    cSize = 3;
    for(int i=1; i<=100; i++){ //100초까지 연산 
        board.assign(100, vector<int>(100, 0));
        if(rSize>=cSize){ //r연산
            cSize = 0;
            //j행 탐색
            for(int j=0; j<100; j++){
                if(rowQ[j].size()>0){
                    while(!rowQ[j].empty()){
                        if(rowQ[j].front()>0){
                            numAndCnt[rowQ[j].front()]++;
                        }
                        rowQ[j].pop();
                    }
                    vector<pair<int,int>> temp;
                    for(auto m : numAndCnt){
                        temp.push_back({m.first, m.second});
                    }

                    cSize = max(cSize, (int)temp.size()*2);
                    //cout<<"cSize "<<cSize<<'\n';
                    sort(temp.begin(), temp.end(), comp);
                    
                    for(int k=0; k<temp.size(); k++){
                        if(2*k<100){
                            board[j][2*k]=temp[k].first;
                            board[j][2*k+1]=temp[k].second;
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    break;
                }
                numAndCnt.clear();
            }
        }
        else{ //c연산
        //cout<<"c\n";
            rSize = 0;
            for(int j=0; j<100; j++){
                if(colQ[j].size()>0){
                    //cout<<"colQ size"<<colQ[j].size()<<'\n';
                    while(!colQ[j].empty()){
                        if(colQ[j].front()>0){
                            numAndCnt[colQ[j].front()]++;
                        }
                        colQ[j].pop();
                    }
                    vector<pair<int,int>> temp;
                    for(auto m : numAndCnt){
                        temp.push_back({m.first, m.second});
                    }

                    rSize = max(rSize, (int)temp.size()*2);
                    sort(temp.begin(), temp.end(), comp);
                    
                    for(int k=0; k<temp.size(); k++){
                        if(2*k<100){
                            board[2*k][j]=temp[k].first;
                            board[2*k+1][j]=temp[k].second;
                            
                        }
                        else{
                            break;
                        }
                    }
                }
                else{
                    break;
                }
                numAndCnt.clear();
            }
            numAndCnt.clear();
        }

        //cout<<"rSize "<<rSize<<" cSize "<<cSize<<'\n';

        if(board[r-1][c-1]==k){
            cout<<i;
            return 0;
        }

        //r연산이나 c연산 이후에 큐에서 값 다 빼기
        for(int j=0; j<100; j++){
            while(!rowQ[j].empty()){
                rowQ[j].pop();
            }
            while(!colQ[j].empty()){
                colQ[j].pop();
            }
        }

        //큐에 다시 값 새로 넣기
        for(int j=0; j<rSize; j++){
            for(int k=0; k<cSize; k++){
                rowQ[j].push(board[j][k]);
                colQ[k].push(board[j][k]);
                //cout<<board[j][k]<<' ';
            }
            //cout<<'\n';
        }
        //cout<<'\n';

    }

    cout<<-1;
    return 0;
}