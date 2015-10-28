/* 
 * File:   main.cpp
 * Author: Benet
 *
 * Created on 28 de octubre de 2015, 18:23
 */

#include <iostream>
#include <math.h>

using namespace std;

/*
 * 
 */


void showMenu(){
    
    cout << "Tema 5" <<endl;
    cout << "Ex 1 "<< endl;
    cout << "Ex 2 "<< endl;
    cout << "Ex 3 "<< endl;
    cout << "Ex 4 "<< endl;
    cout << "Ex 5 "<< endl;
    
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
void generarTemperatures(float t[][2], int l){
    srand(time(NULL));
    cout <<"Temperatures diaries:"<<endl;
    for(int i=0; i<l; i++){
        t[i][0]=rand()%(MAX-MIN)+MIN;
        t[i][1]=0;
        cout << "T. dia " << i+1 <<": "<< t[i][0]<<"º"<<endl;
    }
}

void ordenarAccendent(float t[][2], int l){
    for(int i=0; i<l; i++){
        for(int j=0;j<l-1; j++){
            if(t[j][0]<t[j+1][0]){
                float aux=t[j][0];
                t[j][0]=t[j+1][0];
                t[j+1][0]=aux;
            }
        }
    }
}



void trobarRepeticionsTemperatures(float t[][2], int l){
    
    
    for(int i=0; i<l; i++){
              
        for(int j=0; j<l; j++){
            if(t[i][0]==t[j][0]){
                t[i][1]=t[i][1]+1;
            }
        }
        cout << "Dia "<<i+1<<": "<<t[i][0]<<"º amb "<<t[i][1]<<" repeticions."<<endl;
    }
    
    ordenarAccendent(t,DIES);
    
    float temp_max=0;
    int rep=0;
    int i=0;
    do{
        
        if(t[i][1]>t[i+1][1]){
            temp_max=t[i][0];
            rep=t[i][1];
        }
        i++;
    }while(temp_max==0 && i<l);
    
    cout <<"Temperatura màxima més repetida: "<<temp_max<<"º amb "<<rep<< "repeticions" <<endl;

    float temp_min=0;
    rep=0;
    i=DIES-1;
    do{
        
        if(t[i][1]>t[i-1][1]){
            temp_min=t[i][0];
            rep=t[i][1];
        }
        i--;
    }while(temp_min==0 && i>=0);
    
    cout <<"Temperatura mínima més repetida: "<<temp_min<<"º amb "<<rep<<" repeticions"<<endl;
    
}

void ex2(){
    float t[DIES][2];   //[0] temperatura [1] nº dies repetida
    generarTemperatures(t,DIES);
    
    trobarRepeticionsTemperatures(t,DIES);
    
    
    
    
}
/**
 *Exercici 3
Escriure un algorisme que llegeixi una sèrie de fins a 50 nombres reals acabada amb el
0. És a dir, s’han d’anar llegint nombres per teclat i parar quan s’introdueixi un 0 o bé ja
s’hagin llegit 50 valors. Després de llegir i guardar la sèrie, s’ha de calcular el màxim i
el mínim, el nº de valors positius i el nº de valors negatius de la sèrie, la mitja i la
desviació estàndard. 
 */
#define MAX 50
#define FI 0

int getNumbers(int n[], int l){
    int i=0;
    
    do{
        
        cout << "Valor => ";
        cin >> n[i];
        i++;
        
    }while(n[i-1]!=FI && i<l);
    
    return i-1;//valores del array
}
int getMax(int n[], int l){
    int max=n[0];
    for(int i=1; i<l; i++){
        if(n[i]>max){
            max=n[i];
        }
    }
    return max;
}
int getMin(int n[], int l){
    int min=n[0];
    for(int i=1; i<l; i++){
        if(n[i]<min){
            min=n[i];
        }
    }
    return min;
}
int getPositius(int n[], int l){
    int positius=0;
    for(int i=0; i<l; i++){
        if(n[i]>0){
            positius++;
        }
    }   
    return positius;
}
int getNegatius(int n[], int l){
    int negatius=0;
    for(int i=0; i<l; i++){
        if(n[i]<0){
            negatius++;
        }
    }   
    return negatius;
}
float getMitja(int n[], int l){
    float mitja=0;
    for(int i=0; i<l; i++){
        mitja+=n[i];
    }
    mitja=mitja/l;
    return mitja;
}

float getVarianza(int n[], int l){
//1. Calcula la media (el promedio de los números)
//2. Ahora, por cada número resta la media y eleva el resultado al cuadrado (la diferencia elevada al cuadrado). 
//3. Ahora calcula la media de esas diferencias al cuadrado. 
    float mitja, var;
    float aux=0;
    
    mitja=getMitja(n,l);
    
    for(int i=0; i<l; i++){
        aux+=pow(n[i]-mitja,2);
    }
    
    var=aux/l;
    
    return var;
    
}
float getDesEsta(int n[], int l){
    //es la raíz cuadrada de la varianza.
    float var, d_e;
    
    var=getVarianza(n,l);
    d_e=sqrt(var);
    
    return d_e;
}

void ex3(){
    int array[MAX];
    int max, min, posi, nega, n_valores_introducidos;
    float mitja, d_e;
    n_valores_introducidos=getNumbers(array,MAX);
    max=getMax(array,n_valores_introducidos);
    min=getMin(array,n_valores_introducidos);
    posi=getPositius(array,n_valores_introducidos);
    nega=getNegatius(array,n_valores_introducidos);
    mitja=getMitja(array,n_valores_introducidos);
    d_e=getDesEsta(array,n_valores_introducidos);
    
    cout << "Valor max => "<< max <<endl;
    cout << "Valor min => "<< min <<endl;
    cout << "Valor positius => "<< posi <<endl;
    cout << "Valor negatius => "<< nega <<endl;
    cout << "Valor mitjana => "<< mitja <<endl;
    cout << "Valor desviació estàndard => "<< d_e <<endl;
}
/**
 * Exercici 4
Un polinomi de coeficients reals i grau n,
n
P x = a + a x + a x ++ an x 2
0 1 2 ( )
es pot representar amb una taula unidimensional amb n+1 components. Dissenyeu un
algorisme que permeti guardar polinomis de fins a un grau màxim definit per una
constant GRAU_MAX. L’algorisme, primer de tot, ha de llegir els coeficients d’un
polinomi qualsevol (que, per tant, pot tenir un grau inferior a GRAU_MAX) i després
mostrar un menú amb les següents opcions:
a) Calcular i escriure per pantalla el valor numèric d’un polinomi P(z) , on z és un nº
real introduït per l’usuari.
b) Calcular i escriure per pantalla el polinomi primera derivada, Pʹ′(x), de P(x)
c) Llegir els coeficients d’un nou polinomi que serà el que s’utilitzarà per fer els
càlculs a partir d’aquell moment.
d) Sortir de l’algorisme.
El menú s’ha de repetir fins que l’usuari seleccioni l’opció de sortir.
 */
#define GRAU_MAX 4
void menu(){
    cout <<"1) Calcular i escriure per pantalla el valor numèric d’un polinomi P(z) , on z és un nº real introduït per l’usuari."<<endl;
    cout <<"2) Calcular i escriure per pantalla el polinomi primera derivada, Pʹ′(x), de P(x)"<<endl;
    cout <<"3) Llegir els coeficients d’un nou polinomi que serà el que s’utilitzarà per fer els càlculs a partir d’aquell moment."<<endl;
    cout <<"Sortir"<<endl;
    cout <<"Op => ";
}

void getCoeficients(int c[]){
    for(int i=0; i<GRAU_MAX; i++){
        cout << "valor: ";
        cin>>c[i];
    }
}

float getPz(int c[], int z){
    float res=0;
    res=c[0];
    res+=c[1]*z;
    res+=c[2]*pow(z,2);
    res+=c[3]*pow(z,3);
    
    return res;
}

void ex4(){
    int op=-1;
/**
 * L’algorisme, primer de tot, ha de llegir els coeficients d’un
polinomi qualsevol (que, per tant, pot tenir un grau inferior a GRAU_MAX) i després
mostrar un menú amb les següents opcions:
 */
    //                   2   3
    // farem P(x)=5+2x-3x^+4x^   pq he posat grau_max 4
    //coef[0]=5
    //coef[1]=2 ...
    int coef[GRAU_MAX];
    getCoeficients(coef);
    
    do{
        menu();
        cin >> op;
        switch(op){
            case 1:
                int z;
                float res;
                cout <<"Valor de z => ";
                cin >> z;
                res=getPz(coef,z);
                cout <<"P(z)= "<<res<<endl;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                cout <<"Bye"<<endl;
                break;
            default:
                cout <<"Opció no vàlida."<<endl;
                break;
        }
    }while(op!=4);
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
            case 3:
                ex3();
                break;
            case 4:
                ex4();
                break;               
            default:
                cout <<"Exercici no trobat"<<endl;
                break;
        }
    }while(op!=-1);
    
    return 0;
}

