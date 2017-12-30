#include "../include/quienesquien.h"
#include <sstream>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>


QuienEsQuien::QuienEsQuien(){
	
}
QuienEsQuien::QuienEsQuien(const QuienEsQuien &quienEsQuien){
	*this = quienEsQuien;
}
QuienEsQuien& QuienEsQuien::operator= (const QuienEsQuien &quienEsQuien){
	//Copia personajes
	this->personajes = quienEsQuien.personajes;
	//Copia atributos
	this->atributos = quienEsQuien.atributos;
	//Copia tablero
	this->tablero = quienEsQuien.tablero;
	//Copia arbol
	this->arbol = quienEsQuien.arbol;
	//Copia jugada actual
	this->jugada_actual = quienEsQuien.jugada_actual;

	return *this;
}
QuienEsQuien::~QuienEsQuien(){
	this->limpiar();
}

void QuienEsQuien::limpiar(){
	//TODO :)
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

void QuienEsQuien::mostrar_estructuras_leidas(){
	cout << "personajes: "<< (this->personajes) << endl;
	cout << "atributos:  "<< (this->atributos)  << endl;
	cout << "tablero:    "<< endl;


	// Escribe la cabecera del tablero
	for(vector<string>::iterator it_atributos = this->atributos.begin();
		it_atributos != this->atributos.end();
		it_atributos++){
		cout << *it_atributos << "\t";
	}
	cout <<endl;

	int indice_personaje = 0;
	for(vector<vector<bool>>::iterator it_tablero_atributos = tablero.begin();
		it_tablero_atributos!= tablero.end();
		it_tablero_atributos++){

		string personaje = this->personajes[indice_personaje];
		int indice_atributo = 0;
		for(vector<bool>::iterator it_atributos_personaje = (*it_tablero_atributos).begin();
			it_atributos_personaje != (*it_tablero_atributos).end();
			it_atributos_personaje++){

			cout << *it_atributos_personaje<<"\t";

			indice_atributo++;
		}

		cout << personaje << endl;

		indice_personaje++;
	}

}

/**
  * @brief Devuelve una copia de la cadena original sin las subcadenas no deseadas.
  * 
  * @param cadena_original Cadena de la que se eliminan las subcadenas no deseadas.
  * @param cadena_a_eliminar Subcadena que se busca y se elimina.
  *
  * @return Copia de la cadena original sin las subcadenas no deseadas.
  */
string limpiar_string(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);

	while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}

istream& operator >> (istream& is, QuienEsQuien &quienEsQuien) {
	quienEsQuien.limpiar();
	
  	if(is.good()){
  		string linea;
    	getline(is, linea, '\n');

    	linea = limpiar_string(linea,"\r");
    	
    	while(linea.find('\t') != string::npos ){
    		string atributo = linea.substr(0,linea.find('\t'));
			quienEsQuien.atributos.push_back(atributo);
    		linea = linea.erase(0,linea.find('\t')+1);
    	}

		assert(linea ==  "Nombre personaje");
	}
	
    while( is.good() ) {
    	string linea;
    	getline(is, linea, '\n');
    	linea = limpiar_string(linea,"\r");

    	//Si la linea contiene algo extrae el personaje. Si no lo es, la ignora.
    	if(linea != ""){;
	    	vector<bool> atributos_personaje;
	    	
	    	int indice_atributo=0;
	    	while(linea.find('\t') != string::npos){
	    		string valor = linea.substr(0,linea.find('\t'));
	    		
	    		assert(valor == "0" || valor == "1");
	    		
	    		bool valor_atributo = valor == "1";
	    		
	    		atributos_personaje.push_back(valor_atributo);
				
	    		linea = linea.erase(0,linea.find('\t')+1);
	    		indice_atributo++;
			}
			
			string nombre_personaje = linea;
	    	
	    	quienEsQuien.personajes.push_back(nombre_personaje);
	    	quienEsQuien.tablero.push_back(atributos_personaje);
	    }
  	}
  	
	return is;
}

