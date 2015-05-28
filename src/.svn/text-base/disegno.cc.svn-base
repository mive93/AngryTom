/**
 * @file 
 * File contenente il modulo Disegno.
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

void Disegna_cuori( ALLEGRO_BITMAP *image, Giocatore &tom)
{
    int frameHeight = 20;
    int frameWidth = 20;

	for(int i=0; i<partita.vite; i++)
	al_draw_bitmap_region(image, 0,0, frameWidth, frameHeight,800+(20*i),0,0);
}

void Disegna_giocatore(Giocatore &tom)
{	
	int fx =(tom.corFrame % tom.animationCol) * tom.frameLun;
	int fy = tom.animationRow * tom.frameAlt;

	al_draw_bitmap_region(tom.immagine, fx, fy, tom.frameLun,
		tom.frameAlt, tom.x - tom.frameLun / 2, tom.y - tom.frameAlt / 2, 0);
	tom.frameCont++;
	/*al_draw_filled_rectangle(tom.x - tom.bordox, tom.y - tom.bordoy, tom.x + tom.bordox,
		tom.y + tom.bordoy, al_map_rgba(255, 0, 255, 100));*/
}

void Disegna_Nemici(Nemici nemici[])
{
	for(int i = (partita.livello-1); i < (NUM_NEMICI/2 -2 +partita.livello); i++)
	{
		if(nemici[i].vite)
		{
			int fx = (nemici[i].corFrame % nemici[i].animationCol) * nemici[i].frameLun;
			int fy = nemici[i].animationRow*nemici[i].frameAlt;

			al_draw_bitmap_region(nemici[i].immagine, fx, fy, nemici[i].frameAlt,
				nemici[i].frameLun, nemici[i].x - nemici[i].frameAlt / 2, nemici[i].y - nemici[i].frameLun / 2, 0);
			nemici[i].frameCont++;
			/*al_draw_filled_rectangle(nemici[i].x - nemici[i].bordox, nemici[i].y - nemici[i].bordoy, nemici[i].x + nemici[i].bordox,
				nemici[i].y + nemici[i].bordoy, al_map_rgba(255, 0, 255, 100));*/
		}
	}
}

void Disegna_colpo(Colpo colpi[])
{	
	int fx;
	int fy=0;
	for( int i = 0; i < NUM_COLPI; i++)
	{
		if(colpi[i].vite)
		{	//al_draw_filled_circle(colpi[i].x, colpi[i].y, 2, al_map_rgb(255, 255, 255));
	
			fx = colpi[i].animationRow * colpi[i].frameAlt;
			al_draw_bitmap_region(colpi[i].immagine, fx, fy, colpi[i].frameAlt,
					colpi[i].frameLun, colpi[i].x - colpi[i].frameAlt / 2,
					colpi[i].y - colpi[i].frameLun / 2, 0);
		}
	}
}


void Disegna_impatti(Impatti impatti[])
{	
	for(int i = 0; i < NUM_IMPATTI; i++)
	{
		if(impatti[i].attivo)
		{
			int fx = (impatti[i].corFrame % impatti[i].animationCol) * impatti[i].frameLun;		
			int fy = 0;
			if(impatti[i].animationRow==1)
			al_draw_bitmap_region(impatti[i].Nemico1, fx, fy, impatti[i].frameAlt,
				impatti[i].frameLun, impatti[i].x - impatti[i].frameAlt / 2, impatti[i].y - impatti[i].frameLun / 2, 0);
			else	al_draw_bitmap_region(impatti[i].Nemico2, fx, fy, impatti[i].frameAlt,
		impatti[i].frameLun, impatti[i].x - impatti[i].frameAlt / 2, impatti[i].y - impatti[i].frameLun / 2, 0);
		}
	}
}

void DrawBackground(Sfondo &s)
{
	al_draw_bitmap(s.immagine, s.x, s.y, 0);

	if(s.x + s.lunghezza< LARGHEZZA)
		al_draw_bitmap(s.immagine, s.x + s.lunghezza, s.y, 0);
}



