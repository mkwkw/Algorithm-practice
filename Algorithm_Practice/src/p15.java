//백준 12865
//평범한 배낭
import java.util.*;
public class p15 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //물건 개수
		int k = sc.nextInt(); //가능한 무게
	
		int w[] = new int [n+1]; //각 물건의 무게
		int v[] = new int [n+1]; //각 물건의 가치
		
		//dp[현재 물건 개수][현재 배낭 무게]=현재가치
		int dp[][] = new int [101][100001];
		
		w[0]=0;
		v[0]=0;
		
		for(int i=1; i<=n; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}
		
		//dp
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=k; j++) {
				if(j<w[i]) //j(주어진 전체 배낭무게)<현재 배낭무게
					dp[i][j] = dp[i-1][j]; //가치는 이전 가치와 동일
				else //주어진 전체 배낭무게 >= 현재 배낭무게
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
					//가치는 이전 가치와 현재 배낭무게를 제외했을 때의 가치에 현재 가치를 더한 것 중 최댓값
			}
		}
		int result = dp[n][k]; //n개의 물건, 최대 k무게일 때 최대 가치
		System.out.println(result);
		sc.close();
		
		
	}

}
