#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define NR_MAX_ARBORI 100

// definirea structurii asociate unui nod de arbore Huffman
struct NodArboreHuffman{
     // un caracter specificat la un moment dat
    char caracter;
     // Frecventa de aparitie a caracterului in cadrul sirului de caractere specificat
    unsigned fr_ap;
     // Nodurile fii stanga si dreapta pentru care este parinte nodul curent
    struct NodArboreHuffman *nodf_stanga, *nodf_dreapta;
};

struct Arbore{
     // dimensiunea actuala a arborelui
    unsigned dim;
     // capacitatea arborelui
    unsigned capacitate;
     // se defineste un vector de pointeri catre nodurile arborelui Huffman
    struct NodArboreHuffman** vect_arbori;
};

// functia defNodNou permite alocarea/definirea unui nou nod care contine caracterul "caracter" si frecventa "frecventa_aparitie"
struct NodArboreHuffman* defNodNou(char caracter, unsigned frecventa_aparitie){
    struct NodArboreHuffman* nod_arbore=(struct NodArboreHuffman*)malloc(sizeof(struct NodArboreHuffman));
    nod_arbore->nodf_stanga=nod_arbore->nodf_dreapta=NULL;
    nod_arbore->caracter=caracter;
    nod_arbore->fr_ap=frecventa_aparitie;

    return nod_arbore;
}

// functia creareArboreHuffman permite definirea unui arbore cu, capacitatea/nr. de noduri precizate
struct Arbore* creareArboreHuffman(unsigned capacitate){

    struct Arbore* arbore=(struct Arbore*)malloc(sizeof(struct Arbore));
    arbore->dim = 0;
    arbore->capacitate=capacitate;
    arbore->vect_arbori=(struct NodArboreHuffman**)malloc(arbore->capacitate*sizeof(struct NodArboreHuffman*));
    return arbore;
}

//functia interschimba_ArboreHuffman este utilizata pentru interschimbarea a doi arbori
void interschimba_ArboreHuffman(struct NodArboreHuffman** a,struct NodArboreHuffman** b){

    struct NodArboreHuffman* t=*a;
    *a=*b;
    *b=t;
}

// Functia de ordonare a arborilor din vect_arbori
void ordonareArboreHuffman(struct Arbore* arbore,int index){

    int index_arbore_dim_minima=index;
    int arbore_stanga=2*index+1;
    int arbore_dreapta=2*index+2;

    if(arbore_stanga<arbore->dim && arbore->vect_arbori[arbore_stanga]->fr_ap<arbore->vect_arbori[index_arbore_dim_minima]->fr_ap)
        index_arbore_dim_minima = arbore_stanga;

    if(arbore_dreapta<arbore->dim && arbore->vect_arbori[arbore_dreapta]->fr_ap<arbore->vect_arbori[index_arbore_dim_minima]->fr_ap)
        index_arbore_dim_minima = arbore_dreapta;

    if(index_arbore_dim_minima!=index){
        interschimba_ArboreHuffman(&arbore->vect_arbori[index_arbore_dim_minima],&arbore->vect_arbori[index]);
        ordonareArboreHuffman(arbore,index_arbore_dim_minima);
    }
}

// functia areUnSingurNod, testeaza daca arborele specificat ca argument, are dimensiunea 1 (adica are un singur nod)
int areUnSingurNod(struct Arbore* arbore){
    return (arbore->dim==1); // conditia de testare returneaza valoarea 1 daca dimensiunea arborelui este 1
}

//functia extragereArboreMinim permite extragere arborelui de dimensiune minima
struct NodArboreHuffman* extragereArboreMinim(struct Arbore* arbore){

    struct NodArboreHuffman* a=arbore->vect_arbori[0]; // se defineste un arbore "a" ca fiind arborele cu dimensiunea minima (vect_arbori[0])
    arbore->vect_arbori[0]=arbore->vect_arbori[arbore->dim-1];// se suprascrie arborele minim cu arborele de pe pozitia (dimensiune-1);
    --arbore->dim;//se decrementeaza dimensiunea arborelui datorita extragerii arborelui minim
    ordonareArboreHuffman(arbore, 0);
    return a; //se returneaza arborele de dimensiune minima
}

