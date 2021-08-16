#include <iostream>
using namespace std;

int N;
long long dist[100001];
long long price[100001];
long long minprice;
long long minidx;
long long sumprice=0;
long long oilprice=0;
long long gasdist = 0;
int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> dist[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> price[i];
		minprice = price[0];
		if (i != N - 2) {
			minprice = min(price[i], minprice);
			if (minprice == price[i])minidx = i; //�⸧ ������ �ּ��� �� �ε��� ����
		}
	}

	/*Ǯ�� ����-�̷��� �ϸ� �� �� ����.
	ù ��° ������, if ù ��° ������ ������ �� ��° ������ ���ݺ��� ��δٸ� 
						�� ��° ������ ����ŭ�� �ֱ�
					else
						ù ��° ������ ������ ���� �������� ���ϰ� ù ��° ������ ������ ������ ��������.
	
	���� ���� ���ݺ��� ������ ���� �������� �������ϰ� �Ÿ��� ������ ���ؼ� ���س�����.
	*/
	
	sumprice = price[0] * dist[0]; //ù ��° ������
	oilprice = price[0];

	for (int i = 1; i < N - 1; i++) { 
		if (oilprice > price[i]) {
			oilprice = price[i];
		}
		
		sumprice += oilprice * dist[i];

	}
	

	cout << sumprice;
}