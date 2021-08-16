#include <iostream>

using namespace std;
	int arr[1001][1001];
	int dp[1001][1001];
	int N=1001, M=1001;

int main() {
	

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}


	
	int tmp = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp = max(dp[i - 1][j], dp[i][j - 1]);
			tmp = max(tmp, dp[i - 1][j - 1]);
			dp[i][j] = dp[i][j] + tmp;
		}
	}

	int result = dp[N][M];
	cout << result;
	return 0;
}