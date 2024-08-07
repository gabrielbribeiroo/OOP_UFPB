#ifndef AUTOR_H
#define AUTOR_H

#include <string>

class autor {
    std::string nome;
    std::string data_nascimento;
    std::string nacionalidade;
public:
    autor(const std::string &n, const std::string &d, const std::string &na);
    ~autor();

    std::string get_nome();
    void set_nome(const std::string &n);

    std::string get_data_nascimento();
    void set_data_nascimento(const std::string &d);

    std::string get_nacionalidade();
    void set_nacionalidade(const std::string &na);

    void print_info();
};

#endif //AUTOR_H