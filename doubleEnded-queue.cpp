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
struct node *prev = NULL;  //iþaretçiler tanýmlanýr


void ekle (int sayi)
{	
	struct node * eleman=(struct node*)malloc (sizeof(struct node)); //bellekte yer ayýrýlýr
	eleman->data=sayi;
	eleman->next=start;   //listeye eleman eklenip start noktasý belirtilir
	
	if (start==NULL)
	{
		start=eleman;
		start->next=start;
		start->prev=start; //listenini baþý ve sonu birbirine baðlanýr
	}
	else
	{
		if(start->next==start) //eðer tek element var ise
		{
			start->next=eleman;
			start->prev=eleman;
			eleman->next=start;
			eleman->prev=start; //sona eleman eklenip start ile baðlanýr
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
	
	if(start==NULL) //liste boþmu diye kontrol edilir
	{
	printf("list is empty there is no element \n");
	}
	else //deðilse burdan devam eder
	{
		if(start->next==start) //eðer tek eleman var ise çalýþýr
		{
			free(start);
			start=NULL;
		}
		else{      //birden fazla eleman var ise çalýþýr
			temp=start;
			
			while(temp->next!=start)   //listede sona kadar gider
			{
				temp=temp->next;
				
				if(temp->data==silinecek)   //kullanýcýdan alýnan datayý arar
					{
						temp2=temp->prev;
						temp3=temp->next;
						delete temp;
						temp2->next=temp3;
						temp3->prev=temp2;
						break;                   // bulup sildikten sonra önceki ve sonraki elemanlarý baðlar
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
	if(start==NULL)   //liste boþmu kontrolü
	printf("List is empty \n");
	else
	{
		temp=start;
		while(temp->next!=start)  //listenin sonuna kadar gider
		{
			printf("%d\n", temp->data);
			temp=temp->next;     //starttan baþlayýp saat yönünde liste sonuna kadar listeler
		}
		printf("%d", temp->data); //listeyi yazdýrýr
	}
}

void saatyonununtersindelistele()
{
	system("cls");   // konsolu temizler
	if(start==NULL)   //liste boþmu kontrolü
	printf("List is empty \n");
	else
	{
		temp=start;
		while(temp->prev!=start)   //listenin sonuna kadar gider
		{
			temp=temp->prev;       //starttan baþlayýp saat yönünün tersinde liste sonuna kadar listeler
			printf("%d\n", temp->data);
			
		}
		printf("%d", start->data);   //listeyi yazdýrýr
	}
}


void ara(int aranan)
{
	int i = 1;  //eleman sýrasý için kullanýlýr
    bool kontrol = false;   //verdiðimiz koþulu kontrol etmek için kullanýlýr
    struct node *temp = start;  
    if(start == NULL) {  //boþ liste kontrolü
        printf("List is empty\n");  
        return;  
    }  
    while(temp != NULL) {   
        if(temp->data == aranan){  //kullanýcýdan alýnan datayý arar
            kontrol = true;  //koþulumuz saðlanýyor ise geçerlidir
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
    	 printf("Element which is searched couldn't find \n");      //tanýmladýðýmýz koþula göre çýktý verir
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
		printf("Make your choose \n");   //Menü
		
		scanf("%d", &secim );
		switch(secim )
		{
			case 1: printf("Element which is add to list: ");  //ekle fonksiyonunu çalýþtýrýr
			scanf("%d", &sayi);
			ekle(sayi);
			break;
		
			case 2: //saat yönünde listeleme fonksiyonunu çalýþtýrýr
			saatyonundelistele();
			break;
			
			case 3: //saat yönünün tersinde listeleme fonksiyonunu çalýþtýrýr
			saatyonununtersindelistele();
			break;
			
			case 4:printf("Write the element which one will delete \n"); //sil fonksiyonunu çalýþtýrýr
			scanf("%d", &sayi);
			sil(sayi);
			break;	
			
			case 5:printf("Write the element which one will search \n");  //ara fonksiyonunu çalýþtýrýr
			scanf("%d", &sayi);
			ara(sayi);
		}
	}
	

}
