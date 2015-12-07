#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result, 
                     struct timeval *t2, struct timeval *t1) {
  long int diff = 
    (t2->tv_usec + 1000000 * t2->tv_sec) - 
    (t1->tv_usec + 1000000 * t1->tv_sec);
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;
  return (diff < 0);
}

/* Bir matrisi rasgele sayilarla dolduran fonksiyon */
void matrand(int n, int pitch, double M[]) {
  const double r = 10.0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      M[i*pitch + j] = r * (2*drand48() - 1);
    }
  }
}

/* Matrisi ekrana yazdiran fonksiyon */
void matprint(int n, int pitch, const double M[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%10.2f ", M[i*pitch + j]);
    }
    printf("\n");
  }
}

/* TODO: Klasik matris carpimi algoritmasi: C = A * B */

/* Matmult fonksiyonu n^3 zamanda çalışıyor çünkü iç içe her biri
n defa dönen 3 döngü var n*n*n = n^3*/
void matmult(int n, 
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[]) {
	int i,j,k,a=0;
	for(i=0;i<n;i++){
		for(j=0; j<n ; j++){
			a=0;
			for(k=0;k<n;k++){
				a += A[i*Apitch + k] * B[k*Bpitch + j];
			}
			C[i*Cpitch + j] = a;
		}
	}
}

/* Matris toplami: S = A + B */
void matadd(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      S[i*Spitch + j] = A[i*Apitch + j] + B[i*Bpitch + j];
    }
  }
}

/* Matris farki: S = A - B */
void matsub(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      S[i*Spitch + j] = A[i*Apitch + j] - B[i*Bpitch + j];
    }
  }
}

//          _    _          _   _
//     X = | A  B |    Y = | E F |
//         | C  D |        | G H |

//     P0 = A * (F - H)
//     P1 = (A + B) * H
//     P2 = (C + D) * E
//     P3 = D * (G - E)
//     P4 = (A + D) * (E + H)
//     P5 = (B - D) * (G + H)
//     P6 = (A - C) * (E + F)
//        _                                            _
//   Z = | (P3 + P4) + (P5 - P1)   P0 + P1              |
//       | P2 + P3                 (P0 + P4) - (P2 + P6)|
//        -                                            -
//


/* Matmultfast fonksiyonu ise her N i n/2 duruma getirip 7 tane ayrı parçaya böldüğü için log2(7) 
zamanda ayırıyor ve birleştirmeyle beraber N^log2(7) zamanda bitirmiş oluyor.*/
void matmult_fast(int n, 
                  int Xpitch, const double X[],
                  int Ypitch, const double Y[],
                  int Zpitch, double Z[], int min_mat_recurse) {
  /* TODO: min_mat_recurse'e kucuk esik bir matris geldiyse klasik algoritmayi kullan */
  if (n <= min_mat_recurse) {
    matmult(n, Xpitch, X, Ypitch, Y, Zpitch, Z);
    return;
  }

  /* Bu cagridaki alt-matrislerin boylari n/2 olacak */
  const int new_n = n/2;
  
  const int sz = new_n*new_n*sizeof(double);
  double *P[7];
  /* TODO: 7 adet Px hesabi icin heap'ten yer ayirin */
  int i =0;
  for(i=0;i< 7 ;i++){
  		P[i] = malloc(sz);}
  
  /* TODO: Toplama ve cikarmalar icin gecici T ve U matrisleri icin yer ayirin */
  double *T = malloc(sz);
  double *U = malloc(sz);

  /* TODO: A-B-C-D matrislerinin baslangic adreslerini ayarlayin
   * (Hepsi X matrisinin icerisinde gomulu) */
  const double *A = &X[0];
  const double *B = &X[new_n];
  const double *C = &X[new_n*Xpitch];
  const double *D = &X[new_n*Xpitch + new_n];


  /* TODO: E-F-G-H matrislerinin baslangic adreslerini ayarlayin
   * (Hepsi Y matrisinin icerisinde gomulu) */
  const double *E = &Y[0];
  const double *F = &Y[new_n];
  const double *G = &Y[new_n*Ypitch];
  const double *H = &Y[new_n*Ypitch+new_n];

   /* TODO: P0 = A*(F - H) */
  matsub(new_n,Ypitch,F,Ypitch,H,new_n,T);
  matmult_fast(new_n,Xpitch,A,new_n,T,new_n,P[0],min_mat_recurse);

  /* TODO: P1 = (A + B)*H */
  matadd(new_n,Xpitch,A,Xpitch,B,new_n,T);
  matmult_fast(new_n,new_n,T,Ypitch,H,new_n,P[1],min_mat_recurse);

  /* TODO: P2 = (C + D)*E */
  matadd(new_n,Xpitch,C,Xpitch,D,new_n,T);
  matmult_fast(new_n,new_n,T,Ypitch,E,new_n,P[2],min_mat_recurse);
  

  /* TODO: P3 = D*(G - E) */
  matsub(new_n,Ypitch,G,Ypitch,E,new_n,T);
  matmult_fast(new_n,Xpitch,D,new_n,T,new_n,P[3],min_mat_recurse);

  /* TODO: P4 = (A + D)*(E + H) */
  matadd(new_n,Xpitch,A,Xpitch,D,new_n,T);
  matadd(new_n,Ypitch,E,Ypitch,H,new_n,U);
  matmult_fast(new_n,new_n,T,new_n,U,new_n,P[4],min_mat_recurse);

  /* TODO: P5 = (B - D)*(G + H) */
  matsub(new_n,Xpitch,B,Xpitch,D,new_n,T);
  matadd(new_n,Ypitch,G,Ypitch,H,new_n,U);
  matmult_fast(new_n,new_n,T,new_n,U,new_n,P[5],min_mat_recurse);

  /* TODO: P6 = (A - C)*(E + F) */
  matsub(new_n,Xpitch,A,Xpitch,C,new_n,T);
  matadd(new_n,Ypitch,E,Ypitch,F,new_n,U);
  matmult_fast(new_n,new_n,T,new_n,U,new_n,P[6],min_mat_recurse);

  /* Sonucun hesaplanmasi */
  /* TODO: Z sol ust = (P3 + P4) + (P5 - P1) */
  matadd(new_n,new_n,P[3],new_n,P[4],new_n,T);
  matsub(new_n,new_n,P[5],new_n,P[1],new_n,U);
  matadd(new_n,new_n,T,new_n,U,Zpitch,&Z[0]);

  /* TODO: Z sol alt = (P2 + P3) */
  matadd(new_n,new_n,P[2],new_n,P[3],Zpitch,&Z[new_n*Zpitch]);

  /* TODO: Z sag ust = (P0 + P1) */
  matadd(new_n,new_n,P[0],new_n,P[1],Zpitch,&Z[new_n]);
  
  /* TODO: Z sag alt = (P0 + P4) - (P2 + P6) */
  matadd(new_n,new_n,P[0],new_n,P[4],new_n,T);
  matadd(new_n,new_n,P[2],new_n,P[6],new_n,U);
  matsub(new_n,new_n,T,new_n,U,Zpitch,&Z[new_n*Zpitch + new_n]);

  /* TODO: Gecici pointerlar U ve T'yi free() edin */
  free(U);
  free(T);
  
  /* TODO: P[] dizisindeki heap alanlarini free() edin */
  for(i=0;i<6;i++){
  	free(P[i]);
  }
}

