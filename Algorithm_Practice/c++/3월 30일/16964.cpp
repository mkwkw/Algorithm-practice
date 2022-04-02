#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited, sequence, result;

bool cmp(const int &i1, const int &i2) {
    return sequence[i1] < sequence[i2];
}

//����Լ��� dfs ����
void dfs(int cur, vector<vector<int>> &graph) {
    visited[cur] = true;
    result.push_back(cur);
    for (int i = 0; i < graph[cur].size(); i++) {
        if (!visited[graph[cur][i]])
            dfs(graph[cur][i], graph);
    }
}

//�Է¹��� ������ dfs ��� ��
bool isDfs(vector<int> &route) {
    for (int i = 0; i < route.size(); i++) {
        if (route[i] != result[i])
            return false;
    }
    return true;
}

/**
 *  ���� �Է� 3  -> ���� �Է� 3
 *  1 | 2 3        1 | 3 2
 *  2 | 1 4        2 | 1 4
 *  3 | 1          3 | 1
 *  4 | 2          4 | 2
 *
 *  route : 1 3 2 4
 *
 *  �� �� �ִ� ��
 *  1. 1�� ������ 3, 2, 4�� �������� ���� Ž���ȴ�.
 *  2. 3�� ������ 2, 4�� �������� ���� Ž���ȴ�.
 *  3. 2�� ������ 4�� �������� ���� Ž���ȴ�.
 *  -> ���� i, j�� ��ġ�� x, y��� �� ��, x < y�� ���� i�� ���� j���� ���� Ž���ؾ� ��
 *  -> ��ġ ���踦 �������� ����
 *
 *  ���� �� dfs Ž���� �� ����� �Էµ� ��ο� ���ٸ� �ùٸ� �湮 ����
 */
int main() {
    int n, a, b;

    //�Է�
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    vector<int> route(n, 0);
    visited.assign(n + 1, 0);
    sequence.assign(n + 1, 0);

    for (int i = 1; i < n; i++) { //������ �׷���
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++) { //�� ������ ���� �ε����� sequence �迭�� ����
        cin >> route[i];
        sequence[route[i]] = i;
    }

    //����
    for (int i = 1; i <= n; i++) //sequence ���� �������� ����
        sort(graph[i].begin(), graph[i].end(), cmp);
    dfs(1, graph);

    //���
    cout << isDfs(route);
}