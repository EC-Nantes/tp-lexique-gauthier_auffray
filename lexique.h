#ifndef LEXIQUE_H
#define LEXIQUE_H

#include <string>
#include <map>

class lexique {
private:
    std::string name;
    std::map<std::string, uint32_t> lex;

public:
    lexique() = delete;
    lexique(lexique&) = delete;
    lexique(lexique&&) = delete;
    lexique(std::string, const char*);
    ~lexique();

    void print_lex();
    void save_info_file();
    uint32_t exist(std::string);
    void supr(std::string);
    void print_nb_mot();
    std::map<std::string, uint32_t>& get_lex() {return lex;}
    lexique& operator+=(lexique&);
    lexique& operator-=(lexique&);
};

std::ostream& operator<<(std::ostream&, lexique&);


#endif