void DisegnaInizio(Sfondo &s,Sfondo &s2,Sfondo &s3)
{	

	bottone[GIOCAb].posX= LARGHEZZA/3-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[GIOCAb].distanza= 0;
	bottone[CARICAb].posX= LARGHEZZA/3-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[CARICAb].distanza= 50;
	bottone[PUNTEGGIb].posX= LARGHEZZA/3-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[PUNTEGGIb].distanza= 100;
	bottone[HOWTOb].posX= LARGHEZZA/3-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[HOWTOb].distanza= 150;
	bottone[DOCb].posX= 2*LARGHEZZA/3 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[DOCb].distanza= 0;
	bottone[CREDITSb].posX= 2*LARGHEZZA/3 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[CREDITSb].distanza= 50;
	bottone[ESCIb].posX= 2*LARGHEZZA/3 -bottone[GIOCAb].lunghezzaFrame/2;
	bottone[ESCIb].distanza= 100;

	DrawBackground(s);
	DrawBackground(s2);
	DrawBackground(s3);
	
	al_draw_text(font100, al_map_rgb(0, 255, 0), LARGHEZZA/2, 50,
		ALLEGRO_ALIGN_CENTRE, "ANGRY TOM");
				  
	al_draw_bitmap_region(bottone[GIOCAb].immagine,
		bottone[GIOCAb].curFrame*bottone[GIOCAb].lunghezzaFrame,0, 
		bottone[GIOCAb].lunghezzaFrame, 
		bottone[GIOCAb].altezzaFrame , 
		bottone[GIOCAb].posX,
		bottone[GIOCAb].posY+bottone[GIOCAb].distanza,0);
	al_draw_bitmap_region(bottone[CARICAb].immagine,
		bottone[CARICAb].curFrame*bottone[CARICAb].lunghezzaFrame,0, 
		bottone[CARICAb].lunghezzaFrame, 
		bottone[CARICAb].altezzaFrame , 
		bottone[CARICAb].posX,
		bottone[CARICAb].posY+bottone[CARICAb].distanza,0);
	al_draw_bitmap_region(bottone[PUNTEGGIb].immagine,
		bottone[PUNTEGGIb].curFrame*bottone[PUNTEGGIb].lunghezzaFrame,0, 
		bottone[PUNTEGGIb].lunghezzaFrame, 
		bottone[PUNTEGGIb].altezzaFrame,  
		bottone[PUNTEGGIb].posX,
		bottone[PUNTEGGIb].posY+bottone[PUNTEGGIb].distanza,0);
	al_draw_bitmap_region(bottone[HOWTOb].immagine,
		bottone[HOWTOb].curFrame*bottone[HOWTOb].lunghezzaFrame,0, 
		bottone[HOWTOb].lunghezzaFrame, 
		bottone[HOWTOb].altezzaFrame,  
		bottone[HOWTOb].posX,
		bottone[HOWTOb].posY+bottone[HOWTOb].distanza,0);
	al_draw_bitmap_region(bottone[DOCb].immagine,
		bottone[DOCb].curFrame*bottone[DOCb].lunghezzaFrame,0,
		bottone[DOCb].lunghezzaFrame, 
		bottone[DOCb].altezzaFrame,
		bottone[DOCb].posX,
		bottone[DOCb].posY+bottone[DOCb].distanza ,0);
	al_draw_bitmap_region(bottone[CREDITSb].immagine,
		bottone[CREDITSb].curFrame*bottone[CREDITSb].lunghezzaFrame,0,
		bottone[CREDITSb].lunghezzaFrame, 
		bottone[CREDITSb].altezzaFrame,
		bottone[CREDITSb].posX,
		bottone[CREDITSb].posY+bottone[CREDITSb].distanza,0);
	al_draw_bitmap_region(bottone[ESCIb].immagine,
		bottone[ESCIb].curFrame*bottone[ESCIb].lunghezzaFrame,0, 
		bottone[ESCIb].lunghezzaFrame, 
		bottone[ESCIb].altezzaFrame, 
		bottone[ESCIb].posX,
		bottone[ESCIb].posY+bottone[ESCIb].distanza,0);
}

