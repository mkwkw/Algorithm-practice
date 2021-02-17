//11780
//플로이드와샬
import java.io.*;
import java.util.*;
public class p36 {
	public static int n, m;
	public static int dist[][];
	public static int node[][]; //거치는 경유 정점들 저장
	public static String brr[];
	public static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		n = Integer.parseInt(br.readLine());  //도시 개수 -> 정점 개수
		m = Integer.parseInt(br.readLine()); //버스 개수 -> 간선 개수
		dist = new int [n+1][n+1]; //모든 정점에서 모든 정점으로의 최소 거리 저장
		node = new int [n+1][n+1]; //경로에서의 정점 구하기
		
		
		//초기화
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				node[i][j]=-1;
				if(i==j)
					dist[i][j] = 0; 
				else
					dist[i][j] = INF;
			}
		}
		
		
		for(int i=0; i<m; i++) {
			int a, b, c;
			brr = br.readLine().split(" ");
			a = Integer.parseInt(brr[0]);
			b = Integer.parseInt(brr[1]);
			c = Integer.parseInt(brr[2]);
			
			dist[a][b] = Math.min(dist[a][b], c); //입력 값 중에 작은 값 저장
			node[a][b] = a; //시작점 저장
			
		}
		
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					
					int stopover = 0; //경유하는 경로 값 저장
					
					//오버플로우 예외처리
					try{
						stopover = dist[i][k]+dist[k][j];
						if(stopover- Integer.MAX_VALUE>0)
							throw new Exception();
					}
					catch(Exception e) {
						stopover = INF;
					}
					dist[i][j] = Math.min(dist[i][j], stopover); //직통 값과 경유 값 중에서 작은 값을 dist[i][j]에 저장
					
					if(dist[i][j]==stopover) //경유한다면 경유지점을 node배열에 저장
						node[i][j] = node[k][j];
					
					
				}
				
			}
			
		}
		
		
		//nXn 출력
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				System.out.print(dist[i][j]+" ");
			}
			System.out.println();
		}
		
		//경로 출력
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				
				if(node[i][j]==-1)
					System.out.println(0);
				else {
					Stack<Integer> path = new Stack<>();
					int pre = j;
					path.add(j); //거쳐가는 정점 저장
					while(i!=node[i][pre]) {
						pre = node[i][pre];
						path.push(pre);
					}
					
					System.out.print(path.size()+1+" " +i +" ");
					while(!path.empty()) {
						System.out.print(path.pop()+" ");
					}
					System.out.println();
				}
			}
		}
		
	
		
		
	}

}
