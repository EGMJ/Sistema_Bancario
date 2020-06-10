#include <iostream>
using namespace std;

class ContaBancaria
{
private:
    int n_agencia, id_cliente, n_conta;
    float saldo;
    char nome[30];

public:
    void reeniciar()
    {
        saldo = 0.0;
        id_cliente = 0;
        n_agencia = 0;
        n_conta = 0;
    }
    void inicializar()
    {
        printf("\ndigite seu nome:");
        scanf("  %[^\n]s", nome);
        fflush(stdin);
        printf("\ndigite sua agencia:");
        scanf("%d", &n_agencia);
        printf("\ndigite sua conta:");
        scanf("%d", &n_conta);
        printf("\ndigite seu id_cliente:");
        scanf("%d", &id_cliente);
        printf("\ndigite seu saldo inicial:");
        scanf("%f", &saldo);
        printf("\nconcluido!!");
    }
    void sacar()
    {
        float saque;
        char opcsaque[1];
        printf("quanto quer sacar?");
        scanf("%f", &saque);
        if (saque > saldo)
        {
            printf("saldo indisponivel!");
        }
        else
        {
            printf("deseja retirar %0.2f do seu saldo de %0.2f??\n novo saldo sera=%0.2f", saque, saldo, saldo - saque);
            printf("s-n");
            scanf("%c", &opcsaque);
            if (opcsaque == "s")
            {
                saldo -= saque;
                printf("processo concluido!!");
            }
            else
            {
                printf("processo cancelado!!");
                return;
            }
        }
    }
    void depositar()
    {
        float depositar;
        printf("quanto deseja depositar?");
        scanf("%f", &depositar);
        saldo += depositar;
    }
    void mostrar_saldo()
    {
        printf("saldo atual:%0.2f", saldo);
    }
    void imprimir_saldo()
    {
        printf("\n-----------SALDO-----------\n");
        printf("\nnome:%s", nome);
        printf("\nnumero da agencia:%i", n_agencia);
        printf("\nnumero da agencia:%i", n_conta);
        printf("\nnumero da agencia:%i", id_cliente);
        printf("\nsaldo:%0.2f", saldo);
        printf("\n-------------------------------\n");
    }
};

int main()
{
    int opc = -1;
    ContaBancaria dados;
    while (opc != 0)
    {
        printf("\n-----MENU-----");
        printf("\n1-iniciar");
        printf("\n2-definir dados bancarios");
        printf("\n3-sacar");
        printf("\n4-depositar");
        printf("\n5-obter saldo");
        printf("\n6-imprimir saldo");
        printf("\n0-sair\n");
        scanf("%i", &opc);
        switch (opc)
        {
        case 1:
            dados.reeniciar();
            printf("\nconta formatada!");
            printf("\n-------------------\n");
            break;
        case 2:
            dados.inicializar();
            printf("\n-------------------\n");
            break;
        case 3:
            dados.sacar();
            printf("\n-------------------\n");
            break;
        case 4:
            dados.depositar();
            printf("\n-------------------\n");
            break;
        case 5:
            dados.mostrar_saldo();
            printf("\n-------------------\n");
            break;
        case 6:
            dados.imprimir_saldo();
            printf("\n\nconcluido!");
            printf("\n-------------------\n");
            break;
        default:
            printf("\nnumero invalido!!");
            break;
        }
    }
}