#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &board, int n, int m, int row, int col) { //치즈 외부 공간과 내부 공간을 구분하는 dfs 함수
    //board 범위 초과 또는 board[row][col]==1 || board[row][col]==-1 인 경우, 이 조건문에 막혀서 내부의 0에 접근 불가 - 내부, 외부 공간 구분 가능
    if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) 
        return;
    board[row][col] = -1; //외부 공기로 표시
    for (int i = 0; i < 4; i++)
        dfs(board, n, m, row + dr[i], col + dc[i]);
}

//맞닿아있는 외부공간 개수 세기 (사방에서 -1이 몇 개인가) - 외부공간이 2개 이상이어서 녹일 수 있다 - true
bool canMelt(vector<vector<int>> &board, int row, int col) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (board[nr][nc] == -1) //맞닿아 있는 외부 공간이 몇 개인지 세야함.
            cnt++;
    }
    return cnt >= 2;
}

//이번에 녹을 치즈 찾기
vector<ci> findCheese(vector<vector<int>> &board, int n, int m) {
    vector<ci> list;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && canMelt(board, i, j)) //녹지 않은 치즈면서, 이번에 녹일 수 있다면
                list.emplace_back(i, j); //이번에 녹을 치즈를 저장할 벡터에 저장 (push_back({i,j}))
        }
    }
    return list;
}

int solution(int n, int m, vector<vector<int>> b){
    int time=0; //다 녹이는 데 몇 시간 걸릴 것인가
    dfs(b, n, m, 0, 0); //외부 공간, 내부 공간 나누기
    
    while (true) {
        vector<ci> list = findCheese(b, n, m); //이번에 녹을 치즈들 저장
        
        //종료조건
        if (list.empty())
            break;

        //치즈를 녹이고, 새롭게 생긴 외부 공간 표시
        for (int i = 0; i < list.size(); i++) {
            int row = list[i].first, col = list[i].second;
            b[row][col] = 0; //1->0
            dfs(b, n, m, row, col); //새롭게 생긴 외부 공간 표시
        }
        time++;
    }

    return time;
}

int main() {
    int n, m, answer;
    vector<vector<int>> board;
    
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    answer = solution(n,m,board);
    
    //출력
    cout << answer;
}