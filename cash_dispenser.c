#include <stdio.h>
#include <string.h>

void depositar ( int valores[], int quantidade[], int totalPNota[], int saldo){  
    int nota, quantNota;

    printf("Informe o valor de depósito (10, 20, 50, 100): ");
    scanf("%d", &nota);
    printf ("Informe a quantidade de notas: ");
    scanf("%d", &quantNota);
  
    if (nota==10) {
        quantidade[0]=quantNota;
    }
    if (nota==20) {
        quantidade[1]=quantNota;
    }
    if (nota==50) {
        quantidade[2]=quantNota;
    }
    if (nota==100){
        quantidade[3]=quantNota;
    }

   else {
    printf("ERRO! Valor não aceito, tente novamente \n");
   }
   
   //atualização de saldo
   for(int i=0; i<4; i++)
      totalPNota[i] = valores[i]*quantidade[i];
    
    for (int i=0; i<4; i++)
     saldo = saldo + totalPNota[i];

     printf ("Seu saldo atual é: %d reais \n", saldo);
}

void saque (int valores[], int quantidade[], int totalPNota[], int saldo){
    int valor;

    printf("Qual valor deseja sacar: ");
    scanf("%d", &valor);

}

int main()
{
  int valores[4]={10, 20, 50, 100};
  int quantidade[4]={0};
  int totalPNota[4];
  int saldo=0;
  char operacao[8];
  
  printf("CASH DISPENSER\n");
  printf("Seu saldo atual é: %d \n", saldo);
  //Seleção de tipo de operação
  do {
    printf("Qual operação deseja executar (Deposito, Saque, Sair): \n");
    scanf("%s", operacao);

    if (strcmp(operacao,"Deposito") == 0) {
        depositar(valores, quantidade, totalPNota, saldo );
    }

    if (strcmp(operacao,"Saque") ==0){
        saque(valores, quantidade, totalPNota, saldo);
    }

    if (strcmp(operacao,"Sair")==0){
        printf("Finalizando operação");
        return 0;
    }

  } while (strcmp(operacao,"Sair") !=0);

  return 0;
}
