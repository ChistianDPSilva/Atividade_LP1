#include <iostream>
#include "ContaBancaria.h"


ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo){
    this->numero = numero;
    this->titular = titular;
    this->saldo = saldo;
}

void ContaBancaria::depositar(double valor){
    if(valor > 0){
        saldo += valor;
    }//adicionar o caso '<= 0'
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
