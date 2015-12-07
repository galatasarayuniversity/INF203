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
      M[i*pitch + j] = r * (rand()%10 - 1);
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
void matmult(int n,
             int Apitch, const double A[],
             int Bpitch, const double B[],
             int Cpitch, double C[])
             {
    int toplam;
    for(int i=0; i<n; ++i)
    {
    for(int y=0; y<n; ++y)
    {
    for(int k1=0; k1<n; ++k1)
    {
       toplam = toplam +A[i*Apitch + k1] * B[k1*Bpitch + y];
    }
    C[i*Cpitch + y] = toplam;
    toplam = 0;
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
  for(int i = 0; i < 7; i++)
  {
   *(P+i) = malloc(sz);

  }
  double *A, *B, *C, *D, *E, *F, *G, *H;
  double *U =(double *)malloc(sizeof(double) * new_n * new_n);
  double *T =(double *)malloc(sizeof(double) * new_n * new_n);
  A = X; B = X+new_n; C = X+new_n*Xpitch; D = X+new_n*Xpitch+new_n;
  E = Y; F = Y+new_n; G = Y+new_n*Ypitch; H = Y+new_n*Ypitch+new_n;
  matsub(new_n, Ypitch,F,Ypitch,H,Xpitch/2,T);
  matmult_fast(new_n,Xpitch,A,Xpitch/2,T,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matadd(new_n, Xpitch,A,Xpitch,B,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,U,Ypitch,H,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matadd(new_n, Xpitch,C,Xpitch,D,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,U,Ypitch,E,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matsub(new_n, Ypitch,G,Ypitch,E,Xpitch/2,T);
  matmult_fast(new_n,Xpitch,D,Xpitch/2,T,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matadd(new_n, Xpitch,A,Xpitch,D,Xpitch/2,U);
  matadd(new_n, Ypitch,E,Ypitch,H,Xpitch/2,T);
  matmult_fast(new_n,Xpitch/2,U,Ypitch/2,T,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matsub(new_n, Xpitch,B,Xpitch,D,Xpitch/2,T);
  matadd(new_n, Ypitch,G,Ypitch,H,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,T,Ypitch/2,U,Xpitch/2,P,min_mat_recurse);
  *P = *P + sz;
  matsub(new_n, Xpitch,A,Xpitch,C,Xpitch/2,T);
  matadd(new_n, Ypitch,E,Ypitch,F,Xpitch/2,U);
  matmult_fast(new_n,Xpitch/2,T,Ypitch/2,U,Xpitch/2,P,min_mat_recurse);
  matadd(new_n, Xpitch/2,*P-sz*3,Xpitch/2,*P-sz*2,Xpitch/2,U);
  matsub(new_n, Xpitch/2,*P-sz,Xpitch/2,*P-5*sz,Xpitch/2,T);
  matadd(new_n, Xpitch/2,U,Xpitch/2,T,Xpitch,Z);
  matadd(new_n, Xpitch/2,*P-4*sz,Xpitch/2,*P-3*sz,Xpitch,Z + new_n*Xpitch);
  matadd(new_n, Xpitch/2,*P-6*sz,Xpitch/2,*P-5*sz,Xpitch,Z +new_n);
  matadd(new_n, Xpitch/2,*P-6*sz,Xpitch/2,*P-2*sz,Xpitch/2,U);
  matadd(new_n, Xpitch/2,*P-4*sz,Xpitch/2,P,Xpitch/2,T);
  matsub(new_n, Xpitch/2,U,Xpitch/2,T,Xpitch,Z + new_n*Xpitch + new_n);
  free(U);
  free(T);
  for(int i = 0; i < 7; i++)
  {
   free(P+i);

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
  int sz = mat_size*mat_size*sizeof(double);
  double *X, *Y, *Z, *Zfast;
  X = (double *)malloc(sz);
  Y = (double *)malloc(sz);
  Z = (double *)malloc(sz);
  Zfast = (double *)malloc(sz);
  if (X||Y||Z||Zfast) {
    fprintf(stderr, "Error allocating memory.\n");
    exit(1);
  }

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

  /* TODO: 4 gostericiye ayrilan yerleri free() edin. */

  return 0;
}