ostream& operator << (ostream& os, const QuienEsQuien &quienEsQuien){

	//Escribimos la cabecera, que contiene los atributos y al final una columna para el nombre
	for(vector<string>::const_iterator it_atributos = quienEsQuien.atributos.begin();
		it_atributos != quienEsQuien.atributos.end();
		it_atributos++){

		os  << *it_atributos << "\t";
	}
	os << "Nombre personaje" << endl;

	//Rellenamos con ceros y unos cada línea y al final ponemos el nombre del personaje.
	for(int indice_personaje=0;indice_personaje<quienEsQuien.personajes.size();indice_personaje++){
		for(int indice_atributo=0;indice_atributo<quienEsQuien.atributos.size();indice_atributo++){

			os  << quienEsQuien.tablero[indice_personaje][indice_atributo] << "\t";
		}
		os  << quienEsQuien.personajes[indice_personaje] << endl;
	}

	return os;
}

/**
  * @brief Convierte un número a un vector de bool que corresponde 
  *        con su representación en binario con un numero de digitos
  *        fijo.
  *
  * @param n Número a convertir en binario.
  * @param digitos Número de dígitos de la representación binaria.
  *
  * @return Vector de booleanos con la representación en binario de @e n 
  *      con el número de elementos especificado por @e digitos. 

  */
vector<bool> convertir_a_vector_bool(int n, int digitos) {
  vector<bool> ret;
  while(n) {
    if (n&1){
      ret.push_back(true);
    } else{
      ret.push_back(false);
    }
    n>>=1;  
  }

  while(ret.size()<digitos){
  	ret.push_back(false);
  }

  reverse(ret.begin(),ret.end());
  return ret;
}

bintree<Pregunta> QuienEsQuien::crear_arbol(){
	vector<bool> p_no_usados; //vector propio para llevar cuenta de personajes no puestos en el arbol
	vector<bool> at_no_usados; //vector temporal
	int n_personajes = personajes.size();

	//Inicializamos todos a true
	for (int i = 0; i < n_personajes; i++){
		p_no_usados.push_back(true);
	}

	//Inicializamos todos a true
	for (int i = 0; i < atributos.size(); i++){
		at_no_usados.push_back(true);
	}

	//creamos el nodo raiz
	int mejor_pos_atributo = decidir_mejor_pregunta(at_no_usados, p_no_usados, n_personajes);
	Pregunta pregunta_raiz;
	pregunta_raiz.atributo = atributos[mejor_pos_atributo];
	pregunta_raiz.num_personajes = n_personajes;

	pregunta_raiz.atrib_no_usados = at_no_usados;

	pregunta_raiz.personajes_no_tumbados = p_no_usados;

	//Introducimos nodo raiz en el arbol con el constructor
	bintree<Pregunta> subarbol(pregunta_raiz);

	arbol = subarbol;
	
	crear_nodos(arbol.root());

	cout << "COUT 5" <<endl;
	return arbol;
}

void QuienEsQuien::usar_arbol(bintree<Pregunta> arbol_nuevo){
	arbol = arbol_nuevo;
}

void QuienEsQuien::iniciar_juego(){
	char opcion;
	int num_personajes = personajes.size();
	//Crear arbol
	//this->crear_arbol();
	
	//Hacer preguntas
	bintree<Pregunta>::node nodo_act;
	nodo_act = arbol.root();

	while((*nodo_act).num_personajes != 1){
		cout << (*nodo_act).atributo;
		do{
			cin >> opcion;
			opcion = toupper(opcion);
		}while(opcion!='S' || opcion!='N');

		if(opcion == 'S'){
			nodo_act = nodo_act.left();
		}else if(opcion == 'N'){
			nodo_act = nodo_act.right();
		}
	}

	cout << "Tu personaje es: " << (*nodo_act).atributo;

}

