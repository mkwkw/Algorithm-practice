#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(vector<vector<int>> &board, int n, int m, int row, int col) { //ġ�� �ܺ� ������ ���� ������ �����ϴ� dfs �Լ�
    //board ���� �ʰ� �Ǵ� board[row][col]==1 || board[row][col]==-1 �� ���, �� ���ǹ��� ������ ������ 0�� ���� �Ұ� - ����, �ܺ� ���� ���� ����
    if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != 0) 
        return;
    board[row][col] = -1; //�ܺ� ����� ǥ��
    for (int i = 0; i < 4; i++)
        dfs(board, n, m, row + dr[i], col + dc[i]);
}

//�´���ִ� �ܺΰ��� ���� ���� (��濡�� -1�� �� ���ΰ�) - �ܺΰ����� 2�� �̻��̾ ���� �� �ִ� - true
bool canMelt(vector<vector<int>> &board, int row, int col) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (board[nr][nc] == -1) //�´�� �ִ� �ܺ� ������ �� ������ ������.
            cnt++;
    }
    return cnt >= 2;
}

//�̹��� ���� ġ�� ã��
vector<ci> findCheese(vector<vector<int>> &board, int n, int m) {
    vector<ci> list;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && canMelt(board, i, j)) //���� ���� ġ��鼭, �̹��� ���� �� �ִٸ�
                list.emplace_back(i, j); //�̹��� ���� ġ� ������ ���Ϳ� ���� (push_back({i,j}))
        }
    }
    return list;
}

int solution(int n, int m, vector<vector<int>> b){
    int time=0; //�� ���̴� �� �� �ð� �ɸ� ���ΰ�
    dfs(b, n, m, 0, 0); //�ܺ� ����, ���� ���� ������
    
    while (true) {
        vector<ci> list = findCheese(b, n, m); //�̹��� ���� ġ��� ����
        
        //��������
        if (list.empty())
            break;

        //ġ� ���̰�, ���Ӱ� ���� �ܺ� ���� ǥ��
        for (int i = 0; i < list.size(); i++) {
            int row = list[i].first, col = list[i].second;
            b[row][col] = 0; //1->0
            dfs(b, n, m, row, col); //���Ӱ� ���� �ܺ� ���� ǥ��
        }
        time++;
    }

    return time;
}

int main() {
    int n, m, answer;
    vector<vector<int>> board;
    
    //�Է�
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    answer = solution(n,m,board);
    
    //���
    cout << answer;
}