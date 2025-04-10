#include <stdio.h>
#define TAMCli 3
#define TAMProd 3

int qtdVendas;

typedef struct
{
    int id;
    char nome[20];
    int quantidade;
    float valor;
} Produto;
typedef struct
{
    int id;
    char nome[20];
} Cliente;
typedef struct
{
    int idCliente;
    int idProduto;
    int quantProduto;
    float valorTotal;
} Venda;
void cadastrarCliente(Cliente c[])
{
    for (int i = 0; i < TAMCli; i++)
    {
        printf("Cliente %d, Primeiro Nome: ", i + 1);
        scanf("%s", c[i].nome);
        c[i].id = i + 1;
    }
}
void cadastrarProduto(Produto p[])
{
    for (int i = 0; i < TAMProd; i++)
    {
        printf("\nPrimeiro Nome do Produto %d: ", i + 1);
        scanf("%s", p[i].nome);
        printf("Quantidade: ");
        scanf("%d", &p[i].quantidade);
        printf("Valor: ");
        scanf("%f", &p[i].valor);
        p[i].id = i + 1;
    }
}
void consultarCliente(Cliente *c)
{
    for (int i = 0; i < TAMCli; i++)
    {
        printf("\nId Cliente: %d.", c[i].id);
        printf("\nPrimeiro Nome: %s.", c[i].nome);
    }
    printf("\n\n");
}
void consultarProduto(Produto p[])
{
    for (int i = 0; i < TAMProd; i++)
    {
        printf("\nId Produto: %d.", p[i].id);
        printf("\nNome Produto: %s.", p[i].nome);
        printf("\nQuantidade: %d.", p[i].quantidade);
        printf("\nValor: %.2f.", p[i].valor);
        printf("\n----------------------------------");
    }
    printf("\n\n");
}

void realizarVenda(Venda vendas[], Cliente clientes[], Produto produtos[])
{
    int idCliente, idProduto, qtdDesejada;
    int existeCliente = 0, existeProduto = 0;
    printf("\nID Cliente: ");
    scanf("%d", &idCliente);

    //verifica se o cliente existe
    for (int i = 0; i < TAMCli; ++i)
    {
        if (clientes[i].id == idCliente)
        {
            existeCliente = 1;
            break;
        }
    }

    if (!existeCliente)
    {
        printf("Cliente não encontrado!\n");
        return;
    }

    printf("ID do Produto: ");
    scanf("%d", &idProduto);

    // Verifica se o produto existe
    for (int i = 0; i < TAMProd; i++)
    {
        if (produtos[i].id == idProduto)
        {
            existeProduto = 1;

            printf("Quantidade desejada: ");
            scanf("%d", &qtdDesejada);

            if (produtos[i].quantidade >= qtdDesejada)
            {
                produtos[i].quantidade -= qtdDesejada;

                vendas[qtdVendas].idCliente = idCliente;
                vendas[qtdVendas].idProduto = idProduto;
                vendas[qtdVendas].quantProduto = qtdDesejada;
                vendas[qtdVendas].valorTotal = qtdDesejada * produtos[i].valor; //calculo do valor

                printf("Venda realizada com sucesso! Valor total: %.2f\n", vendas[qtdVendas].valorTotal);

                qtdVendas++; //venda realizada
            }
            else
            {
                printf("Estoque insuficiente!\n");
            }
            return;
        }
    }

    if (!existeProduto)
    {
        printf("Produto não encontrado!\n");
    }
}

void consultarVendas(Venda vendas[])
{
    if (qtdVendas == 0)
    {
        printf("\nNenhuma venda realizada até o momento.\n");
        return;
    }

    printf("\nRelatório de Vendas:\n");
    for (int i = 0; i < qtdVendas; i++)
    {
        printf("\nVenda %d:", i + 1);
        printf("\nID Cliente: %d", vendas[i].idCliente);
        printf("\nID Produto: %d", vendas[i].idProduto);
        printf("\nQuantidade Comprada: %d", vendas[i].quantProduto);
        printf("\nValor Total: %.2f", vendas[i].valorTotal);
        printf("\n-----------------------------");
    }
    printf("\n");
}

int main()
{
    int opcao, sair = 0; // sair inicialmente falso
    Cliente clientes[5];
    Produto produtos[5];
    Venda vendas[5];
    do
    {
        printf("\n\n>>>> Sistema de Vendas <<<< ");
        printf("\n\t1 – Cadastrar Clientes");
        printf("\n\t2 – Cadastrar Produtos");
        printf("\n\t3 – Consultar Clientes");
        printf("\n\t4 – Consultar Produtos");
        printf("\n\t5 – Realizar Venda");
        printf("\n\t6 – Consultar Vendas");
        printf("\n\t7 – Sair\n\t>>>> ");
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            cadastrarCliente(&clientes);
        }
        else if (opcao == 2)
        {
            cadastrarProduto(&produtos);
        }
        else if (opcao == 3)
        {
            consultarCliente(&clientes);
        }
        else if (opcao == 4)
        {
            consultarProduto(&produtos);
        }
        else if (opcao == 5)
        {
            realizarVenda(vendas, clientes, produtos);
        }
        else if (opcao == 6)
        {
            consultarVendas(vendas);
        }
        else if (opcao == 7)
        {
            sair = 1;
        }
        else
        {
            printf("\n\nOpcao Invalida!");
        }
    } while (sair != 1);
    return 0;
}
