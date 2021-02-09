//2263
//트리의 순회

import java.io.*;
public class p31 {
	
	public static int inorder[], postorder[], index[]; //inorder 입력 값, postorder 입력 값, 각 원소의 inorder배열에서의 인덱스 값 저장 
	
	//preorder구하기 인자-inorder시작 인덱스 값, 끝 인덱스 값, postorder시작 인덱스 값, 끝 인덱스 값
	public static void preorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
		
		//리턴
		if(inorderStart>inorderEnd || postorderStart>postorderEnd) {
			return;
		}
		
		//postorder의 마지막 원소가 이 (서브)트리의 root이다.
		int root = postorder[postorderEnd];
		System.out.print(root+" ");
		
		//왼쪽 subtree (inorder에서의 root노드 기준 왼쪽, postorder에서의 처음부터 중간까지)
		preorder(inorderStart, index[root]-1, postorderStart, postorderStart+(index[root]- inorderStart)-1 );
		//오른쪽 subtree (inorder에서의 root노드 기준 오른쪽, postorder에서의 중간부터 끝까지(root노드 제외))
		preorder(index[root]+1, inorderEnd, postorderStart+(index[root]-inorderStart), postorderEnd-1);
	}
	

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		inorder = new int [n+1];
		postorder = new int [n+1];
		index = new int [n+1];
		
		//inorder 배열
		String brr[] = br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			inorder[i] = Integer.parseInt(brr[i]);
		}
		//postorder 배열
		String brr1[] = br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			postorder[i]= Integer.parseInt(brr1[i]);
		}
		
		//inorder 배열에서의 원소의 "인덱스 저장"
		for(int i=0; i<n; i++) {
			index[inorder[i]] = i;
		}
		
		preorder(0, n-1, 0, n-1); //preorder구하기 
	}

}
