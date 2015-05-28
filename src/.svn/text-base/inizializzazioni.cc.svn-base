/**
 * @file 
 * File contenente il modulo Inizializzazioni.
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


void inizializza_partita()
{
	partita.fase=INIZIO;
	partita.punti=0;
	partita.vite=0;
	partita.livello=0;
	partita.difficolta=500;
	partita.n_nemici=10;
	partita.velocita=0;
	stat.precisione=0;
	stat.colpi=0;
	stat.vite_perse=0;
	
}

void Inizializza_g(Giocatore &tom, ALLEGRO_BITMAP *immagine) {

	tom.x = 20;
	tom.y = ALTEZZA / 2;
	tom.vel = 7;
	tom.bordox = 15;
	tom.bordoy = 20;

	tom.maxFrame = 9;
	tom.corFrame = 1;
	tom.frameCont = 0;
	tom.frameRit = 2;
	tom.frameLun = 96;
	tom.frameAlt = 96;
	tom.animationCol = 9;
	tom.animationDir = 1;

	tom.attacco=false;
	tom.colpito=false;

	tom.animationRow = 1;

	tom.immagine = immagine;
}

void Inizializza_Nemici(Nemici nemici[],ALLEGRO_BITMAP *nemici1, ALLEGRO_BITMAP *nemici2)
{
	for(int i = 0; i < NUM_NEMICI; i++)
	{	
		if(i<NUM_NEMICI/2-1)
		{
			nemici[i].vite = 0;
			nemici[i].vel = 3+partita.velocita;
			nemici[i].bordox =19;
			nemici[i].bordoy = 24;
			
			nemici[i].maxFrame = 7;
			nemici[i].corFrame = 0;
			nemici[i].frameCont = 0;
			nemici[i].frameRit = 5;
			nemici[i].frameAlt = 96;
			nemici[i].frameLun = 96;
			nemici[i].animationCol = 7;
	
			nemici[i].animationDir = 1;
	
			nemici[i].immagine = nemici1;
		}
		else {
			nemici[i].vite = 0;
			nemici[i].vel = 1.5+partita.velocita;
			nemici[i].bordox = 19;
			nemici[i].bordoy = 24;
			

			nemici[i].maxFrame = 7;
			nemici[i].corFrame = 0;
			nemici[i].frameCont = 0;
			nemici[i].frameRit = 5;

			nemici[i].frameAlt = 96;
			nemici[i].frameLun = 96;
			nemici[i].animationCol = 7;
			nemici[i].animationRow=0;
			nemici[i].animationDir = 1;
	
			nemici[i].immagine = nemici2;
			}		
	}
}


void Inizializza_colpo(Colpo colpi[],ALLEGRO_BITMAP* immagine)
{
	for(int i = 0; i < NUM_COLPI; i++)
	{
		colpi[i].vel = 10;
		colpi[i].vite = 0;
		colpi[i].immagine = immagine;
	}
}



void Inizializza_impatti(Impatti impatti[], ALLEGRO_BITMAP *image,ALLEGRO_BITMAP *image2)
{
	for(int i = 0; i < NUM_IMPATTI; i++)
	{
		impatti[i].attivo = false;

		impatti[i].maxFrame = 11;
		impatti[i].corFrame = 0;
		impatti[i].frameCont = 0;
		impatti[i].frameRit = 3;
		impatti[i].frameAlt = 128;
		impatti[i].frameLun = 128;
		impatti[i].animationCol = 11;
		impatti[i].animationDir = 1;		

		impatti[i].animationRow = 0;		
		impatti[i].Nemico1 = image;
		impatti[i].Nemico2 = image2;
	}
}



void InitBackground(Sfondo &s, float x, float y, float velx, float vely, int l, int a, int dirX, int dirY, ALLEGRO_BITMAP *image)
{
	s.x = x;
	s.y = y;
	s.velX = velx;
	s.velY = vely;
	s.lunghezza= l;
	s.altezza = a;
	s.dirX = dirX;
	s.dirY = dirY;
	s.immagine = image;
}

bool InizializzaBottoni(Bottoni bottone[])
{
	for(int i=0; i<N_BOTTONI;i++)
	{
		bottone[i].curFrame = 0;
		bottone[i].lunghezzaFrame = 192 ;
		bottone[i].altezzaFrame = 48 ;
		bottone[i].posX=0;
		bottone[i].posY=200;
		bottone[i].distanza=0;
	}
	// Inizializzazione delle bitmap dei bottoni del menu
	bottone[GIOCAb].immagine = al_load_bitmap("img/gioca_sheet.bmp");
	bottone[ESCIb].immagine = al_load_bitmap("img/esci_sheet.bmp");
	bottone[CARICAb].immagine = al_load_bitmap("img/carica_sheet.bmp");
	bottone[PUNTEGGIb].immagine =al_load_bitmap("img/punteggi_sheet.bmp");
	bottone[RIPRENDIb].immagine = al_load_bitmap("img/riprendi_sheet.bmp");
	bottone[DOCb].immagine =al_load_bitmap("img/documentazione_sheet.bmp");
	bottone[CREDITSb].immagine=al_load_bitmap("img/credits_sheet.bmp");
	bottone[CARICACPb].immagine=al_load_bitmap("img/caricacp_sheet.bmp");
	bottone[HOWTOb].immagine=al_load_bitmap("img/howto_sheet.bmp");
	bottone[INDIETROb].immagine=al_load_bitmap("img/indietro_sheet.bmp");
	
	for(int i=0;i<N_BOTTONI;i++)
	{	if(bottone[i].immagine==NULL)
			return false;
	}
	//Creazione delle maschere dello lo sfondo di ogni bottone 
	for(int i=0; i<N_BOTTONI;i++)
		al_convert_mask_to_alpha(bottone[i].immagine,al_map_rgb(122,128,124));
	return true;
}


void InizializzaPunteggi (Punteggi &p)
{

	for(int i=0; i<NUM_PUNTEGGI; i++)
		p[i]=0;

}

/** 
 * Fine del file contenente il modulo Inizializzazione
 */
