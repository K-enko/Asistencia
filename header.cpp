#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "header.h"

void cargar_alumnos(struct Alumno *puntAlumno, int *p1, int *p2)
{
	int aux;
	(*p1) = 0;
	
	ifstream imp_file;
	imp_file.open("Alumnos.txt", ios::in);
	if(imp_file.is_open())
	{
		while(!imp_file.eof())
		{
			getline(imp_file, puntAlumno[*p1].nombres);
			getline(imp_file, puntAlumno[*p1].apellido);
			imp_file >> puntAlumno[*p1].dni;
			imp_file.ignore();

			if( (!puntAlumno[*p1].nombres.empty()) && (!puntAlumno[*p1].apellido.empty()) )
			{
				(*p1)++;
			}
		}
	}
	imp_file.close();

	ifstream imp2_file;
	imp2_file.open("Asistencia.txt", ios::in);
	if(imp2_file.is_open())
	{
		while(!imp2_file.eof())
		{
			for(int i=0 ; i<(*p1) ; i++)
			{
				for(int j=0 ; j<=(*p2); j++)
				{
					imp2_file >> puntAlumno[i].asistencia[j];
				}
			}
		}
	}
	imp2_file.close();
}

void cambiar_clase(int *p1)
{
	cout << "Digite el numero de la clase: ";
	cin >> *p1;
	cout << endl;
}

void ingresar_alumno(struct Alumno *puntAlumno, int *p1)
{
	cout << "Ingrese el nombre/s del alumno: ";
	getline(cin, puntAlumno[*p1].nombres);
	cout << endl;
	cout << "Ingrese el apellido/s: ";
	getline(cin, puntAlumno[*p1].apellido);
	cout << endl;
	cout << "Ingrese el DNI: ";
	cin >> puntAlumno[*p1].dni;
	cout << endl;

	ofstream oup_file;
	oup_file.open("Alumnos.txt", ios::app);
	if(oup_file.is_open())
	{
		oup_file << puntAlumno[*p1].nombres << endl;
		oup_file << puntAlumno[*p1].apellido << endl;
		oup_file << puntAlumno[*p1].dni << endl;
	}
	oup_file.close();

	(*p1)++;
}

void mostrar_alumnos(struct Alumno *puntAlumno, int *p1, int *p2)
{
	cout << endl;
	for(int i=0; i<(*p1) ; i++)
	{
		cout << puntAlumno[i].nombres << " " << puntAlumno[i].apellido << endl;
		cout << puntAlumno[i].dni << endl;
		for(int j=0 ; j<=(*p2) ; j++)
		{
			cout << puntAlumno[i].asistencia[j];
			if(j+1<(*p2))
			{
				cout << " - ";
			}
		}
		cout << endl;
		cout << endl;
	}
	cout << endl;
}

void ingresar_asistencia(struct Alumno *puntAlumno, int *p1, int *p2)
{
	string nomAux;
	string apeAux;
	int dniAux;
	int pos=0;

	cout << "Ingrese su nombres/s: ";
	getline(cin, nomAux);
	cout << "Ingrese su apellido/s: ";
	getline(cin, apeAux);
	cout << "Ingrese su DNI: ";
	cin >> dniAux;
	cin.ignore();

	while(((nomAux != puntAlumno[pos].nombres) || (apeAux != puntAlumno[pos].apellido) || (dniAux != puntAlumno[pos].dni)) && (pos<(*p1)))
	{
		pos++;
	}
	if((nomAux == puntAlumno[pos].nombres) && (apeAux == puntAlumno[pos].apellido) && (dniAux == puntAlumno[pos].dni))
	{
		puntAlumno[pos].asistencia[*p2] = 1;

		ofstream oup_file;
	    oup_file.open("Asistencia.txt", ios::out);
	    if(oup_file.is_open())
	    {
	    	for(int i=0; i<(*p1) ; i++)
	    	{
	    		for(int j=0 ; j<=(*p2) ; j++)
	    		{
	    			oup_file << puntAlumno[i].asistencia[j] << " ";
	    		}
	    		oup_file << endl;
	    	}

	    	oup_file << endl;
	    }
	    oup_file.close();
	}
	else
	{
		cout << "No se encontro el alumno en la lista." << endl;
		cout << endl;
	}
}