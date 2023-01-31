#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<pair<long long, long long>> pinary;
    int n;

    cin>>n;

    pinary.assign(91,{0,0}); //{0���� ������ ��ģ�� ����, 1�� ������ ��ģ�� ����}

    pinary[1] = {0,1}; //1�ڸ� ��ģ��: 1 -> 1�� ������ ��ģ�� 1��
    pinary[2] = {1,0}; //2�ڸ� ��ģ��: 10 -> 0���� ������ ��ģ�� 1��
    pinary[3] = {1,1}; //3�ڸ� ��ģ��: 100, 101 -> 0���� ������ ��ģ�� 1��, 1�� ������ ��ģ�� 1��
    
    //0���� ������ ���� �ڸ����� 1,0 ���� �� ����
    //1�� ������ ���� �ڸ����� 0�� ���� �� ����

    for(int i=4; i<=n; i++){
        //i�ڸ� ��ģ��
        pinary[i].first = pinary[i-1].first + pinary[i-1].second; //i-1�ڸ� ��ģ�� ���� (0���� ������ ��ģ�� ���� + 1�� ������ ��ģ�� ����) 
        pinary[i].second = pinary[i-1].first; //i-1�ڸ� ��ģ�� �� 0���� ������ ��ģ�� ����
    }

    cout<<pinary[n].first+pinary[n].second;
}

//�ڷ��� ���� ����!
//pair<int, int>�� �ϸ� n�� Ŭ �� (ex. n=90) �����÷ο� �߻�
//int ��� long long���� �ٲ��־����.

