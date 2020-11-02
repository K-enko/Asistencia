#ifndef HEADER_H
#define HEADER_H

struct Alumno
{
	string nombres;
	string apellido;
	int dni;
	int asistencia[50];
};

void cargar_alumnos(struct Alumno *puntAlumno, int *p1, int *p2);
// Ingresa los datos guardados en el txt dentro del arreglo

void cambiar_clase(int *p1);
// Pide el numero de clase

void ingresar_alumno(struct Alumno *puntAlumno, int *p1);
// Guarda un nuevo alumno en el txt

void mostrar_alumnos(struct Alumno *puntAlumno, int *p1, int *p2);
// Muestra todos los alumnos del arreglo

void ingresar_asistencia(struct Alumno *puntAlumno, int *p1, int *p2);
// Pide la informacion de un alumno y le asigna el valor 1 de presente

#endif