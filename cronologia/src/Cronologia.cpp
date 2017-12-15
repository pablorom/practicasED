#include "Cronologia.h"
using namespace std;

Cronologia::Cronologia(){}

Cronologia::Cronologia(string nombre){
	leerFichero(nombre);
}

int Cronologia::getNumFechas() const{
	return cronologia.size();
}
 
 
void Cronologia::aniadirFecha(FechaHistorica fecha){
	if(cronologia.count(fecha.getAnio()))
		cronologia[fecha.getAnio()] = cronologia[fecha.getAnio()] + fecha;
	else
		cronologia[fecha.getAnio()] = fecha;
}


void Cronologia::leerFichero(string nombre){
	ifstream fi(nombre);
	char c;
	
	//// Bucle con centinela, actúa hasta que el fichero termine
	fi.get(c);
	while(!fi.eof()){
	
		//// Extraemos un año del flujo. Damos por hecho que toda línea empezará así
		string anioTmp;		
		while(c != '#'){
			anioTmp += c;
			fi.get(c);
		}
		FechaHistorica fechaTmp(atoi(anioTmp.c_str()));
		
		//// Bucle que lee los eventos de una fecha. Damos por hecho que, si hay una, esta tendrá eventos
		do{
			fi.get(c);
			string eventoTmp;
			
			//// Bucle que lee cada uno de los eventos, hasta encontrar algún separador
			while(c != '#' && c != '\n' && !fi.eof()){
				eventoTmp += c;
				fi.get(c);
				if(c == '\r')
					fi.get(c);
			}
			fechaTmp.aniadirEvento(eventoTmp);
		}while(c != '\n' && !fi.eof());
		aniadirFecha(fechaTmp);
		fi.get(c);
	}
	fi.close();
}

void Cronologia::escribirFichero(string nombre){
	ofstream fi(nombre);
	string contenido=this->toString();
	fi << contenido;
	fi.close();
}

void Cronologia::eliminarAnio(int anio){
	cronologia.erase(anio);
}

string Cronologia::eventosEnAnio(int anio){
	string resultado;
	
	if(cronologia.count(anio))
		resultado = cronologia[anio].toString();
	else
		resultado = "No se encontró el año";
		
	return resultado;
}


Cronologia Cronologia::periodoEntre(int inicio, int fin){
	assert(inicio <= fin);
	Cronologia resultado;

	for(int i=inicio; i <= fin; i++){
		if(cronologia.count(i))
			resultado.cronologia.insert(pair<int,FechaHistorica>(i,cronologia[i]));
	}
	
	return resultado;
}


Cronologia Cronologia::buscarPalabraClave(string palabraClave){
	Cronologia resultado;
	map<int,FechaHistorica>::iterator cit;
	set<string>::iterator fit;
	int posicion=-1;

	for(cit=cronologia.begin(); cit!=cronologia.end(); cit++){
		FechaHistorica fecha_tmp(cit->first);
		for(fit=cit->second.fecha.second.begin(); fit!=cit->second.fecha.second.end(); fit++){
			posicion=fit->find(palabraClave);
			if(posicion!=-1)
				fecha_tmp.aniadirEvento(*fit);
			posicion=-1;
		}

		if(fecha_tmp.getNumEventos()>0)
			resultado.aniadirFecha(fecha_tmp);

	}
	return resultado;
}
 
string Cronologia::toString(){
	string resultado;
	map<int,FechaHistorica>::iterator it;

	for(it = cronologia.begin(); it != cronologia.end(); it++){
		resultado += it->second.toString();
	}
		
	return resultado;
}


string Cronologia::toString() const{
	string resultado;
	map<int,FechaHistorica>::const_iterator it;

	for(it = cronologia.begin(); it != cronologia.end(); it++){
		resultado += it->second.toString();
	}
		
	return resultado;
}



Cronologia Cronologia::operator+(Cronologia &otraCronologia){
	Cronologia resultado = *this;

	map<int,FechaHistorica>::iterator it;

	for(it = otraCronologia.cronologia.begin(); it != otraCronologia.cronologia.end(); it++){
		resultado.aniadirFecha(it->second);
	}

	return resultado;
}


FechaHistorica Cronologia::operator[](int anio){
	return cronologia[anio];
}

ostream& operator<<(ostream &flujo, const Cronologia &unaCronologia){
	flujo << unaCronologia.toString();
	
	return flujo;
}

void Cronologia::recuentoEventos(){
	int num_total_eventos=0, num_fechas=0, maximo=0, promedio=0, anio_max=0;
	num_fechas=cronologia.size();
	map<int,FechaHistorica>::iterator it;

	for(it=cronologia.begin(); it!=cronologia.end(); it++){
		int aux = it->second.fecha.second.size();
		num_total_eventos+=aux;
		if(aux>maximo){
			maximo=aux;
			anio_max=it->first;
		}
	}

	promedio=num_total_eventos/num_fechas;

	cout << "Recuento eventos:" <<endl;
	cout << "Numero total de eventos: " << num_total_eventos << endl;
	cout << "Numero total de fechas: " << num_fechas << endl;
	cout << "Maximo numero eventos en una fecha: " << maximo << ", en la fecha " << anio_max << endl;
	cout << "Promedio de eventos por fechas: " << promedio << endl;

}
