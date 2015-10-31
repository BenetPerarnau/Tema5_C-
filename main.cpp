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
    cout << "Ex 6 "<< endl;
    cout << "Ex 7 "<< endl;
    cout << "Ex 8 "<< endl;
    cout << "Ex 9 "<< endl;
    cout << "Ex 10 "<< endl;
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
#include <string.h>
void menu(){
    cout <<"1) Calcular i escriure per pantalla el valor numèric d’un polinomi P(z) , on z és un nº real introduït per l’usuari."<<endl;
    cout <<"2) Calcular i escriure per pantalla el polinomi primera derivada, Pʹ′(x), de P(x)"<<endl;
    cout <<"3) Llegir els coeficients d’un nou polinomi que serà el que s’utilitzarà per fer els càlculs a partir d’aquell moment."<<endl;
    cout <<"Sortir"<<endl;
    cout <<"Op => ";
}

void getCoeficients(int c[]){
    for(int i=0; i<GRAU_MAX; i++){
        cout << "valor de ";
        switch(i){
            case 0:
                cout <<"terme sense x => ";
                break;
            case 1:
                cout <<"terme x => ";
                break;
            default:
                cout <<"terme x^"<<i<<" => ";
                break;
        }
        
        cin>>c[i];
    }
}

float getPz(int c[], int z){
    float res=0;
    res=c[0];
    for(int i=1; i<GRAU_MAX; i++){
        res+=c[i]*pow(z,i);
    }
    
    return res;
}

