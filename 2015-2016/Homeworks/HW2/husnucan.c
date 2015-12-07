
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
  long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;
  return (diff < 0);
}

/* Bir matrisi rasgele sayilarla dolduran fonksiyon */ /* n: sutun sayısı, pitch: satir sayisi */
void matrand(int n, int pitch, double M[])
{
  const double r = 10.0;
  int i, j;
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
              M[i*pitch + j] = r * (rand()%10);
    }
  }
}

/* Matrisi ekrana yazdiran fonksiyon */
void matprint(int n, int pitch, const double M[]) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%10.2f ", M[i*pitch + j]);
    }
    printf("\n");
  }
}
/* TODO: Klasik matris carpimi algoritmasi: C = A * B */
void matmult(int n,
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[])
{
    int i = 0, j = 0, z = 0, x = 0, sum = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            z = 0;
            x = 0;

            while(z < n && x < n)
            {
                sum = sum + ((A[i*Apitch + z]) * (B[x*Bpitch + j]));
                z++;
                x++;
            }
            C[(i*Cpitch) + j] = sum;
            sum = 0;
        }
    }
}

/* Matris toplami: S = A + B */
void matadd(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      S[i*Spitch + j] = A[i*Apitch + j] + B[i*Bpitch + j];
    }
  }
}

