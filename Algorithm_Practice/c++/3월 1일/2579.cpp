#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int>& score) {
	int answer=0;
	vector<int> dp;
	dp.assign(score.size(),0);
	
    //n��ġ���� ���� ���: n-3���� ���� n-1��� ���, n ��� ��� / n-2���� ���� n ��� ���

	dp[0]=score[0];
	dp[1]=max(score[1], score[0]+score[1]);
	dp[2]=max(score[0]+score[2], score[1]+score[2]);
	
	for(int i=3; i<score.size(); i++){
		dp[i]= max(dp[i-3]+score[i-1]+score[i], dp[i-2]+score[i]);
	}
	
	answer = dp[score.size()-1];	
	return answer; // �ִ������� ����Ǿ� �ִ� ������ ����� ������ ����
}

int main() {
	int n; // ����� ���� n
	cin >> n;
	int answer;
	vector<int> score(n + 1, 0); // ����� ������ ������ ���� ����, ���ÿ� �ʱ�ȭ
			   // -> 1��° index���� �����ϱ� ����, ����� ���� + 1 ��ŭ ũ�� �Ҵ�
	for (int i = 1; i <= n; i++)
		cin >> score[i];
	
	answer = solution(n, score);
	cout << answer;
}