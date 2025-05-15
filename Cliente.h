#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
    private:
        std::string nome;
        std::string cpf;

    public:
        Cliente(std::string nome, std::string cpf);
        std::string getNome();
        std::string getCpf();

};

#endif