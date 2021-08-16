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
			if (minprice == price[i])minidx = i; //기름 가격이 최소인 곳 인덱스 저장
		}
	}

	/*풀이 과정-이렇게 하면 될 것 같다.
	첫 번째 주유소, if 첫 번째 주유소 가격이 두 번째 주유소 가격보다 비싸다면 
						두 번째 주유소 갈만큼만 넣기
					else
						첫 번째 주유소 가격을 기준 가격으로 정하고 첫 번째 이후의 주유소 가격을 따져본다.
	
	이후 기준 가격보다 적으면 기준 가격으로 재지정하고 거리와 가격을 곱해서 더해나간다.
	*/
	
	sumprice = price[0] * dist[0]; //첫 번째 주유소
	oilprice = price[0];

	for (int i = 1; i < N - 1; i++) { 
		if (oilprice > price[i]) {
			oilprice = price[i];
		}
		
		sumprice += oilprice * dist[i];

	}
	

	cout << sumprice;
}