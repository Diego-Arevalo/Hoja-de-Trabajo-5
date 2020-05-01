/*Hoja de Trabajo # 5.2
Una persona desea comprar entradas para un concierto que se realizará en la explanada de cierto lugar de la ciudad.*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct reg{
	int		zona;
	int 	socio;
	string 	dato;
	int 	entradas;
	float	precio;	};

float 	tzona1;
float 	tzona2;
float 	tzona3;
float	tprecio;
int		tentradas;

int operacion;	//variable
void calculo();	//Funcion01
void reporte();	//Funcion02

int main(){
	do{
	cout<<"--------------------------------------------"<<endl;	
	cout<<"Bienvenido, que accion desea realizar ?"<<endl<<endl;
	cout<<"1. Generar calculo y grabar datos"<<endl<<"2. informes"<<endl<<"3.salir"<<endl<<endl;
	cout<<"--------------------------------------------"<<endl;	
	cin>>operacion;
 	if (operacion==1){
 		system("CLS");
		calculo();	};
 	if (operacion==2){
 		system("CLS");
		reporte();	};
 } 	while (operacion!=3);
 	return (0);				}

/*solicite la zona elegida, el número de entradas a comprar
y consulte si es socio o no y nos determine y muestre el monto
 a pagar por la compra de las entradas. y GRABAR */
void calculo(){
	int		zzona;
	int 	zsocio;
	int 	zdescuento;
	int 	zentradas;
	float	zprecio;
	
	cout<<"--------------------------------------------"<<endl;
	cout <<"Ingrese ZONA de Preferencia"<<"\n"<<"1. VIP\n2.Platea\n3.Popular"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zzona;
	cout<<"--------------------------------------------"<<endl;
	cout <<"Es usted un SOCIO nuestro?\n1. SI\n2.NO"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zsocio;
	cout<<"--------------------------------------------"<<endl;
	cout <<"Cuantas Entradas Comprara?"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zentradas;
	cout<<"--------------------------------------------"<<endl;

if (zzona==1){
	zprecio=(350.00*zentradas);
	if (zentradas>=3 and zentradas<=6){
		zprecio=(zprecio-((zprecio*5)/100));}
	if (zentradas>=7 and zentradas<=9){
		zprecio=(zprecio-((zprecio*7.5)/100));}
	if (zentradas>9){
		zprecio=(zprecio-((zprecio*10)/100));}	}
if (zzona==2){
	zprecio=(130.00*zentradas);
	if (zentradas>=3 and zentradas<=6){
		zprecio=(zprecio-((zprecio*5)/100));}
	if (zentradas>=7 and zentradas<=9){
		zprecio=(zprecio-((zprecio*7.5)/100));}
	if (zentradas>9){
		zprecio=(zprecio-((zprecio*10)/100));}	}	   
if (zzona==3){
	zprecio=(50.00*zentradas);
	if (zentradas>=3 and zentradas<=6){
		zprecio=(zprecio-((zprecio*5)/100));}
	if (zentradas>=7 and zentradas<=9){
		zprecio=(zprecio-((zprecio*7.5)/100));}
	if (zentradas>9){
		zprecio=(zprecio-((zprecio*10)/100));}	}	   

if (zsocio==1){
	zprecio=(zprecio-((zprecio*8)/100));}	  	 

cout<<"Total: Q. "<<zprecio<<endl;	
	
	
//GRABAR---------------------------------------------------------------------------------
ofstream grabararchivo;
	try {
		grabararchivo.open("Hoja de trabajo #5.2.txt",ios::app);
		grabararchivo<<zzona<<"\t"<<zprecio<<"\t"<<zentradas<<"\t"<<zsocio<<endl;
		grabararchivo.close();		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	}	
}

void reporte(){
/*el programa de ser capaz de mostrar el monto total de lo vendido
 globalmente y por tipo de entrada, mostrando también el porcentaje 
 respecto al total global vendido. */

	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("Hoja de trabajo #5.2.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" No se pudo abrir el archivo";
		exit(1);	}
	
	string	base="Hoja de trabajo #5.2.txt";
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
    archivo.close();
   /*----------------------------------------------------------------
   ----------------------------------------------------------------------*/ 
    reg recordset[lineas];
	archivo.open(base.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);	}	
	
	for (int i = 0; i < lineas; i++) {
        if (!archivo) {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
            break; }

	archivo>>recordset[i].zona>>recordset[i].precio>>recordset[i].entradas>>recordset[i].socio;	}
    archivo.close();
       /*----------------------------------------------------------------
   ----------------------------------------------------------------------*/ 
    cout<<"Zona"<<"\t"<<"Afiliado"<<"\t"<<"Entradas"<<"\t"<<"Total pagado"<<endl;
 	
    for (int i = 0; i < lineas; i++){
    if (recordset[i].socio==1){
   	recordset[i].dato="SI";    }
    if (recordset[i].socio==2){
   	recordset[i].dato="NO";    }  
    	cout<<recordset[i].zona<<"\t"<<recordset[i].dato<<"\t\t"<<recordset[i].entradas<<"\t\t$."<<recordset[i].precio<<endl;
		tprecio=(recordset[i].precio+tprecio);
		if (recordset[i].zona==1){
			tzona1=(recordset[i].precio+tzona1)	;	}
		else if (recordset[i].zona==2){
			tzona2=(recordset[i].precio+tzona2)	;	}
		else if (recordset[i].zona==3){
			tzona3=(recordset[i].precio+tzona3)	;	}				
		}
		cout<<"--------------------------------------------"<<endl;	
		cout<<"Total Venta VIP (V)"<<"\tQ."<<tzona1<<"\t%"<<((tzona1*100)/tprecio)<<endl;
		cout<<"Total Venta PLATEA (P)"<<"\tQ."<<tzona2<<"\t%"<<((tzona2*100)/tprecio)<<endl;
		cout<<"Total Venta POPULAR (E)"<<"\tQ."<<tzona3<<"\t%"<<((tzona3*100)/tprecio)<<endl<<endl;
		cout<<"Total Global de ventas"<<"\tQ."<<tprecio<<"\t"<<"100%"<<endl;			
		cout<<"--------------------------------------------"<<endl;		
	
	system("Pause");}
