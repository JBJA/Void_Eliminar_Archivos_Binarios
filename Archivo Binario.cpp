#include<iostream>
#include<stdio.h>
#include<string.h>
#define VALOR_CENTINELA -1

using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};

void abrir();
void ingresar();
void elimiar();
main()
{
	abrir();
	ingresar();
	elimiar();
}

void abrir(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	// condiciona si existe el archivo
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");;
	}
	
	Estudiante estudiante;
	int registro = 0;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
cout<<"___________________________________________________________"<<endl;
cout<<"id "<<"Codigo "<<"Nombres     "<<"Apellidos      "<<"Telefono"<<endl;

	// Recorrer el archivo
	do{
		cout<<"___________________________________________"<<endl;
		cout<<registro<<" | "<<estudiante.codigo<<" | "<<estudiante.nombres<<" | "<<estudiante.apellidos<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		registro+=1;
		}
	while(feof(archivo)==0);//feof=file end of file
	cout<<endl;
	fclose(archivo);
}

void ingresar(){
	char continuar;
	// crear y abrir archivo
	FILE* archivo = fopen(nombre_archivo,"ab");
	// datos del estudiante
	Estudiante estudiante;
	string nombre,apellido;
	// pregunta si desea ingresar otra informacion
	do{
		// bufer limpia 
		fflush(stdin);
		//system("cls");
		cout<<"Ingrese el Codigo: ";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese los Nombres: ";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		
		cout<<"Ingrese los Apellidos: ";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		
		cout<<"Ingrese el Telefono: ";
		cin>>estudiante.telefono;
		
		// escribe en el archivo
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
		cout<<"Desea agragar otro Nombre (s/n): ";
		cin>>continuar;
	}
	while(continuar=='s'||continuar=='S');
	fclose(archivo);
	abrir();
}

//Metodo Buscar por Indice
void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos = 0;
	cout<<"Que registros dese visualizar (id): ";
	cin>>pos;
	fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);

	Estudiante estudiante;

	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombres: "<<estudiante.nombres<<endl;
	cout<<"Apellidos: "<<estudiante.apellidos<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	fclose(archivo);
}

//Metodo Modificar
void modificar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	string nombre,apellido;
	Estudiante estudiante;
	int id = 0;
	cout<<"Que registros dese modificar (id): ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingres Nuevo Codigo: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<"Ingres Nuevo Nombres: ";
	getline(cin,nombre);
	strcpy(estudiante.nombres,nombre.c_str());
	cout<<"Ingres Nuevo Apellidos: ";
	getline(cin,apellido);
	strcpy(estudiante.apellidos,apellido.c_str());
	cout<<"Ingres Nuevo Telefono: ";
	cin>>estudiante.telefono;
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	abrir();
}

//Metodo Buscar con Codigo
void buscar_codigo(){
	FILE* archivo = fopen(nombre_archivo,"rb");	
	int	 indice=0,pos=0,cod= 0;
	cout<<"Buscar Codigo:";
	cin>>cod;
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	do{
		if (estudiante.codigo ==cod){
			pos = indice;
		}
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		indice+=1;
	} while (feof(archivo)==0);

	cout<<"_____________"<<pos<<"__________________"<<endl;
	fseek(archivo,pos * sizeof(Estudiante),SEEK_SET);
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"Codigo: "<<estudiante.codigo<<endl;
	cout<<"Nombres: "<<estudiante.nombres<<endl;
	cout<<"Apellidos: "<<estudiante.apellidos<<endl;
	cout<<"Telefono: "<<estudiante.telefono<<endl;
	fclose(archivo);	
}

void eliminar(){
	FILE*archivo=fopen(nombre_archivo, "r+b");
	int id;
	string nombre,apellido;
	Estudiante estudiante;
	
	cout<<"Igrese el id del registro que desea eliminar: ";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante), SEEK_SET);
	
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	
	fclose(archivo);
	abrir_Estudiante();
	system("pause");
}



