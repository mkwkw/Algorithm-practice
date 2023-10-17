#include <vector>

using namespace std;

vector<vector<int>> board;

//플로이드 와샬 - 모든 지점에서 모든 지점으로 - 3중 for문
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1000000001;
    int INF = 100000000;
    board.assign(n+1, vector<int>(n+1, INF));

    // 초기 지도 완성
    for (int i = 0; i < fares.size(); i++) {
        board[fares[i][0]][fares[i][1]] = fares[i][2];
        board[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    // 자기 노드로 가는 비용 0
    for (int i = 1; i <= n ; i++) {
        board[i][i] = 0;
    }

    // floyd warshall - 모든 노드에서 모든 노드로 가는 최소 요금 구하기
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                board[i][j] =  min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {  //합승 지점이 i 일 때 최소 비용 도출 (i==s일 때, 합승하지 않는 경우 포함)
        answer = min(answer, board[s][i] + board[i][a] + board[i][b]);
    }

    return answer;
}