/* 
 * File:   main.cpp
 * Author: Benet
 *
 * Created on 28 de octubre de 2015, 18:23
 */

#include <iostream>

using namespace std;

/*
 * 
 */


void showMenu(){
    
    cout << "Tema 5" <<endl;
    cout << "Ex 1 "<< endl;
    cout <<"Nº=> ";
}
/**
 * Exercici 1
Escriure un algorisme que llegeixi la temperatura mitja dels dotze mesos de l’any i els
guardi en una estructura de dades adient. Que a continuació digui quins mesos han
tingut la temperatura mínima i màxima, i quins mesos han tingut una temperatura
inferior i superior a la mitja anual.
 */
void imprimirNomMes(int m){
    switch(m){
        case 0:
            cout << "Gener";
            break;
        case 1:
            cout << "Febrer";
            break;
        case 2:
            cout << "Març";
            break;
        case 3:
            cout << "Abril";
            break;
        case 4:
            cout << "Maig";
            break;
        case 5:
            cout << "Juny";
            break;
        case 6:
            cout << "Juliol";
            break;
        case 7:
            cout << "Agost";
            break;
        case 8:
            cout << "Setembre";
            break;
        case 9:
            cout << "Octubre";
            break;
        case 10:
            cout << "Novembre";
            break;
        case 11:
            cout << "Desembre";
            break;
            
    }
}
void demanarTemperatures(float t[], int l){
    for(int i=0; i<l;i++){
        cout << "Temperatura mitja mes " << (i+1) << ": ";
        cin >> t[i];
    }
}
float buscarMesMin(float t[], int l){
    float min=t[0];
    float mes=0;
    for(int i=1; i<l; i++){
        if(t[i]<min){
            min=t[i]; 
            mes=i;
        }
    }
    
    return mes;
}
float buscarMesMax(float t[], int l){
    float max=t[0];
    float mes=0;
    for(int i=1; i<l; i++){
        if(t[i]>max){
            max=t[i]; 
            mes=i;
        }
    }
    
    return mes;  
   
}
float calcularMAnual(float t[], int l){

    float m=0;
    
    for(int i=0; i<l; i++){
        m+=t[i];
    }
    m=m/l;
    return m;
}
void trobarMesosSotaMitja(float t[], int l, float mitj){
    
    for(int i=0; i<l; i++){
        
        if(t[i]<mitj){
           imprimirNomMes(i);
           cout << " amb "<<t[i]<<" º"<<endl; 
        }
    }
    
}
void trobarMesosSobreMitja(float t[], int l, float mitj){
    
    for(int i=0; i<l; i++){
        
        if(t[i]>mitj){
           imprimirNomMes(i);
           cout <<" amb "<<t[i]<<" º"<<endl; 
        }
    }
    
}
void ex1(){
    int m=12;
    float temperatures[m];
    float mes_max, mes_min, mitja;    
    demanarTemperatures(temperatures,m);
    mes_min=buscarMesMin(temperatures,m);
    cout << "El mes amb la temperatura mitja més baixa és: ";
    imprimirNomMes(mes_min);
    cout <<""<<endl;
    mes_max=buscarMesMax(temperatures,m);
    cout << "El mes amb la temperatura mitja més alta és: ";
    imprimirNomMes(mes_max);
    cout <<""<<endl;
    mitja=calcularMAnual(temperatures,m);
    cout << "La mitja de temperatues és: " << mitja<<endl;
    cout <<"Mesos que estan per sota la mitjana anual: "<<endl;
    trobarMesosSotaMitja(temperatures,m,mitja);
    cout <<"Mesos que estan per sobre la mitjana anual: "<<endl;
    trobarMesosSobreMitja(temperatures,m,mitja);  
}
/**
 * Exercici 2
Llegir i guardar, en una estructura de dades, les temperatures de cada dia durant un any
(356 dies). 
Escriure un algorisme que ens permeti saber quina és la temperatura diària
màxima que s’ha repetit més cops al llarg de tots els dies d’un any. 
Podem suposar que a temperatura mai serà inferior a -10º ni superior a 50º. 
L’algorisme haurà de llegir la
temperatura màxima de tots els dies de l’any i haurà de construir una taula en què per
cada possible valor de temperatura (de -10 a 50) es guardi quants dies han tingut aquella
temperatura al llarg de l’any. Després, l’algorisme haurà de mostrar el contingut final
d’aquesta taula i calcular i escriure quina és la temperatura que s’ha repetit més cops al
llarg de l’any i quina és la temperatura que s’ha repetit menys vegades.
 */
#define DIES 365
#define MIN -10
#define MAX 50
void generarTemperatures(float t[], int l){
    srand(time(NULL));
    for(int i=0; i<l; i++){
        t[i]=rand()%(MAX-MIN)+MIN;
        cout << "t " << i+1 <<": "<< t[i]<<endl;
    }
}

void ordenarAccendent(float t[], int l){
    for(int i=0; i<l; i++){
        for(int j=0;j<l-1; j++){
            if(t[j]<t[j+1]){
                float aux=t[j];
                t[j]=t[j+1];
                t[j+1]=aux;
            }
        }
    }
}

void trobarRepeticionsTemperatures(float t[], int l){
    
    float aux[DIES][2];
    
    for(int i=0; i<l; i++){
        
        aux[i][0]=t[i]; //Temperatura 
        aux[i][1]=0; //Repeticions
        
        for(int j=0; j<l; j++){
            if(t[i]==t[j]){
                aux[i][1]=aux[i][1]+1;
            }
        }
        
    }
    
    getTemperaturaMaxMesRepetida(aux,DIES);
    getTemperaturaMinMesRepetida(aux,DIES);
    
    
}
void getTemperaturaMaxMesRepetida(float aux[][], int l){
    float temp_max=0;
    int rep=0;
    int i=0;
    do{
        
        if(aux[i][1]>aux[i+1][1]){
            temp_max=aux[i][0];
            rep=aux[i][1];
        }
        i++;
    }while(temp_max==0 && i<l);
    
    cout <<"Temperatura màxima més repetida: "<<temp_max<<" nº repeticions: "<<rep<<endl;
}
void getTemperaturaMinMesRepetida(float aux[][], int l){
    float temp_min=0;
    int rep=0;
    int i=DIES-1;
    do{
        
        if(aux[i][1]>aux[i-1][1]){
            temp_min=aux[i][0];
            rep=aux[i][1];
        }
        i--;
    }while(temp_min==0 && i>=0);
    
    cout <<"Temperatura mínima més repetida: "<<temp_min<<" nº repeticions: "<<rep<<endl;
}
void ex2(){
    float t[DIES];   
    generarTemperatures(t,DIES);
    //Temp max mes repetida
    ordenarAccendent(t,DIES);
    trobarRepeticionsTemperatures(t,DIES);
    
    
}
int main() {

    
    int op=-1;
    
    
    do{
        showMenu();
        cin >> op;
        switch(op){
            case 1:
                ex1();
                break;
            case 2:
                ex2();
                break;
            default:
                cout <<"Exercici no trobat"<<endl;
                break;
        }
    }while(op!=-1);
    
    return 0;
}