void getPrimeraDerivada(int c[]){
    
    string d="";
    
    d=std::to_string(c[1]);
    
    for(int i=2; i<GRAU_MAX; i++){
        if(c[i]>0){
            d+="+";
        }
        switch(i){
            case 2:
                d+=std::to_string(c[i]*i)+"X";
                break;
            default:
                d+=std::to_string(c[i]*i)+"X^"+std::to_string(i-1);
                break;
        }
        
    }
    
    cout <<"P'(z)= "<<d<<endl;
    
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
                cout <<"P(z="<<z<<")= "<<res<<endl;
                break;
            case 2:
                getPrimeraDerivada(coef);
                break;
            case 3:
                getCoeficients(coef);
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
/**
 *Exercici 5
a) Escriure un algorisme que llegeixi i guardi N nombres enters per teclat (que poden
estar en qualsevol ordre). Els ordeni i+ de més petit a més gran. Imprimir el resultat
per pantalla.
b) Suposant que tenim una taula amb N nombres enters ordenada tal com s’explica a
l’apartat anterior, escriure un algorisme que demani un nombre enter i si està dins de
la taula, l’elimini desplaçant la resta de valors que té a la dreta una posició cap a
l’esquerra.
 */
#define N_NOMBRES 10
void getN_Nombres(int n[]){
    for(int i=0; i<N_NOMBRES; i++){
        cout << "Nombre " << i+1 <<" => ";
        cin >> n[i];
    }
}
void ordenarAscendent(int n[]){
    for(int i=0; i<N_NOMBRES; i++){
        for(int j=0; j<N_NOMBRES-1; j++){
            int aux;
            if(n[j]>n[j+1]){
                aux=n[j];
                n[j]=n[j+1];
                n[j+1]=aux;
            }
        }
    }
}
void imprimirArray(int n[], int l){
    for (int i=0; i<l-1; i++){
        cout <<n[i]<<", ";
    }
    cout <<n[l-1]<<endl;
}
int buscarEliminar(int n[], int x){
    
    int i=0, eliminats=0;
    while(i<N_NOMBRES){
        
        if(n[i]==x){
            eliminats++;
            for(int j=i; j<N_NOMBRES-1; j++){
                n[j]=n[j+1];
            }
            i--;
        }
        i++;
    }

    return eliminats;
}
void ex5(){
    int n[N_NOMBRES];
    int x;
    getN_Nombres(n);
    ordenarAscendent(n);
    imprimirArray(n,N_NOMBRES);
    
    cout <<"Valor a buscar i eliminar si està dins de la taula => ";
    cin >> x;
    
    int eliminats;
    eliminats=buscarEliminar(n,x);
    if(eliminats!=0)cout << "El valor "<< x<<" s'ha trobat i s'ha eliminat de la taula."<<endl; 
    else cout << "El valor "<< x<<" NO s'ha trobat i s'ha eliminat de la taula."<<endl; 
    imprimirArray(n,N_NOMBRES-eliminats);
}
/**
 *Exercici 6
Donada una taula unidimensional de N elements diferents de 0, dissenyar un algorisme
per eliminar els elements repetits de la taula. La taula resultant haurà de tenir 0 a les
posicions ocupades inicialment pels elements repetits. La primera aparició de cada
element repetit s’ha de mantenir a la taula final. Totes les operacions s’han de fer sobre
la taula original. Feu dues versions diferents de l’algorisme:
a) Suposant que els valors de la taula estan ordenats de més petit a més gran.
b) Suposant que els valors de la taula no estan ordenats.  
 */
#define N 30
void omplirArray(int n[], int l){
    for(int i=0; i<l; i++){
        n[i]=rand()%30+1;
    }
}
void impArray(int n[], int l){
    for(int i=0; i<l-1; i++){
        if(n[i]<10)cout<< n[i]<<" , ";
        else cout<< n[i]<<", ";
    }
    cout<<n[l-1]<<endl;
}
void replaceNombresRepetits(int n[], int l){

    for(int i=0; i<l; i++){
        
        for(int j=i+1; j<l; j++){
            if(n[i]==n[j]){
                n[i]=0;
                n[j]=0;
            }
        }
    }
}
void ex6(){
    int array[N];
    omplirArray(array, N);
    impArray(array,N);
    replaceNombresRepetits(array,N);
    impArray(array,N);
}
/*
 Exercici 7
Dissenyeu algorismes per:
a) Sumar dues matrius.
b) Multiplicar una matriu per un nombre real.
c) Multiplicar dues matrius.
d) Calcular la suma de cada fila d’una matriu.
e) Calcular la suma de cada columna d’una matriu.
f) Calcular la suma de tots els elements de la matriu.
g) Permutar dues files de la matriu.
h) Permutar dues columnes de la matriu.
i) Transposar una matriu.
j) Comprovar si dues matrius són idèntiques
k) Multiplicar una matriu per un vector.
l) Trobar l’element màxim de la matriu i escriure la posició que ocupa dins de la matriu.
m) Comprovar si una matriu és simètrica.
En cada cas, definiu amb constants el tamany fix que vulgueu per les matrius.
 */
#define F 3
#define C 3
void ops(){
    cout << "a) Sumar dues matrius.\n"
            "b) Multiplicar una matriu per un nombre real.\n"
            "c) Multiplicar dues matrius.\n"
            "d) Calcular la suma de cada fila d’una matriu.\n"
            "e) Calcular la suma de cada columna d’una matriu.\n"
            "f) Calcular la suma de tots els elements de la matriu.\n"
            "g) Permutar dues files de la matriu.\n"
            "h) Permutar dues columnes de la matriu.\n"
            "i) Transposar una matriu.\n"
            "j) Comprovar si dues matrius són idèntiques\n"
            "k) Multiplicar una matriu per un vector.\n"
            "l) Trobar l’element màxim de la matriu i escriure la posició que ocupa dins de la matriu.\n"
            "m) Comprovar si una matriu és simètrica.\n"
            "op => ";
}
void omplirMatriuRand(int m[][C]){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            m[i][j]=rand()%11;
        }
    }
}
void omplirMatriu(int m[][C]){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            cout<<"Valor f"<<i+1<<" columna "<<j+1<<"=> ";
            cin >>m[i][j];
        }
    }
}
void imprimirMatriu(int m[][C]){
        for(int i=0; i<F; i++){
            cout<<"\t";
            for(int j=0; j<C; j++){
                cout <<m[i][j]<<"\t";
            }
            cout <<endl;
        }
}
void imprimirMatriu(int m1[][C], int m2[][C],int m3[][C], char s){
        for(int i=0; i<F; i++){
            cout<<"\t";
            for(int j=0; j<C; j++){
                cout <<m1[i][j]<<"\t";
            }
            if(i==F/2)cout<<s<<+"       ";
            else cout<<"\t";
            for(int j=0; j<C; j++){
                cout <<m2[i][j]<<"\t";
            }
            if(i==F/2)cout<<+"=       ";
            else cout<<"\t";
            for(int j=0; j<C; j++){
                cout <<m3[i][j]<<"\t";
            }            
            cout <<endl;
        } 
}
void imprimirVector(int v[], int l){
    cout <<"(";
    for(int i=0; i<l-1; i++){
        cout <<v[i]<<",";
    }
    cout <<v[l-1]<<")"<<endl;
}
void sumarM(int m1[][C], int m2[][C], int sum[][C]){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            sum[i][j]=m1[i][j]+m2[i][j];
        }
    }
}
void multiplicarMperEscalar(int m[][C],int mEscalar[][C], int k){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            mEscalar[i][j]=m[i][j]*k;
        }
    }
}
void sumaValorsPerFila(int m[][C]){
    int suma;
        for(int i=0; i<F; i++){
            suma=0;
            for(int j=0; j<C; j++){
                suma+=m[i][j];
            }
            cout <<"Suma F"<<i+1<<"= "<<suma<<endl;;
    }
}
void sumaValorsPerColumna(int m[][C]){
    int suma;
        for(int i=0; i<C; i++){
            suma=0;
            for(int j=0; j<F; j++){
                suma+=m[j][i];
            }
            cout <<"Suma C"<<i+1<<"= "<<suma<<endl;;
    }
}
void multiplicar2Matrius(int m1[][C],int m2[][C], int p_m1m2[][C]){
    
    int sum=0;
    int aux=0;
    
    for(int i=0; i<F; i++){
       
        for(int n=0; n<F; n++){
            for(int j=0; j<C; j++){
           
                sum+=m1[i][j]*m2[j][n];
            }
        p_m1m2[i][n]=sum;
        sum=0;        
        }

    }
    
}
int sumatoriCoeficientsMatriu(int m[][C]){
    int sum=0;
    
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            sum+=m[i][j];
        }
    }
    
    return sum;
}
void permutarDuesFiles(int m[][C], int p1, int p2){
    int aux;
        for(int j=0; j<C; j++){
            aux=m[p1][j];
            m[p1][j]=m[p2][j];
            m[p2][j]=aux;
        }  
    
}
void permutarDuesColumnes(int m[][C], int p1, int p2){
    int aux;
        for(int j=0; j<F; j++){
            aux=m[j][p1];
            m[j][p1]=m[j][p2];
            m[j][p2]=aux;
        }     
}
void getTransposada(int m[][C]){
    int aux;    
    for(int i=0; i<F; i++){
            for(int j=i+1; j<C; j++){
                aux=m[i][j];
                m[i][j]=m[j][i];
                m[j][i]=aux;
            }
    }    
}
bool areEcuals(int m1[][C], int m2[][C]){
    bool res=true;
    int i=0,j=0;
    
    while(res==true && i<F){      
        while(res==true && j<C){
            if(m1[i][j]!=m2[i][j]){
                res=false;
            }
            j++;
        }
        i++;
    }
    
    return res;
}
void omplirVector(int v[], int l){
    for(int i=0; i<l; i++){
        cout <<"V"<<(i+1)<<" => ";
        cin >> v[i];
    }
}
void multiplicarVectorMatriu(int v[], int m[][C], int r[C]){
    int sum=0;
    for(int i=0; i<C; i++){
        
        for(int j=0; j<F; j++){
            sum+=v[j]*m[j][i];
        }
        r[i]=sum;
        sum=0;
    }
    
    
}
int getElementMax(int m[][C]){
    int max=m[0][0];
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            if(max<m[i][j])max=m[i][j];
        }
    }
    return max;
}
void copyMatriu(int m[][C], int c[][C]){
    for(int i=0; i<F; i++){
        for(int j=0; j<C; j++){
            c[i][j]=m[i][j];
        }
    }
}
void ex7(){
    int m1[F][C];
    int m2[F][C];
    int suma[F][C];
    int mEscalar[F][C];
    int k;
    int p_m1m2[F][C];
    
    char op;
    
    omplirMatriuRand(m1);
    omplirMatriuRand(m2);
    cout << "Matriu A: "<<endl;
    imprimirMatriu(m1);
    cout << "Matriu B: "<<endl;
    imprimirMatriu(m2);
    
    ops();
    cin >> op;
    switch(op){
        case 'a':
            sumarM(m1,m2,suma);
            cout <<"A + B :"<<endl;
            imprimirMatriu(suma);
            
            break;
        case 'b':
            cout << "Valor de k per multiplicar la matriu => ";
            cin >> k; 
            multiplicarMperEscalar(m1,mEscalar,k);
            cout <<" A * "<<k<<" :"<<endl;
            imprimirMatriu(mEscalar);
            break;
        case 'c':// * dues matrius
            multiplicar2Matrius(m1,m2,p_m1m2);
            imprimirMatriu(m1,m2,p_m1m2,'*');
            break;
        case 'd': //calcula suma de cada fila
            cout <<"Suma de cada fila de A: "<<endl;
            sumaValorsPerFila(m1);
            break;
        case 'e'://calcula suma de cada columna
            cout <<"Suma de cada columna de A: "<<endl;
            sumaValorsPerColumna(m1);
            break;      
        case 'f'://"f) Calcular la suma de tots els elements de la matriu.\n"
            imprimirMatriu(m1);
            cout<<"Suma de tots els coeficients: "<<endl;
            cout<<sumatoriCoeficientsMatriu(m1)<<endl;
            break;
        case 'g'://"g) Permutar dues files de la matriu.\n"
            int f, f2;
            cout<<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            cout <<"Permutar Fila => ";
            cin>>f;
            cout <<"Amb Fila => ";
            cin >> f2;
            permutarDuesFiles(m1,f-1,f2-1);
            cout <<"Nova matriu A:"<<endl;
            imprimirMatriu(m1);          
            break;
        case 'h'://"h) Permutar dues columnes de la matriu.\n"
            int c, c2;
            cout<<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            cout <<"Permutar Columna => ";
            cin>>c;
            cout <<"Amb Columna => ";
            cin >> c2;
            permutarDuesColumnes(m1,c-1,c2-1);
            cout <<"Nova matriu A:"<<endl;
            imprimirMatriu(m1);                
            break;
        case 'i'://"i) Transposar una matriu.\n"
            cout <<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            cout <<"Transposada:"<<endl;
            getTransposada(m1);
            imprimirMatriu(m1);
            break;
        case 'j'://Comprovar si dues matrius són idèntiques\n"
            cout <<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            cout <<"Matriu B:"<<endl;
            imprimirMatriu(m2);
            cout <<"Són idèntiques ?"<<endl;
            if(areEcuals(m1,m2))cout <<"SÍ"<<endl;
            else cout<<"NO"<<endl;
            break;
        case 'k'://"k) Multiplicar una matriu per un vector.\n"
            int vector[C];
            int vec_per_mat[C];
            omplirVector(vector, C);
            cout <<"Vector V:"<<endl;
            imprimirVector(vector, C);
            cout <<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            cout <<"V*A ="<<endl;
            multiplicarVectorMatriu(vector,m1,vec_per_mat);
            imprimirVector(vec_per_mat,C);
            break;
        case 'l'://"l) Trobar l’element màxim de la matriu i escriure la posició que ocupa dins de la matriu.\n"
            int max;
            cout <<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            max=getElementMax(m1);
            cout <<"El element màxim és: "<<max<<endl;
            break;
        case 'm'://"m) Comprovar si una matriu és simètrica.\n"
//A es también la matriz traspuesta de sí misma: A^t = A. 
//Esta última igualdad es una definición alternativa de matriz simétrica.
            int aux[F][C];
            cout <<"Matriu A:"<<endl;
            imprimirMatriu(m1);
            copyMatriu(m1,aux);
            getTransposada(aux);
            cout <<"La Matriu ";
            if(!areEcuals(m1,aux)){
                cout <<"NO ";
            }
            cout <<"és simétrica"<<endl;
            
            break;            
        default:
            break;
    }
}
/**
 * Exercici 8
Tenim dues matrius A i B de dimensions MxM i NxN respectivament, on M > N.
Aquestes matrius només contenen 0’s i 1’s. Fer un algorisme que, donada una posició
(x,y) de la matriu A, superposi la matriu B en aquesta posició i miri si hi ha alguna
col·lisió entre les dues matrius, és a dir, si hi ha alguna casella de la matriu B que
contingui un “1” que coincideixi amb alguna casella de la matriu A que també contingui
un “1”.
 */
