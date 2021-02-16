//11780
//플로이드와샬
import java.io.*;
import java.util.*;
public class p36 {
	public static int n, m;
	public static int dist[][];
	public static String brr[];
	public static final int INF = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());
		dist = new int [n+1][n+1];
		//초기화
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
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
			
			dist[a][b] = Math.min(dist[a][b], c);
			
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
					dist[i][j] = Math.min(dist[i][j], stopover);
					
					
					
				}
				
			}
			
		}
		
		
	
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				System.out.print(dist[i][j]+" ");
			}
			System.out.println();
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				
			}
		}
		
		
	}

}
