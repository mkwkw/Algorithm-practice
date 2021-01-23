//백준 1463
//1로 만들기
// 나누기 3, 나누기 2, -1
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
		
		//기저조건
		dp[1] = 0;
		dp[2] = 1;
		dp[3] = 1;
		
		for(int i=4; i<=n; i++) {
			//초기화
			int count1 = 1000000;
			int count2 = 1000000;
			int count3 = 1000000;
			
			//-1 먼저
			count1 = 1+ dp[i-1];
			//나누기2 먼저
			if(i%2==0)
				count2 = 1+dp[i/2];
			//나누기3 먼저
			if(i%3==0)
				count3 = 1+dp[i/3];
			
			//count1,2,3 중 가장 작은 값 찾기
			int a = Math.min(count1, count2);
			count = Math.min(count3, a);
			
			dp[i]= count;
		}
		br.close();
		
		System.out.println(dp[n]);
		
	}

}
