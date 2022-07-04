#include <iostream>
using namespace std;
int A[1000002];
int Gindis;


//HeapSort s�ralamas�n� yapmak i�in kullan�lan swap fonksiyonu
void swap(){
	int k;
	int indis=Gindis; //indis ile i�lem yapaca��z
	while(true){
	if(A[indis] < A[indis/2]){	//indisdeki eleman indisin iki kat�ndaki elemandan k���km� kontrol�
	k=A[indis];	
	A[indis]=A[indis/2]; //indis de�eri swap i�lemi
	A[indis/2]=k;
	indis=indis/2;
	if (indis==1){  //e�er indis 1'e kadar geldiyse dur
		break;
	}
	else
		continue;		
	}
	else
		break;	
	}
	return;
}

//eleman ekleme fonksiyonu
void ekle(int gelen){
	if (Gindis == 0){ //e�er eleman yok ise �al��t�r
		A[++Gindis] = gelen; //indisi bir artt�r�p gelen eleman� atar
		return;
	}
	A[++Gindis] = gelen; //indisi bir artt�r�p gelen eleman� atar
	
	swap();
}

//Heap'i ekrana yada dosyaya yazd�ran fonksiyon
void check(){
	FILE *cikti_out = fopen ("cikti_out.txt", "w"); //Gelen veriyi dosyaya yazd�rmak i�in bu komut ile dosya tan�mlan�r
	for(int i = 1; i < Gindis; i++){ //�ndisdeki elemanlar� tek tek yazd�r�r
		fprintf(cikti_out, "%d \n", A[i]); //elemanlar� dosyaya yazar 
		}
		return;	
}
	
int main(){
	
	int  sayi;	
	FILE *girdi_in = fopen ("girdi_in.txt", "r"); //Girdi_in dosyas�ndan verileri almas� i�in burada dosya tan�mlan�r
	while(!feof(girdi_in)){   //i de�i�keni girilen n de�i�kenine e�it olana kadar ekleme yapar
	fscanf(girdi_in, "%d", &sayi);  //Dosyadan veri okumak i�in kullan�l�r
    ekle(sayi);  
	}
	check();
	return 0;
}	

