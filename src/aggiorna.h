/**
 * @file 
 * Header file contenente l'interfaccia del modulo Aggiorna.
 * In questo Header file sono contenuti gli aggiornamenti del giocatore,
 * dei nemici, degli impatti ma anche della fase di gioco, del
 * background e della posizione del mouse.
 */

/** Inizia la partita.
 *
 * La funzione inizia una nuova partita di tipo ::Gioco
 * Si parte con tre vite e dal livello uno.
 */
void Inizia_partita();

/** Cambio di livello.
 *
 * Ogni qualvolta si passi di livello va utilizzata tale funzione.
 * Serve per aumentare il numero di livello, aggiornare la difficoltà e la
 * velocità. Ad ogni livello superato il giocatore riceve anche una vita bonus.
 */
void Nuovo_livello();

/** Routine dei cambi di fase.
 *
 * Funzione che aggiorna alla nuova fase di gioco 
 * sistemando le procedure di uscita fase e quelle di
 * entrata nella nuova.
 * @param[in] nuova	fase a cui si vuole passare		
 * @param[in] nemici	nemici che potrebbero subire modifiche
 * @param[in] colpi	colpi che potrebbero subire modifiche
 * @param[in] tom	giocatore che potrebbe subire modifiche				
 * @param[in] impatti	impatti che potrebbero subire modifiche		
 */
void Cambia_fase(FASE nuova,Nemici nemici[],Colpo colpi[],Giocatore &tom,Impatti impatti[]);

/** Aggiornamento dell'animazione del giocatore.
 *
 * Funzione che aggiorna l'animazione del ::Giocatore.
 * 
 * Vi sono quattro tipi di animazioni : se il giocatore sta attaccando;
 * se il giocatore è stato colpito; se il giocatore si sta  
 * muovendo nelle varie direzioni, o se è fermo sul posto e cammina.
 * @param[in] tom 	Giocatore da spostare
 */
void Aggiorna_anim_giocatore(Giocatore &tom);

/** Spostamento del giocatore.
 *
 * Funzione che permette al ::Giocatore di spostarsi sull schermo, gestendo 
 * oppurtamente le sue animazioni. 
 *
 * I tasti legati al movimento sono  ::SU, ::GIU, ::DESTRA, ::SINISTRA.
 * @param[in] tom 	Giocatore da spostare
 */
void Sposta_giocatore(Giocatore &tom);

/** Generazione delle posizioni iniziale casuali dei nemici.
 *
 * La funzione assegna ai ::Nemici presenti nel livello la posizione x
 * uguale per tutti, ovvero alla fine dello schermo, mentre la posizione y
 * è generata in modo random.
 *
 * Tali posizioni sono generate solo se i nemici sono vivi,e solo per i nemici
 * presenti nel tale livello.
 * @param[in] nemici 	Nemici di cui generare la posizione
 */
void Spawn_Nemici(Nemici nemici[]);

/** Aggiornamento delle animazioni dei nemici.
 *
 * La funzione aggiorna le animazioni dei diversi nemici, nel caso in cui 
 * essi siano in vita.
 *
 * Sono gestiti due diversi tipi di animazioni : il nemico che avanza; il 
 * nemico colpito.
 * @param[in] nemici 	Nemici di cui aggiornare l'animazione
 */
void Aggiorna_Nemici(Nemici nemici[]);

/** Impatto del giocatore con i nemici.
 *
 * Funzione che gestisce l'impatto tra il giocatore e i vari ::Nemici.
 * Da tale funzione si nota la necessità dei campi bordox e bordoy.
 * 
 * Tale funzione gestisce anche le vite del giocatore :
 * Se il giocatore viene colpito da un nemico, o un nemico non viene ucciso 
 * dal giocatore ma riesce ad uscire dallo schermo vivo, allora il 
 * giocatore perde una vita.
 * @param[in] nemici 	Nemici che possono subire l'impatto
 * @param[in] tom 	Giocatore che può subire l'impatto
 */
void Impatto_Nemici(Nemici nemici[], Giocatore &tom);

/** Sparo del colpo.
 *
 * Funzione che permette al giocatore di sparare un ::Colpo.
 * @param[in] colpi		Colpi sparati
 * @param[in] tom		Gicatore che può sparare il colpo
 * @param[in] shot		Suono associato allo sparo di un colpo
 */
void Spara_colpo(Colpo colpi[], Giocatore &tom, int Row,ALLEGRO_SAMPLE *shot);

/** Aggiornamento del colpo.
 *
 * Funzione che gestisce l'aggiornamento dei colpi.
 * I colpi vengono eliminati se escono dallo schermo.
 * @param[in] colpi		Colpi da aggiornare
 */
void Aggiorna_colpo(Colpo colpi[]);

/** Impatto del colpo col nemico.
 *
 * Funzione che gestisce l'impatto del ::Colpo coi ::Nemici
 * Se un colpo ha un impatto con un nemico, il nemico perde una vita e 
 * i punti del giocatore sono incrementati di 1.
 * @param[in] colpi		Colpi da aggiornare
 * @param[in] tom		Giocatore che spara i colpi
 * @param[in] nemici	Nemici che possono subire l'impatto con i colpi
 * @param[in] impatti	Impatti che possono avvenire
 * @param[in] morte1	Suono per la morte dei nemici, se colpiti
 */
void Impatto_colpo(Colpo colpi[], Nemici nemici[], Giocatore &tom, Impatti impatti[], ALLEGRO_SAMPLE *morte1);

/** Inizio degli impatti. 
 *
 * Funzione che inizia gli ::Impatti in caso le vite di un 
 * tipo di nemico siano 0.
 * @param[in] impatti	Impatti da iniziare
 * @param[in] x			Posizione x che ha avuto l'impatto
 * @param[in] y			Posizione y che ha avuto l'impatto
 * @param[in] j			Indice del tipo di nemico che ha subito l'impatto
 */
void Inizia_impatti(Impatti impatti[], int x, int y,int j);

/** Aggiornamento degli impatti. 
 *
 * Funzione che gestisce l'animazione degli ::Impatti, ovvero delle frame
 * delle morti dei nemici di tipo 1 e 2.
 * @param[in] impatti	Impatti da aggiornare
 */
void Aggiorna_impatti(Impatti impatti[]);

/** Ritorna se il cursore del mouse è su un bottone.
 * 
 * La funzione serve a verificare se il cursore del mouse si
 * trova sulla parte dello schermo sulla quale è disegnato un certo
 * bottone. Si passano diversi parametri per identificare il bottone.
 * @param[in] ev	Evento, serve per ottenere la posizione del mouse
 * @param[in] bottonex	Posizione x del bottone
 * @param[in] bottoney	Posizione y del bottone
 * @param[in] dist	Distanza del bottone dagli altri
 * @param[in] altezza	Altezza del bottone
 * @param[in] lunghezza	Lunghezza del bottone
 * @return Ritorna vero solo se il mouse è nella porzione di schermo occupata
 *         dal bottone.
 */
bool CursoresuBottone(ALLEGRO_EVENT ev, int bottonex, int bottoney, int dist, int altezza, int lunghezza);

/** Aggiornamento dello sfondo.
 *
 * La funzione aggiorna lo ::Sfondo, ovvero gestisce la sua animazione.
 * @param[in] s	Sfondo.
 */
void UpdateBackground(Sfondo &s);


/** Fine header file Aggiorna */
