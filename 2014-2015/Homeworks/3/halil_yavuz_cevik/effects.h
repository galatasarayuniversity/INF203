/*
 * effects.h
 *
 *  Created on: Nov 7, 2014
 *      Author: yc
 */

#ifndef EFFECTS_H_
#define EFFECTS_H_

/* Efekt fonksiyonlari icin bildirimler */

void effect_invert(unsigned char *pixels, int width, int height);
void effect_threshold(unsigned char *pixels, int width, int height, int threshold);
void effect_random_noise(unsigned char *pixels, int width, int height);
void effect_smooth(unsigned char *pixels, int width, int height);

#endif				/* EFFECTS_H_ */
