#include <iostream>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <vector>
#include <ctype.h>
#include <algorithm>



using namespace std;

// Structuras que se utilizarán en el programa

struct Curso {
	string codigo;
	string nombre;
};

struct Catedratico {
	string correo;
	string nombre;
};

struct Alumno {
	string carne;
	string correo;
	string nombre;
	string apellido;
};

struct Nota {
	int id;
	string carne;
	string curso;
	float test1;
	float test2;
	float zona;
	float retrasada;  
};

struct Imparte {
	int id; 
	string curso;
	string catedratico;	
};


vector<Curso> arrCurso;
vector<Catedratico> arrCatedratico;
vector<Alumno> arrAlumno;
vector<Nota> arrNota;
vector<Imparte> arrImparte;


void menu();
void menuIngreso();
void menuReportes();

// Metodos de Ingreso
void opcionesIngreso();

// Curso
void curso();
void ingresoCurso();
void buscarCurso();
void listarCurso();

//Catedráctico
void catedratico();
void ingresoCatedratico();
void buscarCatedratico();
void listarCatedratico();

//Alumno
void alumno();
void ingresoAlumno();
void buscarAlumno();
void listarAlumno();

//Asignaciones
void imparte();
void ingesoImparte();
void buscarImparte();
void listarImparte();

//Notas 
void nota();
void ingresoNota();
void buscarNota();
void listarNota();


//Obtener el index de un objeto
int getIndex(string codigo, int type, int id);

main() {
	setlocale(LC_CTYPE, "spanish");
	menu();
}

void menu(){
	int opt;
	do{
		system("cls");
		cout << "MENU PRINCIPAL" << endl;
        cout << "1. Ingreso de Datos" << endl;
        cout << "2. Reportes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción \t";
        cin >> opt;
        system("cls");
		switch(opt) {
			case 1:
				menuIngreso();
				break;
			case 2:
				menuReportes();
				break;
			case 3: 
				opt = 3;
				break;
		}
	}while(opt != 3);
}

void menuIngreso() {
	int opt;
	system("cls");
		cout << "INGRESO DE DATOS" << endl;
        cout << "1. Cursos" << endl;
        cout << "2. Catedráticos" << endl;
        cout << "3. Estudiantes" << endl;
        cout << "4. Asignaciones" << endl;
        cout << "5. Ingresar notas" << endl;
        cout << "6. Regresar" << endl;
        cout << "Seleccione una opción \t";
        cin >> opt;
        system("cls");
		switch(opt) {
			case 1:
				curso();
				getch();
				break;
			case 2:
				catedratico();
				getch();
				break;
			case 3:
				alumno(); 
				getch();
				break;
			case 4:
				imparte();
				getch();
				break;
			case 5:
				nota();
				break;
			case 6:
				menu();
				break;
		}
}

void menuReportes() {
	char opt;
	do {
		system("cls");
		cout << "REPORTES" << endl;
        cout << "1. Por Curso" << endl;
        cout << "2. Por Estudiante" << endl;
        cout << "3. Por Catedrático" << endl;
        cout << "4. General de Estudiantes con el mayor promedio por semestre" << endl;
        cout << "5. General de Estudiantes que salieron en limpio" << endl;
        cout << "6. General de Estudiantes que tienen retrasadas" << endl;
        cout << "7. Regresar" << endl;
        cout << "Seleccione una opción \t";
        cin >> opt;
        system("cls");
		switch(opt) {
			case 1:
				cout << "Hola Reporte";
				break;
			case 2:
				break;
			case 3: 
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				menu();
				break;
		}
	} while(opt != 'g');
}


void opcionesIngreso() {
		cout << "OPCIONES DE INGRESO" << endl;
		cout << "1. Agregar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Listar" << endl;
        cout << "4. Regresar" << endl;
        cout << "Seleccione una opción \t";
}

