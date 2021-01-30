//백준 11660
//구간 합 이차원 배열
import java.io.*;
public class p19 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String brr[] = br.readLine().split(" ");
		int n = Integer.parseInt(brr[0]);
		int m = Integer.parseInt(brr[1]);
		
		int num[][] = new int [n+1][n+1];
		int pre[][] = new int [n+1][n+1]; //pre[i][j]: (0,0)부터 (i,j)까지 원소를 모두 합친 값
		
		
		for(int i=1; i<=n; i++) {
			String brrr[] = br.readLine().split(" ");
			
			for(int j=1; j<=n; j++) {
				num[i][j]= Integer.parseInt(brrr[j-1]);
			
				pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + num[i][j]; 
			}
		}
		
		
		
		
		for(int i=0; i<m; i++) {
			String brrrr[] = br.readLine().split(" ");
			int x1 = Integer.parseInt(brrrr[0]);
			int y1 = Integer.parseInt(brrrr[1]);
			int x2 = Integer.parseInt(brrrr[2]);
			int y2 = Integer.parseInt(brrrr[3]);
			
			int result = pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
			System.out.println(result);
		}
		br.close();
		

	}

}
