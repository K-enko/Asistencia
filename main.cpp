#include <iostream>
using namespace std;

#include "header.h"

int main()
{
	int menu;
	int clasenum = 0;

	const int N = 30;
	Alumno *puntAlumno = new Alumno[N];
	int contAlumno = 0;

	do
	{
		cargar_alumnos(puntAlumno, &contAlumno, &clasenum);

		cout << "Num. de clase: " << clasenum << endl;
		cout << endl;
		cout << "1. Cambiar numero de clase." << endl;
		cout << "2. Ingresar alumno." << endl;
		cout << "3. Ver alumnos." << endl;
		cout << "4. Ingresar asistencia." << endl;
		cout << endl;
		cout << "0. Salir." << endl;
		cout << endl;
		cout << "-> ";
		cin >> menu;
		cin.ignore();

		switch(menu)
		{
			case 1:

			cambiar_clase(&clasenum);

			break;
			case 2:

			ingresar_alumno(puntAlumno, &contAlumno);

			break;
			case 3:

			mostrar_alumnos(puntAlumno, &contAlumno, &clasenum);

			break;
			case 4:

			ingresar_asistencia(puntAlumno, &contAlumno, &clasenum);

			break;
			case 0:

			cout << "El programa se esta cerrando..." << endl;
			cin.get();
			delete [] puntAlumno;

			break;
			default:

			cout << "No ingreso un valor valido para el programa, Vuelva a intentar." << endl;
			cout << endl;
		}
	}while(menu != 0);

	return 0;
}