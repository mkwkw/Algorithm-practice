#include <iostream>
#include <vector>

using namespace std;

int prime(int n, int k){
    vector<bool> is_prime(n + 1, true);
    int cnt = 0; //ī��Ʈ ����
    //�����ٱ��� �˻��� ��� �ݷ�: k��° �������� ���� ������ �̻��� �Ҽ��� ���
    //���� �� ���������� �� n���� ������ ��
    for (int i = 2; i <= n; i++) { 
        if (is_prime[i]) { //i�� �Ҽ����
            for (int j = i; j <= n; j += i) { //�� �������� i��°�� ����� ���� �����ϹǷ� i���� i�� ��� ����
                if (!is_prime[j]) //�̹� ������ ����� �Ѿ
                    continue;
                
                is_prime[j] = false; //i�� ����� ����
                if (++cnt == k)
                    return j; //k��° ����� �� ����
            }
        }
    }
    //k��° ����� �� ���ٸ� -1 ����
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, answer;

    cin>>n>>k;

    answer = prime(n,k);

    cout<<answer;
}

//set���� �����ұ�? -> ��ȸ �� �񱳰� ���ŷο�
//queue�� �����ұ�? -> �ð��ʰ� �߻� //pop�� push ��� �ݺ�
//vector<bool>�� �����ϰ� �ε����� ����ó�� �����ؼ� 2�� for ������ �Ҽ� p ���� �� p�� ��� �����
//�ش� �ε����� ��������/������ �ε����̴� = false