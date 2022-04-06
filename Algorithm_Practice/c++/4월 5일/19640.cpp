#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct info {
    int d, h, order, line; //�ٹ� �ϼ�, ���� ����, ������ ����, �� ��ȣ
};

struct cmp {
    bool operator()(const info &a, const info &b) {
        if (a.d != b.d) {
            return a.d < b.d;
        }
        if (a.h != b.h) {
            return a.h < b.h;
        }
        return a.line > b.line;
    }
};

int simulation(vector<queue<info>> &people_line, int &k) {
    int ans = 0;
    priority_queue<info, vector<info>, cmp> pq; //���θ� ������ �켱���� ť

    for (int i = 0; i < people_line.size(); i++) {
        if (!people_line[i].empty()) { //�ش� ��(i)�� ����� ������
            pq.push(people_line[i].front());
            people_line[i].pop();
        }
    }

    while (pq.top().order != k) {
        ans++;

        info people = pq.top();
        pq.pop();
        if (!people_line[people.line].empty()) { //�ش� �ٿ� ����� ������
            pq.push(people_line[people.line].front());
            people_line[people.line].pop();
        }
    }
    return ans;
}

/**
 * [ȭ����� ��Ģ] - �ùķ��̼� ����
 *
 * 1. �� ����� �� ���� % m ��° ���� �ڿ� ���� �ȴ�.
 * 2. �� ����, ��� ���� �� ��� �߿� �켱 ������ ���� ���� ������� ȭ����� �̿��Ѵ�.
 *
 * <�켱����>
 * 1. �ٹ� ���ڰ� ���� ���
 * 2. �� ���� ���
 * 3. �� ��ȣ�� �ռ� ���
 *
 * ---
 * 1. �� ���� ���� �� ����� ���� ������ ������, ť�� �̿��� �����Ѵ�.
 * 2. ��� ���� ���θ� �켱���� ť�� �ְ�, �켱������ ���� �ռ� ������� �����Ѵ�.
 * 3. � ���� ���ΰ� ȭ����� �̿�������, �� ���� ���θ� �켱 ���� ť�� �ִ´�.
 *
 * �̶�, 0������ ǥ���ϹǷ� ��ī�� order�� k�� �ȴ�.
 *
 * !����! ť���� ����� ���� �켱 ���� ť�� ���� ��, �׻� ť�� ������� ������ Ȯ��
 */

int main() {
    int n, m, k, d, h;

    //�Է�
    cin >> n >> m >> k;
    vector<queue<info>> people_line(m, queue<info>());
    for (int i = 0; i < n; i++) {
        cin >> d >> h;
        people_line[i % m].push({d, h, i, i % m});
    }

    //���� & ���
    cout << simulation(people_line, k);
    return 0;
}