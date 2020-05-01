/*Hoja de Trabajo # 5.1
Realice un programa que genere la venta de compra de un terreno/casa/departamento*/
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct reg{
	int		categoria;
	int 	zona;
	int 	tipo;
	int 	area;
	float	precio;	};

float 	tcategoria;
float 	tcategoria2;
		float	tzona;
		float	tzona2;
		float	tzona3;
				float 	ttipo;
				float	ttipo2;
				float	ttipo3;
							   	  float	tprecio;
int operacion;	//variable
void calculo();	//Funcion01
void reporte();	//Funcion02

int main(){
	do{
	cout<<"--------------------------------------------"<<endl;	
	cout<<"Bienvenido, que accion desea realizar ?"<<endl<<endl;
	cout<<"1. Generar calculo y grabar"<<endl<<"2. informes"<<endl<<"3.salir"<<endl<<endl;
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

/*Dada la categoría, zona, tipo y el área del terreno o inmueble
 determine a cuánto asciende el monto que deberá pagar para comprar el inmueble */
void calculo(){
	int 	zcategoria;
	int 	zzona;
	int 	ztipo;
	int 	zarea;
	float	zprecio;
	
	cout<<"--------------------------------------------"<<endl;
	cout <<"Ingrese CATEGORIA correspondiente"<<"\n"<<"1. Comercial\n2.Residencial"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zcategoria;
	cout<<"--------------------------------------------"<<endl;
	cout <<"Ingrese ZONA "<<"\n"<<"1. A\n2.B\n3.C"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zzona;
	cout<<"--------------------------------------------"<<endl;
	cout <<"Ingrese TIPO "<<"\n"<<"1. Terreno\n2.Casa\n3.Departamento"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>ztipo;
	cout<<"--------------------------------------------"<<endl;
	cout <<"Ingrese AREA en mts2 "<<endl;
	cout<<"--------------------------------------------"<<endl;
	cin>>zarea;
	if (zcategoria==1 and zzona==3){
		cout<<"--------------------------------------------"<<endl;
		cout<<"Zona no Disponible en categoria seleccionada"<<endl;
		cout<<"--------------------------------------------"<<endl;
		system("Pause");	}
	
	if (zcategoria==1){
		if(zzona==1){
			if(ztipo==1){
		 		zprecio=zarea*2200	;}
			if(ztipo==2){
		 		zprecio=zarea*2500	;}
			if(ztipo==3){
		 		zprecio=zarea*2100	;}	}
		if(zzona==2){
			if(ztipo==1){
		 		zprecio=zarea*1300	;}
			if(ztipo==2){
		 		zprecio=zarea*1500	;}
			if(ztipo==3){
		 		zprecio=zarea*1200	;}	} 	}	
	if (zcategoria==2){
		if(zzona==1){
			if(ztipo==1){
		 		zprecio=zarea*2100	;}
			if(ztipo==2){
		 		zprecio=zarea*2500	;}
			if(ztipo==3){
		 		zprecio=zarea*2100	;}	}
		if(zzona==2){
			if(ztipo==1){
		 		zprecio=zarea*1500	;}
			if(ztipo==2){
		 		zprecio=zarea*1600	;}
			if(ztipo==3){
		 		zprecio=zarea*1300	;}	} 	
		if(zzona==3){
			if(ztipo==1){
		 		zprecio=zarea*1100	;}
			if(ztipo==2){
		 		zprecio=zarea*1300	;}
			if(ztipo==3){
		 		zprecio=zarea*1000	;}	} 	}	

	cout<<"Total: $. "<<zprecio<<endl;	
	
	
//GRABAR---------------------------------------------------------------------------------
ofstream grabararchivo;
	try {
		grabararchivo.open("Hoja de trabajo #5.1.txt",ios::app);
		grabararchivo<<zcategoria<<"\t"<<zzona<<"\t"<<ztipo<<"\t"<<zprecio<<"\t"<<zarea<<endl;
		grabararchivo.close();		}
	catch(exception X){
		cout<<"Error en el manejo del archivo"<<endl;	}	}


void reporte(){
/*generar un reporte de el total vendido 
por categoría, zona y tipo de inmueble*/

	ifstream archivo; //leer archivo;
	fflush(stdin); //borrar el buffer existente
	archivo.open("Hoja de trabajo #5.1.txt",ios::in); //append
	if(archivo.fail()){
		cout<<" No se pudo abrir el archivo";
		exit(1);	}
	
	string	base="Hoja de trabajo #5.1.txt";
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
	archivo>>recordset[i].categoria>>recordset[i].zona>>recordset[i].tipo>>recordset[i].precio>>recordset[i].area;	}
    archivo.close();
       /*----------------------------------------------------------------
   ----------------------------------------------------------------------*/ 
    cout<<"Cat"<<"\t"<<"Zona"<<"\t"<<"Tipo"<<"\t"<<"Precio"<<"\t"<<"En base al AREA de:"<<endl;
    for (int i = 0; i < lineas; i++){
    	cout<<recordset[i].categoria<<"\t"<<recordset[i].zona<<"\t"<<recordset[i].tipo<<"\t$."<<recordset[i].precio<<"\t<>"<<recordset[i].area<<endl;
		if (recordset[i].categoria==1){
			tcategoria=(recordset[i].precio+tcategoria);}
		if (recordset[i].categoria==2){
			tcategoria2=(recordset[i].precio+tcategoria2);}
		if (recordset[i].zona==1){
			tzona=(recordset[i].precio+tzona);}
		if (recordset[i].zona==2){
			tzona2=(recordset[i].precio+tzona2);}
		if (recordset[i].zona==3){
			tzona3=(recordset[i].precio+tzona3);}
		if (recordset[i].tipo==1){
			ttipo=(recordset[i].precio+ttipo);}
		if (recordset[i].tipo==2){
			ttipo2=(recordset[i].precio+ttipo2);}
		if (recordset[i].tipo==3){
			ttipo3=(recordset[i].precio+ttipo3);}
		tprecio=(recordset[i].precio+tprecio);
		}
		cout<<"--------------------------------------------"<<endl;	
		cout<<"Total CAT Comercial"<<"\t$."<<tcategoria<<endl;
		cout<<"Total CAT Residencial"<<"\t$."<<tcategoria2<<endl;
		cout<<"Total ZONA A"<<"\t\t$."<<tzona<<endl;
		cout<<"Total ZONA B"<<"\t\t$."<<tzona2<<endl;	
		cout<<"Total ZONA C"<<"\t\t$."<<tzona3<<endl;	
		cout<<"Total TIPO TERRENO"<<"\t$."<<ttipo<<endl;
		cout<<"Total TIPO CASA"<<"\t\t$."<<ttipo2<<endl;	
		cout<<"Total TIPO DEPTO"<<"\t$."<<ttipo3<<endl;
		cout<<"\tTotal de VENTAS"<<"\t\t$."<<tprecio<<endl;	
		
	system("Pause");}
