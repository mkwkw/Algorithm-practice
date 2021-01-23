//백준 1920
//수 찾기

import java.io.*;
import java.util.Arrays;
public class p13 {

	private static int n,m;
	private static int narr[], marr[];
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		String nsarr[] = br.readLine().split(" ");
		int narr[] = new int [n];
		for(int i=0; i<n; i++) {
			narr[i] = Integer.parseInt(nsarr[i]);
		}
		
		int m = Integer.parseInt(br.readLine());
		String msarr[] = br.readLine().split(" ");
		int marr[] = new int [m];
		
		for(int i=0; i<m; i++) {
			marr[i] = Integer.parseInt(msarr[i]);
		}	
		
		Arrays.sort(narr);
		
		for(int i=0; i<m; i++) {
			System.out.println(binary_search(narr,marr[i],0,n-1));
		}
		

	}
	
	private static int binary_search(int narr[], int value, int low, int high) {
		int left = 0;
		int right = narr.length;
		int mid;
		while(left<right) {
			mid = (left+right)/2;
			if (narr[mid]<value) {
				left=mid+1;
			
			}
			else if(narr[mid]==value)
				return 1;
			else
				right=mid;
		}
		return 0;
	}
	

}
