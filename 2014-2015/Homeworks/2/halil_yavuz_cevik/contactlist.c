/*
 * contactlist.c
 */

#include <stdio.h>
#include <string.h>
#include "contactlist.h"

/*Bu fonksiyonumuzun girdisi Struct pointer tipindeki cPtr. Girdiyi aldıktan
 * sonra cPtr pointerının gösterdiği struct contact kişisindeki bilgileri
 *  printf fonksiyonlarının içinde sırasıyla isim-soyisim mail ve
 * telefon şeklinde bastırdık*/
void print_contact(struct Contact* cPtr) {

	printf("Ad Soyad: %s %s    ", cPtr->name, cPtr->surname);

	printf("Mail: %s   ", cPtr->mail);

	printf("Telefon Numarası: %s\n", cPtr->tel_numb);

}

/*Printf_contact_list fonksiyonu girdi olarak struct ContactList tipinde
 * bir pointer alıyor. Eğer bu pointerın gösterdiği contactlist struct'ının
 * counter (kişi) sayacı sıfıra eşitse -ki bu da telefon defterinin boş
 * oldugu durum oluyor- hata mesajı basıyor, değilse sırasıyle defterin içinde
 * bulunan kişileri print_contact fonksiyonunu kullanarak ekrana basıyor*/

void print_contact_list(struct ContactList* clPtr) {

	int count;

	if (clPtr->counter == 0) {

		printf("Hata! İcerigini gormeye calistiginiz telefon defteri bos\n");

	}

	else {

		for (count = 0; count < clPtr->counter; count++)

			print_contact(&clPtr->Contactlst[count]);

	}

}

//Telefon defterimize kişi eklediğimiz fonksiyon.
void insert_new_contact(struct ContactList* clPtr) {

	int countprsn, countchr, countnmbchr = 0;
	int flag = 0;

//Defter doluysa hata döndürüyor. Counter değişkeni kişi sayısını göstermekte
	if (clPtr->counter == 20) {

		printf("Hata! Telefon Defteri Dolu\n");

	}

	else {

//Kullanıcıdan bilgileri istiyoruz kullanıcı sırayla girmeye başlıyor
		printf("Lutfen deftere eklemek istediginiz kisinin adini giriniz\n");
		scanf("%50s", &clPtr->Contactlst[clPtr->counter].name);

		printf("Lutfen deftere eklemek istediginiz kisinin soyadini giriniz\n");
		scanf("%50s", &clPtr->Contactlst[clPtr->counter].surname);

		printf(
				"Lutfen deftere eklemek istediginiz kisinin mail adresini giriniz\n");
		scanf("%50s", &clPtr->Contactlst[clPtr->counter].mail);

/*Bonus soru burada başlıyor.En dıştaki for'da eklemeye çalıştığımız counter'ıncı
* kişinin mail adresi ile defterin ilk elemanından başlayarak diğer elemanların
* mail adreslerini kontrol ediyoruz*/

		for (countprsn = 0; countprsn < clPtr->counter; countprsn++) {

          //flag 1 ise aynı mail adresi bulunmuştur. Kontrole son verecek

			if (flag == 1) {

				break;
			}

/*Girilen kişi ile defterdeki kişinin mail adreslerinin uzunluğu aynı ise bir sonraki
 * aşamaya geçerek mail adresleri aynı mı diye bakacak*/

			if (strlen(clPtr->Contactlst[clPtr->counter].mail)
					== strlen(clPtr->Contactlst[countprsn].mail)) {

				//Harf harf karşılaştırma bu for'da başlıyor

				for (countchr = 0;
						countchr
								< strlen(clPtr->Contactlst[clPtr->counter].mail);
						countchr++) {

					if (clPtr->Contactlst[clPtr->counter].mail[countchr]
							== clPtr->Contactlst[clPtr->counter].mail[countchr]) {

			      //Her harf aynı olduğunda tuttuğumuz sayaç 1 arttırılıyor

						countnmbchr++;
					}

				}

				if (countnmbchr
						== strlen(clPtr->Contactlst[clPtr->counter].mail)) {

/*Son kontrolde eğer tuttuğumuz sayacın büyüklüğü ile girilen kişinin mail adresleri
 *  uzunluğu aynı ise, mail adreslerinin aynı olduğunu buluyoruz. Hata mesajı
 *  basıp koyduğumuz flag'e 1 atıyoruz. Bu sayede daha fazla kontrol etmeyecek*/

					printf(
							"Hata! Girdiginiz kisinin mail adresi defterde mevcut\n");

					flag = 1;
				}
			}

		}
/*Flag 1e eşit ise telefon numarası sorulmayacak bir sonraki kişiye atlanmayacak
 * bir sonraki girişte daha önce alınmış isim soyisim mail adreslerinin
 * üzerine yazılacak*/

		if (flag == 0) {
			printf(
					"Lutfen deftere eklemek istediginiz kisinin telefon numarasini giriniz\n");
			scanf("%50s", &clPtr->Contactlst[clPtr->counter].tel_numb);

			clPtr->counter++;
		}
	}
}

