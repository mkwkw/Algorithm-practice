#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <cmath>

using namespace std;

/**
 * 1. 규칙에 따라 첫 번째 학생은 [1][1]자리에 들어갈 수 밖에 없음
 * 2. 빈 칸을 돌면서 주어진 규칙에 따라 더 높은 우선 순위의 위치이면 stack에 push -> 마지막에는 최종 위치인 곳이 top에 위치
 * 3. top 위치에 숫자를 넣기
 * 4. 만족도 계산 - 친구들 번호가 숫자를 위치시킬 때도 사용하고 만족도 계산할 때도 사용되므로 vector<set<int>> 사용해서 미리 다 저장해놓고 사용하였음 
 * 결과: 성공
*/
struct Pos{
    int friendCnt; //해당 위치에서 인접한 좋아하는 학생 수 (친구라고 하겠음)
    int emptyCnt; //해당 위치에서 인접한 빈 칸 수
    int row; //해당 위치의 행
    int col; //해당 위치의 열
};

//범위 체크
bool verify(int r, int c, int n){
    if(r<0 || r>=n || c<0 || c>=n){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num, f1, f2, f3, f4;
    vector<vector<int>> board;
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    int answer = 0; //만족도
    
    cin>>n;

    board.assign(n, vector<int>(n,0));
    vector<set<int>> idxFSet(n*n+1); //각 인덱스의 친구 셋 

    cin>>num>>f1>>f2>>f3>>f4;

    set<int> f;
    f.insert(f1);
    f.insert(f2);
    f.insert(f3);
    f.insert(f4);
    idxFSet[num] = f;

    board[1][1] = num;

    for(int i=1; i<n*n; i++){
        cin>>num>>f1>>f2>>f3>>f4;
        
        set<int> f;
        f.insert(f1);
        f.insert(f2);
        f.insert(f3);
        f.insert(f4);
        idxFSet[num] = f;
        //vector<Pos> posCandidate;
        stack<Pos> posCandidate;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(board[j][k]==0){
                    int fCnt = 0, eCnt = 0;
                    
                    for(int t=0; t<4; t++){
                        int nextR = j+dr[t];
                        int nextC = k+dc[t];

                        if(verify(nextR, nextC, n)){ 
                            if(f.find(board[nextR][nextC])!=f.end()){
                                fCnt++;
                            }
                            else if(board[nextR][nextC]==0){
                                eCnt++;
                            }
                        }
                    }

                    //cout<<"fCnt "<<fCnt<<" eCnt "<<eCnt<<'\n';
                    
                    if(posCandidate.empty()){
                        posCandidate.push(Pos{fCnt,eCnt,j,k});
                    }
                    else{
                        Pos pos = posCandidate.top();
                        bool flag = false;
                        //cout<<"top board["<<pos.row<<"]["<<pos.col<<"] = "<<num<<'\n';
                        if(pos.friendCnt<fCnt){
                            flag = true;
                        }
                        else if(pos.friendCnt==fCnt){
                            if(pos.emptyCnt<eCnt){
                                flag = true;
                            }
                            else if(pos.emptyCnt==eCnt){
                                if(pos.row>j){
                                    flag=true;
                                }
                                else if(pos.row==j){
                                    if(pos.col>k){
                                        flag=true;
                                    }
                                }
                            }
                        }

                        if(flag){
                            posCandidate.pop();
                            posCandidate.push(Pos{fCnt,eCnt,j,k});
                        }
                    }
                }
            }
        }

        Pos pos = posCandidate.top();
        //cout<<"final board["<<pos.row<<"]["<<pos.col<<"] = "<<num<<'\n';
        board[pos.row][pos.col] = num;
    }

    //만족도 계산
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cnt = 0;
            for(int k=0; k<4; k++){
                int nextR = i+dr[k];
                int nextC = j+dc[k];

                if(verify(nextR, nextC, n) && idxFSet[board[i][j]].find(board[nextR][nextC])!=idxFSet[board[i][j]].end()){
                    cnt++;
                }
            }

            //cout<<cnt<<'\n';
            if(cnt>0){
                answer += (int)pow(10, cnt-1);
            }

        }
    }

    cout<<answer;
}