int main(int argc, char *argv[]) {

  /* Fonksiyonlarin test edilmesi */
  double _X[4*4] = {
    1, 2, 3, 1,
    -1, 1, 2, 3,
    0, 4, 5, -3,
    -1, 1, 2, 3
  };
  double _Y[4*4] = {
    1, 2, 3, 4,
    4, 3, 2, 1,
    -1, -1, 2, 2,
    3, 0, 1, 2
  };
  double _Z[4*4] = {0};

  matmult(4, 4, _X, 4, _Y, 4, _Z);
  matprint(4, 4, _Z);
  printf("=========================\n");

  double _Zfast[4*4] = {0};
  matmult_fast(4, 4, _X, 4, _Y, 4, _Zfast, 2);
  matprint(4, 4, _Zfast);

  double err = 0.0;
  for (int i = 0; i < sizeof(_Z) / sizeof(double); ++i) {
    err += _Z[i] - _Zfast[i];
  }
  printf("Error between methods: %.5f\n", err);
  assert(err < 0.0000001);
  
  /////////////////////////////////////////////////////////////

  /* Matris boyutu (int)      : argv[1] */
  /* recursion base case (int): argv[2] */
  if (argc != 3) {
    printf("Usage: %s <matrix dimension> <base recursion case>\n", argv[0]);
    exit(1);
  }

  /* Komut satirindan verilen matris boyutu ve ozyinelemenin
   * sonlandirilacagi temel durum. */
  int mat_size = atoi(argv[1]);
  int min_mat_recurse = atoi(argv[2]);

  /* Zaman olcumleri icin gerekli */  
  struct timeval tvBegin, tvEnd, tvDiff;

  double *X, *Y, *Z, *Zfast;
  /* TODO: 4 gosterici icin ilgili yerleri ayirin */
  X = malloc(mat_size*mat_size*sizeof(double));
  Y = malloc(mat_size*mat_size*sizeof(double));
  Z = malloc(mat_size*mat_size*sizeof(double));
  Zfast = malloc(mat_size*mat_size*sizeof(double));

  /* TODO: Gostericilerden birisi NULL ise bellek hatasi verip
   * programi 1 donus degeriyle sonlandirin. */
  if (X == NULL || Y == NULL || Z == NULL || Zfast == NULL) {
    fprintf(stderr, "Error allocating memory.\n");
    exit(1);
  }

  /* TODO: X ve Y matrislerini rasgele doldurun */
  matrand(mat_size,mat_size,X);
  matrand(mat_size,mat_size,Y);

  /* Klasik carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult(mat_size, mat_size, X, mat_size, Y, mat_size, Z);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult (%dx%d) --> %ld.%06ld\n", mat_size, mat_size, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

  /* Strassen carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult_fast(mat_size, mat_size, X, mat_size, Y, mat_size, Zfast, min_mat_recurse);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult_fast (%dx%d - base_case: %d) --> %ld.%06ld\n", mat_size, mat_size, min_mat_recurse, (long int) tvDiff.tv_sec, (long int) tvDiff.tv_usec);

  /* TODO: 4 gostericiye ayrilan yerleri free() edin. */
  free(X);
  free(Y);
  free(Z);
  free(Zfast);

  return 0;
}
