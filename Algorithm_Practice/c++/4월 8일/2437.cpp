#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findUnmeasurable(vector<int> &weight) {
    int sum = 0;

    for (int i = 0; i < weight.size(); i++) {
        if (sum + 1 < weight[i]) {
            return sum + 1;
        }
        sum += weight[i];
    }
    return sum + 1;
}

/**
 * [����]
 *
 * ���� ������ ���� �������� �ľ��ؾ� �ϹǷ�, ������������ �����Ѵ�.
 * ���� 0���� scope���� ��� ���Ը� �������� ���������ϴٰ� ���� ��, ���ο� ���Դ� scope + 1���� �۰ų� ���ƾ� �Ѵ�.
 * ex) ���� 1~5���� ���� �����ѵ�, ���� ���� 7�� ��� -> 6�� ���� �Ұ�
 *
 * ���� �� ������ ������ ���, ���� ������ ������ [1, scope + ���ο� ����]�� ���ŵȴ�.
 * ��� ������ ����ôµ��� ����ִ� ���� ������, scope + 1 ����
 */

int main() {
    int n;

    //�Է�
    cin >> n;
    vector<int> weight(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    //����
    sort(weight.begin(), weight.end());

    //���� & ���
    cout << findUnmeasurable(weight);
    return 0;
}