#define A_F 3
#define A_C 3
#define B_F 2
#define B_C 2
void imprimirMatriuA(int m[][A_C]){
        for(int i=0; i<A_F; i++){
            cout<<"\t";
            for(int j=0; j<A_C; j++){
                cout <<m[i][j]<<"\t";
            }
            cout <<endl;
        }
}
void imprimirMatriuB(int m[][B_C]){
        for(int i=0; i<B_F; i++){
            cout<<"\t";
            for(int j=0; j<B_C; j++){
                cout <<m[i][j]<<"\t";
            }
            cout <<endl;
        }
}
bool superposarMatriu(int m1[][A_C], int m2[][B_C], int x, int y){
    int aux_f=0, aux_c=0;
    bool coincideix=false;
    
    for(int i=x; i<A_F; i++){
        
        for(int j=y; j<A_C; j++){
            if(m1[i][j]==m2[aux_f][aux_c]){ 
                coincideix=true;
            }     
            if(aux_f<B_F && aux_c<B_C){
                m1[i][j]=m2[aux_f][aux_c];
                aux_c++;
            }
        }
        if(aux_f<B_F){
            aux_f++;
            aux_c=0;
        }
    }
    return coincideix;
}
void ex8(){
    int a[A_F][A_C]={{1,1,0},{0,0,0},{1,0,0}};
    int b[B_F][B_C]={{0,1},{1,0}};
    
    cout <<"Matriu A: "<<endl;
    imprimirMatriuA(a);
    cout <<"Matriu B: "<<endl;
    imprimirMatriuB(b); 
    
    int x,y;
    cout <<"Posició F de la matriu A on es vol introduir la matriu B => ";
    cin>>x;
    cout <<"Posició C de la matriu A on es vol introduir la matriu B => ";
    cin >>y;
    
    x=x-1;
    y=y-1;
    
    if(x+B_C>A_C|| y+B_F>A_F){
        cout <<"No es pot superposar la matiu B dins de la matriu A en aquestes coordenades."<<endl;
    }else{
        cout <<"Resultat de superposar la matriu B dins de la matriu A en les cordenades ("<<x<<","<<y<<")"<<endl;
        if(superposarMatriu(a,b,x,y)){
            cout <<"S'ha trobat coincidències"<<endl;
        }else{
            cout <<"NO S'ha trobat coincidències"<<endl;
        }
        cout <<"Matriu superposada:"<<endl;
        imprimirMatriuA(a);
    }
    
}
/**
 * Exercici 9
En el joc del Space Invaders, els búnkers protectors del canó es podran representar amb
una taula bidimensional de tamany 3x3. El valor guardat a cada posició de la taula ens
pot servir per codificar la forma actual del búnker. Per exemple, un 1 a una posició de la
taula ens pot indicar que aquella part del búnker encara està activa, i un 0 ens pot indicar
que ha estat destruïda per l’impacte d’un tret. A la figura següent il·lustrem aquesta
equivalència entre els valors de la taula i la forma del búnker.

Volem fer un algorisme que ens determini si un tret disparat per un alienígena impactarà
o no amb un búnker. Al principi de l’algorisme s’haurà de demanar la posició a pantalla
de la cantonada esquerra inferior del búnker, i la coordinada X del tret (la columna de la
pantalla per la qual es desplaçarà el tret). S’haurà de determinar si la columna del tret
coincideix amb alguna de les columnes que ocupa el búnker i si és així s’haurà de
determinar si quan el tret arribi a l’alçada del búnker xocarà o no amb alguna de les
seves posicions actives. En aquest cas, s’haurà de desactivar aquesta part del búnker a la
taula que el representa. Al final de l’algorisme s’ha de mostrar per pantalla un missatge
indicant si hi haurà col·lisió del tret amb el búnker o no. Podeu suposar que la matriu
amb la forma inicial del búnker ja ha estat correctament inicialitzada.
 */
