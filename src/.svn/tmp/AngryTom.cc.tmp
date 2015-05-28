/*
 * @file 
 * File contenente il main del programma.
 */

/**
 * @mainpage AngryTom
 *
 * Programma per il gioco 2D Angry Tom. Il gioco è sviluppato con la
 * libreria allegro5, è diviso in 10 livelli, e vede come giocatore 
 * principale l'arciere, arrabbiato, Tom, il quale combatte contro
 * ladri e guerrieri. 
 * Scopo del gioco è eliminare ogni nemico fino a completare i livelli e 
 * totalizzare punteggi sempre migliori.
 * 
 * Il programma è suddiviso in diversi moduli :
 * 
 * 1) inizializzazioni.cc adibito all'inizializzazione delle varie
 * strutture dichiarate in objects.h
 *
 * 2) dichiarazioni.cc adibito alla dichiarazione degli oggetti 
 * del gioco
 *
 * 3) disegno.cc adibito al disegno sullo schermo.
 * 
 * 4) aggiorna.cc adibito all'aggiornamento delle strutture del gioco.
 *
 * 5) fileIO.cc adibito al salvataggio e al caricamento della
 * partita e dei punteggi.
 *
 * 
 * Vedere la documentazione completa per maggiori dettagli
 * sulla strutture, le funzioni e l'implementazione del gioco.
 *
 * Funzione main contenuta in AngryTom.cc
 *
 * @author Emanuele Vineti & Micaela Verucchi
 */


#include <iostream>
#include <fstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
	
using namespace std;

#include "objects.h"
#include "dichiarazioni.h"
#include "disegno.h"
#include "inizializzazioni.h"
#include "fileIO.h"
#include "aggiorna.h"
#include "DBG.h"

//#define DEBUG_MODE

#ifdef DEBUG_MODE 

unsigned int MASK = 1;

#define DBG(A,B) { if( (A) & MASK ) { B;}}

#else 

#define DBG(A,B)

#endif 

#define DB1(a) DBG(1,a)
#define DB2(a) DBG(2,a)



