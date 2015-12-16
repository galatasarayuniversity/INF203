#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

// c99 standartlarında derlemek için : gcc -std=c99 tp7.c
//!! p bir pointer, a bir dizi : p++ GEÇERLİ çünkü p bir nesne.a++ GEÇERSİZ
//çünkü a bir nesne değil. AMA p++ , p + i, p + 2 gibi ifadelere atama
//yapamazsın!! YANİ tanımlamadığın bir pointera (p++, p + 2 vs) atama işlemi
//gerçekleştiremezsin.

/* Zaman olcum fonksiyonlari */
int timeval_subtract(struct timeval *result, struct timeval *t2,
                     struct timeval *t1) {
  long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) -
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
      M[i * pitch + j] = r * (2 * drand48() - 1);
    }
  }
}

/* Matrisi ekrana yazdiran fonksiyon */
void matprint(int n, int pitch, const double M[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%10.2f ", M[i * pitch + j]);
    }
    printf("\n");
  }
}

/* TODO: Klasik matris carpimi algoritmasi: C = A * B */
void matmult(int n, int Apitch, const double A[], int Bpitch, const double B[],
             int Cpitch, double C[]) {
  int i, k, j;

  for (i = 0; i < n;
       i++) //Çağırılan matrisin içindeki çöp değerler 0 değerine dönüştürülür.
    for (j = 0; j < n; j++)
      C[i * Cpitch + j] = 0;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
        C[i * Cpitch + j] +=
            A[i * Apitch + k] *
            B[k * Bpitch + j]; // Algoritme karmaşıklığı O(n3) !
}

/* Matris toplami: S = A + B */
void matadd(int n, int Apitch, const double A[], int Bpitch, const double B[],
            int Spitch, double S[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      S[i * Spitch + j] = A[i * Apitch + j] + B[i * Bpitch + j];
    }
  }
}

