#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*
				             *****************GENEL AÇIKLAMALAR*******************
-------1.ilk yapılan işlem altı tane radn sayı üretip bu sayıları 6 lı bir dizinin içerisine atmaktır-----------
-------2.bu kolonlar her hesaplandığında ekrana bastırılmıştır ve bu altılı dizi sıfırlanmıştır-----------------
-------3.histogramda hangi kaç sayının kaç kere geldiğini bulmak için 6000 lik bir dizi oluşturulmuştur---------
-------4.her kolon hesaplanmasının sonunda bu 6000 lik dizinin içerisine atılmış bulunmaktadır------------------
-------5.en sonda her sayı teker teker kontrol edilip kaç defa geldiği bulunarak ekrana bastırılmıştır ---------
							 *****************************************************
*/

int main(int argc, char *argv[])
{
   
     int a,i,j,k,l,m,n,o,p;  
	 int b[6];
	 int c[6000];
	 m=0;
     
     srand( time(NULL) );    
       for( i = 0; i < 1000; i++ ){ 
			 k=0;
			 j=0;
			 b[0]=0;
			 b[1]=0;
			 b[2]=0;
			 b[3]=0;
			 b[4]=0;
			 b[5]=0;
			 
			 
			 //kolon oluşturma işlemi burada gerçekleştirilmiştir
			 while( j<6 ){  
				  a=1+rand()%49;
				  
				     //burada 6 dizi içerisindeki kontrol mekanizması geliştirilmiştir
					 if(a!=b[0] && a!=b[1] && a!=b[2] && a!=b[3] && a!=b[4] && a!=b[5]){
						 b[k]=a;
						 k++;	//6 lı dizinin içine atmak icin k++
						 i++;	//total kolon sayisi icin
						 j++;	//6 sayı hesaplayıp 6 lı dizinin içine yazdıktan sonra kolon döngüsünden çıkması için
						 
				  }
			  }
			 
			

			 for(l = 0; l < 6 ; l++){
						 printf("%d\t",b[l]);	 // kolonların ekrana basılma işlemi burada gerçekleştirilmiştir
						 c[m] = b[l];			 //kolonlar 6000 lik arrayin içerisinde tutulmuştur 
						 m++;
			 
			 }
			
			 printf("\n");
          }        

		  printf("\n\nHistogrami gormek icin herhangi bir tusa basiniz...\n");
		  printf("----------------------------------------------------\n");
		  _getch();
		  
		  
		//burada ki döngü her sayının tek tek kontrolü içindir
		//kısacası histogram için yazılmış basit bir döngü
		  for(o = 1 ; o < 50; o++)   {
			p=0;		
		  	for(n = 0; n < 1000; n++){
			  if( c[n] == o )
			   p++;
			 
			  }
			   printf("%d. sayi %d kere sayisal loto sonucunda gelmistir...\n\n",o,p);
		    }    
		           
system("pause");
      
  return 0;
}
