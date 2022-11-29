#include <iostream>
#include <string>
#include <cstring>
#include "utilitaire.hpp"
#include "lexique.h"

int main() {
    std::cout << "Programme lexique start" << std::endl << std::endl;
    lexique LesMiserables("Les Miserables", "./tp1-Lexique-fichiers/lesMiserables_A.txt");
    lexique NotreDamedeParis("Notre Dame de Paris", "./tp1-Lexique-fichiers/notreDameDeParis_A.txt");
    //LesMiserables.save_info_file();
    
    LesMiserables.supr("the");

    LesMiserables -= NotreDamedeParis;
    std::cout << "Miserable : Nombre de fois le mot the : " << LesMiserables.exist("the") << std::endl;
    std::cout << "Miserable : Nombre de fois le mot of : " << LesMiserables.exist("of") << std::endl;
    std::cout << "NDdP : Nombre de fois le mot the : " << NotreDamedeParis.exist("the") << std::endl;
    std::cout << "NDdP : Nombre de fois le mot of : " << NotreDamedeParis.exist("of") << std::endl;
    LesMiserables.print_nb_mot();
    NotreDamedeParis.print_nb_mot();

    std::cout << "test d'affichage : " << std::endl << LesMiserables << std::endl;

    return 0;
}