void DisegnaCredits(Sfondo &s)
{

	bottone[INDIETROb].posX= 3*LARGHEZZA/4 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[INDIETROb].distanza= 150;
	DrawBackground(s);

	al_draw_text(font18, al_map_rgb(255, 255, 255),50, 100, 0, 
		"All credits to Emanuele Vineti & Micaela Verucchi");

	al_draw_bitmap_region(bottone[INDIETROb].immagine,
		bottone[INDIETROb].curFrame*bottone[INDIETROb].lunghezzaFrame,0, 
		bottone[INDIETROb].lunghezzaFrame, 
		bottone[INDIETROb].altezzaFrame,
		bottone[INDIETROb].posX,
		bottone[INDIETROb].posY+bottone[INDIETROb].distanza,0);
}

void DisegnaInGioco(Sfondo &s, Giocatore &tom, Nemici nemici[], Colpo colpi[], Impatti impatti[], Sfondo & s2,Sfondo & s3, ALLEGRO_BITMAP * immagine_cuori, ALLEGRO_FONT* font18)
{


	DrawBackground(s);		
					
	Disegna_giocatore(tom);
	Disegna_Nemici(nemici);
	Disegna_colpo(colpi);
	Disegna_impatti(impatti);
	DrawBackground(s2);
	DrawBackground(s3);
	Disegna_cuori(immagine_cuori,tom);

	al_draw_textf(font18, al_map_rgb(28,57,187), 5, 5, 0,
					"Punteggio: %i                  Livello %i",
					 partita.punti,partita.livello);
}

void DisegnaPausa(Sfondo &s)
{

	bottone[RIPRENDIb].posX = LARGHEZZA/2-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[RIPRENDIb].distanza= 50;
	bottone[CARICACPb].posX= LARGHEZZA/2-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[CARICACPb].distanza= 100;
	bottone[ESCIb].posX= LARGHEZZA/2-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[ESCIb].distanza= 150;

	DrawBackground(s);

	al_draw_text(font100, al_map_rgb(0, 255, 0), LARGHEZZA/2, 50, 
		ALLEGRO_ALIGN_CENTRE, "PAUSA");

	al_draw_bitmap_region(bottone[RIPRENDIb].immagine,
		bottone[RIPRENDIb].curFrame*bottone[RIPRENDIb].lunghezzaFrame,0, 
		bottone[RIPRENDIb].lunghezzaFrame, 
		bottone[RIPRENDIb].altezzaFrame,
		bottone[RIPRENDIb].posX,
		bottone[RIPRENDIb].posY+bottone[RIPRENDIb].distanza,0);
	al_draw_bitmap_region(bottone[CARICACPb].immagine,
		bottone[CARICACPb].curFrame*bottone[CARICACPb].lunghezzaFrame,0, 
		bottone[CARICACPb].lunghezzaFrame, 
		bottone[CARICACPb].altezzaFrame,
		bottone[CARICACPb].posX,
		bottone[CARICACPb].posY+bottone[CARICACPb].distanza,0);
	al_draw_bitmap_region(bottone[ESCIb].immagine,
		bottone[ESCIb].curFrame*bottone[ESCIb].lunghezzaFrame,0, 
		bottone[ESCIb].lunghezzaFrame, 
		bottone[ESCIb].altezzaFrame,
		bottone[ESCIb].posX,
		bottone[ESCIb].posY+bottone[ESCIb].distanza,0);

}

void DisegnaHowTo(Sfondo &s)
{

	bottone[INDIETROb].posX= 3*LARGHEZZA/4 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[INDIETROb].distanza= 150;


	DrawBackground(s);

	al_draw_text(font18, al_map_rgb(255, 255, 255),100, 200, 0, 
		"How To :");
	al_draw_text(font18, al_map_rgb(255, 255, 255),100, 300, 0, 
		"Muoviti con le frecce");
	al_draw_text(font18, al_map_rgb(255, 255, 255),100, 350, 0, 
		"Spara con SPACE");
	al_draw_text(font18, al_map_rgb(255, 255, 255),100, 400, 0, 
		"Metti in pausa con P");

	al_draw_bitmap_region(bottone[INDIETROb].immagine,
		bottone[INDIETROb].curFrame*bottone[INDIETROb].lunghezzaFrame,0, 
		bottone[INDIETROb].lunghezzaFrame, 
		bottone[INDIETROb].altezzaFrame,
		bottone[INDIETROb].posX,
		bottone[INDIETROb].posY+bottone[INDIETROb].distanza,0);



}