set<string> QuienEsQuien::informacion_jugada(bintree<Pregunta>::node jugada_actual){
	
	vector<bool> levantados = (*jugada_actual).personajes_no_tumbados;
	set<string> personajes_levantados;

	for(int i = 0; i<levantados.size(); i++){
		if(levantados[i] == 1){
			personajes_levantados.insert(personajes[i]);
		}
	}
	return personajes_levantados;
}

void escribir_esquema_arbol(ostream& ss,
					  const bintree<Pregunta>& a, 
		    		  bintree<Pregunta>::node n,
					  string& pre){
	if (n.null()){
	    ss << pre << "-- x" << endl;
	} else {
	    ss << pre << "-- " << (*n) << endl;
	    if ( !n.right().null() || !n.left().null()) {// Si no es una hoja
			pre += "   |";
	    	escribir_esquema_arbol(ss,a, n.right(), pre);
	     	pre.replace(pre.size()-4, 4, "    ");
	      	escribir_esquema_arbol (ss,a, n.left(), pre);
	      	pre.erase(pre.size()-4, 4);    
	    }
  	}
}

void QuienEsQuien::escribir_arbol_completo() const{
	string pre = "";
	escribir_esquema_arbol(cout,this->arbol,this->arbol.root(),pre);
}

/*
void QuienEsQuien::eliminar_nodos_redundantes(){
	// TODO ^^
}
*/

float QuienEsQuien::profundidad_promedio_hojas(){
	//TODO :)

	return -1;
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max).
**/

int generaEntero(int min, int max){
    int tam= max -min;
    return ((rand()%tam)+min);
}

void QuienEsQuien::tablero_aleatorio(int numero_de_personajes){
	srand(0);

	this->limpiar();

	float log_2_numero_de_personajes = log(numero_de_personajes)/log(2);

	int numero_de_atributos = ceil(log_2_numero_de_personajes);

	cout << "Petición para generar "<< numero_de_personajes<<" personajes ";
	cout << "con "<<numero_de_atributos<< " atributos"<<endl;
	cout << "Paso 1: generar "<< pow(2,numero_de_atributos) << " personajes"<<endl;

	//Fase 1: completar el tablero con todos los personajes posibles
	//Completo el tablero y los nombres de personajes a la vez
	for(int indice_personaje=0;indice_personaje< pow(2,numero_de_atributos);indice_personaje++){
		vector<bool> atributos_personaje = convertir_a_vector_bool(indice_personaje,numero_de_atributos);
		string nombre_personaje = "Personaje_"+to_string(indice_personaje);

		this->personajes.push_back(nombre_personaje);
		this->tablero.push_back(atributos_personaje);
	}

	// Completo los nombres de los atributos.
	for(int indice_atributo=0;indice_atributo<numero_de_atributos;indice_atributo++){
		string nombre_atributo = "Atributo_"+to_string(indice_atributo);
		this->atributos.push_back(nombre_atributo);
	}

	cout << "Paso 2: eliminar "<< (pow(2,numero_de_atributos)-numero_de_personajes) << " personajes"<<endl;
	//Fase 2. Borrar personajes aleatoriamente hasta que quedan solo los que hemos pedido.
	while(personajes.size()>numero_de_personajes){
		int personaje_a_eliminar = generaEntero(0,personajes.size());

		personajes.erase(personajes.begin()+personaje_a_eliminar);
		tablero.erase(tablero.begin()+personaje_a_eliminar);
	}

}

int QuienEsQuien::decidir_mejor_pregunta(vector<bool> atrib_no_usados, vector<bool> p_no_tumbados, int n){
	//1 son no usados 0 usados
	int atrib_menor_diferencia;
	double menor_diferencia = 100;
	double valor_a_alcanzar = n / 2;
	int valor_atrib = 0;

	cout << endl;
	for (int i = 0; i < atrib_no_usados.size(); i++){
		if(atrib_no_usados[i]==true){
			valor_atrib = num_personajes_cumplen(i, p_no_tumbados);
			if (abs(valor_atrib - valor_a_alcanzar) < menor_diferencia){
				atrib_menor_diferencia = i;
				menor_diferencia = abs(valor_atrib - valor_a_alcanzar);
			} 
		}
	}
	return atrib_menor_diferencia;
}

