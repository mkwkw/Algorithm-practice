//백준 1260
//dfs bfs
import java.io.*;
import java.util.*;
public class p30 {
	
	public static int mat[][]; //인접 행렬
	public static boolean visited[]; //방문했는지 나타낼 배열
	public static int n, m, v;

	public static void dfs(int i) { //깊게
		visited[i] = true; //i노드가 방문되었다.
		System.out.print(i + " ");
		for(int j=1; j<=n; j++) {
			if(mat[i][j]==1 && visited[j]==false) {
				dfs(j);
			} //i노드와 j노드가 연결되어 있고 j노드가 방문되지 않았다면 j노드에 대한 dfs시행
		}
	}
	
	public static void bfs(int i) { //넓게
		Queue<Integer> que = new LinkedList<Integer>(); //큐 이용
		que.offer(i);
		visited[i] = true; //i노드가 방문되었다.
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
		
		for(int i=0; i<=n; i++) { //인접 행렬 원소 모두 0으로 초기화
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
		Arrays.fill(visited, false); //방문했는지 나타내는 배열 모두 false로 초기화
		bfs(v);

	}

}
