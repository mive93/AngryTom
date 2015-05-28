/**
 * @file 
 * Header file contenente l'interfaccia del modulo Debug.
 * Nell'header sono contenuti i tre livelli di tracing.
 */

/**Stampa delle variabili di aggiornamento del gioco.
 *
 * Funzione che stampa le variabili booleane adibite all'aggiornamento
 * della stampa dello schermo del programma, del salvataggio dei punteggi
 * e della fine del gioco
 * @param[in] fine	Fine gioco
 * @param[in] render 	Aggiornamento schermo
 * @param[in] HSaggiornati	Aggiornamento punteggi
 */
void controllo_inizio(bool fine,bool render,bool HSaggiornati);

/**Stampa delle variabili globali di gestione della partita.
 *
 * Funzione che stampa la variabili del ::Gioco che gestiscono i 
 * dati della partita, quelli delle ::Statistiche adibita alla 
 * memorizzazione di quest'ultime, e le variabili dei ::Punteggi
 */
void stampa_dati_partita();

/**Stampa delle variabili degli oggetti di gioco.
 *
 * La funzione stampa gli oggetti che usa il gioco,
 * quindi ::Giocatore, i ::Nemici, quelli del ::Colpo e gli ::Impatti
 * @param[in] colpi	Gestione proiettili 
 * @param[in] nemici 	Gestione nemici
 * @param[in] tom	Gestione giocatore
 * @param[in] impatti	Gestione collisioni
 */
void stampa_dati_in_gioco(const Colpo colpi[],const Nemici nemici[], Giocatore tom,const Impatti impatti[]);

/** Fine header file di DEBUG*/
