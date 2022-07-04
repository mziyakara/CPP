#include<stdio.h> 
#include<stdlib.h> 
#include <time.h>  

struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
void sirala(struct Node**, struct Node*); 
//Listeyi b�y�kten k����e s�ralamak i�in kullan�lan iki fonksiyon 
void siraliekle(struct Node **head) 
{    
    struct Node *sorted = NULL;
    struct Node *temp = *head; 
    while (temp != NULL) 
    {       
        struct Node *next = temp->next;  
        sirala(&sorted, temp);
        temp = next; 
    } 
    *head = sorted; 
}   
void sirala(struct Node** head, struct Node* yeni) 
{ 
    struct Node* temp; 
    
    if (*head == NULL || (*head)->data >= yeni->data)  //Head bo�sa veya datas� yeni gelen dataya e�it ise �al��t�r
    { 
        yeni->next = *head; 
        *head = yeni; 
    } 
    else
    {       
        temp = *head; 
        while (temp->next!=NULL && temp->next->data < yeni->data) //Liste dolu ve temp next datas� yeni datadan k���k oldu�u s�rece �al��t�r
        { 
            temp = temp->next; 
        } 
        yeni->next = temp->next; 
        temp->next = yeni; 
    } 
}   
//Listeyi yazd�rma fonksiyonu
void yazdir(struct Node *head) 
{ 
    struct Node *temp = head; 
    FILE *cikti_out = fopen ("girdi_in.txt", "w"); //Gelen veriyi dosyaya yazd�rmak i�in bu komut ile dosya tan�mlan�r
    while(temp != NULL) 
    { 
 		//printf("%d", temp->data);
        fprintf(cikti_out, "%d \n", temp->data);  //Gelen veriyi dosyaya yazar
        temp = temp->next; 
    } 
} 
//Listeye eleman ekleme fonksiyonu  
void ekle(struct Node** head, int yeni_data) 
{ 
    struct Node* yeni = new Node; 
    yeni->data = yeni_data;
    yeni->next = (*head);
    (*head)    = yeni; 
} 
    
int main() 
{ 
struct Node *a = NULL;
int i,sayi;
srand(time(NULL)); //Program�n s�rekli ayn� say�lar �retmemesi i�in kullan�l�r

for(i=0; i<1000001; i++){
//Tek basamakl� say�lar
if(i < 99999){	
	sayi = rand() % 9 + 1;
	ekle(&a, sayi);
}
//�ift basamakl� say�lar	
else if(i > 99999 && i < 200000){
	
	sayi = rand() % 10 + 1;
	ekle(&a, sayi);
}
//�� basamakl� say�lar	
else if(i > 199999 && i < 300000){
	
	sayi = rand() % 100 + 10;
	ekle(&a, sayi);
}
//D�rt basamakl� say�lar
else if(i > 299999 && i < 400000){

	sayi = rand() % 10000 + 1000;
	ekle(&a, sayi);
}
//Be� basamakl� say�lar
else if(i > 399999 && i < 500000){
	
	sayi = rand() % 100000 + 10000;
	ekle(&a, sayi);
	
}
//Alt� basamakl� say�lar
if(i > 499999 && i < 1000001){
	
	sayi = rand() % 1000000 + 99999;
	ekle(&a, sayi);
}
}
	//siraliekle(&a);
	yazdir(a);
} 
