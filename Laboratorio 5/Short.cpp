#include <bits/stdc++.h>
using namespace std;

int main(){
	char col1,col2; //columna
	int row1,row2; //fila
	cin>>col1>>row1>>col2>>row2;
	char letras[8]={'a','b','c','d','e','f','g','h'};

	int newcol1, newcol2;
	for(int i=0;i<8;i++){
		if(letras[i]==col1){
			newcol1=i+1;
		}
		if(letras[i]==col2){
			newcol2=i+1;
		}
	}
	int posKing[2]={newcol1,row1}; //columnas, fila de la posicion s

	int posFin[2]={newcol2,row2}; //columna, fila de la posicion t

	//ver los cuadrantes
	int pasos;
	int dia,hola;
	string cuadrante;
	string pasito;
	if(posFin[0]>posKing[0]){
	 	if(posFin[1]>posKing[1]){
			cuadrante="RU";
			if((posFin[0]-posKing[0])>(posFin[1]-posKing[1])){
				pasito="R";
			}
			else{
				pasito="U";
			}
			pasos=max(posFin[0]-posKing[0],posFin[1]-posKing[1]);
			cout<<pasos<<"\n";
			dia=min(posFin[0]-posKing[0],posFin[1]-posKing[1]);
		}
		else {
			cuadrante="RD";
			if((posFin[0]-posKing[0])>(-posFin[1]+posKing[1])){
				pasito="R";
			}
			else{
				pasito="D";
			}
			pasos=max(posFin[0]-posKing[0],-posFin[1]+posKing[1]);
			cout<<pasos<<"\n";
			dia=min(posFin[0]-posKing[0],-posFin[1]+posKing[1]);
		}
	}
	else {
		if(posFin[1]>posKing[1]){
			cuadrante="LU";
			if((-posFin[0]+posKing[0])>(posFin[1]-posKing[1])){
				pasito="L";
			}
			else{
				pasito="U";
			}
			pasos=max(-posFin[0]+posKing[0],posFin[1]-posKing[1]);
			cout<<pasos<<"\n";		
			dia=min(-posFin[0]+posKing[0],posFin[1]-posKing[1]);
		}	
		else{
			cuadrante="LD";
			if((-posFin[0]+posKing[0])>(-posFin[1]+posKing[1])){
				pasito="L";
			}
			else{
				pasito="D";
			}
			pasos=max(-posFin[0]+posKing[0],-posFin[1]+posKing[1]);
			cout<<pasos<<"\n";		
			dia=min(-posFin[0]+posKing[0],-posFin[1]+posKing[1]);
		}
	}
	int otro=pasos-dia;

	for(int i=0;i<dia;i++){
		cout<<cuadrante<<"\n";
	}
	for(int i=0;i<otro;i++){
		cout<<pasito<<"\n";
	}

}