void curso() {
	int opt;
	opcionesIngreso();
	cin >> opt;
	system("cls");
	switch(opt) {
		case 1:
			ingresoCurso();
			break;
		case 2:
			buscarCurso();
			break;
		case 3:
			listarCurso();
			break;
		case 4:
			menuIngreso();
			break;
	}
}

void ingresoCurso() {
	char respuesta;
	do{
		cin.ignore();
		system("cls");
		Curso curso;
		cout << "INGRESO DE DATOS DEL CURSO" << endl;
		cout << "Ingrese el código del curso \t";
		getline(cin, curso.codigo);
		cout << "Ingrese el nombre del curso \t";
		getline(cin, curso.nombre);
		arrCurso.push_back(curso);
		system("cls");
		cout << "¿Desea agergar otro registro? (S/N) \t";
		cin >> respuesta;
	} while (toupper(respuesta) == 'S');
	system("cls");
	curso();
}
int getIndex(string codigo, int type, int id) {
	int index = -1;
	if (type == 1) {
		for(int i = 0; i < arrCurso.size(); i ++) {
			if(arrCurso[i].codigo == codigo) {
				index = i;
			}	
		}		
	} 
	
	if(type == 2) {
		for(int i = 0; i < arrCatedratico.size(); i ++) {
			if(arrCatedratico[i].correo == codigo) {
				index = i;
			}	
		}	
	}
	
	if(type == 3) {
		for(int i = 0; i < arrAlumno.size(); i ++) {
			if(arrAlumno[i].carne == codigo) {
				index = i;
			}	
		}	
	}
	
	if(type == 4) {
		for(int i = 0; i < arrImparte.size(); i ++) {
			if(arrImparte[i].id == id) {
				index = i;
			}	
		}
	}
	
	if(type == 5) {
		for(int i = 0; i < arrNota.size(); i ++) {
			if(arrNota[i].id == id) {
				index = i;
			}	
		}
	}
	
	return index;
}
void buscarCurso() {
	int index = 0;
	char opt;

		do {
			cin.ignore();
			system("cls");
			string curso;
			cout << "Ingrese el código del curso \t";
			getline(cin, curso);
			cout << "\n";
			index = getIndex(curso, 1, 0);
			if (index > -1) {
				cout << "Código del curso \t";
				cout << arrCurso[index].codigo << "\n";
				cout << "Nombre del curso \t";
				cout << arrCurso[index].nombre << "\n";
			} else {
				cout << "El elemento buscado no fue encontrado \n";	
			}
			cout << "\n"; 
			cout << "¿Desea buscar otro curso? (S/N)" << "\t";
			cin >> opt;
		}while(toupper(opt) == 'S');
		system("cls");
		curso();
}
void listarCurso() {
	
		cout << "***** LISTADO DE CURSOS ***** \n";
		for(int i = 0; i < arrCurso.size(); i ++) {
			cout << "Código del curso " << i + 1 << "\t";
			cout << arrCurso[i].codigo << endl;
			cout << "Nombre del curso " << i + 1 << "\t";
			cout << arrCurso[i].nombre << endl;
			cout << "\n";
		}
	
	
	cout << "\n";
	getch();
	system("cls");
	curso();
}

void catedratico() {
	int opt;
	opcionesIngreso();
	cin >> opt;
	switch(opt) {
		case 1:
			ingresoCatedratico();
			break;
		case 2:
			buscarCatedratico(); 
			break;
		case 3:
			listarCatedratico();
			break;
		case 4:
			menuIngreso();
			break;
	}
}
void ingresoCatedratico(){
char respuesta;
	do{
		cin.ignore();
		system("cls");
		Catedratico prof;
		cout << "INGRESO DE DATOS DEL CATEDRÁTICO" << endl;
		cout << "Ingrese el correo del catedrático \t";
		getline(cin, prof.correo);
		cout << "Ingrese el nombre del catedrático \t";
		getline(cin, prof.nombre);
		arrCatedratico.push_back(prof);
		system("cls");
		cout << "¿Desea agergar otro registro? (S/N) \t";
		cin >> respuesta;
	} while (toupper(respuesta) == 'S');
	system("cls");
	catedratico();
	} 
