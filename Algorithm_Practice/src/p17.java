//백준 3079
//입국심사
//이분탐색
import java.util.*;
public class p17 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong(); //입국심사대 개수
		long m = sc.nextLong(); //사람 인원 수
		
		long t[] = new long [100005]; //각 입국심사대의 소요시간
		t[0]=0;
		for(int i=1; i<=n; i++) {
			t[i] = sc.nextLong();
		}
		long answer = 0;
		long high = (long)Math.pow(10, 18);
		long low = 1;
		long mid = 0;
		while(high>=low) {
			mid = (high+low)/2;
			long sum = 0;
			for(int i=1; i<=n; i++) {
				sum += mid/t[i];
				if(sum>=m)
					break;
			}
			if(sum>=m) {
				answer = mid;
				high = mid-1;
				
			}
			else {
				low = mid+1;
			}
		}
		System.out.println(answer);
		
		sc.close();
	}

}
