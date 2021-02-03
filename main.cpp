#include <iostream>
#include <fstream>
using namespace std;

void Escribir_Archivo(string nombrearchivo);
void Leer_Archivo(string nombrearchivo);

int main() {
  string nombrearchivo;
  int opc;
  do 
  {
    cout<<"Menu\n";
    cout<<"1. Ingresar datos\n";
    cout<<"2. Mostrar datos\n";
    cout<<"3. Salir\n";
    cout<<"Ingrese el número de su opción: ";
    cin>>opc;
    cin.ignore();
    cout<<"\n";
    switch (opc)
    {
      case 1:
      cout<<"Ingrese el nombre del archivo:\n";
      getline(cin,nombrearchivo);
      Escribir_Archivo(nombrearchivo);
      break;
      case 2:
      Leer_Archivo(nombrearchivo);
      break;
      case 3:
      cout<<"Saliendo....\n";
      break;
      default:
      cout<<"Opción no válida.\n";
    }
  } while (opc!=3);  
  return 0;
}

//Función escribir en el archivo
void Escribir_Archivo(string nombrearchivo)
{
  string nombre, apellido, carrera;
  int edad;
  char r;
  ofstream archivoprueba;
  archivoprueba.open(nombrearchivo.c_str(),ios::out);
  do
  {
    cout<<"\t Ingrese el nombre:\n";
    getline(cin,nombre);
    cout<<"\t Ingrese el apellido:\n";
    getline(cin,apellido);
    cout<<"\t Ingrese la carrera:\n";
    getline(cin,carrera);
    cout<<"\t Ingrese la edad:\n";
    cin>>edad;
    archivoprueba<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea ingresar otro contacto: \n";
    cin>>r;
    cin.ignore();
  } while(r=='s');
  archivoprueba.close();
}



//Función leer el archivo
void Leer_Archivo(string nombrearchivo)
{
  string nombre, apellido, carrera;
  int edad;
  ifstream archivolectura(nombrearchivo);
  string texto;
  while (!archivolectura.eof())
  {
    archivolectura>>nombre>>apellido>>carrera>>edad;
    getline(archivolectura,texto);
    if (!archivolectura.eof())
    {
      cout<<"Nmobre: "<<nombre<<endl;
      cout<<"Apellido: "<<apellido<<endl;
      cout<<"Carrera: "<<carrera<<endl;
      cout<<"Edad: "<<edad<<endl;
    }
  }
  archivolectura.close();
}