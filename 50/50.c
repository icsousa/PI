#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int um() {
    int lista, maior = -1;

    while(1) {
        scanf("%d", &lista);
        if(lista == 0) break;
        if (lista > maior) maior = lista;
    }
    printf("%d\n", maior);
    return maior;
}

int dois() {
    int lista, media = -1, n = 0, soma = 0;

    while(1) {
        scanf("%d", &lista);
        if(lista == 0) break;
        n++;
        soma += lista;
        media = soma / n;

    }
    printf("%d\n", media);
    return media;
}

int tres() {
    int lista, s_maior = -1, maior = 0;

    while(1) {
        scanf("%d", &lista);
        if(lista == 0) break;
        if (lista > maior) {
            s_maior = maior;
            maior = lista;
        }
        else {
            if (lista > s_maior) s_maior = lista;
        }
    }
    printf("%d\n", s_maior);
    return s_maior;
}

int bitsUm (unsigned int n){
    int r = 0;
    while(n) {
        r += (n % 2);
        n >>= 1; 
    }
    return r;
}


int trailingZ (unsigned int n) {
    if(n % 2) return 0;
    else return 1 + trailingZ(n >> 1);
}


int qDig (unsigned int n) {
    if(n / 10 < 1) return 1;
    else return 1 + qDig(n / 10);
}

char mystrcat(char s1[], char s2[]) {
    char *ptr = s1;

    while(*ptr != '\0') {
        ptr++;
    }

    while(*s2 != '\0') {
        *ptr = *s2;
        ptr++;
        s2++;
    }

    *ptr = '\0';

    return *s1;
}

char mystrcpy(char *dest, char source[]) {
    char *ptr = dest;

    while(*source != '\0') {
        *ptr = *source;
        ptr++;
        source++;
    } 

    *ptr = '\0';

    return *dest;
}

int mystrcmp(char s1[], char s2[]) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }
    
    return *s1 - *s2;
}

int maxCres(int v[], int N) {
    int seq = 1, maiorSeq = 1;

    for (int i = 0; i < N; i++) {
        if (v[i] <= v[i+1]) {
            seq++;
        }
        else {
            if(maiorSeq < seq) {
                maiorSeq = seq;
            }
            seq = 1;
        }
    }
    
    return maiorSeq;
}

int elimRep (int v[], int n) {
    int i = 1;

    while(i < n) {
        int rep = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) rep = 1;
        }
        if(rep) {
            for (int j = i; j < n; j++) {
                v[j] = v[j+1];
            }
            n--;
        }
        else i++;
    }

    printf("%d", n);
    return n;
}

int elimRepOrd (int v[], int n) {

    int j = 0;

    for (int i = 1; i < n; i++) {
        if (v[i] != v[j]){
            j++;
            v[j] = v[i];
        }
    }
    printf("%d", j + 1);
    return j + 1;
}


int comunsOrd (int a[], int na, int b[], int nb) {
    int i = 0, j = 0, rep = 0;

    while(i < na && j < nb) {
        if (a[i] == b[j]) {
            rep ++;
            i++;
            j++;
        }
        else if(a[i] > b[j]) {
            j++;
            }
        else i++;
    }

    return rep;
}


int comuns(int a[], int na, int b[], int nb) {
    int count = 0;


    for (int i = 0; i < na; i++) {
        for (int j = 0; j < nb; j++) {
            if (a[i] == b[j]) {
                count++;
                break;
            }
        }
    }

    printf("%d", count);
    return count;
}


int minInd (int v[], int n) {
    int mInd = 0, value = v[mInd]; 

    for (int i = 1; i < n; i++) {
        if (value > v[i]) {
            value = v[i];
            mInd = i;
        }
        printf("%d - mInd\n", mInd);
        printf("%d - valor\n", value);

    }
    printf("%d", mInd);
    return mInd;
}

void somasAc (int v[], int Ac[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            Ac[i] += v[j]; 
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d\n", Ac[i]);
    }
}

int triSup (int N, float m[N][N]) {

    for(int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] != 0) return 0;
        }
    }
    return 1;
}

void transposta (int N, float m[N][N]) {

    float n[N][N];
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {
            n[j][i] = m[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = n[i][j];
        }
    }
}

void addTo (int N, int M, int a[N][M], int b[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            a[i][j] += b[i][j];
        }
    }
}

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] || v2[i];
    }
    return 0;
}

int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
    }
    return 0;
}

int intersectMSet(int N, int v1[N], int v2[N], int r[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = v1[i] && v2[i];
    }
    return 0;
}





int main() {
    int v[5] = {4,7,2,8,3};
    float m1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    float m2[3][3] = {
        {1,2,3},
        {0,5,6},
        {0,0,9}
    };

    int b[5] = {};
    printf("Matriz - %s\n", triSup(3, m1) ? "Sim" : "Não");
    printf("Matriz - %s\n", triSup(3, m2) ? "Sim" : "Não");

    return 0;
}