#include "griglia.h"
#include <vector>

#ifndef BATTLESHIP_GIOCATORE_H
#define BATTLESHIP_GIOCATORE_H

class Nave;

class Giocatore {
private:
    battaglia_navale::Griglia griglia_attacco;
    std::vector<Nave *> navi;

    //controllo se le coordinate della nave sono libere nella "griglia"
    bool is_posizionabile(Nave &nave);

public:
    //costruttore
    Giocatore() =default;

    //aggiunge una nave nella lista di navi
    void add_nave(Nave nave);

    //setta il risultato (X/O) di un'azione nella griglia di attacco
    void set_risultato(battaglia_navale::Coordinate coord, char stato);

    //restituisce le navi
    std::vector<Nave *> get_navi();

    void cancella_avvistamenti();

    std::vector<std::vector<char>> get_griglia_attacco();

    std::vector<std::vector<char>> get_griglia_difesa();
};

#include "nave.h"

#endif //BATTLESHIP_GIOCATORE_H

/*
// C++ program to show
// the need for Forward Declaration

#include <iostream>
	using namespace std;

class A;
class B;

class B {

public:
    int x;
	void getdata(int n)
	{
		x = n;
	}
	friend int sum(A, B);
};

class A {
public:
	int y;

	void getdata(int m)
	{
		y = m;
	}
	friend int sum(A, B);
};

int sum(A m, B n)
{
	int result;
	result = m.y + n.x;
	return result;
}

int main()
{
	B b;
	A a;
	a.getdata(5);
	b.getdata(4);
	cout << "The sum is : " << sum(a, b);
	return 0;
}

 */