int main(void)
{
	bool fine = false; 	// Booleano che gestisce il loop del gioco
	bool render= true; 	// Booleano che gestisce il disegno del gioco


	// Inizializzo i pulsanti a false, cioè non premuti
	for(int i=0; i<NUM_TASTI; i++)
		keys[i]=false;

	bool controllo =true;	//variabile di controllo per le inizializziazioni
				//di allegro 

	const int FPS = 60;	// Variabile che indica le Frame Per Second
	
	ALLEGRO_DISPLAY *display = NULL; // Oggetto Display
	ALLEGRO_EVENT_QUEUE *coda_eventi = NULL;//Oggetto Coda degli Eventi
	ALLEGRO_TIMER *timer = NULL;	// Oggetto Timer

	//Inizializzazione di Allegro
	if(!al_init())
	{	cerr<<"Inizializzazione fallita"<<endl;
		return -1;
	} 

	display = al_create_display(LARGHEZZA,ALTEZZA);
	coda_eventi = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	// Test sull'oggetto display, coda_eventi e timer appena creati
	if(!display || !coda_eventi || !timer)
	{
		cerr<<"Inizializzazione fallita"<<endl;
		return -1;
	}

	//Creazione degli oggetti
	Giocatore tom;
	Colpo colpi[NUM_COLPI];
	Nemici nemici[NUM_NEMICI];
	Impatti impatti[NUM_IMPATTI];
	

	Sfondo sfondo_g;
	Sfondo sfondo_g2;
	Sfondo sfondo_g3;
	Sfondo inizioBG;	
	Sfondo punteggiBG;

	//Installazione delle componenti di allegro con controllo
	al_init_font_addon();
	controllo=
		al_init_primitives_addon()&&
		al_install_keyboard()&&
		al_install_mouse()&&
		al_init_ttf_addon()&&
		al_init_image_addon()&&
		al_install_audio()&&
		al_init_acodec_addon();

	
	if(!controllo)
	{	cerr<<"Errore Inizializzazioni allegro"<<endl;
		return -1;
	}
	// Inizializazione delle immagini utili al gioco ed
	// eventuale creazione delle loro maschere.

	ImmC = al_load_bitmap("img/arrow.bmp");
	al_convert_mask_to_alpha(ImmC, al_map_rgb(128, 128, 128));

	ImmG  = al_load_bitmap("img/bowstan.bmp");
	al_convert_mask_to_alpha(ImmG, al_map_rgb(106,76,48));

	ImmN1 = al_load_bitmap("img/enemy1.bmp");
	al_convert_mask_to_alpha(ImmN1, al_map_rgb(106,76,48));
	
	ImmN2 = al_load_bitmap("img/enemy2.bmp");
	al_convert_mask_to_alpha(ImmN2, al_map_rgb(97,68,43));
	
	ImmI = al_load_bitmap("img/enemy_dead.bmp");
	al_convert_mask_to_alpha(ImmI, al_map_rgb(106,76,48));

	ImmI2 = al_load_bitmap("img/enemy2_dead.bmp");
	al_convert_mask_to_alpha(ImmI2, al_map_rgb(97,68,43));

	ImmV = al_load_bitmap("img/Hearts.png");



	ImmS = al_load_bitmap("img/sfondo.png");
	ImmS2 = al_load_bitmap("img/nuvole1.png");
	ImmS3 = al_load_bitmap("img/nuvole2.png");

	PannelloRisultati = al_load_bitmap("img/punteggi.bmp");
	al_convert_mask_to_alpha(PannelloRisultati,al_map_rgb(122,128,124));

	PannelloPunteggi =  al_load_bitmap("img/pannellohighscores.bmp");
	al_convert_mask_to_alpha(PannelloPunteggi,al_map_rgb(122,128,124));

	punteggi = al_load_bitmap("img/Aged_Antique_Paper_8_by_Craftmans.jpg");
	inizio = al_load_bitmap("img/about-ourteam.jpg");

	// Inizializzazione dei font 
	font18 = al_load_font("font/Amiga Forever.ttf", 18, 0);
	font15 = al_load_font("font/A.C.M.E._Explosive.ttf", 15, 0);
	font100 = al_load_font("font/a_Papa.ttf", 100, 0);
	
	DB1(int i=0;
	if(ImmG==NULL)
	cout<<i++<<endl;
	if(ImmC==NULL)
	cout<<i++<<endl;	
	if(ImmN1==NULL)
	cout<<i++<<endl;
	if(ImmN2==NULL)
	cout<<i++<<endl;
	if(ImmI==NULL)
	cout<<i++<<endl;
	if(ImmI2==NULL)
	cout<<i++<<endl;
	if(ImmV==NULL)
	cout<<i++<<endl;
	if(ImmS==NULL)
	cout<<i++<<endl;
	if(ImmS2==NULL)
	cout<<i++<<endl;
	if(ImmS3==NULL)
	cout<<i++<<endl;
	if(PannelloRisultati==NULL)
	cout<<i++<<endl;
	if(PannelloPunteggi==NULL)
	cout<<i++<<endl;
	if(punteggi==NULL)
	cout<<i++<<endl;
	if(inizio==NULL)
	cout<<i++<<endl;
	if(font15==NULL)
	cout<<i++<<endl;
	if(font18==NULL)
	cout<<i++<<endl;
	if(font100==NULL)
	cout<<i++<<endl;)
	// test sul caricamento  immagini 
	if(ImmC==NULL||ImmG==NULL||ImmN1==NULL||ImmN2==NULL||ImmI==NULL||
	   ImmI2==NULL||ImmV==NULL||ImmS==NULL||ImmS2==NULL||ImmS3==NULL||
	   PannelloRisultati==NULL||PannelloPunteggi==NULL||punteggi==NULL||
		inizio==NULL||font18==NULL||font15==NULL||font100==NULL)
		{		
		cerr<<"Errato caricamento immagini"<<endl;
		return -1;
		}
	// Inizializzazione degli sfondi del menu 
	InitBackground(inizioBG,0,0,1,0,1000,700,-1,1,inizio);
	InitBackground(punteggiBG,0,0,1,0,1000,700,-1,1,punteggi);
	InitBackground(sfondo_g2, 0, 0, 2, 0, 1250, 500, -1, 1, ImmS3);
	InitBackground(sfondo_g, 0, 0, 1, 0, 1250, 500, -1, 1, ImmS);
	InitBackground(sfondo_g3, 0, 0, 4, 0, 1250, 500, -1, 1, ImmS2);


	// Creazione dei canali per i suoni
	al_reserve_samples(10);

	// Inizializzazione dei suoni del gioco
	shot = al_load_sample("sound/ARROW1.WAV");
	morte1 = al_load_sample("sound/death1.wav");
	music = al_load_sample("sound/Defiance.ogg");

	music_menu = al_load_sample("sound/Rec Room.wav");
	music_lose = al_load_sample("sound/File Selection.wav");

	if(shot==NULL||morte1==NULL||music==NULL||music_menu==NULL||
	   music_lose==NULL)
	{	cerr<<"errato caricamento suoni"<<endl;
		return -1;
	}
	songInstance_g = al_create_sample_instance(music);
	al_set_sample_instance_playmode(songInstance_g, ALLEGRO_PLAYMODE_LOOP);

	songInstance_m = al_create_sample_instance(music_menu);
	al_set_sample_instance_playmode(songInstance_m, ALLEGRO_PLAYMODE_LOOP);

	songInstance_l = al_create_sample_instance(music_lose);
	al_set_sample_instance_playmode(songInstance_l, ALLEGRO_PLAYMODE_LOOP);

	al_attach_sample_instance_to_mixer(songInstance_g, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(songInstance_m, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(songInstance_l, al_get_default_mixer());
	al_set_sample_instance_gain(songInstance_m, 3);
	al_set_sample_instance_gain(songInstance_l, 3);
	al_set_sample_instance_gain(songInstance_g, 1);	

	// Inizializzazione della fase della partita
	partita.fase=INIZIO;
	al_play_sample_instance(songInstance_m);


	//Inizializzazione delle strutture principali del programma
	inizializza_partita();
	Inizializza_g(tom,ImmG);
	Inizializza_Nemici(nemici, ImmN1, ImmN2);
	Inizializza_colpo(colpi,ImmC);
	Inizializza_impatti(impatti,ImmI,ImmI2);
	if(!InizializzaBottoni (bottone)){
		cerr<<"Errore caricamento immagini bottoni"<<endl;
		return -1;
	}

	// Inizializzazione della funzione rand()
	srand(time(NULL));

	// Registrazione degli eventi alla coda_eventi
	al_register_event_source(coda_eventi, al_get_keyboard_event_source());
	al_register_event_source(coda_eventi, al_get_timer_event_source(timer));
	al_register_event_source(coda_eventi, al_get_display_event_source(display));
	al_register_event_source(coda_eventi, al_get_mouse_event_source());

	// Inizio del timer
	al_start_timer(timer);

	//Inizio della parita
	Inizia_partita();
	
	DB2(stampa_dati_partita();
		stampa_dati_in_gioco(colpi,nemici, tom,impatti);
		controllo_inizio(fine,render,HSaggiornati));
	// Inizio di loop del gioco 
	while(!fine)
	{
		ALLEGRO_EVENT ev;	//Evento di allegro
		al_wait_for_event(coda_eventi, &ev);


		// Evento : Timer 
		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;
			DB1(if(keys[TASTO_N])
					{
						stampa_dati_in_gioco(colpi,nemici, tom,impatti);
					});
			DB1(if(keys[TASTO_M])
					{	controllo_inizio(fine,render,HSaggiornati);
						stampa_dati_partita();
					});
			switch(partita.fase)
			{

			case INIZIO:
				HSaggiornati = false;
				CaricaPunteggi(p);
				UpdateBackground(sfondo_g);
				UpdateBackground(sfondo_g2);
				UpdateBackground(sfondo_g3);
				break;
			case IN_GIOCO:
			{	
				Sposta_giocatore(tom);
				Aggiorna_anim_giocatore(tom);
				
				if(keys[TASTO_P])
				{	DB2(stampa_dati_partita();
						stampa_dati_in_gioco(colpi,nemici, tom,impatti));
					Cambia_fase(PAUSA,nemici,colpi,tom,impatti);
				}
				if((partita.punti)%(25*partita.livello+partita.livello)==0&&
					partita.livello<10&&partita.punti!=0)
				{	DB2(stampa_dati_partita();
						stampa_dati_in_gioco(colpi,nemici, tom,impatti));
					Cambia_fase(LIVELLO,nemici,colpi,tom,impatti);
				}
				if(partita.vite<=0)
				{	
					DB2(controllo_inizio(fine,render,HSaggiornati);
						stampa_dati_partita();
						stampa_dati_in_gioco(colpi,nemici, tom,impatti));
					Cambia_fase(GAMEOVER,nemici,colpi,tom,impatti);
				}
				if(partita.livello==10&&partita.punti>300)
					partita.livello+=1;
				UpdateBackground(sfondo_g);
				UpdateBackground(sfondo_g2);
				UpdateBackground(sfondo_g3);
				Aggiorna_impatti(impatti);
				Aggiorna_colpo(colpi);
				Spawn_Nemici(nemici);
				Aggiorna_Nemici(nemici);
				Impatto_Nemici(nemici,tom);
				Impatto_colpo(colpi, nemici, tom,impatti,morte1);
			
			}

				break;		
			case PAUSA:
				break;
			case CREDITS:
				break;
			case HOWTO:
				break;
			case LIVELLO:	
				
				if(keys[INVIO])
				{
					Cambia_fase(IN_GIOCO,nemici,colpi,tom,impatti);
				}
					
				break;		
			case PUNTEGGI:

					if(keys[ESC])
						fine = true;
					break;
			case GAMEOVER:
				UpdateBackground(sfondo_g);
				UpdateBackground(sfondo_g2);
				UpdateBackground(sfondo_g3);
				break;
			}
		
		}

		// Evento : chiusura del display 
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			fine = true;
		}

		// Evento : tasto premuto 
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				keys[ESC] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[SU] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[GIU] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[SINISTRA] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DESTRA] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPAZIO] = true;
				if(partita.fase==IN_GIOCO)
					Spara_colpo(colpi,tom,2,shot);
				break;
			case ALLEGRO_KEY_ENTER:
				keys[INVIO] = true;
				break;
			case ALLEGRO_KEY_P:
				keys[TASTO_P] = true;
				break;
			case ALLEGRO_KEY_M:
				keys[TASTO_M] = true;
				break;
			case ALLEGRO_KEY_N:
				keys[TASTO_N] = true;
				break;
			}
		}

		// Evento : Tasto rilasciato 
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				keys[ESC] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[SU] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[GIU] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[SINISTRA] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DESTRA] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPAZIO] = false;
				break;
			case ALLEGRO_KEY_ENTER:
				keys[INVIO] = false;
				break;
			case ALLEGRO_KEY_P:
				keys[TASTO_P] = false;
				break;
			case ALLEGRO_KEY_M:
				keys[TASTO_M] = false;
				break;
			case ALLEGRO_KEY_N:
				keys[TASTO_N] = false;
				break;
			}
		}
		// Evento : movimento del mouse
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
              	ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
		{
			if(CursoresuBottone(ev, bottone[GIOCAb].posX,
				bottone[GIOCAb].posY,
				bottone[GIOCAb].distanza, 
				bottone[GIOCAb].altezzaFrame, 
				bottone[GIOCAb].lunghezzaFrame))
					bottone[GIOCAb].curFrame = 1;
			else
				bottone[GIOCAb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[CARICAb].posX,
				bottone[CARICAb].posY,
				bottone[CARICAb].distanza, 
				bottone[CARICAb].altezzaFrame,
				bottone[CARICAb].lunghezzaFrame))
					bottone[CARICAb].curFrame = 1;
			else
				bottone[CARICAb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[PUNTEGGIb].posX,
				bottone[PUNTEGGIb].posY,
				bottone[PUNTEGGIb].distanza, 
				bottone[PUNTEGGIb].altezzaFrame,
				bottone[PUNTEGGIb].lunghezzaFrame))
					bottone[PUNTEGGIb].curFrame = 1;
			else
				bottone[PUNTEGGIb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[HOWTOb].posX,
				bottone[HOWTOb].posY, 
				bottone[HOWTOb].distanza, 
				bottone[HOWTOb].altezzaFrame, 
				bottone[HOWTOb].lunghezzaFrame))
					bottone[HOWTOb].curFrame = 1;
			else
				bottone[HOWTOb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[DOCb].posX,
				bottone[DOCb].posY, 
				bottone[DOCb].distanza, 
				bottone[DOCb].altezzaFrame, 
				bottone[DOCb].lunghezzaFrame))
						bottone[DOCb].curFrame = 1;
			else
				bottone[DOCb].curFrame = 0;
	
			if(CursoresuBottone(ev, bottone[CREDITSb].posX,
				bottone[CREDITSb].posY, 
				bottone[CREDITSb].distanza, 
				bottone[CREDITSb].altezzaFrame, 
				bottone[CREDITSb].lunghezzaFrame))
					bottone[CREDITSb].curFrame = 1;
			else
				bottone[CREDITSb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[RIPRENDIb].posX,
				bottone[RIPRENDIb].posY, 
				bottone[RIPRENDIb].distanza, 
				bottone[RIPRENDIb].altezzaFrame, 
				bottone[RIPRENDIb].lunghezzaFrame))
					bottone[RIPRENDIb].curFrame = 1;
			else
				bottone[RIPRENDIb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[CARICACPb].posX,
				bottone[CARICACPb].posY, 
				bottone[CARICACPb].distanza, 
				bottone[CARICACPb].altezzaFrame, 
				bottone[CARICACPb].lunghezzaFrame))
					bottone[CARICACPb].curFrame = 1;
			else
				bottone[CARICACPb].curFrame = 0;

			if(CursoresuBottone(ev, bottone[ESCIb].posX,
				bottone[ESCIb].posY, 
				bottone[ESCIb].distanza, 
				bottone[ESCIb].altezzaFrame, 
				bottone[ESCIb].lunghezzaFrame))
					bottone[ESCIb].curFrame = 1;
			else
				bottone[ESCIb].curFrame = 0;		
			if(CursoresuBottone(ev, bottone[INDIETROb].posX,
				bottone[INDIETROb].posY, 
				bottone[INDIETROb].distanza, 
				bottone[INDIETROb].altezzaFrame, 
				bottone[INDIETROb].lunghezzaFrame))
					bottone[INDIETROb].curFrame = 1;
			else
				bottone[INDIETROb].curFrame = 0;								
		} 

		// Evento : click del mouse premuto
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			
			if(CursoresuBottone(ev, bottone[GIOCAb].posX,
				bottone[GIOCAb].posY,
				bottone[GIOCAb].distanza, 
				bottone[GIOCAb].altezzaFrame, 
				bottone[GIOCAb].lunghezzaFrame) &&
				(partita.fase == INIZIO || partita.fase == GAMEOVER) )
					bottone[GIOCAb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[CARICAb].posX,
				bottone[CARICAb].posY, 
				bottone[CARICAb].distanza, 
				bottone[CARICAb].altezzaFrame, 
				bottone[CARICAb].lunghezzaFrame) && 
				partita.fase ==INIZIO)
					bottone[CARICAb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[PUNTEGGIb].posX,
				bottone[PUNTEGGIb].posY, 
				bottone[PUNTEGGIb].distanza, 
				bottone[PUNTEGGIb].altezzaFrame, 
				bottone[PUNTEGGIb].lunghezzaFrame) && 
				partita.fase == INIZIO)
					bottone[PUNTEGGIb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[HOWTOb].posX,
				bottone[HOWTOb].posY, 
				bottone[HOWTOb].distanza, 
				bottone[HOWTOb].altezzaFrame, 
				bottone[HOWTOb].lunghezzaFrame) && 
				partita.fase==INIZIO)
					bottone[HOWTOb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[DOCb].posX,
				bottone[DOCb].posY, 
				bottone[DOCb].distanza, 
				bottone[DOCb].altezzaFrame, 
				bottone[DOCb].lunghezzaFrame) && 
				partita.fase==INIZIO)
				bottone[DOCb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[RIPRENDIb].posX,
				bottone[RIPRENDIb].posY, 
				bottone[RIPRENDIb].distanza, 
				bottone[RIPRENDIb].altezzaFrame, 
				bottone[RIPRENDIb].lunghezzaFrame) && 
				partita.fase==PAUSA)
					bottone[RIPRENDIb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[CARICACPb].posX,
				bottone[CARICACPb].posY, 
				bottone[CARICACPb].distanza, 
				bottone[CARICACPb].altezzaFrame, 
				bottone[CARICACPb].lunghezzaFrame) && 
				partita.fase==PAUSA)
					bottone[CARICACPb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[CREDITSb].posX,
				bottone[CREDITSb].posY, 
				bottone[CREDITSb].distanza, 
				bottone[CREDITSb].altezzaFrame, 
				bottone[CREDITSb].lunghezzaFrame) && 
				partita.fase==INIZIO)
					bottone[CREDITSb].curFrame=2;
	
			if(CursoresuBottone(ev, bottone[ESCIb].posX,
				bottone[ESCIb].posY, 
				bottone[ESCIb].distanza, 
				bottone[ESCIb].altezzaFrame, 
				bottone[ESCIb].lunghezzaFrame))
					bottone[ESCIb].curFrame = 2;

			if(CursoresuBottone(ev, bottone[INDIETROb].posX,
				bottone[INDIETROb].posY, 
				bottone[INDIETROb].distanza, 
				bottone[INDIETROb].altezzaFrame, 
				bottone[INDIETROb].lunghezzaFrame) )
					bottone[INDIETROb].curFrame = 2 ;

		}
		// Evento : click del mouse rilasciato
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			
			if(CursoresuBottone(ev, bottone[GIOCAb].posX,
				bottone[GIOCAb].posY, 
				bottone[GIOCAb].distanza, 
				bottone[GIOCAb].altezzaFrame, 
				bottone[GIOCAb].lunghezzaFrame) &&
				(partita.fase == INIZIO || partita.fase == GAMEOVER) )
				{if(partita.fase==INIZIO)
					Cambia_fase(IN_GIOCO,nemici,colpi,tom,impatti);
				else	Cambia_fase(INIZIO,nemici,colpi,tom,impatti);
				}

			if(CursoresuBottone(ev, bottone[CARICAb].posX,
				bottone[CARICAb].posY, 
				bottone[CARICAb].distanza, 
				bottone[CARICAb].altezzaFrame, 
				bottone[CARICAb].lunghezzaFrame) && 
				partita.fase ==INIZIO)
			{		
				al_clear_to_color(al_map_rgb(0,0,0));
				if(carica( partita, stat))
				{	Cambia_fase(IN_GIOCO,nemici,colpi,tom,impatti);
					al_draw_textf(font18, 
					al_map_rgb(28,57,187), LARGHEZZA/2,
				 	ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , 
					"Caricamento riuscito");
				}
				else
					al_draw_textf(font18, 
					al_map_rgb(28,57,187), LARGHEZZA/2, 
					ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , 
					"Caricamento non riuscito");
				al_flip_display();
				al_rest(1);
			}
			if(CursoresuBottone(ev, bottone[PUNTEGGIb].posX,
				bottone[PUNTEGGIb].posY, 
				bottone[PUNTEGGIb].distanza, 
				bottone[PUNTEGGIb].altezzaFrame, 
				bottone[PUNTEGGIb].lunghezzaFrame) && 
				partita.fase == INIZIO)
					Cambia_fase(PUNTEGGI,nemici,colpi,tom,impatti);

			if(CursoresuBottone(ev, bottone[HOWTOb].posX,
				bottone[HOWTOb].posY, 
				bottone[HOWTOb].distanza, 
				bottone[HOWTOb].altezzaFrame, 
				bottone[HOWTOb].lunghezzaFrame) && 
				partita.fase==INIZIO)
					Cambia_fase(HOWTO,nemici,colpi,tom,impatti);

			if(CursoresuBottone(ev, bottone[DOCb].posX,
				bottone[DOCb].posY, 
				bottone[DOCb].distanza, 
				bottone[DOCb].altezzaFrame, 
				bottone[DOCb].lunghezzaFrame) && 
				partita.fase==INIZIO)
					system("sensible-browser ./html/index.html");

			if(CursoresuBottone(ev, bottone[RIPRENDIb].posX,
				bottone[RIPRENDIb].posY, 
				bottone[RIPRENDIb].distanza, 
				bottone[RIPRENDIb].altezzaFrame, 
				bottone[RIPRENDIb].lunghezzaFrame) && 
				partita.fase==PAUSA)
					Cambia_fase(IN_GIOCO,nemici,colpi,tom,impatti);

			if(CursoresuBottone(ev, bottone[CARICACPb].posX,
				bottone[CARICACPb].posY, 
				bottone[CARICACPb].distanza, 
				bottone[CARICACPb].altezzaFrame, 
				bottone[CARICACPb].lunghezzaFrame) && 
				partita.fase==PAUSA)
			{		
				al_clear_to_color(al_map_rgb(0,0,0));
				if(carica(partita, stat))
				{	Cambia_fase(IN_GIOCO,nemici,colpi,tom,impatti);
					al_draw_textf(font18, 
					al_map_rgb(28,57,187), LARGHEZZA/2,
				 	ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , 
					"Caricamento riuscito");
				}
				else
					al_draw_textf(font18, 
					al_map_rgb(28,57,187), LARGHEZZA/2,
					ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , 
					"Caricamento non riuscito");
				al_flip_display();
				al_rest(1);
			}


			if(CursoresuBottone(ev, bottone[CREDITSb].posX,
				bottone[CREDITSb].posY, 
				bottone[CREDITSb].distanza, 
				bottone[CREDITSb].altezzaFrame, 
				bottone[CREDITSb].lunghezzaFrame) && 
				partita.fase==INIZIO)
					Cambia_fase(CREDITS,nemici,colpi,tom,impatti);

			if(CursoresuBottone(ev, bottone[ESCIb].posX,
				bottone[ESCIb].posY, 
				bottone[ESCIb].distanza, 
				bottone[ESCIb].altezzaFrame, 
				bottone[ESCIb].lunghezzaFrame))
			{
			if(partita.fase == INIZIO || partita.fase == PAUSA || partita.fase == PUNTEGGI)
				fine = true;
			else if (partita.fase == GAMEOVER)
				Cambia_fase(PUNTEGGI,nemici,colpi,tom,impatti);
			}
			if(CursoresuBottone(ev, bottone[INDIETROb].posX,
				bottone[INDIETROb].posY, 
				bottone[INDIETROb].distanza, 
				bottone[INDIETROb].altezzaFrame, 
				bottone[INDIETROb].lunghezzaFrame) && 
				(partita.fase==CREDITS || partita.fase == HOWTO || partita.fase == PUNTEGGI))
				Cambia_fase(INIZIO,nemici,colpi,tom,impatti);
		}
		// Rendering : Disegno dello schermo 
		if(render && al_is_event_queue_empty(coda_eventi))
		{	
			render = false; 
			switch(partita.fase)
			{
			case INIZIO:

					DisegnaInizio(sfondo_g,sfondo_g2,sfondo_g3);
					break;

			case IN_GIOCO:
					
					DisegnaInGioco(sfondo_g,tom,nemici,
						colpi,impatti,sfondo_g3,sfondo_g2,ImmV,font18);
					break;		
				
			case PAUSA:

					DisegnaPausa(inizioBG);	
					break;

			case LIVELLO:
		
					DisegnaCambioLivello(inizioBG);					
					break;	

			case CREDITS:

					DisegnaCredits(inizioBG);
					break;

			case HOWTO:

					DisegnaHowTo(inizioBG);
					break;
		
			case PUNTEGGI:

					DisegnaPunteggi(punteggiBG,p);	
					break;

			case GAMEOVER:

					DisegnaGameOver(sfondo_g,sfondo_g2,sfondo_g3);
					break;
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}	
	}//Fine Loop di gioco

	// Eliminazione degli oggetti creati

	al_destroy_bitmap(inizio);	
	al_destroy_bitmap(punteggi);	
	al_destroy_bitmap(PannelloRisultati);	
	al_destroy_bitmap(PannelloPunteggi);	
	al_destroy_font(font18);
	al_destroy_font(font15);
	al_destroy_font(font100);
	al_destroy_bitmap(ImmV);
	al_destroy_bitmap(ImmC);
	al_destroy_bitmap(ImmN1);
	al_destroy_bitmap(ImmN2);
	al_destroy_bitmap(ImmG);
	al_destroy_bitmap(ImmI);
	al_destroy_bitmap(ImmI2);
	al_destroy_bitmap(ImmS);
	al_destroy_bitmap(ImmS2);
	al_destroy_sample(shot);
	al_destroy_sample(music);
	al_destroy_sample(morte1);
	al_destroy_event_queue(coda_eventi);
	al_destroy_timer(timer);
	al_destroy_display(display);						

	return 0;
}

