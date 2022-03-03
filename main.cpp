#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <bits/stdc++.h>

#include "main.h"
#include "print.h"
#include "iof.h"
#include "coins.h"

int state;

void progress() {
    sleep(1);
    std::cout<<".";
    sleep(1);
    std::cout<<".";
    sleep(1);
    std::cout<<".\n";
    sleep(1);
}

char menu() {
    char in;
    std::cout.setf(std::ios::fixed);

    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime (&rawtime);

    if (state == 0) {

        if (timeinfo->tm_hour>4 && timeinfo->tm_hour<16){
            if (timeinfo->tm_min<10)
                std::cout<<"\n\nBuongiorno! *********************** "<<timeinfo->tm_hour<<":0"<<timeinfo->tm_min<<"\n";
            else
                std::cout<<"\n\nBuongiorno! *********************** "<<timeinfo->tm_hour<<":"<<timeinfo->tm_min<<"\n";
        }
        else {
            if (timeinfo->tm_min<10)    
                std::cout<<"\n\nBuonasera! ************************ "<<timeinfo->tm_hour<<":0"<<timeinfo->tm_min<<"\n";
            else
                std::cout<<"\n\nBuonasera! ************************ "<<timeinfo->tm_hour<<":"<<timeinfo->tm_min<<"\n";
        }


        std::cout<<"***************** MENU ******************\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [m] Inserisci monete\n";
        std::cout<<"\t> [s] Compra prodotto\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n";
        std::cout<<"\n\t> [a] Admin\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 1) {

        std::cout<<"\n\n********* COS'ALTRO VUOI FARE? **********\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [m] Inserisci monete\n";
        std::cout<<"\t> [s] Compra prodotto\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 2) {

        std::cout<<"\n\n********* COS'ALTRO VUOI FARE? **********\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [s] Compra prodotto\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 3) {

        std::cout<<"\n\n********* COS'ALTRO VUOI FARE? **********\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [m] Inserisci monete\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 4) {

        std::cout<<"\n\n********* COS'ALTRO VUOI FARE? **********\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [m] Inserisci monete\n";
        std::cout<<"\t> [s] Compra prodotto\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 5) {

        std::cout<<"\n\n******* PRODOTTO NON DISPONIBILE ********\n";
        std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [s] Scegli un 'altro prodotto\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    else if (state == 6) {

        std::cout<<"\t> [v] Visualizza altri prodotti\n";
        std::cout<<"\t> [m] Inserisci monete\n";
        std::cout<<"\t> [s] Scegli un'altro prodotto\n\n";
        if (balance>0)
            std::cout<<"\t> [r] Restituisci resto\n\n";
        std::cout<<"\t> [e] Torna al menu principale\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }

    if (state == 7) {

        if (timeinfo->tm_hour>4 && timeinfo->tm_hour<16){
            if (timeinfo->tm_min<10)
                std::cout<<"\n\nBuongiorno Admin! ***************** "<<timeinfo->tm_hour<<":0"<<timeinfo->tm_min<<"\n";
            else
                std::cout<<"\n\nBuongiorno Admin! ***************** "<<timeinfo->tm_hour<<":"<<timeinfo->tm_min<<"\n";
        }
        else {
            if (timeinfo->tm_min<10)    
                std::cout<<"\n\nBuonasera Admin! ****************** "<<timeinfo->tm_hour<<":0"<<timeinfo->tm_min<<"\n";
            else
                std::cout<<"\n\nBuonasera Admin! ****************** "<<timeinfo->tm_hour<<":"<<timeinfo->tm_min<<"\n";
        }

        std::cout<<"***************** MENU ******************\n";
        std::cout<<"\t> [v] Visualizza prodotti\n";
        std::cout<<"\t> [+] Rifornimento\n";
        std::cout<<"\t> [p] Modifica prezzi\n";
        std::cout<<"\n\t> [e] Esci\n";
        std::cout<<"\n*****************************************\n";
        std::cin>>in;
    }
    

    return in;
}

int main() {
    state = 0;

    struct BEVERAGE storage[ROWS];
    balance = 0;

    // TODO: update ogni TOT per l'orario

    readFile(storage);

    while (true) {

        switch (menu()) {
            case 'v':
                printAllBeverages(storage);
                if (state == 7)
                    break;
                state = 1;
                break;
            case 'm':
                insertCoins();
                state = 2;
                break;
            case 's':
                state = 3;
                int temp, id, s;

                std::cout<<"Inserisci il codice prodotto: ";
                std::cin>>temp; //TODO: Problema con Caratteri diversi dagli interi

                id = temp/10;

                s = temp%10;

                if (storage[id-1].s[s]==0){
                    state = 5;
                    break;
                }
                
                if (storage[id-1].price>balance){
                    state = 6;
                    std::cout.setf(std::ios::fixed);

                    std::cout<<"\n\n********* SALDO NON SUFFICIENTE *********\n";
                    std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]"<<std::setw(21)<<"[Mancano: "<<std::setprecision(2)<<storage[id-1].price-balance<<"$]\n";
                    break;
                }
                std::cout<<"Prodotto in erogazione"/*Inserire progress bar*/;
                progress();
                storage[id-1].s[s]--;
                writeFile(storage);
                balance -= storage[id-1].price;
                break;

            case 'r':
                state = 4;
                if (balance>0) {
                    std::cout<<"Erogazione resto di "<<balance<<"$ in corso"/*Progress bar da inserire*/;
                    progress();
                    balance = 0;
                }
                break;
            
            case 'a': {
                char c=' ';
                int test = 0;
                std::cout<<"Inserisci password: ";
                for (int i=0;i<5;i++) {
                    c=getch();
                    test+=c;
                    std::cout<<"*";
                }
                if (test == 521){
                    state = 7;
                    break;
                }
                std::cout<<"\nPassword Errata!";
                break;
            }

            case '+': 
                if (state != 7){
                    std::cout<<"Non possiedi i permessi necessari\nRicarico menu principale";
                    progress();
                    state = 0;
                    break;
                }
                temp = 0, id = 0, s = 0;
                std::cout<<"Inserisci ID prodotto da rifornire: ";
                std::cin>>temp; //Problema con Caratteri diversi dagli interi

                id = temp/10;

                s = temp%10;

                //CONTROLLO
                if (id<10 && s<5){
                        if (storage[id-1].s[s]==10){
                        std::cout<<"Lo scaffale e' già rifornito.\n";
                        sleep(1);
                        break;
                    }
                    storage[id-1].s[s]=10;
                    std::cout<<"Lo scaffale viene rifornito";
                    progress();
                    writeFile(storage);

                    break;
                }

                std::cout<<"ID prodotto non trovato";
                progress();
                break;

            case 'p':
                if (state != 7){
                    std::cout<<"Non possiedi i permessi necessari\nRicarico menu principale";
                    progress();
                    state = 0;
                    break;
                }

                id = 0;
                float tprice;
                std::cout<<"Inserisci Riga prodotti da modificare: ";
                std::cin>>id; //Problema con Caratteri diversi dagli interi

                //CONTROLLO
                if (id<10){
                    std::cout<<"Inserisci il nuovo prezzo del prodotto "<<storage[id-1].name<<": ";
                    std::cin>>tprice;
                    if (tprice < 0.50 || tprice > 5) {
                        std::cout<<"Il prezzo non e' valido, inserire un valore tra 0.50$ e 5.00$\n";
                        sleep(1);
                        break;
                    }
                    std::cout<<"Il prezzo del prodotto "<<storage[id-1].name<<" viene modificato da "<<storage[id-1].price<<" a "<<tprice;
                    progress();
                    storage[id-1].price = tprice;
                    writeFile(storage);
                    break;
                }

                std::cout<<"Riga prodotti non valida\n";
                sleep(1);
                break;

            case 'e':
                state = 0;
                break;

            default:
                return -1;
        }
        // system("cls");
    }    
    return 0;
}