#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "lexique.h"
#include "utilitaire.hpp"

lexique::lexique(std::string name, const char* path) {
    const std::string my_path = path;
    this->name = name;
    std::string text;
    readFileIntoString(my_path, text);
    toLower(text);
    char* text_char = text.data();
    char* mot = std::strtok(text_char, " ");
    while (mot != NULL) {
        std::string mot_str(mot);
        remove_punctuation(mot_str);
        if(lex.count(mot_str) == 1) {
            lex.at(mot_str) += 1; 
        }
        else {
            lex.insert({mot, 1});
        }
        mot = strtok(NULL, " \n.-\"()[],;|{}+-*/\\#_!?<>:");
    }
}

lexique::~lexique(){;}

void lexique::print_lex() {
    std::cout << "Lexique of " << name << " : " << std::endl;
    std::map<std::string, uint32_t>::iterator it;
    for(it = lex.begin(); it != lex.end(); it++) {
        std::cout << "Mot : " << std::setw(20) << it->first << "\tNb occurences : " << it->second << std::endl;
    }
    std::cout << std::endl << "Nombre de mot differents : " << lex.size() << std::endl;
}

void lexique::save_info_file() {
    std::ofstream save_file("./save_file.txt");
    if(save_file) {
        save_file << "Lexique of " << name << " : " << std::endl;
        std::map<std::string, uint32_t>::iterator it;
        for(it = lex.begin(); it != lex.end(); it++) {
            save_file << "Mot : " << std::setw(20) << it->first << "\tNb occurences : " << it->second << std::endl;
        }
        save_file << std::endl << "Nombre de mot differents : " << lex.size() << std::endl;
        save_file.close();
    }
}

uint32_t lexique::exist(std::string mot) {
    if(lex.count(mot) == 1) {
        return lex.at(mot);
    }
    else {
        return 0;
    }
}

void lexique::supr(std::string mot) {
    lex.erase(mot);
}

void lexique::print_nb_mot() {
    std::cout << "Nombre de mot differents dans " << name << " : " << lex.size() << std::endl;
}

lexique& lexique::operator+=(lexique& lex_t2) {
    std::map<std::string, uint32_t> lex2 = lex_t2.get_lex();
    std::map<std::string, uint32_t>::iterator it;
    for(it = lex2.begin() ; it != lex2.end() ; it++) {
        if(lex.count(it->first) == 1) {
            lex.at(it->first) += it->second;
        }
        else {
            lex.insert({it->first, it->second});
        }
    }
    return *this;
}

lexique& lexique::operator-=(lexique& lex_t2) {
    std::map<std::string, uint32_t> lex2 = lex_t2.get_lex();
    std::map<std::string, uint32_t>::iterator it;
    for(it = lex2.begin() ; it != lex2.end() ; it++) {
        if(lex.count(it->first) == 1) {
            lex.erase(it->first);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, lexique& lex_t) {
    std::map<std::string, uint32_t> lex = lex_t.get_lex();
    std::map<std::string, uint32_t>::iterator it;
    for(it = lex.begin(); it != lex.end(); it++) {
        os << "Mot : " << std::setw(20) << it->first << "\tNb occurences : " << it->second << std::endl;
    }
    return os;
}
