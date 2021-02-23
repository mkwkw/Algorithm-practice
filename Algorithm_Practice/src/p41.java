//2579
//계단 오르기
//dp
import java.util.*;
public class p41 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int point[] = new int [300];
		int dp[] = new int [300];
		
		for(int i=0; i<n; i++) {
			point[i] = sc.nextInt();
		}
		
		dp[0] = point[0]; //첫 번째 계단
		dp[1] = Math.max(point[0]+point[1], point[1]); //두 번째 계단 - 첫 번째 계단 다음 두 번째 계단 / 바로 두 번째 계단
		dp[2] = Math.max(point[0]+point[2], point[1]+point[2]); //세 번째 계단 - 첫 번째 계단 다음 세 번째 계단 / 두 번째 계단 다음 세 번째 계단
		
		for(int i=3; i<n+1; i++) {
			dp[i] = Math.max(dp[i-2]+point[i], dp[i-3]+point[i-1]+point[i]);
		}
		
		System.out.println(dp[n-1]);
		
	}

}
