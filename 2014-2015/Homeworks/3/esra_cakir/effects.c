#include "effects.h"

void effect_random_noise(unsigned char *pixels, int width, int height)
{
	int nr_noisy_pixel = (width * height) / 5;	// %5 oraninda noise ekle
	int i;

	for (i = 0; i < nr_noisy_pixel; ++i) {
		int which_pixel = (rand() % (width * height));
		pixels[which_pixel] = (rand() % 256);
	}
}

void effect_smooth(unsigned char *pixels, int width, int height)
{
	int i;
	for (i = 0; i < width * height - 1; ++i) {
		pixels[i] = ((pixels[i] + pixels[i + 1]) / 2) % 256;
	}
}

/* TODO: Invert efekti her pikselin degerinin tumleyenini o pikselin
 * yeni degeri olarak belirler.
 */
void effect_invert(unsigned char *pixels, int width, int height)
{
	int k;
	for (k = 0; k < width * height - 1; ++k) {
		pixels[k] = 255 - pixels[k];
	}
}

/* TODO: Belirlenen bir esik degerin altinda kalan pikselleri siyah,
 * uzerinde kalanlari ise beyaz yaparak 2 renkli bir resim olusturur.
 */
void effect_threshold(unsigned char *pixels, int width, int height, int threshold)
{
	int m;
	for (m = 0; m < width * height - 1; ++m)	// burda charla int karşılaştırmak zorunda kaldım ama doğru mu oldu bilmiyorum
	{
		if (pixels[m] < threshold) {
			pixels[m] = 0;
		}
		if (pixels[m] > threshold) {
			pixels[m] = 255;
		}

	}
}
