#include <iostream>
#include "ContaBancaria.h"


ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
: numero(numero), titular(titular), saldo(saldo) {}

void ContaBancaria::depositar(double valor){
    if(valor > 0){
        saldo += valor;
    }else {
        std::cout << "Saldo inválido\n";
    }
}

void ContaBancaria::sacar(double valor){
    if(valor > 0 && valor <= saldo){
        saldo -= valor;
    }else{
        std::cout << "Saldo insuficiente\n";
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino){
    if(valor > 0 && valor <= saldo){
        saldo -= valor;
        destino.depositar(valor);
        
        std::cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << std::endl;

    }else{
        std::cout << "Saldo insuficiente\n";
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
    
    double metade = valor / 2.0;

    if(valor > 0 && saldo >= valor){
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        
        std::cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << std::endl;

    }else{
        std::cout << "saldo insuficiente\n";
    }
}

void ContaBancaria::exibirSaldo(){
    std::cout << "Saldo atual da conta " << numero << ": R$ " << saldo << std::endl;
}

void ContaBancaria::exibirInformacoes(){
    std::cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << "\nNúmero da conta: " << numero << ", Saldo: R$ " << saldo << std::endl;
}

