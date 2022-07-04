#include <iostream>
using namespace std;
int A[1000];
int Gindis;

//HeapSort sýralamasýný yapmak için kullanýlan swap fonksiyonu
void swap(){
	int k;
	int indis=Gindis; //indis ile iþlem yapacaðýz
	while(true){
	if(A[indis] > A[indis/2]){	//indisdeki eleman indisin iki katýndaki elemandan büyükmü kontrolü. Bu kontrol ile MaxHeap Root olacaktýr
	k=A[indis];	
	A[indis]=A[indis/2]; //indis deðeri swap iþlemi
	A[indis/2]=k;
	indis=indis/2;
	if (indis==1){  //eðer indis 1'e kadar geldiyse dur
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
	if (Gindis == 0){  //eðer eleman yok ise çalýþtýr
		A[++Gindis] = gelen;  //indisi bir arttýrýp gelen elemaný atar
		return;
	}
	A[++Gindis] = gelen;  //indisi bir arttýrýp gelen elemaný atar
	
	swap();
}

//Heap'i ekrana yada dosyaya yazdýran fonksiyon
void check(){
	int i;
	for(i=1; i<=Gindis; i++) //Ýndisdeki elemanlarý tek tek yazdýrýr
		printf("\n %d", A[i]);
		return;	
}

//Heap'den veri silme fonksiyonu
void sil(){
	int n, k;
	k = Gindis; //k deðiþkeni ile iþlem yapmak için k'yý Gindise atadýk
	printf("Silinecek Eleman Indisini Giriniz \n"); //Hangi indis'den eleman silineceðini ister
 	scanf("%d", &n); //Ýndis numarasýný alýr
 	if (n <= Gindis){  //n deðiþkenini indis'de bulmak için k'yý sürekli azaltýr
 		while(k != n){ 	 
 		k--;
	}
	printf("Silinen Eleman %d \n", A[k]); //Silinen elemaný ekrana yazdýrýr
	A[k] = A[Gindis]; //Eleman silmek için silinecek eleman son elemana atýlýr
	Gindis = Gindis - 1; //Dizi indisi bir azaltýlarak silme iþlemi yapýlýr

	swap(); //swap fonksiyonunu çalýþtýrýr
	
	check(); //verileri ekrana yazdýrýr
	
	}
	else{ //Ýndis numarasý bulunamaz ise çalýþýr
	printf("Girdiginiz Indis Bulunmuyor Daha Kucuk Bir Indis Giriniz \n"); 
	sil(); //Sil fonksiyonunu tekrar çalýþtýrýr
	}
} 
	
//Heap içi dolumu boþmu kontrolü yapan fonksiyon	
void kontrol(){
	if(A[Gindis] == NULL){ //Dolu indis yok ise çalýþýr
		printf("Heap Bos \n");	
	}
	else //Aksi takdirde çalýþýr
	printf("Heap Dolu \n");
}
	
//Heap'deki eleman sayýsýný veren fonksiyon	
void elemansayisi(){
	int i = Gindis; //Eleman sayýsý heap'e eklenen son elemanýn indisidir
	
	printf("Heap'deki Eleman Sayisi: %d \n", i); //Bu indisi ekrana yazdýrýr
	printf("\n");
}





int main(){
	
	//Ýþlem menüsü
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

