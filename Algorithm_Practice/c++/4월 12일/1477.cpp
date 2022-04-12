#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ްԼ� �� �� ��ġ�ϴ��� ���ϴ� �Լ�
int cntRest(int dist, int l, vector<int> &rest) {
    int cnt = 0;

    if (rest.size() == 0) { //ó�� �ްԼ� �ƿ� ���� ��� ���� ó��
        return (l - 1) / dist;
    }
    cnt += (rest[0] - 1) / dist;
    for (int i = 1; i < rest.size(); i++) {
        cnt += (rest[i] - rest[i - 1] - 1) / dist;
    }
    cnt += (l - rest[rest.size() - 1] - 1) / dist;
    return cnt;
}

//�ްԼҰ� ���� ������ �ִ� �� �ּڰ� ���ϴ� �Լ� -> lower bound
int lowerSearch(int left, int right, int m, int l, vector<int> &rest) {
    while (left <= right) {
        int mid = (left + right) / 2; //�ִ� ����
        int cnt = cntRest(mid, l, rest); //�� �� �ްԼ� ��ġ�ϴ���

        if (cnt > m) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

/**
 * [�ްԼ� �����]
 *
 * M���� �ްԼҸ� ���� �� �Ŀ� �ްԼҰ� ���� ������ �ִ��� �ּڰ���?
 * -> �ްԼҰ� ���� ������ �ִ��� k(������ ��)�� ��, M���� �ްԼҸ� ���� �� �ִ°�?
 *
 * left: �ްԼҰ� ���� ������ �ּڰ� -> 1
 * right: �ްԼҰ� ���� ������ �ִ� -> l - 1
 *
 * �ްԼ� ������ �ִ��� �־����� ��, �� ���� �ްԼ� ������ ���ϴ� ���
 * -> ó�� �����ϴ� �ްԼ� ������ �ִ밪���� ������ �� ���� �ִ� ������ �ִ밪�� �ǵ��� ���� ���� �ȿ� ��ġ�ؾ� �ϴ� �ްԼ� ����!
 */

int main() {
    int n, m, l;

    //�Է�
    cin >> n >> m >> l;
    vector<int> rest(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> rest[i];
    }

    //����
    sort(rest.begin(), rest.end());

    //���� & ���
    cout << lowerSearch(1, l - 1, m, l, rest);
    return 0;
}

// ��ü �Ÿ�/�ްԼ� �� �Ÿ� -> �ްԼ� ����
// �ްԼ� ������ m�� �� ������ �̺� Ž��