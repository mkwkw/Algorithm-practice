//���� 1757
//�޷��޷�
//dp
import java.io.*;
public class p11 {

	private static int n,m;
	private static int dp[][][] = new int [10005][505][2];
	private static int darr[] = new int [10001]; //�Ÿ�
	//dp[x][y][z]: x�п� y�� ��ħ������ ������ z(�ٰ� �ִ°� ���� �ִ°�), �޸� �Ÿ��� �ִ�
	//x-1������ ���� Ȯ�� �ʿ�
	
	//1. �л����� ���� �����ϸ� ��ħ������ 0�� �Ǳ� ������ �ٽ� �޸� �� ����.
	//2. 0�� �� ���� ��ħ������ �״�� 0�̴�.
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
				if(j!=1) { //��ħ������ 1�� �ƴ϶��
					if(j!=0) {//��ħ������ 0
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
