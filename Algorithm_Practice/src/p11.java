//백준 1757
//달려달려
//dp
import java.io.*;
public class p11 {

	private static int n,m;
	private static int dp[][][] = new int [10005][505][2];
	private static int darr[] = new int [10001]; //거리
	//dp[x][y][z]: x분에 y의 지침지수를 가지고 z(뛰고 있는가 쉬고 있는가), 달린 거리의 최댓값
	//x-1에서의 정보 확인 필요
	
	//1. 학생들은 쉬기 시작하면 지침지수가 0이 되기 전에는 다시 달릴 수 없다.
	//2. 0일 때 쉬면 지침지수는 그대로 0이다.
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String arr[] = br.readLine().split(" ");
		n = Integer.parseInt(arr[0]);
		m = Integer.parseInt(arr[1]);
		
		darr[0]=0;
		for(int i=1; i<=n; i++) {
			darr[i] = Integer.parseInt(br.readLine());
		}
		
		
		for(int i=1; i<=n; i++) {
			for(int j=0; j<=m; j++) {
				if(j!=1) { //지침지수가 1이 아니라면
					if(j!=0) {//지침지수가 0
						dp[i][j][1] = dp[i-1][j-1][1]+darr[i];
						dp[i][j][0] = Math.max(dp[i-1][j+1][1], dp[i-1][j+1][0]);
						
					}
					else {
						int a = Math.max(dp[i-1][j+1][0], dp[i-1][j+1][1]);
						dp[i][j][0] = Math.max(dp[i-1][j][0], a);
					}
				}
				else {
					dp[i][j][1] = Math.max(dp[i-1][j-1][1], dp[i-1][j-1][0])+darr[i];
					dp[i][j][0] = Math.max(dp[i-1][j+1][1], dp[i-1][j+1][0]);
				}
			}
			
			
		}
		
	
		System.out.println(dp[n][0][0]);
		

	}

}
