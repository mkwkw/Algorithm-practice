//���� 1158
//�似Ǫ�� ����
//ť
//k��° ���ڸ� ����, �������� �ְ� �ݺ�
import java.util.*;
public class p25 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int arr[] = new int [n];
		
		Queue<Integer> que = new LinkedList<Integer>();
		
		//1~n���� ���ڸ� ť�� ����
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
