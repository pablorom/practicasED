SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/main_prueba
# ************ Generación de documentación ******************
#documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/main_prueba: $(OBJ)/main_prueba.o $(OBJ)/Pila_max_VD.o
	$(CXX) -I$(INC) $(OBJ)/main_prueba.o $(OBJ)/Pila_max_VD.o $(OBJ)/Pila_max_cola.o -o $(BIN)/main_prueba
	
$(OBJ)/main_prueba.o : $(SRC)/main_prueba.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/main_prueba.cpp -o $(OBJ)/main_prueba.o
	
$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_VD.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_VD.cpp -o $(OBJ)/Pila_max_VD.o

$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_cola.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_cola.cpp -o $(OBJ)/Pila_max_cola.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
