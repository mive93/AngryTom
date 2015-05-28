/**
 * @file 
 * Header file contenente l'interfaccia del modulo Dichiarazioni.
 * Tutte le varibili di tale header file sono utili quasi a tutti i moduli
 * per cui necessitano dell'extern per non essere dichiarate ogni volta
 * che viene creato il file oggetto di ogni modulo.
 */

extern ALLEGRO_FONT *font18 ;		/**< Font utilizzato nel Menu*/
extern ALLEGRO_FONT *font15 ;		/**< Font utilizzato nella fase GAMEOVER*/
extern ALLEGRO_FONT *font100 ;		/**< Font utilizzato per i titoli del Menu*/

extern ALLEGRO_BITMAP *PannelloRisultati; 	/**< Immagine del pannello dei risultati*/
extern ALLEGRO_BITMAP *PannelloPunteggi;	/**< Immagine del pannello dei punteggi*/


extern ALLEGRO_BITMAP * inizio;	/**< Sfondo utilizzato per le fasi INIZIO,
				 				 * PAUSA, CREDITS, HOWTO, GAMEOVER
								 */
extern ALLEGRO_BITMAP * punteggi;	/**< Sfondo utilizzato per la fase PUNTEGGI*/
extern ALLEGRO_BITMAP *ImmS;		/**< Sfondo 1 utilizzato per la fase IN_GIOCO*/
extern ALLEGRO_BITMAP *ImmS2;		/**< Sfondo 2 utilizzato per la fase IN_GIOCO*/
extern ALLEGRO_BITMAP *ImmS3;		/**< Sfondo 3 utilizzato per la fase IN_GIOCO*/

extern ALLEGRO_BITMAP *ImmG;		/**< Immagine del giocatore*/
extern ALLEGRO_BITMAP *ImmN1;		/**< Immagine del nemico di tipo 1*/
extern ALLEGRO_BITMAP *ImmN2;		/**< Immagine del nemico di tipo 2*/
extern ALLEGRO_BITMAP *ImmI;		/**< Immagine dell'impatto del nemico 1*/
extern ALLEGRO_BITMAP *ImmI2;		/**< Immagine dell'impatto del nemico 2*/
extern ALLEGRO_BITMAP *ImmC;		/**< Immagine del proiettile */
extern ALLEGRO_BITMAP *ImmV;		/**< Immagine delle vite*/


extern ALLEGRO_SAMPLE *shot;					/**< Suono del lancio del proiettile*/
extern ALLEGRO_SAMPLE *music;					/**< Suono della musica di gioco*/
extern ALLEGRO_SAMPLE *music_menu;				/**< Suono della musica del menu*/
extern ALLEGRO_SAMPLE *music_lose;				/**< Suono della musica di gameover*/
extern ALLEGRO_SAMPLE *morte1;					/**< Suono di nemico ucciso*/
extern ALLEGRO_SAMPLE_INSTANCE *songInstance_g;	/**< Suono di gioco */
extern ALLEGRO_SAMPLE_INSTANCE *songInstance_m;	/**< Suono di gioco */
extern ALLEGRO_SAMPLE_INSTANCE *songInstance_l;	/**< Suono di gioco */

extern Gioco partita;			/** Oggetto partita, tipo ::Gioco*/
extern Statistiche stat;		/** Oggetto statistiche, tipo ::Statistiche*/
extern Bottoni bottone[N_BOTTONI];	/** Array di bottoni, tipo ::Bottoni*/
extern Punteggi p;					/** Punteggi del gioco di tipo ::Punteggi*/
extern bool keys[NUM_TASTI];		/**Array dei tasti*/
extern bool HSaggiornati; 			/**< Booleano che indica se i punteggi 
					 *sono già stati aggiornati
					 */


/* Fine header modulo Dichiarazioni */