int QuienEsQuien::num_personajes_cumplen(int columna, vector<bool> p_no_tumbados){
	int suma = 0;
	for (int i = 0; i < personajes.size() ; i++){
		if(tablero[i][columna] == 1 && p_no_tumbados[i])
			suma++;	
	}
	return suma;
}


int QuienEsQuien::posicion_atributo(string atr){
	int i;
	bool encontrado=false;
	for (i = 0; i < atributos.size() && !encontrado; i++){
		if(atributos[i]==atr){
			encontrado=true;
		}
	}
	if(encontrado)
		return i;
	else
		return -1;
}

void QuienEsQuien::actualizar_nodo(const bintree<Pregunta>::node & nodo_actual, Pregunta & pregunta, const int n_per, bool rama){
	
	//Actualizamos atrib_no_usados del nuevo nodo
	pregunta.atrib_no_usados = ((*nodo_actual).atrib_no_usados);

	pregunta.atrib_no_usados[posicion_atributo((*nodo_actual).atributo)] = 0;
	

	cout << "COUT A" << endl;
	//Resize de los vectores
	pregunta.personajes_no_tumbados.resize((*nodo_actual).personajes_no_tumbados.size());

	//Copiamos el vector personajes_no_tumbados del padre
	pregunta.personajes_no_tumbados = (*nodo_actual).personajes_no_tumbados;
	//Actualizamos personajes_no_tumbados del nuevo nodo
	for (int i = 0; i < ((*nodo_actual).personajes_no_tumbados).size(); i++){
		if((*nodo_actual).personajes_no_tumbados[i] == 1){
			if(rama == true)
				pregunta.personajes_no_tumbados[i] = tablero[i][posicion_atributo((*nodo_actual).atributo)];
			else
				pregunta.personajes_no_tumbados[i] = !tablero[i][posicion_atributo((*nodo_actual).atributo)];
		}
	}

	cout << "COUT B" << endl;

	//Actualizamos num_personajes del nuevo nodo
	pregunta.num_personajes = n_per;

	if(n_per != 1){
		//Actualizamos atributo del nuevo nodo
		pregunta.atributo = atributos[decidir_mejor_pregunta(pregunta.atrib_no_usados,
									 pregunta.personajes_no_tumbados, n_per)];
	}else{
		int i;
		bool encontrado = false;
		for (i = 0; i < pregunta.personajes_no_tumbados.size() && !encontrado; i++){
			if(pregunta.personajes_no_tumbados[i] == 1)
				encontrado == true;
		}
		assert(encontrado == true);
		pregunta.atributo = personajes[i];
	}
	cout << "COUT C" << endl;
}

//FUNCION RECURSIVA
void QuienEsQuien::crear_nodos(bintree<Pregunta>::node nodo){
	int atr = decidir_mejor_pregunta((*nodo).atrib_no_usados, (*nodo).personajes_no_tumbados, 
										(*nodo).num_personajes);
	int izda = 0, dcha = 0;

	
	for (int i = 0; i < personajes.size(); i++){
		if(tablero[atr][i] == 1)
			izda++;
	}
	dcha = personajes.size() - izda;


	Pregunta preg_izda, preg_dcha;

	bintree<Pregunta>::node nodo_izda(preg_izda), nodo_dcha(preg_dcha);



	//CAMBIAR IMPLEMENTACION
	actualizar_nodo(nodo, preg_izda, izda, true);
	actualizar_nodo(nodo, preg_dcha, dcha, false);


	arbol.insert_left(nodo, preg_izda);
	arbol.insert_right(nodo, preg_dcha);

	cout << "ARBOL RAIZ: " << (*arbol.root()).num_personajes;
	cout << "RAIZ -> IZQD: " << (*(arbol.root()).left()).num_personajes;

	/*	
	if(izda != 1)
		crear_nodos(nodo_izda);
	if(dcha != 1)
		crear_nodos(nodo_dcha);
	*/
}