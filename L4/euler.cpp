#include<iostream>
using namespace std;
int a[20][20]; // Declarați un tablou bidimensional pentru a reprezenta matricea de adiacență a grafului
int n; // Variabila pentru a stoca numărul de noduri în graf
int drum1[50],drum[50],drum2[50],ini[50],gasit; // Declarați tablouri pentru a stoca drumurile și alte variabile auxiliare

// Funcție pentru a găsi un subciclu pornind de la un nod dat
void ciclu(int nod){
    int nod1=nod,i=1,gasit=0,j; // Inițializarea variabilelor pentru a parcurge graful și a verifica dacă s-a găsit un ciclu
    do{j=1;
    while(a[nod1][j]==0)j++; // Găsim următorul nod adiacent disponibil pentru nodul curent
    drum1[i]=j;a[nod1][j]=0;a[j][nod1]=0; // Adăugăm nodul în drum și ștergem muchia dintre noduri
    nod1=j;i++;
    if(j==nod) gasit=1; // Verificăm dacă am revenit la nodul de start
    }while(!gasit); // Continuăm până când găsim un ciclu complet

    cout<<"\n\n construire subciclu pornind de la nodul\n"<<nod<<endl; // Afișăm subciclul construit
}

// Funcție pentru a copia conținutul unui vector în altul
void copY(int x[],int y[]){
    int i=1;
    while(i<49) {x[i]=y[i];i++;}
}

// Funcție pentru a inițializa vectorii
void init(){
    for(int i=1;i<=n;i++) {drum[i]=0;drum1[i]=0;drum2[i]=0;ini[i]=0;}
}

// Funcție pentru a găsi un ciclu Eulerian
void euler(){
    int i=1,j;
    do{
        ciclu(drum[i]); // Găsim un subciclu începând cu nodul curent
        for(int l=1;l<=i;l++) drum2[l]=drum[l]; // Copiem drumul curent într-un alt vector
        j=1;
        while(drum1[j]){
            drum2[i+j]=drum1[j];j++;}j--;int l=1;
        while(drum[i+l]!=0) {drum2[i+j+l]=drum[i+l];l++;}
        copY(drum,drum2);copY(drum2,ini);copY(drum1,ini); // Actualizăm drumurile
        i=1;
        gasit=0;
        while(drum[i]&&!gasit){for(int j=1;j<=n;j++) if(a[drum[i]][j])gasit=1;
	                                             i++;}
        i--;
    }while(gasit); // Continuăm până când nu mai putem adăuga noduri în drum
}

int main(){
    cin>>n; // Citim numărul de noduri în graf

    // Citim matricea de adiacență a grafului
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    
    // Inițializăm vectorii
    init();

    drum[1]=1; // Alegem primul nod ca fiind nodul de start pentru ciclu
    euler(); // Găsim ciclul Eulerian în graf
    int i=1;cout<<"ciclu eulerian"; // Afișăm ciclul Eulerian
    while(drum[i]) {cout<<drum[i]<<" ";i++;}
}
