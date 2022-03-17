#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<bool> visited;
vector<vector<int>> matrix;
int ans = INF;

/**
 * ��� ���ø� �湮�� �� ���ƿ� �� �ִ� ��� ��� Ž��
 * !�����غ���! �Լ��� �� ���ڴ� ���� � ������ �ϰ� �ֳ���?
 */
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) {
    if (cost >= ans) //�����غ��� : �� ���ǹ��� ������ ��� �ɱ��?
        return;
    if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
        //��� ���÷� �ٽ� ���ƿ� �� �ִ��� Ȯ��
        if (matrix[cur_city][start_city] != 0)
            ans = min(ans, cost + matrix[cur_city][start_city]);
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
        if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ����
            visited[i] = true; //�湮 ó��
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]);
            visited[i] = false; //�̹湮 ó��
        }
    }
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 *
 * !����! ��� ���ø� �湮 �� ���� ���÷� ���ƿ;� �ϱ� ������ � ���ÿ��� ����ߴ��� �˰� �־�� ��.
 */
int main() {
    int n;

    //�Է�
    cin >> n;
    visited.assign(n, false);
    matrix.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //����
    //i��° ���ø� �������� ��ȸ
    for (int i = 0; i < n; i++) {
        visited[i] = true; //�湮 ó��
        backtracking(n, i, i, 1, 0);
        visited[i] = false; //�̹湮 ó��
    }

    //���
    cout << ans;
}