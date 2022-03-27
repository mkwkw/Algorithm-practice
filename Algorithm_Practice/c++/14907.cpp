#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 26;

vector<string> splitInput(string input) { //�Է� ���ڿ� �и�
    vector<string> result; //�۾� ��ȣ, �۾� �ϼ�, ���� �ؾ��ϴ� �۾� ��� ������ ����
    string tmp;
    input += " "; //������ ���ڿ� �и��� ���� ���� �߰�
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            result.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += input[i];
    }
    return result;
}

//�������� + DP
int topologicalSort(vector<int> &days, vector<int> &indegree, vector<vector<int>> &graph) {
    queue<int> q;
    vector<int> dp(SIZE, 0); //���� �۾� �ϱ���� �ɸ� �ð�
    int ans = 0;

    for (int i = 0; i < SIZE; i++) {
        dp[i] = days[i]; //dp �迭 �ʱ�ȭ
        if (days[i] && !indegree[i]) //�����ϴ� �����̰�, ���������� 0�̶��
            q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans = max(ans, dp[node]); //���� ���� (������ ������ ���� ���� ���, ���� �� �ð��� �����ؾ� �ϱ� ����)
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i];
            indegree[next_node]--; //����� ������ ���������� 1�� ����
            if (!indegree[next_node]) //����� ������ ���������� 0�� �Ǿ��ٸ�
                q.push(next_node);

            //���� ������ �ּ� �ð� ��� -> �̾��� �� ���� �� ���� �� �۾� �ϼ��� ���� ������ ����
            dp[next_node] = max(dp[next_node], dp[node] + days[next_node]);
        }
    }
    return ans;
}

/**
 * �Է��� EOF�� ���� �޾ƾ� �� (�Է��� ���� ������)
 * ���� ������ ������ ������ ���� ���� ���, ���� �� �ð��� �����ؾ� �ϱ� ������ ������ �׻� maxó�� ���־�� ��
 *
 * !����! �Է����� ������ �� ���� �ؾ� �� �۾��� 0���� �� ����. �� �־����� ���� �� ����.
 * -> ����, getline�� ���� �� ���� �Է¹��� ��, �۾�, �۾� �ϼ�, �� ���� �ؾ� �� �۾����� ������ ����
 */

int main() {
    vector<int> indegree(SIZE, 0);
    vector<vector<int>> graph(SIZE, vector<int>(0));
    vector<int> days(SIZE, 0);
    string input;

    //�Է�
    while (getline(cin, input)) {
        vector<string> list = splitInput(input);
        int work = list[0][0] - 'A'; //�۾� ��ȣ
        days[work] = stoi(list[1]); //�ش� �۾� �ϼ�
        if (list.size() == 2) //�� ���� �ؾ� �ϴ� �۾��� ���ٸ�
            continue;

        string prev = list[2]; //�� ���� �ؾ� �ϴ� �۾�
        indegree[work] = prev.length();
        for (int i = 0; i < prev.length(); i++)
            graph[prev[i] - 'A'].push_back(work);
    }

    //���� & ���
    cout << topologicalSort(days, indegree, graph);
}