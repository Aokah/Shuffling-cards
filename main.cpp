#include <iostream>
#include <ctime>
#include <new>
using namespace std;


struct carte{
  string Symbole;
  int num;
};

struct Paquet{
  carte c[52];
};

//juste mettre num = i pour num carte
void fill_deck(Paquet *p){
  for(int i=0; i<52+1; i++){
    cout << 1;
    if(i>=0 and i<13){
      p->c[i].Symbole = "Pic";
    }
    cout << 2;
    if(i>=13 and i<26){
      p->c[i].Symbole = "Coeur";
    }
    cout << 3;
    if(i>=26 and i<39){
      p->c[i].Symbole = "Trefle";
    }
    cout << 4;
    if(i>=0 and i<52){
      p->c[i].Symbole = "Carreau";
    }
    p->c[i].num = i;
  }
}

void print_5_rand(Paquet *p){
  for(int i=0; i<5; i++){
    int a = rand()%52 +1;
    cout << "Carte : " << a << " Symbole : " << p->c[a].Symbole << endl;
  }
}

void shuffle(Paquet *p){//ajouter des cartes
  for(int i=0; i<52; i++){
    carte tmp;
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
  Paquet *p;
  cout << 1;
  fill_deck(p);
  /*cout << 2;
  shuffle(p);
  cout << 3;
  print_5_rand(p);*/
}
