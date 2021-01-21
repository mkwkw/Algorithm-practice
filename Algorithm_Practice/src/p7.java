//백준 2748
//피보나치 수 2
//dp
import java.io.*;
public class p7 {
	
	private static int arr[] = new int [91];
	private static int fib(int n) {
		if(arr[n]==-1) {
			arr[n]= fib(n-1)+fib(n-2);
		}
		
		return arr[n];
			
	}

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		for(int i=0; i<n+1; i++){
			arr[i] = -1;
		}
		arr[0]=0;
		arr[1]=1;
		System.out.println(fib(n));
		br.close();
	}

}
