#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

#include "iof.h"
#include "main.h"

#define FILE "prodotti.csv"

void readFile (struct BEVERAGE* storage) {

    int c=0;

    std::fstream fs;
    fs.open (FILE, std::fstream::in);

    // Controllo se il file è aperto
    if(!fs.is_open()){
        std::cout<<"\nErrore nell'apertura del file...ABORT";
        exit(-1);
    }
    
    char buffer[BUFFERDIM];

    fs.getline(buffer, BUFFERDIM);

    while (fs.getline(buffer, BUFFERDIM)){
        char* token = strtok(buffer, ",");
        int d=0;
        while (token){
            switch(d) {
                case 0: 
                    storage[c].id=atoi(token); 
                    break; 
                case 1: 
                    storage[c].name=token; 
                    break;
                case 2: 
                    storage[c].s[0]=atoi(token); 
                    break;
                case 3: 
                    storage[c].s[1]=atoi(token); 
                    break;
                case 4: 
                    storage[c].s[2]=atoi(token); 
                    break;
                case 5: 
                    storage[c].s[3]=atoi(token); 
                    break;
                case 6: 
                    storage[c].s[4]=atoi(token); 
                    break;
                case 7: 
                    storage[c].price=atof(token); 
                    break;
                default:  
                    break;
            }
            token = strtok(NULL, ",");
            d++;
        }
        c++; 
    }

    fs.close();
}

void writeFile (struct BEVERAGE* storage) {

    std::fstream fs;
    fs.open (FILE, std::fstream::out);
    
    fs.write("id,name,s1,s2,s3,s4,s5,price\n", 29);
    
    for (int i=0; i<ROWS; i++) {
        fs.setf(std::ios::fixed);
        fs<<storage[i].id<<",";
        fs<<storage[i].name<<",";
        for (int j=0; j<5; j++) 
            fs<<storage[i].s[j]<<",";
        fs<<std::setprecision(2)<<storage[i].price<<"\n";
    }
    
    fs.close();

}