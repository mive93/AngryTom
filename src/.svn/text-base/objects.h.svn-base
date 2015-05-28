/**
 * @file 
 * Header file contenente la dichiarazione delle strutture del programma e le costanti.
 */


/**
 * Tipo di fase del gioco.
 *
 * Angry Tom è suddiviso in diverse fasi. 
 * La prima è sempre la fase INIZIO, dove è gestito il menu principale
 * di tutto il gioco. Da esse si può accedere alle fasi :
 *
 * - IN_GIOCO, la quale fa iniziare il gioco vero e proprio. 
 *    Solo attraverso tale fase si può passare alla fase di PAUSA, a
 *    a quella LIVELLO, o a quella di GAMEVOER.
 *
 * - PUNTEGGI, che mostra i migliori punteggi di sempre.
 *
 * - CREDITS
 *
 * - HOWTO che spiega i comandi del gioco.
 */
enum FASE {INIZIO, IN_GIOCO, PAUSA, LIVELLO, PUNTEGGI, CREDITS, HOWTO, GAMEOVER};

/**
 * Tipo di bottone.
 *
 * Il menu di gioco è strutturato in modo che tu possa muoverti tra le diverse
 * fasi attraverso sia tasti, che bottoni.
 *
 * I bottoni hanno o la funzione di cambiare fase di gioco, o di caricare una 
 * partita salvata, o rimandano alla documentazione del programma, o di uscire
 * dal gioco.
 */
enum BOTTONI {GIOCAb,RIPRENDIb,CARICAb,ESCIb,PUNTEGGIb,HOWTOb,INDIETROb,DOCb,CREDITSb,CARICACPb};

/**
 * Tipo di tasto.
 *
 * Il gioco è gestito anche da tastiera, e per tener traccia di quali tasti
 * sono stati premuti, vi è un enumerato per ogni tasto utile al gioco.
 */

enum KEYS{SU, GIU, SINISTRA, DESTRA, SPAZIO, INVIO, TASTO_P, TASTO_M, TASTO_N, ESC };
/**
 * Struttura del giocatore.
 *
 * Il giocatore ha bisogno di diversi campi per gestire il movimento,
 * l'animazione del suo sprite, e le interazioni con gli 
 * altri oggetti del gioco.
 */
struct Giocatore 
{
	int x;						/**< Posizione x del giocatore*/
	int y;						/**< Posizione y del giocatore*/
	int vel;					/**< Velocità del giocatore*/
	int bordox;					/**< Bordo lungo x, utile per le collisioni*/
	int bordoy;					/**< Bordo lungo y, utile per le collisioni*/
		
	int maxFrame;				/**< Numero massimo di frame del giocatore*/
	int corFrame;				/**< Numero della frame corrente*/
	int frameCont;				/**< Contatore per le frame*/
	int frameRit;				/**< Contatore per il ritardo delle frame*/
	int frameAlt;				/**< Altezza della frame del giocatore*/
	int frameLun;				/**< Lunghezza della frame del giocatore*/
	int animationCol;			/**< Numero della colonna dell'animazione*/
	int animationDir;			/**< Direzione dell'animazione 
					 			 * (1: avanti; -1:indietro)
					 			 */
	bool attacco;				/**< Booleano che indica se il giocatore sta
								 * attaccando o meno 
								 */
	bool colpito;				/**< Booleano che indica se il giocatore è
								 * stato colpito o meno 
								 */
	int animationRow;			/**< Numero della riga di animazione */

	ALLEGRO_BITMAP *immagine;	/**< Immagine associata al giocatore */
};


/**
 * Struttura del proiettile.
 *
 * Il proiettile ha bisogno di gestire il movimento,
 * e l'immagine ad esso associata.
 */
struct Colpo 
{
	int x;						/**< Posizione x del proiettile*/
	int y;						/**< Posizione y del proiettile*/
	int vite;					/**< Vita del proiettile*/
	int vel;					/**< Velocità del proiettile*/

	int frameAlt;				/**< Altezza della frame del proiettile*/
	int frameLun;				/**< Lunghezza della frame del proiettile*/
	int animationRow;			/**< Numero della riga di animazione */

	ALLEGRO_BITMAP *immagine;	/**< Immagine associata al proiettile */
};

/**
 * Struttura del nemico.
 *
 * Il nemico ha bisogno di diversi campi per gestire il movimento,
 * l'animazione del suo sprite, e le interazioni con gli 
 * altri oggetti del gioco.
 */
struct Nemici 
{
	int x;						/**< Posizione x del nemico*/
	int y;						/**< Posizione y del nemico*/
	int vite;
	int vel;					/**< Velocità del nemico*/
	int bordox;					/**< Bordo lungo x, utile per le collisioni*/
	int bordoy;					/**< Bordo lungo y, utile per le collisioni*/

	int maxFrame;				/**< Numero massimo di frame del nemico*/
	int corFrame;				/**< Numero della frame corrente*/
	int frameCont;				/**< Contatore per le frame*/
	int frameRit;				/**< Contatore per il ritardo delle frame*/
	int frameAlt;				/**< Altezza della frame del nemico*/
	int frameLun;				/**< Lunghezza della frame del nemico*/
	int animationCol;			/**< Numero della colonna dell'animazione*/
	int animationDir;			/**< Direzione dell'animazione 
					 			 * (1: avanti; -1:indietro)
					 			 */
	int animationRow;			/**< Numero della riga di animazione */

