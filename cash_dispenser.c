#include <stdio.h>
#include <string.h>
// FUNÇÃO DE DESPOSITAR
void depositar ( int quantidade[]){  
    int nota, quantNota;

    printf("Informe o valor de depósito (10, 20, 50, 100): ");
    scanf("%d", &nota);
    printf ("Informe a quantidade de notas: ");
    scanf("%d", &quantNota);
  
    if (nota==10) {
        quantidade[0]+=quantNota;
    }
    else if (nota==20) {
        quantidade[1]+=quantNota;
    }
    else if (nota==50) {
        quantidade[2]+=quantNota;
    }
    else if (nota==100){
        quantidade[3]+=quantNota;
    }

   else {
    printf("ERRO! Valor não aceito, tente novamente \n");
   }

}

// FUNÇÃO DE SAQUE
void saque (int valores[], int quantidade[]){
    int verificaValor[4]={0};
    int retiraValor [4]= {0};
    int valor;
    int valorRestante;
    int algumaNDisponivel = 0;

    printf("As seguintes notas estão disponíveis: \n");
    for (int i=0; i<4; i++)
        if (quantidade[i] > 0) {
            printf("- %d  reais - ", valores[i]);
            algumaNDisponivel = 1;
        }
   
    if (algumaNDisponivel == 0) {
        printf("Nenhum valor disponivel para saque. \n");
    } 
    // Se tem notas disponiveis existe a possibilidade de saque
    else if (algumaNDisponivel == 1){
    printf("\n Informe o valor de Saque : ");
    scanf("%d", &valor);
    valorRestante = valor;
    }

    // operção de saque
    for (int i=3; i>=0; i--)
        if (quantidade[i] > 0) {
            verificaValor[i] = valorRestante/valores[i];
            if (verificaValor[i]>=quantidade[i]) {
                retiraValor[i] = quantidade[i]*valores[i];
                quantidade[i] = 0;
                valorRestante = valorRestante - retiraValor[i];
            }
            else if (verificaValor[i]<quantidade[i]){
                quantidade[i] = quantidade[i]-verificaValor[i];
                retiraValor[i] = verificaValor[i]*valores[i];
                valorRestante = valorRestante- retiraValor[i];
            }
        }
    
    if (valorRestante ==0){
        printf("Operação Realizada");
    } else {
        printf("Notas insuficiente, operação não realizada");
    }
}

// TELA PRINCIPAL
int main()
{
  int valores[4]={10, 20, 50, 100};
  int quantidade[4]={0};
  int totalPNota[4];
  int saldo = 0;
  int operacao;
  
  printf("CASH DISPENSER\n");
  printf("Seu saldo atual é: %d \n", saldo);
  //Seleção de tipo de operação
  do {
    printf("\n Qual operação deseja executar digite: \n 1 - Deposito. \n 2 - Saque.\n 3 - verificar saldo. \n 4 - Sair.): \n");
    scanf("%d", &operacao);

    if (operacao==1) {
        depositar(quantidade);
    }

    else if (operacao ==2) {
        saque(valores, quantidade);
    }

    else if (operacao ==3) {
        saldo = 0;
        for(int i=0; i<4; i++){
                totalPNota[i] = valores[i]*quantidade[i];
            }
            
            for (int i=0; i<4; i++){
                saldo = saldo + totalPNota[i];
            }

        printf ("Seu saldo atual é: %d reais \n", saldo);

    }

    else  if (operacao ==4){
        printf("Finalizando operação");
        return 0;
    }

  } while (operacao!=4);

  return 0;
}
