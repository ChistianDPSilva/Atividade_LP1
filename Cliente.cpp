#include "Cliente.h"

//Constructor para inicializar nome e cpf decentemente
Cliente::Cliente(std::string nome, std::string cpf){
    this->nome = nome;
    this->cpf = cpf;
}

std::string Cliente::getNome(){
    return nome;
}

std::string Cliente::getCpf(){
    return cpf;
}

