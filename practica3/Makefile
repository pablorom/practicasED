SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/pruebacronologia
# ************ Generación de documentación ******************
#documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/pruebacronologia: $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o
	$(CXX) -I$(INC) $(OBJ)/pruebacronologia.o $(OBJ)/Cronologia.o $(OBJ)/FechaHistorica.o -o $(BIN)/pruebacronologia
	
$(OBJ)/pruebacronologia.o : $(SRC)/pruebacronologia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebacronologia.cpp -o $(OBJ)/pruebacronologia.o
	
$(OBJ)/Cronologia.o : $(SRC)/Cronologia.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Cronologia.cpp -o $(OBJ)/Cronologia.o
	
$(OBJ)/FechaHistorica.o : $(SRC)/FechaHistorica.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/FechaHistorica.cpp -o $(OBJ)/FechaHistorica.o



# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
