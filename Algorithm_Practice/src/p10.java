//���� 1463
//1�� �����
// ������ 3, ������ 2, -1
//dp
import java.io.*;
public class p10 {

	private static int n;
	private static int dp[] = new int [1000000];
	private static int count;
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		count = 0;
		
		//��������
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		
		for(int i=4; i<=n; i++) {
			//�ʱ�ȭ
			int count1 = 1000000;
			int count2 = 1000000;
			int count3 = 1000000;
			
			//-1 ����
			count1 = 1+ dp[i-1];
			//������2 ����
			if(i%2==0)
				count2 = 1+dp[i/2];
			//������3 ����
			if(i%3==0)
				count3 = 1+dp[i/3];
			
			//count1,2,3 �� ���� ���� �� ã��
			int a = Math.min(count1, count2);
			count = Math.min(count3, a);
			
			dp[i]= count;
		}
		br.close();
		
		System.out.println(dp[n]);
		
	}

}
