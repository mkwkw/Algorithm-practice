//2670
//dp
//?
import java.io.*;

public class p40 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		double num[] = new double [n];
		double dp[] = new double [n-2];
		double max = 0;
		
		for(int i=0; i<n; i++) {
			num[i] = Double.parseDouble(br.readLine());
		}
		
		for(int i=0; i<n-2; i++) {
			dp[i] = num[i]*num[i+1]*num[i+2];
			if(max<dp[i])
				max = dp[i];
		}
		max = Math.round(max*1000)/1000.0;
		System.out.println(max);
		
		

	}

}
