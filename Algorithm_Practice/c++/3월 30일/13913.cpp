#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e5;

//������
vector<int> back(int x, vector<int> &path) { //x: k(��������)����
    vector<int> result(0); //���� ���
    while (x != -1) {
        result.push_back(x);
        x = path[x]; //���� ����
    }
    return result;
}

int bfs(int n, int k, vector<int> &path) {
    vector<int> check(SIZE + 1, 0);
    queue<int> q; //ť�� ��ǩ�� ����
    int ans = 0; //�ִ� �ð�

    check[n] = 1; //���� ��� �湮 üũ
    q.push(n); //���� ��� �ʱ�ȭ
    while (!q.empty()) {
        int x = q.front(); //���� Ž���Ϸ��� ��ġ
        q.pop();

        if (x == k) { //���� ã���� Ž�� ����.
            ans = check[x] - 1; //���� ��� �ʱ�ȭ�� 1�� �߱� ������ 1�� ����
            break;
        }

        vector<int> child = {x - 1, x + 1, x * 2}; //�ڽĳ��
        for (int i = 0; i < 3; i++) {
            if (child[i] >= 0 && child[i] <= SIZE && !check[child[i]]) { //���� ���� �ְ�, ù �湮�̶��
                check[child[i]] = check[x] + 1;
                path[child[i]] = x; //��� ����
                q.push(child[i]);
            }
        }
    }
    return ans;
}

/**
 * �ִܰŸ�(BFS) ������
 * - �⺻ ����: ���ٲ���
 */

int main() {
    vector<int> path(SIZE + 1, -1); //��� ���� ����
    int n, k;

    //�Է�
    cin >> n >> k;

    //����
    int ans = bfs(n, k, path);
    vector<int> result = back(k, path);

    //���
    cout << ans << '\n';
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
    return 0;
}