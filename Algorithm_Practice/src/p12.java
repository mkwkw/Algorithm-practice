//백준 11931
//내림차순 정렬
import java.io.*;
import java.util.*;
public class p12 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int n = Integer.parseInt(br.readLine());
		int arr[] = new int [n];
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			
		}
		
		Arrays.sort(arr);
		
		for(int i=n-1; i>=0; i--) {
			sb.append(arr[i]+"\n");
		}
		
		System.out.print(sb);
		br.close();
		
	}

}
