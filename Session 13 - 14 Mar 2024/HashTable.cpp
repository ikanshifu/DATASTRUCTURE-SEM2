#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Session 14 - 14 Mar 2024
Hashing and Hash Table

-Hash set: berisi value yang tidak berulang/unik
-Hash Map: memiliki value and key
-Hash Function:
	1.Mid-Square: dia ambil keynya dan dikuadratin, lalu diambil bagian tengahnya untuk di jadiin key
	2.Division: jumlahin ascii value dari setiap character lalu dimodulo dengan table size
	3.Folding: Membagi value jadi 2 bagian lalu menjumlahkannya, dan hanya mengambil 2 angka belakang dari hasilnya
	4.Rotating hash: melakukan rotasi setelah emnggunakan hash function manapun

-Collision:
	1.Linear probing : mencari tempat terdekat yang available jika tempatnya sudah dipake
	(bad time complexity)
	2.Rehashing: menggangandakan size table jika sudah penuh
	3.Chaining: menggunakan linked list instead of array

*/

//Basic division method and linear probing

const int tableSize = 10;

struct Data{
	int key;
	int steps;
}h[tableSize];

void initial(){
	for(int i=0;i<tableSize;i++){
		h[i].key = -1;
	}
}

void view(){
	for(int i = 0;i<tableSize;i++){
		if(h[i].key==-1){
			printf("[%d] NULL\n", i,h[i].key);
		}else{		
			printf("[%d] %d | %d steps(s)\n", i,h[i].key,h[i].steps);
		}
	}
}

void insert(int key){
	int idx = key%tableSize, step = 1;
	
	while(h[idx].key != -1){
		idx = (idx+1)%tableSize;
		step++;
	}
	h[idx].key = key;
	h[idx].steps = step;
}

int main(){
	initial();
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(6);
	insert(5);
	insert(125);
	insert(54);
	insert(44);
	insert(23);
	view();
	
	return 0;
}
