OBJ = AngryTom.o disegno.o aggiorna.o fileIO.o inizializzazioni.o dichiarazioni.o DBG.o
OBJD = AngryTomD.o disegnoD.o aggiornaD.o fileIOD.o inizializzazioniD.o dichiarazioni.o DBG.o
CXXFLAGS=$(DEBUG_FLAGS)-Wall 
LDFLAGS=-export-dynamic `pkg-config --libs  allegro-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_dialog-5.0 allegro_primitives-5.0 allegro_image-5.0 allegro_audio-5.0 allegro_acodec-5.0`

.PHONY: depend clean cleanall project debug

project: $(OBJ)
	g++ -o AngryTom $(OBJ) $(LDFLAGS)

-include dependencies

# compilazione in modalità DEBUG
debug:  $(OBJD)
	g++ -o AngryTom   $(OBJD) $(LDFLAGS)

AngryTomD.o: 
	   g++ -c -g -D DEBUG_MODE -o AngryTomD.o AngryTom.cc $(LDFLAGS)
disegnoD.o: 
	   g++ -c -g -o disegnoD.o disegno.cc $(LDFLAGS)
aggiornaD.o: 
	   g++ -c -g -o aggiornaD.o aggiorna.cc $(LDFLAGS)
fileIOD.o: 
	   g++ -c -g -o fileIOD.o fileIO.cc $(LDFLAGS)
inizializzazioniD.o: 
	   g++ -c -g -o inizializzazioniD.o inizializzazioni.cc $(LDFLAGS)


depend:
	g++ -MM *.cc >dependencies 
clean:
	rm *.o
cleanall:
	rm AngryTom *.o *~
