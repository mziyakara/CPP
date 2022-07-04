#include <stdio.h>
#include <stdlib.h>
	//D���mlerin tan�mlanmas�
	struct node{ 
	int data;
	struct node *next;
	struct node *prev;       
	};
struct node *ilk, *son;

//Stack'e eleman ekliyecek olan fonksiyon	
void push(int yeni){ 	
	struct node *temp;
	temp = (node*)malloc(1*sizeof(node));
	temp->data = yeni;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(ilk==NULL) //Stack bo�mu dolumu diye kontrol ediyoruz
	{
		ilk=temp;
		son=temp;
		return;
	}
	
	son->next=temp;
	temp->prev=son;
	son=temp;
	return;
}

//Stack'in en �st�nden eleman alan fonksiyon	
int pop(){
	
	int sonEklenen;
	struct node* temp = son;

	son=son->prev;	
	son->next=NULL;
	sonEklenen = temp->data;
	
	return sonEklenen;

}

//Stact'deki elemanlar� ilk eklenenden son eklenene do�ru s�ralayan fonksiyon
void yazdir(){
		
		struct node* temp = ilk;
		while(temp != NULL)		//Stack'in sonuna kadar gitmesini sa�lar
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}	
	
	
}

//Stack dolumu yoksa bo�mu diye kontrol eden fonksiyon
void kontrol(){
	
	if(ilk==NULL) //�lk stack bo� ise �al���r
	{
		printf("---Stack Bos--- \n");
	}
	else  //Aksi halde �al���r
	{
		printf("---Stack Dolu--- \n");
	}
	
	
}

int main()
{
	struct node* temp;
	int sec;
	int i;
	while(1)
	{
		//��lem men�s�
		printf("\n 1-Eleman Ekle \n");
		printf(" 2-Eleman Sil \n");
		printf(" 3-Stack Yazdir \n");
		printf(" 4-Stack Kontrolu \n");
		printf(" Islem Seciniz \n");
		scanf("%d", &sec);

		//Se�ilen i�leme g�re �al���cak switch yap�s�
		switch(sec)
		{
			case 1:
				printf("Eklenecek Sayiyi Giriniz \n");
				scanf("%d", &sec);
				push(sec);
				break;
				
			case 2:
				i = pop(); printf ("Alinan Sayi: %d \n", i);			
				break;
				
			case 3:
				yazdir();
				break;
				
			case 4:
				kontrol();
				break;
		}
	}	
	return 0;	
}
