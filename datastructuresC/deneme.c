#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main() 
{
    char a[50];
    char cevap[10];
    char x;
    int i, k;
    
    int devam = 0;
    
    while (devam==0)
    {
        setlocale(LC_ALL, "Turkish");
        
        printf("Para cekme");
        printf("\nPara Yatirma");
        printf("\nBakiye Sorgulama");
        printf("\nHangi islemi yapmak istersiniz? ");
        gets(a);
        
        int a_size = strlen(a);
        
        //for(i=0 ; i<a_size ; i++)
         //   a[i] = tolower(a[i]);
       
        if(strcmp(a, "para yatirma")==0)
            x = 'y';
            
        else if(strcmp(a, "para cekme")==0)
            x = 'c';
         
        else if(strcmp(a, "bakiye sorgulama")==0)
            x = 'b';
        else printf("invalide");
            
        int bakiye;
        srand(time(NULL));
        bakiye = rand() %1000 +500 ;
            
        int yeni_bakiye;
        int para;
    
        switch (x)
        {
        
            case 'y' : 
            {
                printf("Ne kadar para yatırmak istiyorsunuz? ");
                scanf("%d", &para);
                yeni_bakiye = bakiye+para ;
                printf("Yeni bakiyeniz: %d", yeni_bakiye);
                break;
            }
            
            case 'c' : 
            {
                printf("Ne kadar para cekmek istiyorsunuz? ");
                scanf("%d", &para);
                yeni_bakiye = bakiye-para ;
                printf("Yeni bakiyeniz: %d", yeni_bakiye);
                break;
            }
        
            case 'b' : 
            {
                printf("Bakiyeniz: %d", bakiye);
                break;
            }
            
            default :
            {
                printf("tekrar deneyin");
                break;
            }
        }
        
        printf("\n\nYeni bir islem yapmak ister misiniz? (Evet/Hayır) ");
        gets(cevap);
        
        int cevap_size = strlen(cevap);
        
       // for(k=0 ; k<cevap_size ; k++)
          //  a[k] = tolower(a[k]);
        
        if(strcmp(cevap, "hayir")==0)
        {
            printf("İyi gunler dileriz.");
            devam = 1;
        }
        
        else if(strcmp(cevap, "evet")==0){
            devam=0; }
        
        else{
            printf("evet veya hayir girmelisiniz");
        }
    }
}