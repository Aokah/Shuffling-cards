#include <iostream>
#include <ctime>
#include <new>
using namespace std;


struct carte{
  string symbole;
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
				add->symbole = "Pic";
			}
			else if(i==1){
				add->num = to_string(j);
				add->symbole = "Coeur";
			}
			else if(i==2){
				add->num = to_string(j);
				add->symbole = "Trefle";
			}
			else if(i==3){
				add->num = to_string(j);
				add->symbole = "Carreau";
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
    int a = rand()%52;
    cout << "Carte : " << a << " Numéro : " << p->c[a]->num << " Symbole : " << p->c[a]->symbole << endl;
  }
}

void shuffle(Paquet *p, int coeff){
  for(int i=0; i<coeff; i++){
    carte *tmp;
    int a = rand()%52;
    int b = rand()%52; 
    tmp = p->c[a];    
    p->c[a] = p->c[b];
    p->c[b] = tmp;
  }
}

void print_deck(Paquet p){
	for(int i=0; i<52; i++){
		cout << "Carte : " << i << " Numéro : " << p.c[i]->num << " Symbole : " << p.c[i]->symbole << endl;
	}
}

void test_shuffle(Paquet p){
	int cpt = 0;
	int cpt2 = 0;
	string prev_symb = p.c[0]->symbole;
	string prev_num = p.c[0]->num;
	
	for(int i=1; i<52; i++){
		if(p.c[i]->symbole == prev_symb){
			cpt++;
			if(prev_num == "Valet" || prev_num == "Dame" || prev_num == "Roi" || prev_num == "As" || p.c[i]->num == "As" || p.c[i]->num == "Valet" || p.c[i]->num == "Dame" || p.c[i]->num == "Roi"){
				if(prev_num == "As" || p.c[i]->num == "As"){
					if(p.c[i]->num == to_string(2)) cpt2++;
				}
				if(prev_num == "Valet" || p.c[i]->num == "Valet"){
					if(p.c[i]->num == "Dame") cpt2++;
				}
				else if(prev_num == "Dame" || p.c[i]->num == "Dame"){
					if(p.c[i]->num == "Roi") cpt2++;
				} 
				else if(prev_num == "Roi" || p.c[i]->num == "Roi"){
					if(p.c[i]->num == "As") cpt2++;
				}
			}
			else if(p.c[i]->num == to_string(std::stoi(prev_num) +1)) cpt2++;
		}
		prev_symb = p.c[i]->symbole;
		prev_num = p.c[i]->num;
	}

	cout << "Le nombre de cartes qui se suivent et qui possèdent un symbole identique est : " << cpt << endl;
	cout << "Compris dans ce nombre, le nombre de cartes qui se suivent, qui possèdent un symbole identique et dont les chiffres sont liés par addition de 1 avec la suivante : " << cpt2 << endl;
}

int main() {
	srand(time(NULL));
	Paquet *p = new Paquet;

	fill_deck(&p);
	format_names(&p);
	//print_deck(*p);
	test_shuffle(*p);
	
	shuffle(p, 52);
	print_deck(*p);
	test_shuffle(*p);
}
