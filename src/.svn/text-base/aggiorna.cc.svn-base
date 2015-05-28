/**
 * @file 
 * File contenente il modulo Aggiorna.
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
void Inizia_partita()
{
	partita.punti=0;
	partita.vite=3;
	partita.livello=1;
	partita.difficolta=500;
	partita.n_nemici=10;
	partita.velocita=0;
}

void Nuovo_livello()
{		
	if(partita.vite<NUM_VITE)
		partita.vite++;
	partita.livello++;
	partita.difficolta-=15;
	partita.n_nemici=10;
	partita.velocita+=0.5;
}

void Sposta_giocatore(Giocatore &tom)
{
	tom.animationRow = 6;

	if(keys[SU])
	{	tom.y -= tom.vel;
		if(tom.y < 0)
			tom.y = 0;	
	}	
	if(keys[GIU])
	{	tom.y += tom.vel;
		if(tom.y > ALTEZZA)
			tom.y = ALTEZZA;
	}
	if(keys[SINISTRA])
	{	tom.x -= tom.vel;
		if(tom.x < 0)
			tom.x = 0;	
	}	
	if(keys[DESTRA])
	{	tom.x += tom.vel;
		if(tom.x > 450)
			tom.x = 450;
	}		
}

void Aggiorna_anim_giocatore(Giocatore &tom)
{	if(!tom.colpito && !tom.attacco)
	{	
		if(tom.frameCont>=tom.frameRit)
		{
		tom.corFrame ++;
		tom.frameCont=0;
		}
		if(tom.corFrame>tom.animationCol)
			tom.corFrame=0;
		if(keys[SU])
		{
			tom.animationRow = 0;	
		}	
		if(keys[GIU])
		{
			tom.animationRow = 2;	
		}	
		if(keys[SINISTRA])
		{	
			tom.animationRow = 6;		
		}
		if(keys[DESTRA])
		{	
			tom.animationRow = 1;
		}
	}
	if(tom.colpito)
	{	tom.animationRow = 7;
		if(tom.frameCont>=tom.frameRit)
			{
			tom.corFrame ++;
			tom.frameCont=0;
			}
			if(tom.corFrame>6)
			{	tom.colpito=false;
				tom.corFrame=0;
				Aggiorna_anim_giocatore(tom);
			}
	}
	if(tom.attacco)
	{
		tom.animationRow = 4;
		if(tom.frameCont>=tom.frameRit)
			{
			tom.corFrame ++;
			tom.frameCont=0;
			}
			if(tom.corFrame>tom.animationCol)
			{	tom.attacco=false;
				tom.corFrame=0;
				Aggiorna_anim_giocatore(tom);
			}
	}
	if(!keys[SU]&&!keys[GIU]&&!keys[DESTRA]&&!keys[SINISTRA]&&!tom.attacco&&!tom.colpito)
	{	
		tom.animationRow = 6;
		if(tom.frameCont>=tom.frameRit+4)
			{
			tom.corFrame ++;
			tom.frameCont=0;
			}
			if(tom.corFrame>tom.animationCol)
			tom.corFrame=0;
	}
	
}

void Spawn_Nemici(Nemici nemici[])
{
	for(int i = (partita.livello-1); i < (NUM_NEMICI/2 -2 +partita.livello); i++)
	{
		if(!nemici[i].vite)
		{ 
			if((rand() % partita.difficolta )== 0)
			{	if(i<NUM_NEMICI/2-1)
				nemici[i].vite = 1; 
				else	nemici[i].vite = 2;
				nemici[i].x = LARGHEZZA; 
				nemici[i].y = 30 + rand() % (ALTEZZA- 60);

				break;
			}
		}
	}
}

void Aggiorna_Nemici(Nemici nemici[])
{
	for(int i = (partita.livello-1); i < (NUM_NEMICI/2 -2 +partita.livello); i++)
	{
		if(nemici[i].vite)
		{
			if(++nemici[i].frameCont >= nemici[i].frameRit)
			{
				nemici[i].corFrame += nemici[i].animationDir;

				if(!nemici[i].impatto)
				{	
					nemici[i].animationRow=0;
					if(nemici[i].corFrame >= nemici[i].maxFrame)
						nemici[i].corFrame = 0;
					else if( nemici[i].corFrame <= 0)
						nemici[i].corFrame = nemici[i].maxFrame - 1;
				}else{
					nemici[i].animationRow=1;
					if(nemici[i].corFrame >= nemici[i].maxFrame)
					{	nemici[i].corFrame = 0;
						nemici[i].impatto = false; }
					}
				nemici[i].frameCont = 0;
			}

			nemici[i].x -= nemici[i].vel;
		}
	}
}

void Impatto_Nemici(Nemici nemici[], Giocatore &tom)
{
	for(int i = (partita.livello-1); i < (NUM_NEMICI/2 -2 +partita.livello); i++)
	{
		if(nemici[i].vite)
		{
			if(nemici[i].x - nemici[i].bordox < tom.x + tom.bordox &&
				nemici[i].x + nemici[i].bordox > tom.x - tom.bordox &&
				nemici[i].y - nemici[i].bordoy < tom.y + tom.bordoy &&
				nemici[i].y + nemici[i].bordoy > tom.y - tom.bordoy)
			{
				partita.vite--;
				tom.colpito=true;
				tom.corFrame=0;
				stat.vite_perse++;
				nemici[i].vite=0;
			}
			else if(nemici[i].x < 0)
			{
				nemici[i].vite=0;
				partita.vite--;
				stat.vite_perse++;
			}
		}
	}
}

void Spara_colpo(Colpo colpi[], Giocatore &tom,int Row,ALLEGRO_SAMPLE *shot)
{
	for( int i = 0; i < NUM_COLPI; i++)
	{
		if(!colpi[i].vite)
		{	
			al_play_sample(shot, 1.5, 0, 1.5, ALLEGRO_PLAYMODE_ONCE, NULL);

			tom.attacco=true;
			tom.corFrame=0;
			stat.colpi++;
			colpi[i].x = tom.x + 17;
			colpi[i].y = tom.y;
			colpi[i].vite = 1;
			colpi[i].frameAlt = 32;
			colpi[i].frameLun = 32;
			colpi[i].animationRow=2;
			break;
		}
	}
}

void Aggiorna_colpo(Colpo colpi[])
{
	for(int i = 0; i < NUM_COLPI; i++)
	{
		if(colpi[i].vite)
		{
			colpi[i].x += colpi[i].vel;
			if(colpi[i].x > LARGHEZZA)
				colpi[i].vite = 0;
		}
	}
}

void Impatto_colpo(Colpo colpi[], Nemici nemici[], Giocatore &tom,Impatti impatti[], ALLEGRO_SAMPLE *morte1)
{
	for(int i = 0; i < NUM_COLPI; i++)
	{
		if(colpi[i].vite)
		{
			for(int j = (partita.livello-1); j < (NUM_NEMICI/2 -2 +partita.livello); j++)
			{
				if(nemici[j].vite)
				{	
					if(colpi[i].x > (nemici[j].x - nemici[j].bordox) &&
						colpi[i].x < (nemici[j].x + nemici[j].bordox) &&
						colpi[i].y > (nemici[j].y - nemici[j].bordoy) &&
						colpi[i].y < (nemici[j].y + nemici[j].bordoy))
					{
						al_play_sample(morte1, 1.5, 0, 1.5, ALLEGRO_PLAYMODE_ONCE, NULL);
						colpi[i].vite =0;
						nemici[j].vite--;

						partita.punti++;
						if(nemici[j].vite==0)
							Inizia_impatti(impatti, colpi[i].x, colpi[i].y,j);
						else {
							nemici[j].impatto=true;
							nemici[j].corFrame=0;
							}
					}
				}
			}
		}
	}
}

void Inizia_impatti(Impatti impatti[], int x, int y,int j)
{
	for(int i = 0; i < NUM_IMPATTI; i++)
	{
		if(!impatti[i].attivo)
		{	
			if(j>=NUM_NEMICI/2 -1)
				impatti[i].animationRow=2;
			else	impatti[i].animationRow=1;

			impatti[i].attivo= true;
			impatti[i].x = x;
			impatti[i].y = y;
			break;
		}
	}
}

void Aggiorna_impatti(Impatti impatti[])
{
	for(int i = 0; i < NUM_IMPATTI; i++)
	{
		if(impatti[i].attivo)
		{
			if(++impatti[i].frameCont >= impatti[i].frameRit)
			{
				impatti[i].corFrame += impatti[i].animationDir;
				if(impatti[i].corFrame >= impatti[i].maxFrame)
				{
					impatti[i].corFrame = 0;
					impatti[i].attivo= false;
				}

				impatti[i].frameCont = 0;
			}
		}
	}
}

void UpdateBackground(Sfondo &s)
{
	s.x += s.velX * s.dirX;
	if(s.x + s.lunghezza <= 0)
		s.x = 0;
}

bool CursoresuBottone(ALLEGRO_EVENT ev, int bottonex, int bottoney, int dist, int altezza, int lunghezza)
{
	if(	(ev.mouse.y >bottoney + dist) && 
		(ev.mouse.y<bottoney + dist+altezza) && 
		(ev.mouse.x>bottonex) && 
		(ev.mouse.x<bottonex+ lunghezza)	)
		return true;
	return false;
}

void Cambia_fase(FASE nuova,Nemici nemici[],Colpo colpi[],Giocatore &tom,Impatti impatti[])
{	switch(partita.fase)
	{
	case INIZIO:
		{	
			if(nuova==IN_GIOCO)
			{	
				al_stop_sample_instance(songInstance_m);
				Inizia_partita();
				Inizializza_g(tom,ImmG);
				Inizializza_Nemici(nemici, ImmN1, ImmN2);
				Inizializza_colpo(colpi,ImmC);
				Inizializza_impatti(impatti,ImmI,ImmI2);
			}
		}
		break;
	case IN_GIOCO:
		{
		if(nuova!=PAUSA&&nuova!=LIVELLO)
			al_stop_sample_instance(songInstance_g);
		if(nuova == GAMEOVER)
			if(!HSaggiornati && partita.punti!=0)
			{
				if(AggiornaPunteggi(p,partita,HSaggiornati))
					std:: cout<<"OK"<<endl;
				else
					std:: cerr<<"Errore di apertura del file"<<endl;
			}
		}
		break;		
	case PAUSA:
		break;
	case CREDITS:
		break;
	case HOWTO:
		break;		
	case LIVELLO:	
	{	al_stop_sample_instance(songInstance_m);
		Nuovo_livello();
		Inizializza_Nemici(nemici, ImmN1, ImmN2);
		Inizializza_colpo(colpi,ImmC);
	}
		break;		
	case PUNTEGGI:
		if(nuova==INIZIO)
			al_stop_sample_instance(songInstance_l);
		break;
	case GAMEOVER:
	{	if(nuova!=PUNTEGGI)
		al_stop_sample_instance(songInstance_l);
	}
		break;
	}

	partita.fase=nuova;

	switch(partita.fase)
	{
	case INIZIO:
		al_play_sample_instance(songInstance_m);
		break;
	case IN_GIOCO:
	{	
		al_play_sample_instance(songInstance_g);
	}
		break;		
	case PAUSA:
		break;
	case CREDITS:
		break;
	case HOWTO:
		break;		
	case LIVELLO:
		{					
		al_clear_to_color(al_map_rgb(0,0,0));
		if(salva(partita, stat))
			al_draw_textf(font18, al_map_rgb(28,57,187), LARGHEZZA/2,
					ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , "Salvataggio riuscito");
		else
			al_draw_textf(font18, al_map_rgb(28,57,187), LARGHEZZA/2,
					 ALTEZZA/2, ALLEGRO_ALIGN_CENTRE , "Salvataggio non riuscito");
		al_flip_display();
		al_rest(1);
		}	
		break;		
	case PUNTEGGI:
		break;
	case GAMEOVER:
	{
		stat.precisione = partita.punti/stat.colpi *100;
		al_play_sample_instance(songInstance_l);
	}

		break;
	}
}

/** 
 * Fine del file contenente il modulo Aggiorna
 */
