//백준 2343
//기타레슨
import java.io.*;
public class p16 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String arr[] = br.readLine().split(" ");
		int n = Integer.parseInt(arr[0]);
		int m = Integer.parseInt(arr[1]);
		
		String arr1[] = br.readLine().split(" ");
		int size[] = new int [n];
		int sum = 0;
		int max = 0;
		for(int i=0; i<n; i++) {
			size[i] = Integer.parseInt(arr1[i]);
			if(max<size[i])
				max = size[i];
			sum += size[i];
		}
		
		
		int narr[] = new int [100001];
		for(int i=0; i<100001; i++) {
			narr[i]=0;
		}
		int left = max;
		int right = sum;
		int mid = 0;
		
		while(left<=right) {
			int bcount = 0; //블루레이 개수
			int bsize = 0; //블루레이 크기
			
			mid = (left+right)/2;
			
			for(int i=0; i<n; i++) {
				if(bsize + size[i] > mid) {
					bsize = 0;
					bcount++;
				}
				bsize += size[i];
				
			}
			
			if(bsize != 0)
				bcount++;
			
			if(bcount <= m )
				right = mid-1;
			else
				left = mid+1;
		}
		
		System.out.println(left);
		

	}

}
