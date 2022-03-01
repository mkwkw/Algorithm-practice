#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int>& score) {
	int answer=0;
	vector<int> dp;
	dp.assign(score.size(),0);
	
    //n위치까지 가는 경우: n-3까지 오고 n-1계단 밟고, n 계단 밟기 / n-2까지 오고 n 계단 밟기

	dp[0]=score[0];
	dp[1]=max(score[1], score[0]+score[1]);
	dp[2]=max(score[0]+score[2], score[1]+score[2]);
	
	for(int i=3; i<score.size(); i++){
		dp[i]= max(dp[i-3]+score[i-1]+score[i], dp[i-2]+score[i]);
	}
	
	answer = dp[score.size()-1];	
	return answer; // 최대점수가 저장되어 있는 마지막 계단의 점수값 리턴
}

int main() {
	int n; // 계단의 개수 n
	cin >> n;
	int answer;
	vector<int> score(n + 1, 0); // 계단의 점수를 저장할 변수 선언, 동시에 초기화
			   // -> 1번째 index부터 저장하기 위해, 계단의 개수 + 1 만큼 크기 할당
	for (int i = 1; i <= n; i++)
		cin >> score[i];
	
	answer = solution(n, score);
	cout << answer;
}