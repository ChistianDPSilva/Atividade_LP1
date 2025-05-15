#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H
#include "Cliente.h"

class ContaBancaria{
    private:
        int numero;
        double saldo;
        Cliente titular;

    public:
        ContaBancaria(int numero, Cliente titular, double saldo = 0.0);
        
        void depositar(double);
        void sacar(double);

        void transferir(double valor, ContaBancaria &destino);
        void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);

        void exibirSaldo();
        void exibirInformacoes();

};

#endif