#define F_B 3
#define C_B 3
void ex9(){
    int bunker[F_B][C_B]={{1,1,0},{1,1,1},{1,0,1}};
    int c_x, c_y, t_x;
    //Cordenada inferior esquerra    
    cout <<"Coordenada inferior esquerra:"<<endl;
    cout <<"Cordenada x => ";
    cin >> c_x;
    c_x=c_x-1;
    cout <<"Cordenada y => ";
    cin >> c_y;
    c_y=c_y-1;
    //Cordenada x del tret
    cout <<"Cordenada x tret => ";
    cin >> t_x;
    t_x=t_x-1;
    if((t_x<(c_x+C_B) && t_x>=c_x ) && bunker[c_y][t_x]==1){
        //tocat
        cout <<"Col·lisió!"<<endl;
    }else{
        cout <<"Has fallat!"<<endl;
    }
    
}
/**
 * Exercici 10
El joc del sudoku es pot representar amb una taula bidimensional 9x9 on guardem a
cada casella un nº del 1 al 9 i si la casella està buida (encara no s’hi ha posat cap
número) hi guardem un 0. Escriure un algorisme que, a partir d’una taula bidimensional
que representa un joc del Sudoku, demani un nº i una posició del taulell on col·locar-lo i
ens digui si és correcte posar-lo en aquella posició segons les regles del Sudoku:
- La casella ha d’estar buida
- No pot haver-hi cap altre nº igual a la mateixa fila o columna
- No pot haver-hi cap altre nº igual a la submatriu 3x3 corresponent a la posició
indicada.
indicada.
 */
