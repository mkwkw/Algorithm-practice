
//백준 16401
//이분 탐색
//과자 나눠주기
//1. 과자 개수 >= 사람 명 수
//2. 과자 개수 < 사람 명 수
import java.io.*;
import java.util.*;
public class p14_1 {
	
	private static int n, m;
	private static int answer=0;
	
	
	private static int narr[];
	
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String arr[] = br.readLine().split(" ");
		m = Integer.parseInt(arr[0]);
		n = Integer.parseInt(arr[1]);
		//int num []= new int [100001];
		
		String arr1[] = br.readLine().split(" ");
		narr = new int [n]; //과자 길이 저장
		
		for(int i=0; i<n; i++) {
			narr[i] = Integer.parseInt(arr1[i]);
		}
		//과자 길이 정렬
		Arrays.sort(narr);
		
		
		
			
			//이분탐색
		int left = 0;
		int right = narr[n-1];
		
		
		while(left<=right) {
			int mid = (left+right)/2;
			
			int count = 0;
			for(int i=0; i<n; i++) {
				count += narr[i]/mid; //현재 과자를 몇 조각으로 나누는지 계산
				
			}
			
			
			if (count<m) {
				right=mid-1;
			
			}
			else  {
				
				
				left=mid+1;
				answer=mid;
			}
			
			
		}
		
		
		br.close();
		System.out.println(answer);
		
	}

}

