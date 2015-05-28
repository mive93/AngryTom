/**
 * @file 
 * File contenente il modulo Debug.
 * Contiene tutte le funzioni adibite alla stampa di variabili di gioco
 */
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "objects.h"
#include "dichiarazioni.h"
#include "DBG.h"
	
using namespace std;

void controllo_inizio(bool fine,bool render,bool HSaggiornati)
{
	cout<<"fine:"<<fine<<endl;
	cout<<"render:"<<render<<endl;
	cout<<"HSaggiornati:"<<HSaggiornati<<endl;;

}

void stampa_dati_partita()
{
	cout<<"\nGIOCO: fase: "<<partita.fase<<endl;
	cout<<"punti: "<<partita.punti<<endl;
	cout<<"vite: "<<partita.vite<<endl;
	cout<<"livello: "<<partita.livello<<endl;
	cout<<"difficoltà: "<<partita.difficolta<<endl;
	cout<<"n_nemici: "<<partita.n_nemici<<endl;
	cout<<"velocità: "<<partita.velocita<<endl;
	cout<<"\nSTATISTICHE :colpi: "<<stat.colpi<<endl;
	cout<<"precisione: "<<stat.precisione<<endl;
	cout<<"vite perse: "<<stat.vite_perse<<endl;
	for(int i=0;i<NUM_PUNTEGGI;i++)
		cout<<"\nSTRUCTPUNTEGGI "<<i<<": punteggio: "<<p[i]<<endl;
	

}

void stampa_dati_in_gioco(const Colpo colpi[],const Nemici nemici[], Giocatore tom,const Impatti impatti[])
{
	cout<<"\nGIOCATORE: x: "<<tom.x<<endl;
	cout<<"y: "<<tom.y<<endl;
	cout<<"vel: "<<tom.vel<<endl;
	cout<<"bordox: "<<tom.bordox<<endl;
	cout<<"bordoy: "<<tom.bordoy<<endl;
	cout<<"maxframe: "<<tom.maxFrame<<endl;
	cout<<"corframe: "<<tom.corFrame<<endl;
	cout<<"framecont: "<<tom.frameCont<<endl;
	cout<<"framerit: "<<tom.frameRit<<endl;
	cout<<"framealt: "<<tom.frameAlt<<endl;
	cout<<"framelun: "<<tom.frameLun<<endl;
	cout<<"animationcol: "<<tom.animationCol<<endl;
	cout<<"animationdir: "<<tom.animationDir<<endl;
	cout<<"attacco: "<<tom.attacco<<endl;
	cout<<"colpito: "<<tom.colpito<<endl;
	cout<<"animationrow: "<<tom.animationRow<<endl;

	for(int i=0;i<NUM_NEMICI;i++)
	{	cout<<"\nNEMICI: x: "<<nemici[i].x<<endl;
		cout<<"y: "<<nemici[i].y<<endl;
		cout<<"vite: "<<nemici[i].vite<<endl;
		cout<<"vel: "<<nemici[i].vel<<endl;
		cout<<"bordox: "<<nemici[i].bordox<<endl;
		cout<<"bordoy: "<<nemici[i].bordoy<<endl;
		cout<<"maxframe: "<<nemici[i].maxFrame<<endl;
		cout<<"corframe: "<<nemici[i].corFrame<<endl;
		cout<<"framecont: "<<nemici[i].frameCont<<endl;
		cout<<"framerit: "<<nemici[i].frameRit<<endl;
		cout<<"framealt: "<<nemici[i].frameAlt<<endl;
		cout<<"framelun: "<<nemici[i].frameLun<<endl;
		cout<<"animationcol: "<<nemici[i].animationCol<<endl;
		cout<<"animationdir: "<<nemici[i].animationDir<<endl;
		cout<<"impatto: "<<nemici[i].impatto<<endl;
		cout<<"animationrow: "<<nemici[i].animationRow<<endl;
	}

	for(int i=0;i<NUM_COLPI;i++)
	{	cout<<"\nCOLPO: x: "<<colpi[i].x<<endl;
		cout<<"y: "<<colpi[i].y<<endl;
		cout<<"vite: "<<colpi[i].vite<<endl;
		cout<<"vel: "<<colpi[i].vel<<endl;
		cout<<"framealt: "<<colpi[i].frameAlt<<endl;
		cout<<"framelun: "<<colpi[i].frameLun<<endl;
		cout<<"animationrow: "<<colpi[i].animationRow<<endl;
	}
	for(int i=0; i<NUM_IMPATTI;i++)
	{
		cout<<"\nImpatti: x: "<<impatti[i].x<<endl;
		cout<<"y: "<<impatti[i].y<<endl;
		cout<<"attivo: "<<impatti[i].attivo<<endl;
		cout<<"maxframe: "<<impatti[i].maxFrame<<endl;
		cout<<"corframe: "<<impatti[i].corFrame<<endl;
		cout<<"framecont: "<<impatti[i].frameCont<<endl;
		cout<<"framerit: "<<impatti[i].frameRit<<endl;
		cout<<"framealt: "<<impatti[i].frameAlt<<endl;
		cout<<"framelun: "<<impatti[i].frameLun<<endl;
		cout<<"animationcol: "<<impatti[i].animationCol<<endl;
		cout<<"animationdir: "<<impatti[i].animationDir<<endl;
		cout<<"animationrow: "<<impatti[i].animationRow<<endl;
	}

}
/** Fine file contenente il modulo di DEBUG*/
