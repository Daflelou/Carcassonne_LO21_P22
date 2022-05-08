#ifndef CARCASSONNE_LO21_P22_JOUEURRESSOURCES_H
#define CARCASSONNE_LO21_P22_JOUEURRESSOURCES_H

enum class MeepleTypes {"Abbe","MeppleNormaux","GrandMeeple"};

class JoueurRessources{

public :
  JoueurRessources(const string n):nom(n){
    points=0;
    if (ParametresPartie::getExtensionChoisie()) // a changer avec les vecteurs
      Meeple["Abbe"]=1;
    Meeple["MeepleNormaux"]=10;
    if (ParametresPartie::getExtensionChoisie())
      Meeple["GrandMeeple"]=2;

  }
  int getNbPoints() const {return points;}
  int getNbMeeple(MeepleTypes type){
    return Meeple[type];
  }

  void poserMeeple(MeepleTypes type) {
    if (Meeple[type]==0) {return "pas assez de meeple de cette catérogie";}
    Meeple[type]--;
    return;
  }
  void recupererMeeple(MeepleTypes type) {
    Meeple[type]++;
    return;
  }
  void ajouterPoints(int pt){
    points=points+pt;
  }


private :
  int points;
  string nom;
  map<MeepleType,int> Meeple;

  //nombre de points au fur et à mesure de la partie
  //nom du joueur
  //un tableau qui associe chaque type de meeple à son nombre restant

};


#endif //CARCASSONNE_LO21_P22_JOUEURRESSOURCES_H
