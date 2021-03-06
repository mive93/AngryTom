/**
 * @file 
 * File contenente il modulo Salva/Carica.
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
#include "disegno.h"
#include "inizializzazioni.h"
#include "fileIO.h"


bool salva(Gioco partita,Statistiche stat)
{
	ofstream f(file);
	if(!f)
		return false;
	f.write(reinterpret_cast<const char *>(&partita), sizeof(Gioco)) ;
	f.write(reinterpret_cast<const char *>(&stat), sizeof(Statistiche)) ;
	f.close();
	return f;
}


bool carica(Gioco &partita,Statistiche &stat)
{
	ifstream f(file);
	if(!f)
		return false;
	f.read(reinterpret_cast<char *>(&partita), sizeof(Gioco)) ;
	f.read(reinterpret_cast<char *>(&stat), sizeof(Statistiche)) ;
	f.close();
	return f;
}





void CaricaPunteggi(Punteggi &p)
{
	ifstream f(HSfile);
	if(!f)
		InizializzaPunteggi(p);
	else 
		f.read(reinterpret_cast< char *>(&p),sizeof(Punteggi));	
	f.close();
}



void OrdinaPunteggi (Punteggi &p)
{
	int temp;
	for(int i=0; i<NUM_PUNTEGGI-1; i++)
		for(int j=i+1; j<NUM_PUNTEGGI; j++)
			if(p[j]>p[i])
			{
				temp = p[i];
				p[i]=p[j];
				p[j]=temp;
			}
				
}


int CercaMinimo (Punteggi &p)
{
	int min = 0;
	for(int i=0; i<NUM_PUNTEGGI; i++)
		if(p[i]<p[min])
			min = i;
	return min;
	
}


bool AggiornaPunteggi(Punteggi &p, Gioco partita,bool &HSaggiornati)
{
	HSaggiornati = true;	
	if(partita.punti > p[CercaMinimo(p)])
		p[CercaMinimo(p)] = partita.punti;
		
	OrdinaPunteggi (p);
	ofstream f(HSfile);
	if(!f)
		return false;
	f.write(reinterpret_cast<const char *>(&p),sizeof(Punteggi));
	f.close();
	return f;
}



/** 
 * Fine del file contenente il modulo Salva/Carica
 */
