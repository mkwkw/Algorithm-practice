//백준 20500
//n자리의 수 중 15의 배수 중에 1과 5로만 이루어진 수 찾기
import java.io.*;
public class p9 {
	
	private static int arr [] = new int [1515];
	private static int n;
	private static int count;
	private static int func(int n) {
		//arr[n] : n자리 수 중 1과 5만으로 이루어진 수의 개수
		arr[1]=0; //1의 자리: 15의 배수 없음
		arr[2]=1; //10의 자리: 15 1개
		arr[3]=1; //100의 자리: 555 1개
		
		//맨 끝 자리는 무조건 5
		//그 앞의 n-1자리는 1또는 5
		//n-1자리에 1과 5를 어떻게 배치하느냐
		//맨 끝의 5와 합친 n자리의 수가 15의 배수이냐
		
		int num [] = new int [(int)Math.pow(2,n-1)];
		num[(int)Math.pow(2,n-1)] = 5;
		
		
		
		
		return 0;
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		long[] dp = new long[n+3];
		dp[2]=1;
		dp[3]=1;
		for(int i=4; i<=n; i++) {
			dp[i] = (((dp[i-2]*2)%1000000007)+dp[i-1])%1000000007;
		}
		System.out.println(dp[n]);
	}

}