#define S_F 9
#define S_C 9
void iniciarTaulellSudoku(int t[][S_C]){
    for(int i=0; i<S_F; i++){
        for(int j=0; j<S_C; j++){
            t[i][j]=0;
        }
    }
}
void mostrarTaulell(int t[][S_C]){
    for(int i=0; i<S_F; i++){
        if(i%3==0){
            for(int l=0; l<3; l++){
                cout <<"––––––––––––––";
            }
        }
        cout<<endl;
        /*for(int k=0; k<S_C; k++){
            cout <<" -  ";
        }
        cout<<endl;*/
        for(int j=0; j<S_C; j++){
            if(j%3==0)cout<<"| ["<<t[i][j]<<"] ";
            else cout<<"["<<t[i][j]<<"] ";
            if(j==S_C-1){cout<<"|";}
        }
        cout<<endl;
        
    }
    
    /*for(int k=0; k<S_C; k++){
        cout <<" -  ";
    }
    cout<<endl;*/
    for(int l=0; l<3; l++){
        cout <<"––––––––––––––";
    }
    cout<<endl;
}
bool isEmptyPos(int t[][S_C], int x, int y){
    bool r=true;
    if(t[y][x]!=0)r=false;
    return r;
}
bool isUniqueInFila(int t[][S_C],int pos_fila ,int valor){
    bool r=true;
    for(int i=0; i<S_C; i++){
        if(t[pos_fila][i]==valor){
            r=false;
        }
    }
    return r;
}
bool isUniqueInColumna(int t[][S_C],int pos_col ,int valor){
    bool r=true;
    for(int i=0; i<S_F; i++){
        if(t[i][pos_col]==valor){
            r=false;
        }
    }
    return r;
}
void getIniciSubmatiu(int c, int f, int iniciSub[]){
    if(c<3){
        iniciSub[1]=0;
    }else if(c<6){
        iniciSub[1]=3;
    }else{
        iniciSub[1]=6;
    }
    if(f<3){
        iniciSub[0]=0;
    }else if(f<6){
        iniciSub[0]=3;
    }else{
        iniciSub[0]=6;
    }
}
bool isUniqueInSubmatriu(int t[][S_C], int c, int f, int valor){
    int iniciSub[2]; // 0 => f  1=> c
    bool unique=true;
    
    getIniciSubmatiu(c,f,iniciSub);
    
    for(int i=iniciSub[0]; i<3&&unique==true; i++){
        for(int j=iniciSub[1]; j<3&&unique==true; j++){
            if(t[i][j]==valor)unique=false;
        }
    }
    
    return unique;
}
void setValor(int t[][S_C], int y, int x, int valor){
    t[y][x]=valor;
}
void ex10(){
    int t[S_F][S_C];
    int x, y;
    int valor;
    iniciarTaulellSudoku(t);
    do{
        cout<<"SUDOKU"<<endl;
        mostrarTaulell(t);
        cout<<"Pos x => ";
        cin>>x;
        x=x-1;
        cout<<"Pos y => ";
        cin>>y;
        y=y-1;
        while(x<0||x>S_C || y>=S_F || y<0 || !isEmptyPos(t,x,y)){
            cout<<"ERROR: ";
            if(x<0||x>S_C || y>=S_F || y<0){
                cout<<"la coordenada esta fora de les dimensions del taulell."<<endl;
            }else{               
                cout<<"aquesta posició ja està ocupada."<<endl;
            }
            cout<<"Pos x => ";
            cin>>x;
            x=x-1;
            cout<<"Pos y => ";
            cin>>y;
            y=y-1;
        }
        cout<< "Valor => ";
        cin>>valor;
        while(valor<1||valor>9){
            cout<<"ERROR: valors del 1 al 9."<<endl;
            cout<<"Valor => ";
            cin>>valor;            
        }
        //aki sabem cordenada x,y tulell correcte amb un valor dins el rang 1-9
        //saber si es el unic valor de la fila y columna
        if(isUniqueInFila(t,y,valor)){
           //el valor es unic en aquesta fila 
            if(isUniqueInColumna(t,x,valor)){
                //el valor es unic en aquesta columna
                //saber si aquet valor es únic a la submatriu 3*3 a la que perteneix
                if(isUniqueInSubmatriu(t,x,y,valor)){
                    setValor(t,y,x,valor);
                }else{
                    cout<<"Error: el valor ja existeix dins de la submatriu 3*3"<<endl;            
                }               
            }else{
                //error el valor ja existeix en aquesta columna
                cout<<"Error: el valor ja existeix en aquesta columna"<<endl;
            }
        }else{
            //error el valor ja existeix en aquesta fila
            cout <<"Error: el valor ja existeix en aquesta fila"<<endl;
        }
        
    }while(true);
}
int main() {

    srand(time(NULL));
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
            case 5:
                ex5();
                break;
            case 6:
                ex6();
                break;
            case 7:
                ex7();
                break;
            case 8:
                ex8();
                break;
            case 9:
                ex9();
                break;
            case 10:
                ex10();
                break;
            case 11:
                //ex5();
                break;
            case 12:
                //ex6();
            default:
                cout <<"Exercici no trobat"<<endl;
                break;
        }
    }while(op!=-1);
    
    return 0;
}

