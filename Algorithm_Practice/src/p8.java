//백준 15988
//dp
//+1,+2,+3으로 만들 수 있는 경우의 수 최소
import java.util.*;
public class p8 {

	private static int n;
	private static int arr[];
	private static long dp[] = new long [1000010];
	private static long mod = 1000000009;
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		arr = new int [n];
		//입력 저장
		for(int i=0; i<n; i++) {
			arr[i]= sc.nextInt();
		}
		 
		//기저 조건
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		
		//+1, +2, +3인 경우 세 가지 존재
		for(int i=4; i<=1000000; i++) {
			dp[i] += dp[i-1]+dp[i-2]+dp[i-3];
			dp[i] %= mod;
		}
		
		for(int i=0; i<n; i++) {
			System.out.println(dp[arr[i]]);
		}
	}

}