void buscarCatedratico(){
	int index = 0;
	char opt;

		do {
			cin.ignore();
			system("cls");
			string correo;
			cout << "Ingrese el correo del catedrático \t";
			getline(cin, correo);
			cout << "\n";
			index = getIndex(correo, 2, 0);
			if (index > -1) {
				cout << "Correo del catedrático \t";
				cout << arrCatedratico[index].correo << "\n";
				cout << "Nombre del catedrático \t";
				cout << arrCatedratico[index].nombre << "\n";
			} else {
				cout << "El elemento buscado no fue encontrado \n";	
			}
			cout << "\n"; 
			cout << "¿Desea buscar otro catedrático? (S/N)" << "\t";
			cin >> opt;
		}while(toupper(opt) == 'S');
		system("cls");
		catedratico();
}
void listarCatedratico(){
	system("cls");
	cout << "***** LISTADO DE CATEDRÁTICOS ***** \n";
	for(int i = 0; i < arrCatedratico.size(); i ++) {
		cout << "Correo del catedrático " << i + 1 << "\t";
		cout << arrCatedratico[i].correo << endl;
		cout << "Nombre del catedrático " << i + 1 << "\t";
		cout << arrCatedratico[i].nombre << endl;
		cout << "\n";
	}
	
	cout << "\n";
	getch();
	system("cls");
	catedratico();
}

void alumno() {
	int opt;
	opcionesIngreso();
	cin >> opt;
	switch(opt) {
		case 1:
			ingresoAlumno();
			break;
		case 2:
			buscarAlumno(); 
			break;
		case 3:
			listarAlumno();
			break;
		case 4:
			menuIngreso();
			break;
	}
}
void ingresoAlumno(){
char respuesta;
	do{
		cin.ignore();
		system("cls");
		Alumno alumno;
		cout << "INGRESO DE DATOS DEL ALUMNO" << endl;
		cout << "Ingrese el carne del alumno \t";
		getline(cin, alumno.carne);
		cout << "Ingrese el correo del alumno \t";
		getline(cin, alumno.correo);
		cout << "Ingrese el nombre del alumno \t";
		getline(cin, alumno.nombre);
		cout << "Ingrese el apellido del alumno \t";
		getline(cin, alumno.apellido);
		arrAlumno.push_back(alumno);
		system("cls");
		cout << "¿Desea agergar otro registro? (S/N) \t";
		cin >> respuesta;
	} while (toupper(respuesta) == 'S');
	system("cls");
	alumno();
}

void buscarAlumno(){
	int index = 0;
	char opt;

		do {
			cin.ignore();
			system("cls");
			string carnet;
			cout << "Ingrese el carnet del alumno \t";
			getline(cin, carnet);
			cout << "\n";
			index = getIndex(carnet, 3, 0);
			if (index > -1) {
				cout << "Carnet del alumno \t";
				cout << arrAlumno[index].carne << "\n";
				cout << "Correo del alumno \t";
				cout << arrAlumno[index].correo << "\n";
				cout << "Nombre del alumno \t";
				cout << arrAlumno[index].nombre << "\n";
				cout << "Apellido del alumno \t";
				cout << arrAlumno[index].apellido << "\n";
			} else {
				cout << "El elemento buscado no fue encontrado \n";	
			}
			cout << "\n"; 
			cout << "¿Desea buscar otro alumno? (S/N)" << "\t";
			cin >> opt;
		}while(toupper(opt) == 'S');
		system("cls");
		alumno();
}
void listarAlumno(){
	system("cls");
	cout << "***** LISTADO DE ALUMNOS ***** \n";
	for(int i = 0; i < arrAlumno.size(); i ++) {
		cout << "Carnet del alumno \t";
		cout << arrAlumno[i].carne << "\n";
		cout << "Correo del alumno \t";
		cout << arrAlumno[i].correo << "\n";
		cout << "Nombre del alumno \t";
		cout << arrAlumno[i].nombre << "\n";
		cout << "Apellido del alumno \t";
		cout << arrAlumno[i].apellido << "\n";
		cout << "\n";
	}
	
	cout << "\n";
	getch();
	system("cls");
	alumno();
}	
	