/* Matris farki: S = A - B */
void matsub(int n, int Apitch, const double A[], int Bpitch, const double B[],
            int Spitch, double S[]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      S[i * Spitch + j] = A[i * Apitch + j] - B[i * Bpitch + j];
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
void matmult_fast(int n, int Xpitch, const double X[], int Ypitch,
                  const double Y[], int Zpitch, double Z[],
                  int min_mat_recurse) {
  /* TODO: min_mat_recurse'e kucuk esit bir matris geldiyse klasik algoritmayi
   * kullan */
  if (n <= min_mat_recurse) {
    matmult(n, Xpitch, X, Ypitch, Y, Zpitch, Z);
    return;
  }

  /* Bu cagridaki alt-matrislerin boylari n/2 olacak */
  const int new_n = n / 2;

  const int sz = new_n * new_n * sizeof(double);
  double *P[7];

  for (int i = 0; i < 7; i++)
    P[i] = malloc(sizeof(double) * sz);

  double *T, *U;
  T = malloc(sizeof(double) * sz);
  U = malloc(sizeof(double) * sz);

  double *A, *B, *C, *D, *E, *F, *G, *H;

  A = (double *)X;
  B = (double *)X + n / 2;
  C = (double *)X + n / 2 * Xpitch;
  D = C + n / 2;

  E = (double *)Y;
  F = (double *)Y + n / 2;
  G = (double *)Y + n / 2 * Ypitch;
  H = G + n / 2;

  /* TODO: P0 = A*(F - H) */
  matsub(new_n, Xpitch, F, Ypitch, H, Zpitch, U);
  matmult_fast(new_n, Xpitch, A, Ypitch, U, Zpitch, P[0],
               min_mat_recurse); // fonksiyonun içinde kendisini çağırdım ama
                                 // onunla return ettirmedim yine de
                                 // özyinelemeli olmuş oluyo dimi??

  /* TODO: P1 = (A + B)*H */
  matadd(new_n, Xpitch, A, Ypitch, B, Zpitch, U);
  matmult_fast(new_n, Xpitch, U, Ypitch, H, Zpitch, P[1], min_mat_recurse);

  /* TODO: P2 = (C + D)*E */
  matadd(new_n, Xpitch, C, Ypitch, D, Zpitch, U);
  matmult_fast(new_n, Xpitch, U, Ypitch, E, Zpitch, P[2], min_mat_recurse);

  /* TODO: P3 = D*(G - E) */
  matsub(new_n, Xpitch, G, Ypitch, E, Zpitch, U);
  matmult_fast(new_n, Xpitch, D, Ypitch, U, Zpitch, P[3], min_mat_recurse);

  /* TODO: P4 = (A + D)*(E + H) */
  matadd(new_n, Xpitch, A, Ypitch, D, Zpitch, U);
  matadd(new_n, Xpitch, E, Ypitch, H, Zpitch, T);
  matmult_fast(new_n, Xpitch, U, Ypitch, T, Zpitch, P[4], min_mat_recurse);

  /* TODO: P5 = (B - D)*(G + H) */
  matsub(new_n, Xpitch, B, Ypitch, D, Zpitch, U);
  matadd(new_n, Xpitch, G, Ypitch, H, Zpitch, T);
  matmult_fast(new_n, Xpitch, U, Ypitch, T, Zpitch, P[5], min_mat_recurse);

  /* TODO: P6 = (A - C)*(E + F) */
  matsub(new_n, Xpitch, A, Ypitch, C, Zpitch, U);
  matadd(new_n, Xpitch, E, Ypitch, F, Zpitch, T);
  matmult_fast(new_n, Xpitch, U, Ypitch, T, Zpitch, P[6], min_mat_recurse);

  /* Sonucun hesaplanmasi */
  /* TODO: Z*/ matadd(new_n, Zpitch, P[3], Zpitch, P[4], Zpitch, U);
  matsub(new_n, Zpitch, P[5], Zpitch, P[1], Zpitch, T);
  matadd(new_n, Zpitch, U, Zpitch, T, Zpitch, (double *)X);

  /* TODO: Z sol alt */ matadd(new_n, Zpitch, P[2], Zpitch, P[3], Zpitch,
                               (double *)(X + Xpitch / 2 * Xpitch));

  /* TODO: Z sag ust */ matadd(new_n, Zpitch, P[0], Zpitch, P[1], Zpitch,
                               (double *)(X + Xpitch / 2));

  /* TODO: Z sag alt */ matadd(new_n, Zpitch, P[0], Zpitch, P[4], Zpitch, U);
  matadd(new_n, Zpitch, P[2], Zpitch, P[6], Zpitch, T);
  matsub(new_n, Zpitch, U, Zpitch, T, Zpitch,
         (double *)(X + Xpitch / 2 * Xpitch + Xpitch / 2));

  /* TODO: Gecici pointerlar U ve T'yi free() edin */
  free(U);
  free(T);

  /* TODO: P[] dizisindeki heap alanlarini free() edin */
  for (int i = 0; i < 7; i++)
    free(P[i]);
}

int main(int argc, char *argv[]) {

  srand(time(NULL));

  /* Fonksiyonlarin test edilmesi */
  double _X[4 * 4] = {1, 2, 3, 1, -1, 1, 2, 3, 0, 4, 5, -3, -1, 1, 2, 3};
  double _Y[4 * 4] = {1, 2, 3, 4, 4, 3, 2, 1, -1, -1, 2, 2, 3, 0, 1, 2};
  double _Z[4 * 4] = {0};

  matmult(4, 4, _X, 4, _Y, 4, _Z);
  matprint(4, 4, _Z);
  printf("=========================\n");

  double _Zfast[4 * 4] = {0};
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
  X = malloc(mat_size * mat_size * sizeof(int));
  Y = malloc(mat_size * mat_size * sizeof(int));
  Z = malloc(mat_size * mat_size * sizeof(int));
  Zfast = malloc(mat_size * mat_size * sizeof(int));

  /* TODO: Gostericilerden birisi NULL ise bellek hatasi verip
   * programi 1 donus degeriyle sonlandirin. */
  if (X == NULL || Y == NULL || Z == NULL || Zfast == NULL) {
    fprintf(stderr, "Error allocating memory.\n");
    exit(1);
  }

  /* TODO: X ve Y matrislerini rasgele doldurun */
  for (int i = 0; i < mat_size * mat_size; i++)
    X[i] = rand() % 10;
  for (int i = 0; i < mat_size * mat_size; i++)
    Y[i] = rand() % 10;

  /* Klasik carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult(mat_size, mat_size, X, mat_size, Y, mat_size, Z);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult (%dx%d) --> %ld.%06ld\n", mat_size, mat_size,
         (long int)tvDiff.tv_sec, (long int)tvDiff.tv_usec);

  /* Strassen carpim algoritmasinin olcumu */
  gettimeofday(&tvBegin, NULL);
  matmult_fast(mat_size, mat_size, X, mat_size, Y, mat_size, Zfast,
               min_mat_recurse);
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvBegin);
  printf("matmult_fast(%dx%d - base_case: %d) --> %ld.%06ld\n", mat_size,
         mat_size, min_mat_recurse, (long int)tvDiff.tv_sec,
         (long int)tvDiff.tv_usec);

  /* TODO: 4 gostericiye ayrilan yerleri free() edin. */
  free(X);
  free(Y);
  free(Z);
  free(Zfast);

  return 0;
}