void DisegnaPunteggi(Sfondo &s, Punteggi p)
{

	bottone[INDIETROb].posX= LARGHEZZA/2 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[INDIETROb].distanza= 180;
	bottone[ESCIb].posX= LARGHEZZA/2 - bottone[GIOCAb].lunghezzaFrame/2;
	bottone[ESCIb].distanza= 230;

	DrawBackground(s);

	al_draw_bitmap(PannelloPunteggi,
		LARGHEZZA/2 - al_get_bitmap_width(PannelloPunteggi)/2,10,0);
	for(int i=0; i<NUM_PUNTEGGI; i++)
		al_draw_textf(font18, al_map_rgb(255,255,255), LARGHEZZA/2, 
		150+20*i, ALLEGRO_ALIGN_CENTRE , "%i",p[i]);
	al_draw_bitmap_region(bottone[INDIETROb].immagine,
		bottone[INDIETROb].curFrame*bottone[INDIETROb].lunghezzaFrame,0, 
		bottone[INDIETROb].lunghezzaFrame, 
		bottone[INDIETROb].altezzaFrame,
		bottone[INDIETROb].posX,
		bottone[INDIETROb].posY+bottone[INDIETROb].distanza,0);
	al_draw_bitmap_region(bottone[ESCIb].immagine,
		bottone[ESCIb].curFrame*bottone[ESCIb].lunghezzaFrame,0, 
		bottone[ESCIb].lunghezzaFrame, 
		bottone[ESCIb].altezzaFrame,
		bottone[ESCIb].posX,
		bottone[ESCIb].posY+bottone[ESCIb].distanza,0);


			
}

void DisegnaCambioLivello(Sfondo &s)
{
	DrawBackground(s);

	al_draw_textf(font18, al_map_rgb(255, 255, 255),LARGHEZZA/2, 300, 
		ALLEGRO_ALIGN_CENTRE,"Livello %i",partita.livello+1);
	al_draw_text(font18, al_map_rgb(255, 255, 255),LARGHEZZA/2, 400, 
		ALLEGRO_ALIGN_CENTRE, "Premi INVIO per continuare");
}


void DisegnaGameOver(Sfondo &s,Sfondo &s2,Sfondo &s3)
{

	bottone[GIOCAb].posX = LARGHEZZA/2-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[GIOCAb].distanza= 100;
	bottone[ESCIb].posX= LARGHEZZA/2-bottone[GIOCAb].lunghezzaFrame/2;
	bottone[ESCIb].distanza= 150;

	DrawBackground(s);
	DrawBackground(s2);
	DrawBackground(s3);
	
	if(partita.livello>10)
		al_draw_textf(font100,al_map_rgb(253, 246, 138), 250, 5, 
					0, "VITTORIA");
	else
		al_draw_textf(font100,al_map_rgb(253, 246, 138), 250, 5,
					0, "SCONFITTA");
	al_draw_bitmap(PannelloRisultati,
		LARGHEZZA/2 - al_get_bitmap_width(PannelloRisultati)/2,150,0);
	al_draw_bitmap_region(bottone[GIOCAb].immagine,
		bottone[GIOCAb].curFrame*bottone[GIOCAb].lunghezzaFrame,0, 
		bottone[GIOCAb].lunghezzaFrame, 
		bottone[GIOCAb].altezzaFrame,
		bottone[GIOCAb].posX,
		bottone[GIOCAb].posY+bottone[GIOCAb].distanza,0);
	al_draw_bitmap_region(bottone[ESCIb].immagine,
		bottone[ESCIb].curFrame*bottone[ESCIb].lunghezzaFrame,0,
		bottone[ESCIb].lunghezzaFrame, 
		bottone[ESCIb].altezzaFrame,
		bottone[ESCIb].posX,
		bottone[ESCIb].posY+bottone[ESCIb].distanza,0);
	al_draw_textf(font15,al_map_rgb(253, 246, 138),343, 172,0,
		"%i",partita.punti);
	al_draw_textf(font15,al_map_rgb(253, 246, 138),518, 172,0,
		"%.2f",stat.precisione);
	al_draw_textf(font15,al_map_rgb(253, 246, 138),683, 172,0,
		"%i",stat.vite_perse);
}

/** 
 * Fine del file contenente il modulo Disegno
 */
