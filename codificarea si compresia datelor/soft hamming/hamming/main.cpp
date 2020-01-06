#include<iostream>

using namespace std;

int main() {

	int nr_biti=0,nr_biti_paritate=0,pozitie_bit_eroare=0,i;
	cout<<"Introduceti nr. de biti (7 sau 15)=";
	cin>>nr_biti;

	int vect_biti[nr_biti];

	if(nr_biti==7){
		nr_biti_paritate=3;

		cout<<"\nSpecificati valoarea celor 4 biti de date independenti";
		cout<<"\nbit. nr. 1=";
		cin>>vect_biti[2];
		cout<<"bit. nr. 2=";
		cin>>vect_biti[4];
		cout<<"bit. nr. 3=";
		cin>>vect_biti[5];
		cout<<"bit. nr. 4=";
		cin>>vect_biti[6];

		//Calcularea celor 3 biti de paritate
		vect_biti[0]=vect_biti[2]^vect_biti[4]^vect_biti[6];
    	vect_biti[1]=vect_biti[2]^vect_biti[5]^vect_biti[6];
    	vect_biti[3]=vect_biti[4]^vect_biti[5]^vect_biti[6];

		cout<<"\nCodificarea Hamming(7,4) aplicata bitilor de date independenti specificati este:\n";
    	for(i=0;i<nr_biti;i++){
    		cout<<vect_biti[i];
		}
    }

	if(nr_biti==15){
		nr_biti_paritate=4;

		cout<<"\Valoarea celor 11 biti de date independenti";
		cout<<"\nbit. nr. 1=";
		cin>>vect_biti[2];
		cout<<"bit. nr. 2=";
		cin>>vect_biti[4];
		cout<<"bit. nr. 3=";
		cin>>vect_biti[5];
		cout<<"bit. nr. 4=";
		cin>>vect_biti[6];
		cout<<"bit. nr. 5=";
		cin>>vect_biti[8];
		cout<<"bit. nr. 6=";
		cin>>vect_biti[9];
		cout<<"bit. nr. 7=";
		cin>>vect_biti[10];
		cout<<"bit. nr. 8=";
		cin>>vect_biti[11];
		cout<<"bit. nr. 9=";
		cin>>vect_biti[12];
		cout<<"bit. nr. 10=";
		cin>>vect_biti[13];
		cout<<"bit. nr. 11=";
		cin>>vect_biti[14];

		//Calcularea bitilor de paritate
		vect_biti[0]=vect_biti[2]^vect_biti[4]^vect_biti[6]^vect_biti[8]^vect_biti[10]^vect_biti[12]^vect_biti[14];
    	vect_biti[1]=vect_biti[2]^vect_biti[5]^vect_biti[6]^vect_biti[9]^vect_biti[10]^vect_biti[13]^vect_biti[14];
    	vect_biti[3]=vect_biti[4]^vect_biti[5]^vect_biti[6]^vect_biti[11]^vect_biti[12]^vect_biti[13]^vect_biti[14];
    	vect_biti[7]=vect_biti[8]^vect_biti[9]^vect_biti[10]^vect_biti[11]^vect_biti[12]^vect_biti[13]^vect_biti[14];

		cout<<"\nCodificarea Hamming(15,11) este:\n";
    	for(i=0;i<nr_biti;i++){
    		cout<<vect_biti[i];
		}
    }

	int vect_biti_receptionati[nr_biti];
	int vect_biti_paritate[nr_biti_paritate];

	cout<<"\n\nIntroduceti bitii de date receptionati\n";
    for(i=0;i<nr_biti;i++){
	    cin>>vect_biti_receptionati[i];
	}

	if(nr_biti==7){
		vect_biti_paritate[0]=vect_biti_receptionati[0]^vect_biti_receptionati[2]^vect_biti_receptionati[4]^vect_biti_receptionati[6];
 		vect_biti_paritate[1]=vect_biti_receptionati[1]^vect_biti_receptionati[2]^vect_biti_receptionati[5]^vect_biti_receptionati[6];
    	vect_biti_paritate[2]=vect_biti_receptionati[3]^vect_biti_receptionati[4]^vect_biti_receptionati[5]^vect_biti_receptionati[6];

		pozitie_bit_eroare=vect_biti_paritate[2]*4+vect_biti_paritate[1]*2+vect_biti_paritate[0];
 	}

 	if(nr_biti==15){
		vect_biti_paritate[0]=vect_biti_receptionati[0]^vect_biti_receptionati[2]^vect_biti_receptionati[4]^vect_biti_receptionati[6]^vect_biti_receptionati[8]^vect_biti_receptionati[10]^vect_biti_receptionati[12]^vect_biti_receptionati[14];
    	vect_biti_paritate[1]=vect_biti_receptionati[1]^vect_biti_receptionati[2]^vect_biti_receptionati[5]^vect_biti_receptionati[6]^vect_biti_receptionati[9]^vect_biti_receptionati[10]^vect_biti_receptionati[13]^vect_biti_receptionati[14];
    	vect_biti_paritate[2]=vect_biti_receptionati[3]^vect_biti_receptionati[4]^vect_biti_receptionati[5]^vect_biti_receptionati[6]^vect_biti_receptionati[11]^vect_biti_receptionati[12]^vect_biti_receptionati[13]^vect_biti_receptionati[14];
    	vect_biti_paritate[3]=vect_biti_receptionati[7]^vect_biti_receptionati[8]^vect_biti_receptionati[9]^vect_biti_receptionati[10]^vect_biti_receptionati[11]^vect_biti_receptionati[12]^vect_biti_receptionati[13]^vect_biti_receptionati[14];
		pozitie_bit_eroare=vect_biti_paritate[3]*8+vect_biti_paritate[2]*4+vect_biti_paritate[1]*2+vect_biti_paritate[0];
 	}



    if(pozitie_bit_eroare==0){
        cout<<"\nNu exista erori in transmiterea datelor\n";
    }
    else {
        cout<<"\nEroare detectata la bitul nr. "<<pozitie_bit_eroare;
    }

    cout<<"\nVector de biti transmis: ";
    for(i=0;i<nr_biti;i++)
        cout<<vect_biti[i];

    cout<<"\nVector de biti receptionat: ";
    for(i=0;i<nr_biti;i++)
        cout<<vect_biti_receptionati[i];

    return 0;
}
