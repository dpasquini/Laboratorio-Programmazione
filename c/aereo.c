#include <stdio.h>

#define NUM_POSTI 10

int scelta_classe();
void stampa_imbarco(int, int);
int prima_classe(int posti[]);
int seconda_classe(int posti[]);
int verifica_passaggio();

int main() {
    int posti[NUM_POSTI] = {0};
    int num_biglietti_acquistati = 0;
    for( ;num_biglietti_acquistati < NUM_POSTI; ) {

        int classe_scelta = scelta_classe();
        int posto_assegnato = -1;

        int scelta = 0;

        if (classe_scelta == 1) {
            posto_assegnato = prima_classe(posti);
            if (posto_assegnato == -1) {
                scelta = verifica_passaggio();
                if (scelta == 1) {
                    posto_assegnato = seconda_classe(posti);
                } else {
                    printf("Il prossimo volo parte tra tre ore\n");
                }
            }
        } else if (classe_scelta == 2) {
            posto_assegnato = seconda_classe(posti);
            if (posto_assegnato == -1) {
                scelta = verifica_passaggio();
                if (scelta == 1) {
                    posto_assegnato = prima_classe(posti);
                } else {
                    printf("Il prossimo volo parte tra tre ore\n");
                }
            }
        }
        if(posto_assegnato != -1) {
            stampa_imbarco(classe_scelta, posto_assegnato);
            num_biglietti_acquistati++;
        }

        printf("Sono disponibili ancora %d biglietti\n", NUM_POSTI - num_biglietti_acquistati);
    }

    return 0;
};

/**
 * Verifica se c'è disponibilità di un posto in prima classe e lo assegna all'utente, se disponibile
 * @param aereo array di int che contiene le disponibilità dei posti
 * @return il posto assegnato in prima classe, oppure -1 se non c'è disponibilità di posti
 */
int prima_classe(int aereo[]) {
    for(int i = 0; i < 5; i++) {
        if(aereo[i] == 0) {
            aereo[i] = 1;
            return i;
        }
    }
    return -1;
}

/**
 * Verifica se c'è disponibilità di un posto in classe economica e lo assegna all'utente, se disponibile
 * @param aereo array di int che contiene le disponibilità dei posti
 * @return il posto assegnato in economica, oppure -1 se non c'è disponibilità di posti
 */
int seconda_classe(int aereo[]) {
    for(int i = 5; i < NUM_POSTI; i++) {
        if(aereo[i] == 0) {
            aereo[i] = 1;
            return i;
        }
    }
    return -1;
}

/**
 * Chiede all'utente di digitare in input uno tra i valori 1 e 2
 * che corrispondono alle classi Prima e Economica
 * @return la classe scelta dall'utente (1, 2)
 */
int scelta_classe() {
    int classe = 0;

    while(classe < 1 || classe > 2) {
        printf("Inserisci classe, 1 per Prima classe, 2 per seconda classe: ");
        scanf("%d", &classe);
    }
    return classe;
}


/**
 * Verifica se l'utente vuole passare in un'altra classe o prendere un volo successivo
 * @return scelta dell'utente, 1 per passaggio, 2 per salta volo
 */
int verifica_passaggio() {
    int scelta_passaggio = 0;
    printf("I posti in classe economica non sono più disponibili. Vuoi acquistare in prima classe? 1 per si, 2 per no");
    while(scelta_passaggio < 1 || scelta_passaggio > 2) {
        scanf("%d", &scelta_passaggio);
    }
    return scelta_passaggio;
}

/**
 * Visualizza la carta di imbarco con la posizione sull'aereo, e la classe del posto acquistato
 * @param c classe assegnata in aereo
 * @param p posto in aereo
 */
void stampa_imbarco(int c, int p) {
    printf("***********************************\n");
    printf("Posto assegnato %d in %s \n", p, c == 1? "prima classe" : "seconda classe");
    printf("***********************************\n");
}