#include <iostream>
using namespace std;

struct Punkt1 {
    int x;
    int y;
};

struct Punkt1 utworzPunkt(int x, int y) {
    struct Punkt1 p;
    p.x = x;
    p.y = y;
    
    return p;
}

void wypiszPunkt(struct Punkt1 p) {
    printf("%d, %d", p.x, p.y);
}

int main()
{
    int kierunki[4] = {2, 2, 2, 2};
    int licznik = 0;
    int nr_kierunku = 0;
    char punkty[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    char kopia_punkty[10][10];
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            kopia_punkty[i][j] = punkty[i][j];
        }
    }
    
    struct Punkt1 punkt = utworzPunkt(3, 4);
    
    punkty[punkt.y][punkt.x] = 'X';
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << punkty[i][j];
        }
        cout << "\n";
    }
    
    for(int i = 0; i < 10; i++) {
        if(punkty[punkt.y][i] != punkty[punkt.y][punkt.x] && punkty[punkt.y][i] == '#') {
            licznik++;
        } else if(punkty[punkt.y][i] == punkty[punkt.y][punkt.x] || i == 9) {
            kierunki[nr_kierunku] = licznik;
            licznik = 0;
            nr_kierunku++;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        if(punkty[i][punkt.x] != punkty[punkt.y][punkt.x] && punkty[i][punkt.x] == '#') {
            licznik++;
        } else if(punkty[i][punkt.x] == punkty[punkt.y][punkt.x] || i == 9) {
            kierunki[nr_kierunku] = licznik;
            licznik = 0;
            nr_kierunku++;
        }
    }

    bool czy_znajduje = false;
    
    for(int i = 0; i < 4; i++) {
        if(kierunki[i] % 2 != 0) {
            czy_znajduje = true;
            break;
        }
    }
    
    if(kopia_punkty[punkt.y][punkt.x] == '#') {
        cout << "Punkt nie znajduje się w komnacie";
    } else if(czy_znajduje) {
        cout << "Punkt znajduje się w komnacie";
    } else {
        cout << "Punkt nie znajduje się w komnacie";
    }

    return 0;
}