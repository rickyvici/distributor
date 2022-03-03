#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include <string.h>
#include <conio.h>

#include "main.h"
#include "print.h"
#include "iof.h"
#include "coins.h"

enum State {INITIAL, NORMAL, NOT_AVAILABLE, ADMIN};

State state;

/* 
    PROGRESS BAR 😍
*/
void progress(int n) {
    const int TOT = 30;

    for (int i = 0; i < TOT; i+=(TOT/(float)n)) {

        std::cout<<"\r\r";
        std::cout<<"\t[";

        for (int j = 0; j < i; j++)
            std::cout<<"#";
        for (int j = 0; j < TOT-i-1; j++)
            std::cout<<"-";

        std::cout<<"]";
        sleep(1);
    }

    std::cout<<"\n";
}

/*
    Function that prints a divider with a left message, a center message, and a right message.
    Note that the total width of the divider is of 42 characters.
*/
void print_divider(std::string str_l, std::string str_c, std::string str_r) {
    int div_size = 42;

    std::string _str_l = str_l + " ";
    std::string _str_c = " " + str_c + " ";
    std::string _str_r = " " + str_r;

    int l_len = _str_l.length();
    int c_len = _str_c.length();
    int r_len = _str_r.length();

    std::string str_out = "";

    if (str_l.length()!=0) str_out += _str_l;
    else str_out += "*";
    for (int i = 0; i < div_size/2 - c_len/2 - l_len + 1; i++) str_out += "*";

    if (str_c.length()!=0) str_out += _str_c;
    else str_out += "**";

    for (int i = 0; i < div_size/2 - c_len/2 - r_len + 1; i++) str_out += "*";
    if (str_r.length()!=0) str_out += _str_r;
    else str_out += "*";

    str_out += "\n";

    std::cout << str_out;
}

/*
    Print the initial greetings for the user or for the admin to the left,
    and the current time to the right.
*/
void print_greetings(struct tm* timeinfo, bool is_admin) {
    std::string greeting = timeinfo->tm_hour>4 && timeinfo->tm_hour<16 ? "Buongiorno" : "Buonasera";
    if (is_admin) greeting += " Admin";
    greeting += "!";
    std::string _time = std::to_string(timeinfo->tm_hour) + ":" + (timeinfo->tm_min<10 ? "0" : "") + std::to_string(timeinfo->tm_min);
    std::cout<<"\n";
    print_divider(greeting, "", _time);
}

/*
    Print the default actions of the distributor for the user
*/
void print_default_actions(float balance) {
    std::cout.setf(std::ios::fixed);
    std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]\n";
    std::cout<<"\t> [v] Visualizza prodotti\n";
    std::cout<<"\t> [m] Inserisci monete\n";
    std::cout<<"\t> [s] Compra prodotto\n";
    if (balance>0)
        std::cout<<"\t> [r] Restituisci resto\n\n";
}

char menu() {
    char in;

    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime (&rawtime);
    
    switch(state) {
        case INITIAL:
            print_greetings(timeinfo, false);
            print_divider("", "MENU", "");
            print_default_actions(balance);
            std::cout<<"\n\t> [a] Admin\n";
            print_divider("","","");
            break;
        case NORMAL:
            print_divider("", "COS'ALTRO VUOI FARE?", "");
            print_default_actions(balance);
            std::cout<<"\t> [e] Torna al menu principale\n";
            print_divider("","","");
            break;
        case NOT_AVAILABLE:
            print_divider("","PRODOTTO NON DISPONIBILE", "");
            print_default_actions(balance);
            std::cout<<"\t> [e] Torna al menu principale\n";
            print_divider("","","");
            break;
        case ADMIN:
            print_greetings(timeinfo, true);
            print_divider("", "MENU", "");
            std::cout<<"\t> [v] Visualizza prodotti\n";
            std::cout<<"\t> [+] Rifornimento\n";
            std::cout<<"\t> [p] Modifica prezzi\n";
            std::cout<<"\n\t> [e] Esci\n";
            print_divider("","","");
            break;
    }

    std::cin>>in;

    return in;
}

int main() {
    state = INITIAL;

    struct BEVERAGE storage[ROWS];
    balance = 0;

    // TODO: update ogni TOT per l'orario

    readFile(storage);

    while (true) {

        switch (menu()) {
            case 'v':
                printAllBeverages(storage);
                if (state == ADMIN)
                    break;
                state = NORMAL;
                break;
            case 'm':
                insertCoins();
                state = NORMAL;
                break;
            case 's':
                state = NORMAL;
                int temp, id, s;

                std::cout<<"Inserisci il codice prodotto: ";
                std::cin>>temp; //TODO: Problema con Caratteri diversi dagli interi

                id = temp/10;

                s = temp%10;

                if (storage[id-1].s[s]==0){
                    state = NOT_AVAILABLE;
                    break;
                }
                
                if (storage[id-1].price>balance){
                    state = NOT_AVAILABLE;
                    std::cout.setf(std::ios::fixed);

                    print_divider("","SALDO NON SUFFICIENTE", "");
                    std::cout<<"[Saldo: "<<std::setprecision(2)<<balance<<"$]"<<std::setw(21)<<"[Mancano: "<<std::setprecision(2)<<storage[id-1].price-balance<<"$]\n";
                    break;
                }
                std::cout<<"Prodotto in erogazione\n"/*Inserire progress bar*/;
                progress(5);
                storage[id-1].s[s]--;
                writeFile(storage);
                balance -= storage[id-1].price;
                break;

            case 'r':
                state = NORMAL;
                if (balance>0) {
                    std::cout<<"Erogazione resto di "<<balance<<"$ in corso\n"/*Progress bar da inserire*/;
                    progress(5);
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
                    state = ADMIN;
                    break;
                }
                std::cout<<"\nPassword Errata!";
                break;
            }

            case '+': 
                if (state != ADMIN){
                    std::cout<<"Non possiedi i permessi necessari\nRicarico menu principale\n";
                    progress(2);
                    state = INITIAL;
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
                    std::cout<<"Lo scaffale viene rifornito\n";
                    progress(10);
                    writeFile(storage);

                    break;
                }

                std::cout<<"ID prodotto non trovato\n";
                progress(2);
                break;

            case 'p':
                if (state != ADMIN){
                    std::cout<<"Non possiedi i permessi necessari\nRicarico menu principale\n";
                    progress(2);
                    state = INITIAL;
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
                    std::cout<<"Il prezzo del prodotto "<<storage[id-1].name<<" viene modificato da "<<storage[id-1].price<<" a "<<tprice << "\n";
                    progress(3);
                    storage[id-1].price = tprice;
                    writeFile(storage);
                    break;
                }

                std::cout<<"Riga prodotti non valida\n";
                sleep(1);
                break;

            case 'e':
                state = INITIAL;
                break;

            default:
                return -1;
        }
        // system("cls");
    }

    return 0;
}