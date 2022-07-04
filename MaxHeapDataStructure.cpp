#include <iostream>
using namespace std;
int A[1000];
int Gindis;

//HeapSort s�ralamas�n� yapmak i�in kullan�lan swap fonksiyonu
void swap(){
	int k;
	int indis=Gindis; //indis ile i�lem yapaca��z
	while(true){
	if(A[indis] > A[indis/2]){	//indisdeki eleman indisin iki kat�ndaki elemandan b�y�km� kontrol�. Bu kontrol ile MaxHeap Root olacakt�r
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
	if (Gindis == 0){  //e�er eleman yok ise �al��t�r
		A[++Gindis] = gelen;  //indisi bir artt�r�p gelen eleman� atar
		return;
	}
	A[++Gindis] = gelen;  //indisi bir artt�r�p gelen eleman� atar
	
	swap();
}

//Heap'i ekrana yada dosyaya yazd�ran fonksiyon
void check(){
	int i;
	for(i=1; i<=Gindis; i++) //�ndisdeki elemanlar� tek tek yazd�r�r
		printf("\n %d", A[i]);
		return;	
}

//Heap'den veri silme fonksiyonu
void sil(){
	int n, k;
	k = Gindis; //k de�i�keni ile i�lem yapmak i�in k'y� Gindise atad�k
	printf("Silinecek Eleman Indisini Giriniz \n"); //Hangi indis'den eleman silinece�ini ister
 	scanf("%d", &n); //�ndis numaras�n� al�r
 	if (n <= Gindis){  //n de�i�kenini indis'de bulmak i�in k'y� s�rekli azalt�r
 		while(k != n){ 	 
 		k--;
	}
	printf("Silinen Eleman %d \n", A[k]); //Silinen eleman� ekrana yazd�r�r
	A[k] = A[Gindis]; //Eleman silmek i�in silinecek eleman son elemana at�l�r
	Gindis = Gindis - 1; //Dizi indisi bir azalt�larak silme i�lemi yap�l�r

	swap(); //swap fonksiyonunu �al��t�r�r
	
	check(); //verileri ekrana yazd�r�r
	
	}
	else{ //�ndis numaras� bulunamaz ise �al���r
	printf("Girdiginiz Indis Bulunmuyor Daha Kucuk Bir Indis Giriniz \n"); 
	sil(); //Sil fonksiyonunu tekrar �al��t�r�r
	}
} 
	
//Heap i�i dolumu bo�mu kontrol� yapan fonksiyon	
void kontrol(){
	if(A[Gindis] == NULL){ //Dolu indis yok ise �al���r
		printf("Heap Bos \n");	
	}
	else //Aksi takdirde �al���r
	printf("Heap Dolu \n");
}
	
//Heap'deki eleman say�s�n� veren fonksiyon	
void elemansayisi(){
	int i = Gindis; //Eleman say�s� heap'e eklenen son eleman�n indisidir
	
	printf("Heap'deki Eleman Sayisi: %d \n", i); //Bu indisi ekrana yazd�r�r
	printf("\n");
}





int main(){
	
	//��lem men�s�
	int a, i;
	while(1)
	{
		printf("\n ---Heap Veri Yapisi--- \n");
		printf("\n 1-Heap'e Eleman Ekle \n");
		printf(" 2-Heap'den Eleman Sil \n");
		printf(" 3-Heap Eleman Sayisi \n");
		printf(" 4-Heap Dolumu Yoksa Bosmu Kontrol Et \n");
		printf(" 5-Heap'i Yazdir \n");
		scanf("%d", &a);

		switch(a)
		{
			case 1:
				printf("Eklenecek Sayiyi Giriniz \n");
				scanf("%d", &i);
				ekle(i);
				check();
				break;
				
			case 2:
				sil();			
				break;
				
			case 3:
				elemansayisi();
				break;
				
			case 4:
				kontrol();
				break;
				
			case 5:
			check();
			break;	
		}
	}	
	return 0;
}	

