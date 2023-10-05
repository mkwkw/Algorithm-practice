#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

//dp
//[i][j]에서 나올 수 있는 최대 정사각형의 한변의 길이 구하기
//board[i][j]==1일 때, dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
int solution(vector<vector<int>> board)
{
    vector<vector<int>> dp;
    dp.assign(board.size(), vector<int>(board[0].size(), 0));
    
    int answer = 0;
    for(int i=0; i<board[0].size(); i++){
        dp[0][i] = board[0][i];
    }
    for(int i=0; i<board.size(); i++){
        dp[i][0] = board[i][0];
    }
    
    for(int i=1; i<board.size(); i++){
        for(int j=1; j<board[0].size(); j++){
            if(board[i][j]==1){ //board[i][j]가 1이어야 주변의 사각형에 이어서 사각형을 넓힐 수 있음.
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
        }
    }
    
    //[1,0]
    //[0,0]
    //일 때의 답은 1이 되어야하므로 2차원 벡터 전체 탐색
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            answer = max(answer, dp[i][j]);
        }
    }
    
    answer *= answer;
    
    return answer;
}