//���� 12865
//����� �賶
import java.util.*;
public class p15 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //���� ����
		int k = sc.nextInt(); //������ ����
	
		int w[] = new int [n+1]; //�� ������ ����
		int v[] = new int [n+1]; //�� ������ ��ġ
		
		//dp[���� ���� ����][���� �賶 ����]=���簡ġ
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
				if(j<w[i]) //j(�־��� ��ü �賶����)<���� �賶����
					dp[i][j] = dp[i-1][j]; //��ġ�� ���� ��ġ�� ����
				else //�־��� ��ü �賶���� >= ���� �賶����
					dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
					//��ġ�� ���� ��ġ�� ���� �賶���Ը� �������� ���� ��ġ�� ���� ��ġ�� ���� �� �� �ִ�
			}
		}
		int result = dp[n][k]; //n���� ����, �ִ� k������ �� �ִ� ��ġ
		System.out.println(result);
		sc.close();
		
		
	}

}
