#include <iostream>

using namespace std;

const int SIZE = 15;

int n, ans;
bool check_col[SIZE]; //�� üũ
bool check_left[SIZE * 2]; //������ �밢�� üũ
bool check_right[SIZE * 2]; //������ �밢�� üũ

void backtracking(int cnt) { //cnt: �� - ���� �࿡�� ������ �ٸ� ���� ���� �����Ƿ� ���� �밢���� �˻�
    if (cnt == n) { //��������, n���� ���� ��� ����
        ans++; //���� ����
        return;
    }
    for (int i = 0; i < n; i++) { //i: ��
        if (!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]) { //��� false���� ��ġ ����
            //(cnt, i)�� �� ��ġ -> �׿� ���� ��, ������ �밢��, ������ �밢�� üũ����
            check_col[i] = true;
            check_left[cnt + i] = true;
            check_right[cnt - i + n] = true;
            backtracking(cnt + 1); //���� �� ȣ��
            //��Ž���� �����ϵ��� �������·� ��������
            check_col[i] = false;
            check_left[cnt + i] = false;
            check_right[cnt - i + n] = false;
        }
    }

}

int main() {
    //�Է�
    cin >> n;

    //����
    backtracking(0);

    //���
    cout << ans << '\n';

    return 0;
}

//��Ʈ��ŷ
//�� ���� �ݺ� - ������ ���� �࿡ �� ���� �� �� �´�. �� �࿡ �ϳ���
//n����� �ݺ��ϸ� ��.