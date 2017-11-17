SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/usopilas_max
# ************ Generación de documentación ******************
#documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(OBJ)/Pila_max_VD.o
	$(CXX) -I$(INC) $(OBJ)/usopilas_max.o $(OBJ)/Pila_max_VD.o $(OBJ)/Pila_max_cola.o -o $(BIN)/usopilas_max
	
$(OBJ)/usopilas_max.o : $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o
	
$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_VD.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_VD.cpp -o $(OBJ)/Pila_max_VD.o

$(OBJ)/Pila_max_VD.o : $(SRC)/Pila_max_cola.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_cola.cpp -o $(OBJ)/Pila_max_cola.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
