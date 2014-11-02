#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char* argv[]) {

	int count = 0;
	int control = 0;
	int maincount = 0;
	int secilenler[6];
	int tampon;
	double toplam = 0;
	int i,k,j,m,t;
	double sayilar [49];
	double n;
	srand(time(NULL));

	for(k=0; k<49; k++){
		sayilar[k] = 0;
	}
	//Başta sayılar dizisinin her elemanını sıfır yapmak için oluşturulmuş döngü. Kaç kere çıktığı bilgisini tutmak için kullanılıcak
	
	while(maincount < 1000){
	//Ana döngü işlemi 1000 kere tekrarlayarak 1000 çekiliş gerçekleştirecek
		for(i=0; i<6; i++){
 		secilenler[i] = 0;
		}
		//Secilenler dizisi her çekilişte sayıların aynı çıkmaması için o çekiliş içinde çıkan sayıları tutan dizi. Her çekiliş başında içini sıfırlatmak için yazıldı bu döngü
	while(count < 6){
		//Rastgele 6 sayı üreten çekiliş döngüsü
		control = 0;
		//control değişkeni bir sorun çıkmadığı sürece 0 kalacak
		int number = (rand()%49) +1 ;
		for(j=0; j<6; j++){
			if(secilenler[j]==number){
				control = 1;
				break;
			}
		}
		//number değişkenine 1-49 arasında bir sayı atıldıktan sonra bu sayının seçilenler dizisinde olup olmadığı kontrol ediliyor eğer varsa control değişkeninin değeri 1 oluyor
		//ve döngü tekrardan başa dönüyor
 		if(control == 0){
 			secilenler[count] = number;
 			count++;
			sayilar[number-1]++;
		}
		//Sayı secilenler dizisinin içinde mevcut değilse secilenlere eklenir ve sayılar dizisindeki indexi 1 artar ve döngü kaldığı yerden devam eder

	}
	count = 0;
	maincount++;
	// ilk çekiliş tamamlandıktan sonra count 0 lanır ve maincount 1 artarak çekiliş sayısını belirtir
	for(m=0; m<6; m++){
		for(t=m+1; t<6; t++){
			if(secilenler[t] < secilenler[m]){
				tampon = secilenler[m];
				secilenler[m] = secilenler[t];
				secilenler[t] = tampon;
			}
		}
	}
	// Bu döngü sayısında 6 sayıyı büyükten küçüğe yerleştirdim
	if(maincount<10){
		if(secilenler[0]< 10)
		printf("  %d.   sonuc = %d ",maincount,secilenler[0]);
		else if(secilenler[0]>9)
		printf("  %d.   sonuc = %d",maincount,secilenler[0]);
		if(secilenler[1]< 10)
		printf(" %d ",secilenler[1]);
		else if(secilenler[1]>9)
		printf(" %d",secilenler[1]);
		if(secilenler[2]< 10)
		printf(" %d ",secilenler[2]);
		else if(secilenler[2]>9)
		printf(" %d",secilenler[2]);
		if(secilenler[3]< 10)
		printf(" %d ",secilenler[3]);
		else if(secilenler[3]>9)
		printf(" %d",secilenler[3]);
		if(secilenler[4]< 10)
		printf(" %d ",secilenler[4]);
		else if(secilenler[4]>9)
		printf(" %d",secilenler[4]);
		if(secilenler[5]< 10)
		printf(" %d ",secilenler[5]);
		else if(secilenler[5]>9)
		printf(" %d\n",secilenler[5]);
		
	}
	if(maincount<100 && maincount > 9){
		if(secilenler[0]< 10)
		printf(" %d.   sonuc = %d ",maincount,secilenler[0]);
		else if(secilenler[0]>9)
		printf(" %d.   sonuc = %d",maincount,secilenler[0]);
		if(secilenler[1]< 10)
		printf(" %d ",secilenler[1]);
		else if(secilenler[1]>9)
		printf(" %d",secilenler[1]);
		if(secilenler[2]< 10)
		printf(" %d ",secilenler[2]);
		else if(secilenler[2]>9)
		printf(" %d",secilenler[2]);
		if(secilenler[3]< 10)
		printf(" %d ",secilenler[3]);
		else if(secilenler[3]>9)
		printf(" %d",secilenler[3]);
		if(secilenler[4]< 10)
		printf(" %d ",secilenler[4]);
		else if(secilenler[4]>9)
		printf(" %d",secilenler[4]);
		if(secilenler[5]< 10)
		printf(" %d ",secilenler[5]);
		else if(secilenler[5]>9)
		printf(" %d\n",secilenler[5]);
	}
	if(maincount<1000 && maincount > 99){
		if(secilenler[0]< 10)
		printf(" %d.  sonuc = %d ",maincount,secilenler[0]);
		else if(secilenler[0]>9)
		printf(" %d.  sonuc = %d",maincount,secilenler[0]);
		if(secilenler[1]< 10)
		printf(" %d ",secilenler[1]);
		else if(secilenler[1]>9)
		printf(" %d",secilenler[1]);
		if(secilenler[2]< 10)
		printf(" %d ",secilenler[2]);
		else if(secilenler[2]>9)
		printf(" %d",secilenler[2]);
		if(secilenler[3]< 10)
		printf(" %d ",secilenler[3]);
		else if(secilenler[3]>9)
		printf(" %d",secilenler[3]);
		if(secilenler[4]< 10)
		printf(" %d ",secilenler[4]);
		else if(secilenler[4]>9)
		printf(" %d",secilenler[4]);
		if(secilenler[5]< 10)
		printf(" %d ",secilenler[5]);
		else if(secilenler[5]>9)
		printf(" %d\n",secilenler[5]);
	}
	if(maincount==1000){
		if(secilenler[0]< 10)
		printf(" %d. sonuc = %d ",maincount,secilenler[0]);
		else if(secilenler[0]>9)
		printf(" %d. sonuc = %d",maincount,secilenler[0]);
		if(secilenler[1]< 10)
		printf(" %d ",secilenler[1]);
		else if(secilenler[1]>9)
		printf(" %d",secilenler[1]);
		if(secilenler[2]< 10)
		printf(" %d ",secilenler[2]);
		else if(secilenler[2]>9)
		printf(" %d",secilenler[2]);
		if(secilenler[3]< 10)
		printf(" %d ",secilenler[3]);
		else if(secilenler[3]>9)
		printf(" %d",secilenler[3]);
		if(secilenler[4]< 10)
		printf(" %d ",secilenler[4]);
		else if(secilenler[4]>9)
		printf(" %d",secilenler[4]);
		if(secilenler[5]< 10)
		printf(" %d ",secilenler[5]);
		else if(secilenler[5]>9)
		printf(" %d\n",secilenler[5]);
	}
	//Bu kadar ayrıntılı yazmamın nedeni çıktıda güzel durması için aslında tek satırlık bir kod burada yazılanlar
	//printf("  %d.   sonuc = %d %d %d %d %d %d ",maincount,secilenler[0],secilenler[1],secilenler[2],secilenler[3],secilenler[4],secilenler[5]);
	}
 	printf("\n\n");
 	int s;
 	for(s=0; s<49; s++){
 		if(s<9)
 		printf(" %d  Sayisi %.0f kere cikti.\n",s+1, sayilar[s]);
 		else
 		printf(" %d Sayisi %.0f kere cikti.\n",s+1, sayilar[s]);
	}
	//Sayıların kaç kere çıktığını gösteren dögü yine çıktı da güzel gözükmesi için if else durumu mevcut
	for(s=0; s<49; s++){
		toplam = toplam + sayilar[s];
	}
	for(s=0; s<49; s++){
		sayilar[s] = (sayilar[s] / toplam)*100;
	}
	//Oranları bulmak için yapılan döngü
	printf("\n\n");
	for(s=0; s<49; s++){
		if(s<9)
 		printf(" %d  Sayisinin cikma orani = %.2f%%\n",s+1, sayilar[s]);
 		else
 		printf(" %d Sayisinin cikma orani = %.2f%%\n",s+1, sayilar[s]);
	}
	//Çıkma oranlarını ekrana bastırma
	printf("\n\n");
	for(n=99;n>0;n--){
		if(n<100 )
		printf(" %.1f%%  |",n/10);
		for(k=0;k<49;k++){
			if(sayilar[k]*10 > n)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}
	//Histogramı oluştururken kullandığım döngü. Oranlar üzerinden yaptım sayılarla da aynı şekili elde ediceğimi düşünüyorum. Sınırı %10 koydum çünkü sayılar maksimum %3 ü görüyor.
	printf("---------------------------------------------------------\n");
	printf("Sayilar 1234567890123456789012345678901234567890123456789");
	//Hangi uzunluk hangi sayıyı belirtiyor okunabilirliği artırabilmek için altarına sayıları yerleştirdim. iki basamaklılar sığmadığı için sadece birler basamaklarını koydum.
	return 0;
}