	bool impatto;				/** Booleano che indica se il nemico ha subito 
								 * un impatto o meno 
								 */

	ALLEGRO_BITMAP *immagine;	/**< Immagine associata al nemico */

	
};

/**
 * Struttura dell'impatto.
 *
 * L'impatto ha bisogno di una posizione, un booleano per sapere
 * se è avvenuto e dei campi per la gestione dell'animazione.
 */
struct  Impatti
{
	int x;						/**< Posizione x dell'impatto*/
	int y;						/**< Posizione y dell'impatto*/
	bool attivo;				/**< Booleano che indica se vi è un impatto */

	int maxFrame;				/**< Numero massimo di frame dell'impatto*/
	int corFrame;				/**< Numero della frame corrente*/
	int frameCont;				/**< Contatore per le frame*/
	int frameRit;				/**< Contatore per il ritardo delle frame*/
	int frameAlt;				/**< Altezza della frame dell'impatto*/
	int frameLun;				/**< Lunghezza della frame dell'impatto*/
	int animationCol;			/**< Numero della colonna dell'animazione*/
	int animationDir;			/**< Direzione dell'animazione 
					 			 * (1: avanti; -1:indietro)
					 			 */

	int animationRow;			/**< Numero della riga di animazione */


	ALLEGRO_BITMAP *Nemico1;	/**< Immagine associata al l'impatto 
								 * col nemico di tipo 1 
								 */
	ALLEGRO_BITMAP *Nemico2;	/**< Immagine associata al l'impatto 
								 * col nemico di tipo 2 
								 */
};

/**
 * Struttura dello sfondo.
 *
 * Lo sfondo ha campi di posizione, velocità e quelli per gestire
 * l'immagine di sfondo.
 */
struct Sfondo
{
	float x;					/**< Posizione x dello sfondo*/
	float y;					/**< Posizione y dello sfondo*/
	float velX;					/**< Velocità dello sfondo su x*/
	float velY;					/**< Velocità dello sfondo su y*/
	int dirX;					/**< Direzione dello sfondo su x*/
	int dirY;					/**< Direzione dello sfondo su y*/

	int altezza;				/**Altezza dello sfondo */
	int lunghezza;				/**Lunghezza dello sfondo*/

	ALLEGRO_BITMAP *immagine;	/**Immagine associata allo sfondo*/
};

/**
 * Struttura dello gioco.
 *
 * Tale struttura gestisce i punti principali del gioco, come la fase
 * e i campi necessari per aggiornare i vari livelli.
 */
struct Gioco
{
	FASE fase;			/**< Fase di gioco*/
	int punti;			/**< Punti accumulati dal giocatore */
	int vite;			/**< Vite del giocatore */
	int livello;		/**< Livello del gioco*/
	int difficolta;		/**< Difficoltà del livello*/
	int n_nemici;		/**< Numero di nemici per livello*/
	float velocita;		/**< Velocità della partita, serve per aumentare
						 * la velocità dei nemici man mano che i 
						 * livelli aumentano.						
						 */
};
/**
 * Struttura delle statische.
 *
 * Le statistiche tengono conto dei parziali del gioco.
 */
struct Statistiche
{
	float colpi;		/**< Colpi totalizzati dal giocatore */
	float precisione;	/**< Precisione di tiro del giocatore */
	int vite_perse;		/**< Vite perse del giocatore */
};

/**
 * Struttura dei bottoni.
 *
 * I bottoni hanno i campi per gestire l'immagine associata ai vari
 * bottoni, e la loro posizione sullo schermo.
 */
struct Bottoni 
{
	int lunghezzaFrame;			/*< Lunghezza del frame del bottone*/
	int altezzaFrame;			/*< Altezza del frame del bottone*/
	int curFrame;				/*< Frame del bottone corrente*/
	int posX;					/*< Posizione x del bottone */
	int posY;					/*< Posizione y del bottone */
	int distanza;				/*< Distanza su y del bottone dagli altri */

	ALLEGRO_BITMAP * immagine;	/*< Immagine associata al bottone */
};

const int LARGHEZZA = 1000; /**< Lunghezza del display */
const int ALTEZZA = 500;	/**< Altezza del display */
const int NUM_COLPI = 6;	/**< Numero di colpi del giocatore */
const int NUM_NEMICI = 20;	/**< Numero di nemici*/
const int NUM_IMPATTI = 8;	/**< Numero di impatti */
const int NUM_VITE = 10;	/**< Numero di vite*/
const int N_BOTTONI = 10;	/**< Numero di bottoni */
const int NUM_PUNTEGGI =10;	/**< Numero di punteggi salvati */
const int NUM_TASTI = 10;	/**< Numero di tasti */

const char file[] = "save/data.bin";			/**< File dove sarà salvata e 					
											 	* caricata la partita
						 					 	*/
const char HSfile[] = "save/highscores.bin";	/**<File dove sono salvati i
												 * punteggi di ogni partita
												 */
/**
 * Tipo Punteggi.
 *
 * Al massimo in memoria si salvano ::NUM_PUNTEGGI.
 *
 * Utilizzando una typedef i punteggi sono più facilmente gestibili
 * nel salvataggio e caricamento su e da file binario.
 */
typedef int Punteggi[NUM_PUNTEGGI];	

/** Fine header modulo Objects */	
