//백준 10025
//게으른 백곰
//two pointer
import java.io.*;
public class p24 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//입력
		String brr[] = br.readLine().split(" ");
		int n = Integer.parseInt(brr[0]);
		int k = Integer.parseInt(brr[1]);
		int ice[] = new int [1000001];
		int pre[] = new int[2000001];
		int result=0;
		
		for(int i=0; i<n; i++) {
			brr = br.readLine().split(" ");
			int g = Integer.parseInt(brr[0]);
			int x = Integer.parseInt(brr[1]);
			ice[x]=g;
		}
		
		//누적합 이용
		pre[0] = ice[0];
		for(int i=1; i<=1000000; i++) {
			pre[i] = pre[i-1]+ice[i];
		}
		
		if(k<=1000000) {
			for(int i=0; i<=1000000; i++) {
				if(i+k<=1000000 && i-k>=1)
					result = Math.max(result, pre[i+k]-pre[i-k-1]);
			}
			System.out.println(result);
		}
		else
			System.out.println(pre[1000000]);
	}

}