// functia inserareNod permite introducerea unui nod intr-un arbore
void inserareNod(struct Arbore* arbore,struct NodArboreHuffman* nod){

    ++arbore->dim; // se incrementeaza dimensiunea arborelui cu 1 deoarece se va introduce un nou nod
    int i=arbore->dim-1; // se initializeaza variabila i cu valoarea anterioara a dimensiunii arborelui

    while(i && nod->fr_ap<arbore->vect_arbori[(i-1)/2]->fr_ap){
        arbore->vect_arbori[i]=arbore->vect_arbori[(i-1)/2];
        i=(i-1)/2;
    }

    arbore->vect_arbori[i]=nod;
}

// functia de ordonare a vectorului de arbori, subarbori ai arborului specificat ca parametru
void ord_vect_arbori(struct Arbore* arbore){

    int n=arbore->dim-1;
    int i;

    for (i=(n-1)/2;i>=0;--i)
        ordonareArboreHuffman(arbore,i);
}

// functie de afisare a unui vector de numere intregi cu dimensiunea n
void afisareVector(int vector[], int n){
    int i;
    for(i=0;i<n;++i)
        cout<<vector[i];

    cout<<"\n";
}

// functia esteFrunza testeaza daca nodul nod este frunza a arborelui
int esteFrunza(struct NodArboreHuffman* nod){

    return !(nod->nodf_stanga) && !(nod->nodf_dreapta); // returneaza valoarea conditiei ca nodul nod sa nu aiba fii un nod stanga, respectiv, un nod dreapta
}

// functia initializare_Arbore returneaza un arbore care contine ca noduri, caracterele si frecventa de aparitie corespunzatoare, specificate ca parametri ai functiei
struct Arbore* initializare_Arbore(char sir_caractere[], int frecventa_aparitie[], int dimensiune){

    struct Arbore* arbore=creareArboreHuffman(dimensiune); // este definit un arbore Huffman cu dimensiunea specificata

    for(int i=0;i<dimensiune;++i)
        arbore->vect_arbori[i]=defNodNou(sir_caractere[i], frecventa_aparitie[i]); // se adauga un nou nod la arbore, care contine fiecare caracter cu frecventa specificata prin frecventa_aparitie[i]

    arbore->dim=dimensiune; // se seteaza dimensiunea arborelui
    ord_vect_arbori(arbore);

    return arbore; // se returneaza arborele definit anterior
}

// Functia principala de construire a arborelui Huffman
struct NodArboreHuffman* construireArboreHuffman(char sir_caractere[], int frecventa_asociata[], int dimensiune){
    struct NodArboreHuffman *nod_fiu_stanga, *nod_fiu_dreapta, *nod_parinte;

    // Pasul 1: se initializeaza arbore corespunzator functiei initializare_Arbore descrisa anterior
    struct Arbore* arbore=initializare_Arbore(sir_caractere,frecventa_asociata,dimensiune);

    while(!areUnSingurNod(arbore)){

        // Pasul 2: se extrag nodurile cu cele mai mici 2 frecvente de aparitie (probabilitatea cea mai mica) si se initializeaza nod_fiu_stanga, respectiv, nod_fiu_dreapta
        nod_fiu_stanga=extragereArboreMinim(arbore);
        nod_fiu_dreapta=extragereArboreMinim(arbore);

        // Pasul 3: Este creat un nou nod intern a carui frecventa de aparitie este obtinuta prin insumarea frecventelor asociate nodurilor fii.
        // Vom utiliza caracterul $ pentru a simboliza definirea unui nod intern. Acest caracter nu poate fi utilizat in cadrul sirului de caractere specificat ca parametru
        nod_parinte=defNodNou('$',nod_fiu_stanga->fr_ap+nod_fiu_dreapta->fr_ap);

        nod_parinte->nodf_stanga=nod_fiu_stanga;
        nod_parinte->nodf_dreapta=nod_fiu_dreapta;

        inserareNod(arbore,nod_parinte);
    }

