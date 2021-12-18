#include <iostream>
#include <ctime>
#include <vector>
#include <new>
using namespace std;


struct carte{
  string Symbole;
  string num;
};

struct Paquet{
	carte *c[52];
};

//juste mettre num = i pour num carte
void fill_deck(Paquet **p){
	int cpt = 0;
	for(int i=0; i<4; i++){
		for(int j=1; j<14; j++){
			carte * add = new carte;
			if(i==0){
		        add->num = to_string(j);
				add->Symbole = "Pic";
			}
			else if(i==1){
				add->num = to_string(j);
				add->Symbole = "Coeur";
			}
			else if(i==2){
				add->num = to_string(j);
				add->Symbole = "Trefle";
			}
			else if(i==3){
				add->num = to_string(j);
				add->Symbole = "Carreau";
			}
			(*p)->c[cpt] = add;
			cpt++;
		}
	}
}

void format_names(Paquet **p){
	int cpt = 0;
	for(int i=0; i<4; i++){
		for(int j=1; j<14; j++){
			carte *tmp = (*p)->c[cpt];
			if(tmp->num == "1"){
				tmp->num = "As";
			}
			if(tmp->num == "11"){
				tmp->num = "Valet";
			}
			if(tmp->num == "12"){
				tmp->num = "Dame";
			}
			if(tmp->num == "13"){
				tmp->num = "Roi";
			}
			cpt++;
		}
	}
}

void print_5_rand(Paquet *p){
  for(int i=0; i<5; i++){
    int a = rand()%52 +1;
    cout << "Carte : " << a << " Numéro : " << p->c[a]->num << " Symbole : " << p->c[a]->Symbole << endl;
  }
}

void shuffle(Paquet *p){//ajouter des cartes
  for(int i=0; i<52; i++){
    carte *tmp;
    int a = rand()%52 +1;
    int b = rand()%52 +1;
    tmp = p->c[a];    
    p->c[a] = p->c[b];
    p->c[b] = p->c[a];
  }
}

void test_shuffle(Paquet p){
//là où on va tester les cartes pour les stats, savoir si deux cartes de même symbole se suivent, savoir si 4 cartes de même symbole se suivent
  
}

int main() {
	srand(time(NULL));
	Paquet *p = new Paquet;

	fill_deck(&p);
	
	cout << p->c[51]->num << " de " << p->c[51]->Symbole << endl;

	format_names(&p);

	cout << p->c[51]->num << " de " << p->c[51]->Symbole << endl;
		
	
	//shuffle(p);
	
	print_5_rand(p);
}