/* Matris farki: S = A - B */
void matsub(int n,
            int Apitch, const double A[],
            int Bpitch, const double B[],
            int Spitch, double S[]) {
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
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
void matmult_fast(int n,
                  int Xpitch, const double X[],
                  int Ypitch, const double Y[],
                  int Zpitch, double Z[], int min_mat_recurse) {
  /* TODO: min_mat_recurse'e kucuk esik bir matris geldiyse klasik algoritmayi kullan */
  if (n <= min_mat_recurse)
  {
    matmult(n, Xpitch, X, Ypitch, Y, Zpitch, Z);
    return;
  }

  /* Bu cagridaki alt-matrislerin boylari n/2 olacak */
  const int new_n = n/2;

  const int sz = new_n*new_n*sizeof(double);
  double P1[new_n*new_n];
  double P0[new_n*new_n];
  double P2[new_n*new_n];double P3[new_n*new_n];
  double P4[new_n*new_n];double P5[new_n*new_n];double P6[new_n*new_n];/*sizin dediğiniz gibi heap'den yer vermeye çalıştım ama yapamadım. */
  double *T = malloc(sz);
  double *U = malloc(sz);
  double *A = &X[0];
  double *B = &X[new_n];
  double *C = &X[new_n*Xpitch];
  double *D = &X[new_n*Xpitch + new_n];

  double *E = &Y[0];
  double *F = &Y[new_n];
  double *G = &Y[new_n*Ypitch];
  double *H = &Y[new_n*Ypitch + new_n];

  matsub(new_n, Xpitch,F,Xpitch,H,Xpitch/2,T);
  matmult_fast(new_n,Xpitch,A,Xpitch/2,T,Xpitch/2,P0,min_mat_recurse); /* TODO: P0 = A*(F - H) */


  matadd(new_n, Xpitch,A,Xpitch,B,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,U,Xpitch,H,Xpitch/2,P1,min_mat_recurse); /* TODO: P1 = (A + B)*H */

  matadd(new_n, Xpitch,C,Xpitch,D,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,U,Xpitch,E,Xpitch/2,P2,min_mat_recurse); /* TODO: P2 = (C + D)*E */

  matsub(new_n, Xpitch,G,Xpitch,E,Xpitch/2,T);
  matmult_fast(new_n,Xpitch,D,Xpitch/2,T,Xpitch/2,P3,min_mat_recurse); /* TODO: P3 = D*(G - E) */


  matadd(new_n, Xpitch,A,Xpitch,D,Xpitch/2,U);
  matadd(new_n, Xpitch,E,Xpitch,H,Xpitch/2,T);
  matmult_fast(new_n,Xpitch/2,U,Ypitch/2,T,Xpitch/2,P4,min_mat_recurse); /* TODO: P4 = (A + D)*(E + H) */


  matsub(new_n, Xpitch,B,Xpitch,D,Xpitch/2,T);
  matadd(new_n, Xpitch,G,Xpitch,H,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,T,Ypitch/2,U,Xpitch/2,P5,min_mat_recurse); /* TODO: P5 = (B - D)*(G + H) */


  matsub(new_n, Xpitch,A,Xpitch,C,Xpitch/2,T);
  matadd(new_n, Xpitch,E,Xpitch,F,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,T,Ypitch/2,U,Xpitch/2,P6,min_mat_recurse); /* TODO: P6 = (A - C)*(E + F) */

  matadd(new_n, Xpitch/2,P3,Xpitch/2,P4,Xpitch/2,U);
  matsub(new_n, Xpitch/2,P5,Xpitch/2,P1,Xpitch/2,T);
  matadd(new_n, Xpitch/2,U,Xpitch/2,T,Xpitch,&Z[0]); /* TODO: Z sol ust = (P3 + P4) + (P5 - P1) */

  matadd(new_n, Xpitch/2,P2,Xpitch/2,P3,Xpitch,&Z[new_n*Xpitch]); /* TODO: Z sol alt = (P2 + P3) */

  matadd(new_n, Xpitch/2,P0,Xpitch/2,P1,Xpitch,&Z[new_n]); /* TODO: Z sag ust = (P0 + P1) */

  matadd(new_n, Xpitch/2,P0,Xpitch/2,P4,Xpitch/2,U);
  matadd(new_n, Xpitch/2,P2,Xpitch/2,P6,Xpitch/2,T);
  matsub(new_n, Xpitch/2,U,Xpitch/2,T,Xpitch,&Z[new_n*Xpitch + new_n]); /* TODO: Z sag alt = (P0 + P4) - (P2 + P6) */

  free(U);
  free(T);


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
  int i;
  for (i = 0; i < sizeof(_Z) / sizeof(double); ++i) {
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
  X = malloc(sizeof(double)*mat_size*mat_size);
  Y = malloc(sizeof(double)*mat_size*mat_size);
  Z = malloc(sizeof(double)*mat_size*mat_size);
  Zfast = malloc(sizeof(double)*mat_size *mat_size);

  /* TODO: 4 gosterici icin ilgili yerleri ayirin */

  /* TODO: Gostericilerden birisi NULL ise bellek hatasi verip
   * programi 1 donus degeriyle sonlandirin. */
  if (X == NULL || Y == NULL || Z == NULL || Zfast == NULL ) {
    fprintf(stderr, "Error allocating memory.\n");
    exit(1);
  }
  matrand(mat_size,mat_size,X);
  matrand(mat_size,mat_size,Y);
  /* TODO: X ve Y matrislerini rasgele doldurun */

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
  free(X);
  free(Y);
  free(Z);
  free(Zfast);
  /* TODO: 4 gostericiye ayrilan yerleri free() edin. */

  return 0;
}
/* 2.1 Alt problemlere Bölme:
Soru: Bu bölümlendirerek çarpma algoritması klasik algoritmaya göre zamansal karmaşalıkta iyileşme ya da kötüleşme sağlar mı ? Açıklayınız.
Divide and Conquer ile çarpma işlemini alt problemlere bölme, klasik algoritmaya göre daha farkı yoktur. Çünkü Divide and Conquer ile
yaparsak eğer 8 çarpma ve 4 toplama işlemi yapılacaktır.
Ve master teorem ile ifadesi şöyle olacaktır.
A(n) = 8 x A(n/2) + f( n2 ) ve  nlogba  = nlog28  = n3  n3 > n2 o zaman A(n) = 0(n3)
Klasik algoritmada bir while 2 for işlemi var ve hepsi n defa işlem yapıyor yani klasik algoritmada
A(n) = 0(n3)'dir. Sonuç olarak ikisi de aynı performanstadır.
2.2.2  Karmaşıklık :
Strassen yönteminin klasik yönteme göre neden daha iyi olduğunu ve zaman karmaşıklığını büyük-O gösterimiyle anlatınız.
Strassen yöntemiyle Ana problemi 7 tane recursive yarı büyüklükte problemle çözüyoruz. Yani 7 tane n/2 çarpma yapıorz. Ve
n2 zamanda combine yapılıyor.  A(n) = 7 x A(n/2) + f(n2)
0(n(log2 7)) < 0(n3) sonuç olarak Strassen yöntemi daha kısa sürede çalışıyor bu da onu performans bakımından daha iyi yapıyor. */

