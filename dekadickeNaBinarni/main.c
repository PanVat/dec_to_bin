#include <stdio.h>

#define BITY 32

// VSECHNY FUNKCE
unsigned int vstupDesCisla();

void naplneniAVypisBinCisly(unsigned int, unsigned int *);

int opakovat();

// HLAVNI FUNKCE
int main() {
    unsigned int desCislo;
    unsigned int binarniCislo[BITY];

    do {
        printf("------------------------------\n");
        desCislo = vstupDesCisla();
        naplneniAVypisBinCisly(desCislo, binarniCislo);
        printf("------------------------------\n");
    } while (opakovat());

    return 0;
}

// DEKLARACE VSECH FUNKCI
unsigned int vstupDesCisla() {
    unsigned int cislo;
    int pocetZnaku;

    do {
        printf("Zadej libovolne desitkove cislo: ");
        scanf("%d", &cislo);

        pocetZnaku = 0;
        while (getchar() != '\n') {
            pocetZnaku++;
        }

        if (pocetZnaku != 0 || cislo < 0) {
            printf("Neplatne cislo, zadej znovu.\n");
        }
    } while (pocetZnaku != 0 || cislo < 0);
    return cislo;
}

void naplneniAVypisBinCisly(unsigned int desCislo, unsigned int *binarniCislo) {
    int index;

    if (desCislo == 0) {
        printf("Cislo %u je v binarni soustave 0\n", desCislo);
    } else {
        printf("Cislo %d je v binarni soustave: \n", desCislo);
        for (index = 0; desCislo > 0; ++index) {
            binarniCislo[index] = desCislo % 2;
            desCislo /= 2;
        }
        for (int i = index - 1; i >= 0; i--) {
            printf("%u", binarniCislo[i]);
        }
        printf("\n");
    }

}

int opakovat() {
    printf("Pro opakovani programu stisknete ENTER.\n");
    if (getchar() == '\n') {
        return 1;
    }
    return 0;
}
