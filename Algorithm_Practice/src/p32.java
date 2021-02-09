//2606 ���̷���
//�׷���
//dfs �̿� -> ������� �̿�
import java.io.*;
import java.util.*;
public class p32 {
	public static int mat[][]; //���� ���
	public static boolean visited[]; //�湮�ߴ��� ��Ÿ�� �迭
	public static int n,m, count;
	
	public static void dfs(int i) { //�Ϲ����� dfs�̿�
		visited[i] = true; //i��尡 �湮�Ǿ���.
		for(int j=1; j<=n; j++) {
			if(mat[i][j]==1 && visited[j]==false) {
				dfs(j);
				count++;
			} //i���� j��尡 ����Ǿ� �ְ� j��尡 �湮���� �ʾҴٸ� j��忡 ���� dfs����
		}
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine()); //��ǻ���� ��
		m = Integer.parseInt(br.readLine()); //����Ǿ� �ִ� ��ǻ�� ���� ��
		
		mat = new int [n+1][n+1]; //���� ���
		visited = new boolean [n+1]; //�湮�ߴ��� ��Ÿ���� �迭
		
		for(int i=0; i<=n; i++) { //���� ��� ���� ��� 0���� �ʱ�ȭ
			Arrays.fill(mat[i], 0);
		}
		
		for(int i=0; i<=n; i++) { //visited �迭 ��� false�� �ʱ�ȭ
			Arrays.fill(visited, false);
		}
		
		for(int i=0; i<m; i++) { //��ǻ�� ���� ���� ǥ��
			String brr[] = br.readLine().split(" ");
			int a = Integer.parseInt(brr[0]);
			int b = Integer.parseInt(brr[1]);
			
			mat[a][b]=1;
			mat[b][a]=1;
		}
		
		dfs(1);
		System.out.println(count);

	}

}
