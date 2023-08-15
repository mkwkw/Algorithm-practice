#include <iostream>
#include <vector>

using namespace std;

//dp
//i-1행에서 가장 큰 점수 찾아서(같은 열 제외)
//board[i][j] += 이전 행의 가장 큰 점수
int solution(vector<vector<int>> land)
{
    int answer = 0, maxNum = 0, maxCol = 0;
    vector<vector<int>> board; //dp
    
    board.assign(land.size(), vector<int>(4,0));
    
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<4; j++){
            board[i][j] = land[i][j];
        }
    }
    
    for(int i=1; i<land.size(); i++){
        for(int j=0; j<4; j++){
            maxNum = 0;
            for(int k=0; k<4; k++){
                if(j==k){
                    continue;
                }    

                if(maxNum<board[i-1][k]){
                    maxNum = board[i-1][k];
                } 
            }
            //cout<<"maxNum: "<<maxNum<<'\n';
            board[i][j] += maxNum;
        }
        
    }
    /*
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<4; j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
   */
    for(int i=0; i<4; i++){
        answer = max(answer, board[land.size()-1][i]);
    }
    return answer;
}