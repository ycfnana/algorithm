// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<algorithm>
#include<string> 
#include<math.h>
#include<queue>
using namespace std;

int a[10000];
int indexB[10000];
int indexA[10000];
//归并
void sort(int start,int end){
	int mid = (start + end) / 2;
	if (end - start > 1){
		sort(start, mid);
		sort(mid + 1, end);
	}
	int idxLeft = start, idxRight = mid+1;
	int idx = start;
	
	while (idxLeft <= mid && idxRight <= end){
		if (a[indexA[idxLeft]] < a[indexA[idxRight]]){
			indexB[idx] = indexA[idxLeft];
			idxLeft++;
		}
		else{
			
			indexB[idx] = indexA[idxRight];
			idxRight++;
		}
		idx++;
	}
	int m, n;
	if (idxLeft > mid){
		m = idxRight;
		n = end;
	}
	else{
		m = idxLeft;
		n = mid;
	}
	for (int i = m; i <= n; i++){
		indexB[idx] = indexA[i];
		idx++;
	}
	for (int i = start; i <= end; i++){
		indexA[i] = indexB[i];
		
	}
}



int main()
{
	for (int i = 0; i <10; i++){
		cin >> a[i];
		indexA[i] = i;
	}
	sort(0, 9);
	for (int i = 0; i <10; i++){
		cout << indexB[i] << " ";

	}
	cout << endl;

}
