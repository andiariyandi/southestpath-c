#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#define MAX 45
#define inf 9999

using namespace std;
void path(int, int);
int c[100][100], p[100][100];
ifstream file; 
void infoNode();


int main (){
	int i, j, k, x,awal,akhir,pil;
	
	file.open("Matriks.txt"); 
 	while(!file.eof()){ 
		for(int i=1;i<=MAX;i++){
			for(int j=1;j<=MAX;j++){
				file >> c[i][j];
				p[i][j]=-1;
			}
		}
	}
 	file.close();
	
 	for(k=1;k<=MAX;k++){
  		for(i=1;i<=MAX;i++){
  			for(j=1;j<=MAX;j++){
    			if(i==j)
     			c[i][j]=0;
				 else{
				 	x=c[i][k]+c[k][j];
				 	if(c[i][j]>x){
						c[i][j]=x;
						p[i][j]=k;
					}
    			}
   			}
  		}
 	}
 	
	system("cls");
	printf("\t\t===========================================\n");
 	printf("\t\t= ALGORITMA DIJKSTRA SHORTEST PATH PROBLEM=\n");
	printf("\t\t===========================================\n");

	printf("\n1. Node Information\n");
	printf("2. Find The Shortest Path");
	printf("\nPlease Input(1/2) : ");
	scanf("%d",&pil);
	
	if(pil==1){
		infoNode();
	}else{
		printf("Masukkan Lokasi Awal : ");
 		scanf("%d",&awal);
 		printf("Masukkan Tujuan : ");
 		scanf("%d",&akhir);
		printf("\n\nJarak Terpendek Dari %d menuju % d : ",awal,akhir);
 		printf("%d", awal);
 		path(awal,akhir);
 		printf("%d\n", akhir);
 		printf("Dengan Jarak : %.2f KM",(float)c[awal][akhir]/1000);
	
		return 0;
	}
	
	
	printf("Masukkan Lokasi Awal : ");
 	scanf("%d",&awal);
 	printf("Masukkan Tujuan : ");
 	scanf("%d",&akhir);
	printf("\n\nJarak Terpendek Dari %d menuju % d : ",awal,akhir);
 	printf("%d", awal);
 	path(awal,akhir);
 	printf("%d\n", akhir);
 	printf("Dengan Jarak : %.2f KM",(float)c[awal][akhir]/1000);
	
	return 0;
}

void path(int i, int j){
	int k;
 	k=p[i][j];
 	if(k==-1){
  		printf("->");
  		return;
 	}
 	path(i, k);
 	printf("%d",k);
 	path(k,j);
}

void infoNode(){
	char kembali;
	do{
		system("cls");
		printf("Informasi Berdasarkan Graph");
		printf("\nNode \tsampai \tNode\t\tKelurahan ");
		printf("\n1 \t-> \t10\t\tPrumnas Way Halim");
		printf("\n11 \t-> \t21\t\tWay Halim Permai");
		printf("\n23 \t-> \t29\t\tGunung Sulah");
		printf("\n30 \t-> \t31\t\tJagabaya 1");
		printf("\n34 \t-> \t35\t\tJagabaya 1");
		printf("\n32,36 \t-> \t38\t\tJagabaya 2");
		printf("\n37 \t-> \t38\t\tJagabaya 1");
		printf("\n39 \t-> \t42\t\tjagabaya 3");
		printf("\n43 \t-> \t45\t\tJagabaya 1");
		printf("\nBack [Y/N] : "); scanf("%c",&kembali);
		system("cls");
	}while(kembali!='Y');
	
}
 