void imparte() {
	int opt;
	opcionesIngreso();
	cin >> opt;
	switch(opt) {
		case 1:
			ingesoImparte();
			break;
		case 2:
			buscarImparte(); 
			break;
		case 3:
			listarImparte();
			break;
		case 4:
			menuIngreso();
			break;
	}
}
void ingesoImparte(){
	char respuesta;
	int index = 0;
	int indexCurso = 0;
	int indexIng = 0;
	do{
		cin.ignore();
		system("cls");
		Imparte imparte;
		cout << "INGRESO DE DATOS DE ASIGNACION DE CURSO" << endl;
		cout << "Ingrese el codigo del curso \t";
		getline(cin, imparte.curso);
		cout << "Ingrese el correo del catedrático \t";
		getline(cin, imparte.catedratico);
		
		indexCurso = getIndex(imparte.curso, 1, 0);
		indexIng = getIndex(imparte.catedratico, 2, 0);
		
		if(indexCurso < 0) {
			respuesta = 'n';
		}
		
		if(indexIng < 0) {
			respuesta = 'n';
		}
		
		if(indexCurso >= 0 && indexIng >= 0) {
			arrImparte.push_back(imparte);
			int size = arrImparte.size();
			arrImparte[size - 1].id = size; 
			system("cls");
			cout << "¿Desea agergar otro registro? (S/N) \t";
			cin >> respuesta;
		}
		
	} while (toupper(respuesta) == 'S');
	
	if(indexCurso < 0) {
		system("cls");
		cout << "****************** ERROR ******************* \n";
		cout << "Debe de crear el curso antes de asignarlo \n";
		getch();
	}
		
	if(indexIng < 0) {
		system("cls");
		cout << "****************** ERROR ******************* \n";
		cout << "Debe de crear el catedrático antes de asignarlo \n";
		getch();
	}
	
	system("cls");
	imparte();
}

void buscarImparte(){
	int index = 0;
	char opt;
		do{
			cin.ignore();
			system("cls");
			int id;
			cout << "Ingrese el id de la asignación \t";
			cin >> id;
			cout << "\n";
			index = getIndex("", 4, id);
			if (index > -1) {
				cout << "Código \t";
				cout << arrImparte[index].id << "\n";
				cout << "Código del curso \t";
				cout << arrImparte[index].curso << "\n";
				cout << "Correo del catedrático \t";
				cout << arrImparte[index].catedratico << "\n";
				cout << "\n";
			} else {
				cout << "El elemento buscado no fue encontrado \n";
			}
			cout << "\n";
			cout << "¿Desea buscar otra asignacion? (S/N)" << "\t";
			cin >> opt;
		} while(toupper(opt) == 'S');
		system("cls");
		imparte();
}
void listarImparte(){
	system("cls");
	cout << "***** LISTADO DE ASIGNACIONES ***** \n";
	for(int i = 0; i < arrImparte.size(); i ++) {
		cout << "Código \t";
		cout << arrImparte[i].id << "\n";
		cout << "Código del curso \t";
		cout << arrImparte[i].curso << "\n";
		cout << "Correo del catedrático \t";
		cout << arrImparte[i].catedratico << "\n";
		cout << "\n";
	}
	
	cout << "\n";
	getch();
	system("cls");
	imparte();
}

