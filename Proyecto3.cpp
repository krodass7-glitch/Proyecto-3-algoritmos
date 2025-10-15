//Este programa agrega, busca y modifica un producto por medio de un archivo .tex
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

typedef struct 
{
    string code;
    string name;
    double price;
    string supplier;
    int existence;
    char status;
    float discount;

} products;

int main()
{

products products;
string search;
int opcion;

    do
    {
    cout<<"=====================Menu=====================\n\n";
    cout<<"1. Agregar Producto\n";
    cout<<"2. Buscar Producto\n";
    cout<<"3. Modificar Producto\n";
    cout<<"4. Salir\n";
    cin>>opcion;
    cin.ignore();

    switch (opcion)

    {
    case 1:{
        
        cout<<"==========Agregar Producto==========\n";
        cout<<"Ingresa el Código:\n";
        getline(cin,products.code);
        cout<<"Ingrese el Nombre del producto:\n";
        getline(cin,products.name);
        cout<<"Ingrese el Precio: \n";
        cin>> products.price;
        cin.ignore();
        cout<<"Ingrese el Proveedor:\n";
        getline(cin,products.supplier);
        cout<<"Ingrese las Existencias:\n";
        cin>> products.existence;
        cin.ignore();
        cout<<"Ingrese el estado (A/N):\n";
        cin>> products.status;
        cin.ignore();
        cout<<"Ingrese el Descuento:\n";
        cin>> products.discount;
        cin.ignore();

        ofstream archivo("Products.txt",ios::app);        
        
        archivo<<products.code<<" "<<products.name<<" "<<products.price<<" "<<products.supplier<<" "<<products.existence<<" "<<products.status<<" "<<products.discount<<"\n";
        archivo.close();

        cout<<"Producto guardado Correctamente.\n";

        break;
        
    }
    
    case 2:{
        
        cout<<"==========Busquedad de un Producto==========\n\n";
        cout<<"Ingrese el Codigo o Nombre del producto a buscar: \n";
        getline(cin,search);

        ifstream archivo("Products.txt");
        bool encontrado = false;

        while (archivo>>products.code>>products.name>>products.price>>products.supplier>>products.existence>>products.status>>products.discount)
        {
            if (products.code == search||products.name == search )
            {
                cout<<"Producto Encontrado con Exito\n";
                cout<<"Codigo: "<<products.code<<endl;
                cout<<"Nombre: "<<products.name<<endl;
                cout<<"Precio : Q "<<products.price<<endl;
                cout<<"Proveedor :"<<products.supplier<<endl;
                cout<<"Existencia :"<<products.existence<<endl;
                cout<<"Descuento :"<<products.discount<<"%"<<endl;
                encontrado =true;

            }
            
        }
         if (!encontrado)
         {
            cout<<"Pueda ser que el Producto no a sido registrado\n";
         }
         
         archivo.close();

        break;
    
    }
    case 3:{
        
        cout<<"Modificar los datos de un producto\n\n";
        cout<<"Ingrese el codigo del producto a modificar: \n";
        getline(cin,search);

        ifstream archivo("Products.txt");
        ofstream modificar("Modificarproducts.txt");
        bool modificado = false;

        while (archivo>>products.code>>products.name>>products.price>>products.supplier>>products.existence>>products.status>>products.discount)
        {
            if (products.code == search)
            {
                cout<<"Producto Encontrado con Exito\n";
                cout<<"Codigo: "<<products.code<<endl;
                cout<<"Nombre actual: "<<products.name<<"\n\n";
                cout<<"Ingrese los nuevos datos: \n";
                cout<<"Nuevo Nombre: ";
                getline(cin,products.name);
                cout<<"Nuevo Precio: ";
                cin>> products.price;
                cin.ignore();
                cout<<"Nuevo Proveedor: ";
                getline(cin,products.supplier);
                cout<<"Nueva Existencia: ";
                cin>> products.existence;
                cin.ignore();
                cout<<"Nuevo Estado: ";
                cin>> products.status;
                cin.ignore();
                cout<<"Nuevo Descuento: ";
                cin>> products.discount;
                cin.ignore();
                modificado=true;

            }

            modificar << products.code<<" "<<products.name<<" "<<products.price<<" "<<products.supplier<<" "<<products.existence<<" "<<products.status<<" "<<products.discount<<endl;
            
        }
        
        archivo.close();
        modificar.close();
        remove("Products.txt");
        rename("Modificarproducts.txt","Products.txt");

        if (modificado)
        {
            cout<<"Producto Modificado Correctamente.\n";
        }

            cout<<"No se encontro el Producto\n";

    
        break;
    }
    case 4:
        
        cout<<"======Saliendo del Programa======\n";
        system("cls");
        return 0;

    
    default:

        cout<<"Opción Invalida. Intente de nuveo\n";

        break;

    }


    } while (opcion!=4);
    
    
return 0;



}