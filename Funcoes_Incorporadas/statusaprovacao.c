#include <stdio.h>

int statusaprovacao() {
    int NUMERO_ALUNOS, media, qntdaprovados = 0, qntdreprovados = 0;
    float porcaprovados, porcreprovados;
    for (int i = 0; i < NUMERO_ALUNOS; i++) {
        if (media < 6 && media >= 0) {
        qntdreprovados++;
        }
        if(media >= 6 && media <= 10){
        qntdaprovados++;
        }
    }
    porcaprovados = (qntdaprovados * 100) / NUMERO_ALUNOS;
    porcreprovados = 100 - porcaprovados;
    
    printf("-------STATUS DE APROVACAO-------\n");
    printf("\nTotal de alunos: %d\n", NUMERO_ALUNOS);
    printf("Taxa de aprovacao: %.2f%%\n", porcaprovados);
    printf("Taxa de reprovacao: %.2f%%\n", porcreprovados);
}
