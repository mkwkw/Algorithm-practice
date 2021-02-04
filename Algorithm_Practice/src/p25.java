//백준 1158
//요세푸스 문제
//큐
//k번째 숫자를 빼고, 나머지는 넣고 반복
import java.util.*;
public class p25 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int arr[] = new int [n];
		
		Queue<Integer> que = new LinkedList<Integer>();
		
		//1~n까지 숫자를 큐에 저장
		for(int i=1; i<=n; i++) {
			que.offer(i);
		}
		
		for(int j=0; j<n; j++) {
			for(int i=1; i<k; i++) {
				int num = que.poll();
				que.offer(num);
			}
			arr[j] = que.poll();
		}
		
		System.out.print("<");
		for(int i=0; i<n-1; i++) {
			System.out.print(arr[i]+", ");
		}
		System.out.print(arr[n-1]+">");
	}

}
