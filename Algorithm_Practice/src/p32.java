//2606 바이러스
//그래프
//dfs 이용 -> 인접행렬 이용
import java.io.*;
import java.util.*;
public class p32 {
	public static int mat[][]; //인접 행렬
	public static boolean visited[]; //방문했는지 나타낼 배열
	public static int n,m, count;
	
	public static void dfs(int i) { //일반적인 dfs이용
		visited[i] = true; //i노드가 방문되었다.
		for(int j=1; j<=n; j++) {
			if(mat[i][j]==1 && visited[j]==false) {
				dfs(j);
				count++;
			} //i노드와 j노드가 연결되어 있고 j노드가 방문되지 않았다면 j노드에 대한 dfs시행
		}
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		n = Integer.parseInt(br.readLine()); //컴퓨터의 수
		m = Integer.parseInt(br.readLine()); //연결되어 있는 컴퓨터 쌍의 수
		
		mat = new int [n+1][n+1]; //인접 행렬
		visited = new boolean [n+1]; //방문했는지 나타내는 배열
		
		for(int i=0; i<=n; i++) { //인접 행렬 원소 모두 0으로 초기화
			Arrays.fill(mat[i], 0);
		}
		
		for(int i=0; i<=n; i++) { //visited 배열 모두 false로 초기화
			Arrays.fill(visited, false);
		}
		
		for(int i=0; i<m; i++) { //컴퓨터 간의 연결 표시
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
