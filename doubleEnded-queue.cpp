#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;  
};

struct node *start = NULL;
struct node *temp = NULL;
struct node *temp2 = NULL;
struct node *temp3 = NULL;
struct node *prev = NULL;  //i�aret�iler tan�mlan�r


void ekle (int sayi)
{	
	struct node * eleman=(struct node*)malloc (sizeof(struct node)); //bellekte yer ay�r�l�r
	eleman->data=sayi;
	eleman->next=start;   //listeye eleman eklenip start noktas� belirtilir
	
	if (start==NULL)
	{
		start=eleman;
		start->next=start;
		start->prev=start; //listenini ba�� ve sonu birbirine ba�lan�r
	}
	else
	{
		if(start->next==start) //e�er tek element var ise
		{
			start->next=eleman;
			start->prev=eleman;
			eleman->next=start;
			eleman->prev=start; //sona eleman eklenip start ile ba�lan�r
		}
		else
		{
			temp=start;
			while(temp->next!=start)
			{
				temp=temp->next;
			}
			temp->next=eleman;
			eleman->prev=temp;
			eleman->next=start;
			start->prev=eleman;		//temp sonraki element start olana kadar sona gider yani listenin sonuna	
		}
	}
}

void sil(int silinecek)
{
	
	if(start==NULL) //liste bo�mu diye kontrol edilir
	{
	printf("list is empty there is no element \n");
	}
	else //de�ilse burdan devam eder
	{
		if(start->next==start) //e�er tek eleman var ise �al���r
		{
			free(start);
			start=NULL;
		}
		else{      //birden fazla eleman var ise �al���r
			temp=start;
			
			while(temp->next!=start)   //listede sona kadar gider
			{
				temp=temp->next;
				
				if(temp->data==silinecek)   //kullan�c�dan al�nan datay� arar
					{
						temp2=temp->prev;
						temp3=temp->next;
						delete temp;
						temp2->next=temp3;
						temp3->prev=temp2;
						break;                   // bulup sildikten sonra �nceki ve sonraki elemanlar� ba�lar
					}
					temp=temp->next;
			}
			return;
			}	
		}
		
	}

void saatyonundelistele()
{
	system("cls");  // konsolu temizler
	if(start==NULL)   //liste bo�mu kontrol�
	printf("List is empty \n");
	else
	{
		temp=start;
		while(temp->next!=start)  //listenin sonuna kadar gider
		{
			printf("%d\n", temp->data);
			temp=temp->next;     //starttan ba�lay�p saat y�n�nde liste sonuna kadar listeler
		}
		printf("%d", temp->data); //listeyi yazd�r�r
	}
}

void saatyonununtersindelistele()
{
	system("cls");   // konsolu temizler
	if(start==NULL)   //liste bo�mu kontrol�
	printf("List is empty \n");
	else
	{
		temp=start;
		while(temp->prev!=start)   //listenin sonuna kadar gider
		{
			temp=temp->prev;       //starttan ba�lay�p saat y�n�n�n tersinde liste sonuna kadar listeler
			printf("%d\n", temp->data);
			
		}
		printf("%d", start->data);   //listeyi yazd�r�r
	}
}


void ara(int aranan)
{
	int i = 1;  //eleman s�ras� i�in kullan�l�r
    bool kontrol = false;   //verdi�imiz ko�ulu kontrol etmek i�in kullan�l�r
    struct node *temp = start;  
    if(start == NULL) {  //bo� liste kontrol�
        printf("List is empty\n");  
        return;  
    }  
    while(temp != NULL) {   
        if(temp->data == aranan){  //kullan�c�dan al�nan datay� arar
            kontrol = true;  //ko�ulumuz sa�lan�yor ise ge�erlidir
            break;  
        }
        else
        {
        	break;
		}
        temp = temp->next;   //liste sonuna kadar gider
        i++; 
    }
    if(kontrol)
	{
    	printf("Element which is searched %d . Line \n", i);
	}	
	else
	{
    	 printf("Element which is searched couldn't find \n");      //tan�mlad���m�z ko�ula g�re ��kt� verir
	}
}   

int main()
{
	while(1)
	{
		int sayi, secim, silinecek;
		printf("\n1--> Add element\n");
		printf("2--> List the Elements Clockwise\n");
		printf("3--> List Elements Counter Clockwise\n");
		printf("4--> Delete Element\n");
		printf("5--> Search Element\n");
		printf("Make your choose \n");   //Men�
		
		scanf("%d", &secim );
		switch(secim )
		{
			case 1: printf("Element which is add to list: ");  //ekle fonksiyonunu �al��t�r�r
			scanf("%d", &sayi);
			ekle(sayi);
			break;
		
			case 2: //saat y�n�nde listeleme fonksiyonunu �al��t�r�r
			saatyonundelistele();
			break;
			
			case 3: //saat y�n�n�n tersinde listeleme fonksiyonunu �al��t�r�r
			saatyonununtersindelistele();
			break;
			
			case 4:printf("Write the element which one will delete \n"); //sil fonksiyonunu �al��t�r�r
			scanf("%d", &sayi);
			sil(sayi);
			break;	
			
			case 5:printf("Write the element which one will search \n");  //ara fonksiyonunu �al��t�r�r
			scanf("%d", &sayi);
			ara(sayi);
		}
	}
	

}