    return extragereArboreMinim(arbore);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void afisareCodificareHuffman(struct NodArboreHuffman* nod_radacina,int vector[],int index){

    // Se adauga valoarea "0" la parcugerea spre stanga a arborelui (nodul radacina este reinitializat cu nodul fiu din stanga)
    if (nod_radacina->nodf_stanga){
        vector[index]=0;
        afisareCodificareHuffman(nod_radacina->nodf_stanga,vector,index+1);
    }

    // Se adauga valoarea "1" la parcugerea spre dreapta a arborelui (nodul radacina este reinitializat cu nodul fiu din dreapta)
    if(nod_radacina->nodf_dreapta){
        vector[index]=1;
        afisareCodificareHuffman(nod_radacina->nodf_dreapta,vector,index+1);
    }

 	// daca nodul radacina este nod frunza, atunci acesta contine unul din caracterele de intrare si atunci va fi afisat codul sau Huffman continut in vector
    if(esteFrunza(nod_radacina)){
        printf("%c: ",nod_radacina->caracter);
        afisareVector(vector,index);
    }
}

// functia principala de traversare a nodurilor arborelui Huffman
void traversareArboreHuffman(char sir_caractere[],int frecventa_asociata[],int dimensiune){
    // Construct Huffman Tree
    struct NodArboreHuffman* nod_radacina=construireArboreHuffman(sir_caractere,frecventa_asociata,dimensiune);
    int vector[NR_MAX_ARBORI],index_nod_radacina=0;

    afisareCodificareHuffman(nod_radacina,vector,index_nod_radacina);
}

// functia string_car_unice returneaza un sir de caractere unice, distincte
string string_car_unice(string sir){
	int i,x,k=0;
	int len=sir.length();
	string sir_rez="";
	sir_rez+=sir[0];


	for(i=1;i<len;i++){
		for(x=0;x<sir_rez.length()+1;x++){

    		if(sir[i]==sir_rez[x]){
    			k=1;
    		}
 		}

 		if(k==0){
 			sir_rez+=sir[i];
 		}

  	k=0;
	}


	return sir_rez;
}

int main(){


 	string sir_caractere;
 	cout<<"Introduceti sirul de caractere pt. care se doreste aplicarea algoritmului de compresie Huffman:\n";
 	std::getline(std::cin,sir_caractere);

 	string sir_car_distincte=string_car_unice(sir_caractere);
 	cout<<"\nSirul de caractere distincte obtinut="<<sir_car_distincte<<"\n";
 	int i,j,aux;

 	int frecventa_asociata[sir_car_distincte.length()];
 	for(i=0;i<sir_car_distincte.length();i++){
 		frecventa_asociata[i]=0;
 	}

 	for(i=0;i<sir_car_distincte.length();i++){
 		for(j=0;j<sir_caractere.length();j++){
 			if(sir_car_distincte[i]==sir_caractere[j]){
 				frecventa_asociata[i]++;
			 }

		}
		cout<<"\nNr. aparitii caracter "<<sir_car_distincte[i]<<"="<<frecventa_asociata[i];
	}

  	for(i=0;i<sir_car_distincte.length()-1;i++){
	    for(j=i+1;j<sir_car_distincte.length();j++){
        	if(frecventa_asociata[i]>frecventa_asociata[j]){
        		aux=frecventa_asociata[j];
        		frecventa_asociata[j]=frecventa_asociata[i];
        		frecventa_asociata[i]=aux;
        		aux=sir_car_distincte[j];
        		sir_car_distincte[j]=sir_car_distincte[i];
        		sir_car_distincte[i]=aux;
        	}
    	}

	}
	char vect_car[sir_car_distincte.length()];

	cout<<"\n"<<"\nVectorul caracterelor ordonate dupa prioritatea aparitiei:\n";
	for(i=0;i<sir_car_distincte.length();i++){
		cout<<sir_car_distincte[i]<<":"<<frecventa_asociata[i]<<"\n";
		vect_car[i]=sir_car_distincte[i];
	}

    int dimensiune=sir_car_distincte.length();
 	cout<<"\nPrin aplicarea algoritmului de compresie Huffman se obtine:\n";
    traversareArboreHuffman(vect_car,frecventa_asociata,dimensiune);

    return 0;
}
