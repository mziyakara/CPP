#include <iostream>
using namespace std;
int A[1000002];
int Gindis;


//HeapSort sýralamasýný yapmak için kullanýlan swap fonksiyonu
void swap(){
	int k;
	int indis=Gindis; //indis ile iþlem yapacaðýz
	while(true){
	if(A[indis] < A[indis/2]){	//indisdeki eleman indisin iki katýndaki elemandan küçükmü kontrolü
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
	if (Gindis == 0){ //eðer eleman yok ise çalýþtýr
		A[++Gindis] = gelen; //indisi bir arttýrýp gelen elemaný atar
		return;
	}
	A[++Gindis] = gelen; //indisi bir arttýrýp gelen elemaný atar
	
	swap();
}

//Heap'i ekrana yada dosyaya yazdýran fonksiyon
void check(){
	FILE *cikti_out = fopen ("cikti_out.txt", "w"); //Gelen veriyi dosyaya yazdýrmak için bu komut ile dosya tanýmlanýr
	for(int i = 1; i < Gindis; i++){ //Ýndisdeki elemanlarý tek tek yazdýrýr
		fprintf(cikti_out, "%d \n", A[i]); //elemanlarý dosyaya yazar 
		}
		return;	
}
	
int main(){
	
	int  sayi;	
	FILE *girdi_in = fopen ("girdi_in.txt", "r"); //Girdi_in dosyasýndan verileri almasý için burada dosya tanýmlanýr
	while(!feof(girdi_in)){   //i deðiþkeni girilen n deðiþkenine eþit olana kadar ekleme yapar
	fscanf(girdi_in, "%d", &sayi);  //Dosyadan veri okumak için kullanýlýr
    ekle(sayi);  
	}
	check();
	return 0;
}	

