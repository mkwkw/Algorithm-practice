#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 5000000;

//�Ҽ� ��� �����ؼ� �����ϴ� �Լ�
vector<int> isPrime() {
    vector<int> prime(SIZE + 1, 0); //�Ҽ��� ��� �迭: ���� �ε��� i�� �Ҽ���� i�� �����, i�� 4��� 2����

    //���� ��� ���� �Ҽ��� �����ϰ�, i��° �ε����� i�� ����
    for (int i = 2; i <= SIZE; i++)
        prime[i] = i;

    //�Ҽ� �Ǻ�
    for (int i = 2; i <= sqrt(SIZE); i++) {
        if (prime[i] == i) { //�Ҽ����
            for (int j = i * i; j <= SIZE; j += i) { //���(j+=i)�� �Ҽ�(i) ����
                if (prime[j] == j) { //����� �Ҽ��� ���� ��츸
                    prime[j] = i; //�Ҽ� ����
                }
            }
        }
    }

    return prime;
}

int main() {
    //����� �ӵ� ���
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    //�Է�
    cin >> n;

    //�̸� �ִ� ũ������� �Ҽ� ��� ����
    vector<int> prime = isPrime();

    //�Է�+����+���
    while (n--) {
        //���μ������� �� �Է�
        cin >> k;
        //���μ����� ��� ���
        while (k > 1) {
            cout << prime[k] << ' ';
            k = k / prime[k];
        }
        cout << '\n';
    }
    return 0;
}