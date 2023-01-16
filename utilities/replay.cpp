#include <iostream>
#include <fstream>

using namespace std;

int fpeek(FILE* file)
{
    int carattere;

    carattere = fgetc(file);
    ungetc(carattere, file);

    return carattere;
}

int main(){

    FILE* file;
    char riga[100];

    //leggere il file

    fopen_s(&file, "F:\\wa_RikuTheFuffs\\C++\\2.0\\test.txt", "r"); //versione sicura

    if (file)
    {
        if (fpeek(file) != -1){
            fgets(riga, 100, file);
            while (!feof(file))
            {
                cout << riga;  // conversione da coordinate a tabella
                fgets(riga, 100, file);
            }
            fclose(file);
        }
    }
}


