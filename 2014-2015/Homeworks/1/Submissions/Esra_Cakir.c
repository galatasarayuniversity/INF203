#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

 int main() {
 	int dizi[1000][6];
  int i=1;
  int s,k,d,m,p,l=1;
  int x1=0;
  int x2=0;
  int x3=0;
  int x4=0;
  int x5=0;
  int x6=0;
  int random=0;
  srand(time(NULL));
  
  printf("\n\t\t\t\t\t\t\t ESRA CAKIR\n");
  printf("\n\t\t\t\t\t\t\t FIT-2 12401603\n");
  printf("\n\t\t");
  printf("SAYISAL LOTO CEKILISI ve ISTATISTIKLER\n\n");
   
   for(s=0;s<=999;s++)
   {
   int i=1;
   
    while(i<=6)  {
    	
      random=(rand()%49)+1;
       if(random!=x1 && random!=x2 &&
         random!=x3  && random!=x4 &&
         random!=x5 && random!=x6 )
                   
                   {
           switch(i)  {
             case 1: x1=random; dizi[s][0]=x1; break;
             case 2: x2=random; dizi[s][1]=x2; break;
             case 3: x3=random; dizi[s][2]=x3; break;
             case 4: x4=random; dizi[s][3]=x4; break;
             case 5: x5=random; dizi[s][4]=x5; break;
             case 6: x6=random; dizi[s][5]=x6; break;
             }
             }  else {
                   continue;   
                   }      
       i++;             
       }  
  
         printf("\n");
         printf(" %d.Cekilis :\t%d  %d  %d  %d  %d  %d\n",s+1,x1,x2,x3,x4,x5,x6);
       
   }
   
   printf("\n\n\t CEKILISTE KAZANAN SAYILAR VE TEKRAR SAYILARI\n\n");
  
  for(k=0;k<1000;k++)
  {
  
  		for(d=0;d<6;d++) 
		  {	
  			if(dizi[k][d]!=-1)
  				{
  				 	for(m=k+1;m<1000;m++)
					    {
					    for(p=0;p<6;p++)
							{ 
						
							
  									if(dizi[k][d]==dizi[m][p])
									  {
   											l++;
   											dizi[m][p]=-1; 
   											   
    							      }
    							     	
    							     	else
										 {continue;
    							     	 }
							
										
                            } 
							 
                      } 
					  printf("\t\t\t%d tane %d var\n",l,dizi[k][d]);l=1;
                 }
                 
			else
			 {continue;
             	}
                 
        	
          }
  
  }
  printf("\n\t\t\t\t\t\t\t ESRA CAKIR\n");
  printf("\n\t\t\t\t\t\t\t FIT-2 12401603\n");
         return 0;
         }  
