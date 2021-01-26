//백준 2343
//기타레슨
import java.io.*;
public class p16 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//입력
		String arr[] = br.readLine().split(" ");
		int n = Integer.parseInt(arr[0]);
		int m = Integer.parseInt(arr[1]);
		
		String arr1[] = br.readLine().split(" ");
		int size[] = new int [n];
		
		int sum = 0; //합계
		int max = 0; //가장 큰 값
		for(int i=0; i<n; i++) {
			size[i] = Integer.parseInt(arr1[i]);
			if(max<size[i])
				max = size[i];
			sum += size[i];
		}
		
		
		int left = max; 
		int right = sum;
		int mid = 0;
		
		while(left<=right) {
			int bcount = 0; //블루레이 개수
			int bsize = 0; //하나의 블루레이 크기
			
			mid = (left+right)/2;
			
			for(int i=0; i<n; i++) {
				if(bsize + size[i] > mid) { //크기가 임의의 블루레이 크기를 넘으면 블루레이 개수를 하나 증가시키고 블루레이 크기는 0으로 리셋
					bsize = 0;
					bcount++;
				}
				bsize += size[i]; //크기가 임의의 블루레이 크기를 안 넘으면 블루레이 크기에 추가
				
			}
			
			if(bsize != 0) { 
				
				bcount++;
			}
			
			if(bcount <= m ) //블루레이의 개수가 m이하인 경우
				right = mid-1; //크기가 작아지게 한다.
			else
				left = mid+1; //크기가 커지게 한다.
		}
		
		System.out.println(left);
		

	}

}
