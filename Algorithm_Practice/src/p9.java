//���� 20500
//n�ڸ��� �� �� 15�� ��� �߿� 1�� 5�θ� �̷���� �� ã��
import java.io.*;
public class p9 {
	
	private static int arr [] = new int [1515];
	private static int n;
	private static int count;
	private static int func(int n) {
		//arr[n] : n�ڸ� �� �� 1�� 5������ �̷���� ���� ����
		arr[1]=0; //1�� �ڸ�: 15�� ��� ����
		arr[2]=1; //10�� �ڸ�: 15 1��
		arr[3]=1; //100�� �ڸ�: 555 1��
		
		//�� �� �ڸ��� ������ 5
		//�� ���� n-1�ڸ��� 1�Ǵ� 5
		//n-1�ڸ��� 1�� 5�� ��� ��ġ�ϴ���
		//�� ���� 5�� ��ģ n�ڸ��� ���� 15�� ����̳�
		
		int num [] = new int [(int)Math.pow(2,n-1)];
		num[(int)Math.pow(2,n-1)] = 5;
		
		
		
		
		return 0;
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		long[] dp = new long[n+3];
		dp[2]=1;
		dp[3]=1;
		for(int i=4; i<=n; i++) {
			dp[i] = (((dp[i-2]*2)%1000000007)+dp[i-1])%1000000007;
		}
		System.out.println(dp[n]);
	}

}