void nota() {
	int opt;
	opcionesIngreso();
	cin >> opt;
	switch(opt) {
		case 1:
			ingresoNota();
			break;
		case 2:
			buscarNota(); 
			break;
		case 3:
			listarNota();
			break;
		case 4:
			menuIngreso();
			break;
	}
}
void ingresoNota(){
	char respuesta;
	int index = 0;
	int indexAlumno = 0;
	int indexCurso = 0;
	do{
		cin.ignore();
		system("cls");
		Nota nota;
		cout << "INGRESO DE DATOS DE LA NOTA" << endl;
		cout << "Ingrese el carnet del alumno \t";
		getline(cin, nota.carne);
		cout << "Ingrese el código del curso \t";
		getline(cin, nota.curso);
		cout << "Ingrese la nota del primer parcial \t";
		cin >> nota.test1;
		cout << "Ingrese la nota del segundo parcial \t";
		cin >> nota.test2;
		cout << "Ingrese la nota de las tareas entregadas \t";
		cin >> nota.zona;
		indexAlumno = getIndex(nota.carne, 3, 0);
		indexCurso = getIndex(nota.curso, 1, 0);
		
		if(indexAlumno < 0) {
			respuesta = 'n';
		}
		
		if(indexCurso < 0) { 
			respuesta = 'n';
		}
		
		if(indexAlumno >= 0 && indexCurso >=0) {
			arrNota.push_back(nota);
			nota.retrasada = (nota.test1 + nota.test2 + nota.zona) / 3;
			int size = arrNota.size();
			arrNota[size - 1].id = size; 
			system("cls");
			cout << arrNota.size() << endl;
			cout << "¿Desea agergar otro registro? (S/N) \t";
			cin >> respuesta;
		}
	} while (toupper(respuesta) == 'S');
	if(indexAlumno < 0) {
		system("cls");
		cout << "******************* ERROR ******************** \n";
		cout << "Debe de crear el alumno antes de ingresarlo \n";
		getch();
	}
	if(indexCurso < 0) {
		system("cls");
		cout << "******************* ERROR ******************** \n";
		cout << "Debe de crear el curso antes de ingresarlo\t";
		getch();
	}
	system("cls");
	nota();
}

void buscarNota(){
	int index = 0;
	char opt;
		do{
			cin.ignore();
			system("cls");
			int id;
			cout << "Ingrese el id de la nota \t";
			cin >> id;
			cout << "\n";
			index = getIndex("", 5, id);
			if (index > -1) {
			cout << "Código \t";
				cout << arrNota[index].id << "\n";
				cout << "Código del curso \t";
				cout << arrNota[index].carne << "\n";
				cout << "Carnet del estudiante \t";
				cout << arrNota[index].carne << "\n";
				cout << "Código del curso \t";
				cout << arrNota[index].curso << "\n";
				cout << "Nota Parcial 1 \t";
				cout << arrNota[index].test1 << "\n";
				cout << "Nota Parcial 2 \t";
				cout << arrNota[index].test2 << "\n";
				cout << "Nota Zona Trabajos \t";
				cout << arrNota[index].zona << "\n";
				cout << "Promedio \t";
				cout << arrNota[index].retrasada << "\n";
				cout << "\n";
			} else {
				cout << "El elemento buscado no fue encontrado \n";
			}
			cout << "\n";
			cout << "¿Desea buscar otra nota? (S/N)" << "\t";
			cin >> opt;
		} while(toupper(opt) == 'S');
		system("cls");
		nota();
}

void listarNota(){
	system("cls");
	cout << "***** LISTADO DE NOTAS ***** \n";
	for(int i = 0; i < arrNota.size(); i ++) {
		cout << "Código \t";
				cout << arrNota[i].id << "\n";
				cout << "Código del curso \t";
				cout << arrNota[i].carne << "\n";
				cout << "Carnet del estudiante \t";
				cout << arrNota[i].carne << "\n";
				cout << "Código del curso \t";
				cout << arrNota[i].curso << "\n";
				cout << "Nota Parcial 1 \t";
				cout << arrNota[i].test1 << "\n";
				cout << "Nota Parcial 2 \t";
				cout << arrNota[i].test2 << "\n";
				cout << "Nota Zona Trabajos \t";
				cout << arrNota[i].zona << "\n";
				cout << "Promedio \t";
				cout << arrNota[i].retrasada << "\n";
		cout << "\n";
	}
	
	cout << "\n";
	getch();
	system("cls");
	nota();
}

