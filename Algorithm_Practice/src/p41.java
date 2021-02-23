//2579
//��� ������
//dp
import java.util.*;
public class p41 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int point[] = new int [n];
		int dp[] = new int [n];
		
		for(int i=0; i<n; i++) {
			point[i] = sc.nextInt();
		}
		
		dp[0] = point[0]; //ù ��° ���
		dp[1] = Math.max(point[0]+point[1], point[1]); //�� ��° ��� - ù ��° ��� ���� �� ��° ��� / �ٷ� �� ��° ���
		dp[2] = Math.max(point[0]+point[2], point[1]+point[2]); //�� ��° ��� - ù ��° ��� ���� �� ��° ��� / �� ��° ��� ���� �� ��° ���
		
		for(int i=3; i<n; i++) {
			dp[i] = Math.max(dp[i-2]+point[i], dp[i-3]+point[i-1]+point[i]);
		}
		
		System.out.println(dp[n-1]);
		
	}

}
