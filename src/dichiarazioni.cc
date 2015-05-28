/**
 * @file 
 * File contenente il modulo Dichiarazioni.
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

ALLEGRO_FONT *font18 = NULL ;
ALLEGRO_FONT *font15  = NULL ;
ALLEGRO_FONT *font100  = NULL;

ALLEGRO_BITMAP *PannelloRisultati  = NULL;
ALLEGRO_BITMAP *PannelloPunteggi  = NULL;

ALLEGRO_BITMAP * inizio  = NULL;
ALLEGRO_BITMAP * punteggi  = NULL;
ALLEGRO_BITMAP *ImmS  = NULL;	
ALLEGRO_BITMAP *ImmS2 = NULL;
ALLEGRO_BITMAP *ImmS3 = NULL;

ALLEGRO_BITMAP *ImmG  = NULL;
ALLEGRO_BITMAP *ImmN1 = NULL;
ALLEGRO_BITMAP *ImmN2 = NULL;
ALLEGRO_BITMAP *ImmI = NULL;
ALLEGRO_BITMAP *ImmI2 = NULL;
ALLEGRO_BITMAP *ImmC = NULL;
ALLEGRO_BITMAP *ImmV = NULL;

ALLEGRO_SAMPLE *shot = NULL;
ALLEGRO_SAMPLE *music = NULL;
ALLEGRO_SAMPLE *music_menu = NULL;
ALLEGRO_SAMPLE *music_lose = NULL;
ALLEGRO_SAMPLE *morte1 = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance_g = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance_m = NULL;
ALLEGRO_SAMPLE_INSTANCE *songInstance_l = NULL;

Gioco partita;
Statistiche stat;
Bottoni bottone[N_BOTTONI];
Punteggi p;
bool keys[NUM_TASTI];
bool HSaggiornati;

/* Fine file modulo Dichiarazioni */
