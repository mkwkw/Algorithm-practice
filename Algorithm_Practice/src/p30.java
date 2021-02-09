//���� 1260
//dfs bfs
import java.io.*;
import java.util.*;
public class p30 {
	
	public static int mat[][]; //���� ���
	public static boolean visited[]; //�湮�ߴ��� ��Ÿ�� �迭
	public static int n, m, v;

	public static void dfs(int i) { //���
		visited[i] = true; //i��尡 �湮�Ǿ���.
		System.out.print(i + " ");
		for(int j=1; j<=n; j++) {
			if(mat[i][j]==1 && visited[j]==false) {
				dfs(j);
			} //i���� j��尡 ����Ǿ� �ְ� j��尡 �湮���� �ʾҴٸ� j��忡 ���� dfs����
		}
	}
	
	public static void bfs(int i) { //�а�
		Queue<Integer> que = new LinkedList<Integer>(); //ť �̿�
		que.offer(i);
		visited[i] = true; //i��尡 �湮�Ǿ���.
		while(!que.isEmpty()) {
			int p = que.poll();
			System.out.print(p+" ");
			
			for(int j=1; j<=n; j++) {
				if(mat[p][j]==1 && visited[j]==false) {
					que.offer(j);
					visited[j] = true;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String brr[] = br.readLine().split(" ");
		int n = Integer.parseInt(brr[0]);
		int m = Integer.parseInt(brr[1]);
		int v = Integer.parseInt(brr[2]);
		
		mat = new int [n+1][n+1];
		visited = new boolean [n+1];
		
		for(int i=0; i<=n; i++) { //���� ��� ���� ��� 0���� �ʱ�ȭ
			Arrays.fill(mat[i], 0);
		}
		
		for(int i=0; i<m; i++) {
			String edge[] = br.readLine().split(" ");
			int a = Integer.parseInt(edge[0]);
			int b = Integer.parseInt(edge[1]);
			mat[a][b]=1;
			mat[b][a]=1;
		}
		dfs(v);
		System.out.println();
		Arrays.fill(visited, false); //�湮�ߴ��� ��Ÿ���� �迭 ��� false�� �ʱ�ȭ
		bfs(v);

	}

}
