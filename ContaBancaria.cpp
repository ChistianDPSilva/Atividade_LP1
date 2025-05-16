#include <iostream>
#include "ContaBancaria.h"

//Constructor para inicializar os atributos
ContaBancaria::ContaBancaria(int numero, Cliente titular, double saldo)
: numero(numero), titular(titular), saldo(saldo) {}

//Deposita na conta se o valor for maior que 0, caso contrário mostrará "Valor inválido"
void ContaBancaria::depositar(double valor){
    if(valor > 0){
        saldo += valor;
    }else {
        std::cout << "Valor inválido\n";
    }
}

//Função para sacar o money, mas caso o valor seja inválido será mostrada uma mensagem de erro
void ContaBancaria::sacar(double valor){
    if(valor > 0 && valor <= saldo){
        saldo -= valor;
    }else if(valor <= 0){
        std::cout << "Valor inválido\n";
    }else{
        std::cout << "Saldo insuficiente\n";
    }
}

//Função para transferir o money para outra conta, caso não tenha saldo, mostrará uma mensagem de erro
void ContaBancaria::transferir(double valor, ContaBancaria &destino){
    if(valor > 0 && valor <= saldo){
        saldo -= valor;
        destino.depositar(valor);
        
        std::cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << std::endl;

    }else if(valor <= 0){
        std::cout << "Valor inválido\n";
    }else{
        std::cout << "Saldo insuficiente\n";
    }
}

//Função parar transferir metade do valor para duas contas Se não for possível, será mostrado uma mensagem de erro
void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
    
    double metade = valor / 2.0;

    if(valor > 0 && saldo >= valor){
        saldo -= valor;
        destino1.depositar(metade);
        destino2.depositar(metade);
        
        std::cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << std::endl;

    }else if(valor <= 0){
        std::cout << "Valor inválido\n";
    }else{
        std::cout << "saldo insuficiente\n";
    }
}


//Função para mostrar saldo da conta
void ContaBancaria::exibirSaldo(){
    std::cout << "Saldo atual da conta " << numero << ": R$ " << saldo << std::endl;
}

//Função para mostrar todos os dados da conta
void ContaBancaria::exibirInformacoes(){
    std::cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << "\nNúmero da conta: " << numero << ", Saldo: R$ " << saldo << std::endl;
}
