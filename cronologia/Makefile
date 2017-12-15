SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/union_cronologias $(BIN)/filtradoPalabraClave $(BIN)/filtradoPalabraClave $(BIN)/estadisticaEventos
# ************ Generación de documentación ******************
#documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************

# UNION CRONOLOGIAS
$(BIN)/union_cronologias: $(OBJ)/union_cronologias.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o
	$(CXX) -I$(INC) $(OBJ)/union_cronologias.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o -o $(BIN)/union_cronologias

$(OBJ)/union_cronologias.o : $(SRC)/union_cronologias.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/union_cronologias.cpp -o $(OBJ)/union_cronologias.o

#FILTRADO POR PALABRA
$(BIN)/filtradoPalabraClave: $(OBJ)/filtradoPalabraClave.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o
	$(CXX) -I$(INC) $(OBJ)/filtradoPalabraClave.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o -o $(BIN)/filtradoPalabraClave

$(OBJ)/filtradoPalabraClave.o : $(SRC)/filtradoPalabraClave.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/filtradoPalabraClave.cpp -o $(OBJ)/filtradoPalabraClave.o

#FILTRADO POR INTERVALO
$(BIN)/filtradoIntervalo: $(OBJ)/filtradoIntervalo.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o
	$(CXX) -I$(INC) $(OBJ)/filtradoIntervalo.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o -o $(BIN)/filtradoIntervalo

$(OBJ)/filtradoIntervalo.o : $(SRC)/filtradoIntervalo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/filtradoIntervalo.cpp -o $(OBJ)/filtradoIntervalo.o

#RECUENTO
$(BIN)/estadisticaEventos: $(OBJ)/estadisticaEventos.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o
	$(CXX) -I$(INC) $(OBJ)/estadisticaEventos.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o -o $(BIN)/estadisticaEventos

$(OBJ)/estadisticaEventos.o : $(SRC)/estadisticaEventos.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/estadisticaEventos.cpp -o $(OBJ)/estadisticaEventos.o

$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Cronologia.cpp -o $(OBJ)/Cronologia.o
	
$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/FechaHistorica.cpp -o $(OBJ)/FechaHistorica.o



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
