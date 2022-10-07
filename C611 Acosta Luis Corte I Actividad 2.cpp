 /******************************************************************************
 autor -> Luis Acosta
 Carrera -> Ing. Informatica
 seccion : C611
 *******************************************************************************/

 // Libreria
#include <iostream>
#include <time.h>
#include <stdlib.h>

 // Final de librerias

using namespace std; // Facilidad para hacer el codigo

int main()
{
	
// Variables

	// numeros aleatorios de estudiantes
	int cantidad = 0; // Numero aleatorio del los estudiantes
	// final de numeros aleatorios de estudiantes
	
	// notas aleatorias
	int notas = 0;
	// final de notas aleatorias
	
	//datos si aprobo o no
	int dato = 0;
	
	
	// aprobados o no aprobados
	int aprobados = 0; // aprobados
	int reprobados = 0; // no aprobados
	// final aprobados o no aprobados

// Final Varibles
	

		// Presentacion Del programa
	    cout << "#######################################"<<endl;
	    cout << "autor -> Luis Acosta"<<endl;
	    cout << "Carrera -> Ing. Informatica"<<endl;
	    cout << "Seccion -> C611"<<endl;
	    cout << "#####################################"<<endl;

	    cout << "\n###################################################"<<endl;
	    cout << "Bienvenido al Programa para evaluar Los Estudiantes"<<endl;
	    cout << "1 Corte 40%   2 Corte 60%"<<endl;
	    cout << "###################################################\n"<<endl;
		// Final de presentacion

    	// Empezar a generar el numero aleatorio de estudiantes
		srand(time(NULL));
		cantidad = 30 + rand() % 40; // Genera el numero aleatorio entre el rango  con esta cantida es igual que entre un rango de 30 y 70
		// Fin de la generacion del numero aleatorio de estudiantes

		// Lista de estudiantes
		int estudiantes[cantidad][2]; // Lista de estudiante (aleatorioEstudiante es el numero aleatorio y sera la cantidad de columnas)
		// Final de la lista de los estudiantes
		
		// promedio de los estudiantes
		int promedio[cantidad]; // 
		// final promedio de los estudiantes

		// Obtiene el 0.4 y 0.6 de los datos
		int valor[cantidad]; // 0.4
		int valorDos[cantidad]; // 0.6
		int valorCompleto[cantidad]; // el resultado completo
		// FinalObtiene el 0.4 y 0.6 de los datos
		
		// For para ingresar las notas aleatorias
		for (int i = 0; i < cantidad; i++){
        	for (int j = 0; j < 2; j++){

        		notas = 1 + rand() % 20; // genera las notas aleatorias
        		estudiantes[i][j] = notas; // ingresa las notas aleatorias
        	}
        }
        
        
        for (int i = 0; i < cantidad; i++){
        	for (int j = 0; j < 2; j++){

        		if(j == 0){ 
	        		int	aux = estudiantes[i][0]; // aux para tomar el valor del array 1 corte
	        		valor[i] = (aux * 0.4); // valor del corte se agrega en valor para usarla en los calculo (0.4)
        		
				}
				
				else if (j == 1){
					int	auxDos = estudiantes[i][1]; // aux para tomar el valor del array 2 corte
        			valorDos[i] = (auxDos * 0.6); // valor del corte se agrega en valor para usarla en los calculo (0.6)
				}
        	}
        }

        for (int i = 0; i < cantidad; ++i){

        	valorCompleto[i] = valor[i] + valorDos[i]; // valor para almacenar las notas de los 2 cortes y ver si aprueba o no
        	if (valorCompleto[i] >= 10){ // Condicion para evaluar si aprobo la materia
        		
        		aprobados = aprobados + 1; // se agrega un 1 si aprobo
        	}
        	
        	else{
        		reprobados = reprobados + 1; // se agrga 1 si reprobo
        		}
        }
        		//Se toma para evaluar el mayor del promedio
        int auxAlto = valorCompleto[0];

        	for (int i = 0; i < cantidad; i++) {  
				if (auxAlto < valorCompleto[i]) {
				     auxAlto = valorCompleto[i];
				}
			}

				//Se toma para evaluar el menor del promedio
		int auxBajo = valorCompleto[0];

        	for (int i = 0; i < cantidad; i++) {  
				if (auxBajo > valorCompleto[i]) {
				     auxBajo = valorCompleto[i];
				}
			}

        //Recorrer para mostrar los resultados
        
        cout << "Estudiantes :\t     Nota1\tNota2\tDefinitiva"<<endl;  // Mensaje de los cortes y definitiva
        for (int i = 0; i < cantidad; i++){
    		cout<<endl;
        	for (int j = 0; j < 2; j++){
        		if (j == 0){
        			cout<<"Estudiante["<<i<<"] : "<< "\t";  // Numero de estudiantes
        			cout<<estudiantes[i][0]<<"\t  "; // 1corte
        		}

        		else{
        		cout<<estudiantes[i][1]<<"\t  "; // 2corte
        		cout<<valorCompleto[i]<< "\t";  // Promedio 
        		}
        	}
        }


        		// Nota mas alta del Primer corte
        int corteUno = estudiantes[0][0];

        	for (int i = 0; i < cantidad; i++) {
        		for (int j = 0; j < cantidad; j++){  
					if (corteUno < estudiantes[i][0]) {
				    	 corteUno = estudiantes[i][0];
				   }
				}
			}



				// Nota mas Baja del Primer corte
        int corteUnoBaja = estudiantes[0][0];

        	for (int i = 0; i < cantidad; i++) {
        		for (int j = 0; j < cantidad; j++){  
					if (corteUnoBaja > estudiantes[i][0]) {
				    	 corteUnoBaja = estudiantes[i][0];
				   }
				}
			}



					// Nota mas alta del segundo corte
		int corteDos = estudiantes[0][1];

        	for (int i = 0; i < cantidad; i++) {
        		for (int j = 0; j < cantidad; j++){  
					if (corteDos < estudiantes[1][j]) {
				    	 corteDos = estudiantes[1][j];
				   }
				}
			}


					// Nota mas Baja del segundo corte
		int corteDosBaja = estudiantes[0][1];

        	for (int i = 0; i < cantidad; i++) {
        		for (int j = 0; j < cantidad; j++){  
					if (corteDosBaja > estudiantes[1][j]) {
				    	 corteDosBaja = estudiantes[1][j];
				   }
				}
			}

        
        cout << "\n\nEstudiantes aprobados         : " << aprobados<<endl; // Aprobados
        cout << "Estudiantes reprobados            : " << reprobados<<endl;  // Reprobados

		cout << "\npromedio mas Alto de la seccion : "<<auxAlto<<endl; // Promedio mas alto
		cout << "promedio mas Bajo de la seccion   : "<<auxBajo<<endl; // Promedio mas bajo

		cout << "\nnota mas alta del Primer corte  : "<< corteUno<<endl;	 // Nota mas alta del primer corte
		cout << "nota mas Baja del Primer corte    : "<< corteUnoBaja<<endl;  // Nota mas baja del primer corte

		cout << "\nnota mas alta del Segundo corte : "<< corteDos<<endl; 	// Nota mas alta del segundo corte
		cout << "nota mas Baja del Segundo corte   : "<< corteDosBaja<<endl; // Nota mas baja del segundo corte

	return 0;
}

 /******************************************************************************
 autor -> Luis Acosta 
 Carrera -> Ing. Informatica
 seccion : C611
 *******************************************************************************/
