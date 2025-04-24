#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//using namespace as std;

//Session 32 - 6 Juni 2024
/*
Disjoint Sets
-Sets adalah kumpulan objek yang berbeda
-Union adalah penggabungan 2 set yang berbeda
-Intersection adalah pengirisan angka yang sama
-Disjoint sets adalah sets yang tidak terhubung
-Fungsi: Mencari set yang unik, digunakan untuk social network(mutuals) atau peta(shortest route)
-Setiap set diwakili oleh 1 angka dalam set tersebut
*/

/*
Operations

-MAKE-SET: membuat sebuah set baru dari sebuah angka
-FIND-SET: mencari angka representasi dari sebuah set
-UNION-NAIVE: menggabungkan 2 set, parent yang diikuti adalah yang terbanyak
-UNION-BYRANK: menggabungkan 2 set, tapi yang ditunjuk adalah angka dengan rank tertringgi
-Path Compression: mempersingkat jalur, sehingga ketika find set akan selalu menunjuk ke ancestor
*/

//Using Brute Force
int main(){
	int C,R,a,b;
	scanf("%d %d", &C, &R);
	int position = 1, flag = 0;
	int arr[C], parent[R];
	for(int i = 1; i<=R;i++){
		int routeA = 0, routeB = 0;
		scanf("%d %d",&a,&b);
		for(int j = 1;j<=position;j++){
			if(arr[j]==a){
				routeA = 1;
				break;
			}
		}
		
		for(int j = 1;j<position;j++){
			if(arr[j]==b){
				routeB = 1;
				break;
			}
		}
		
		if(routeA == 0){
			arr[position] = a;
			position++;
		}
		
		if(routeB == 0){
			arr[position] = b;
			position++;
		}
		
		if(routeA == 1 && routeB == 1){
			flag = 1;
		}	
	}	
	if(flag == 1){
		printf("Cycle detected\n");	
	}else{
		printf("Perfect plan\n");
	}
	return 0;
}
