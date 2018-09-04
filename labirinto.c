#include <stdio.h>
#include <stdlib.h>

int x_campo, y_campo;

char dicionario[] = {' ', '#', 'X', 'G', 'I', 'c', 'b', 'e', 'd'};

int searchPath(int campo[x_campo][y_campo], int x_atual, int y_atual, int x_final, int y_final, int sem_retorno){
    int sem_saida = 1;
    
    if (x_atual == x_final && y_atual == y_final)
        return 1;

    if (!sem_retorno){
        campo[x_atual][y_atual] = 4;
        campo[x_final][y_final] = 3;
    }
    
    else
        campo[x_atual][y_atual] = sem_retorno + 4;

    if (x_atual > 0 && sem_retorno != 2)
        if (campo[x_atual-1][y_atual] == 0 || campo[x_atual-1][y_atual] == 3){
            sem_saida = 0;
        
            if(searchPath(campo, x_atual-1, y_atual, x_final, y_final, 1))
                return 1;
        }
    
    if (x_atual < x_campo-1 && sem_retorno != 1)
        if (campo[x_atual+1][y_atual] == 0 || campo[x_atual+1][y_atual] == 3){
            sem_saida = 0;
            
            if(searchPath(campo, x_atual+1, y_atual, x_final, y_final, 2))
                return 1;
        }
    
    if (y_atual > 0 && sem_retorno != 4)
        if (campo[x_atual][y_atual-1] == 0 || campo[x_atual][y_atual-1] == 3){
            sem_saida = 0;
            
            if(searchPath(campo, x_atual, y_atual-1, x_final, y_final, 3))
                return 1;
        }
    
    if (y_atual < y_campo-1 && sem_retorno != 3)
        if (campo[x_atual][y_atual+1] == 0 || campo[x_atual][y_atual] == 3){
            sem_saida = 0;
            
            if(searchPath(campo, x_atual, y_atual+1, x_final, y_final, 4))
                return 1;
        }
    
    if (sem_saida){
        campo[x_atual][y_atual] = 2;
        imprimirCampo(campo);
    }
    
    if (sem_retorno)
        campo[x_atual][y_atual] = 0;
    
    return 0;
}

int imprimirCampo(int campo[x_campo][y_campo]){
    int i, j;
    
    for (i = 0; i <= x_campo+1; i++){
        for (j = 0; j <= y_campo+1; j++){
            if (i == 0 || i == x_campo+1){
                if (j == y_campo+1)
                    printf("#\n");
                    
                else
                    printf("#");
            }
            else{
                if (j == y_campo+1)
                    printf("#\n");
                
                else if (j == 0)
                    printf("#");
                    
                else
                    printf("%c", dicionario[campo[i-1][j-1]]);
            }
        }
    }
    printf("\n");
}

int main(){
    int i, j, x_inicial, y_inicial, x_final, y_final, x_obstaculo, y_obstaculo;
    
    printf("Dimensao do campo (X & Y):\n");
    scanf("%d %d", &x_campo, &y_campo);
    
    while(x_campo < 0 || y_campo < 0){
        printf("Dimensao do campo deverá ser maior que 0");
        scanf("%d %d", &x_campo, &y_campo);
    }
    
    int campo[x_campo][y_campo];
    
    for (i=0; i<x_campo; i++)
        for (j=0; j<y_campo; j++)
            campo[i][j] = 0;
    
    printf("Posicao inicial (X & Y):\n");
    scanf("%d %d", &x_inicial, &y_inicial);
    
    while(x_inicial < 1 || y_inicial < 1 || x_inicial > x_campo || y_inicial > y_campo){
        printf("Posicao invalida, entre 1 e (%d para X e %d para Y):\n", x_campo, y_campo);
        scanf("%d %d", &x_inicial, &y_inicial);
    }
    
    printf("Posicao final (X & Y):\n");
    scanf("%d %d", &x_final, &y_final);
    
    while((x_final == x_inicial && y_inicial == y_final) || x_final < 1 || y_final < 1 || x_final > x_campo || y_final > y_campo){
        printf("Posicao invalida, entre 1 e (%d para X e %d para Y) (cuidado para nao por posicao inicial e final igual):\n", x_campo, y_campo);
        scanf("%d %d", &x_final, &y_final);
    }
    
    printf("\nI - Posicao inicial || G - Chegada || # - Bloqueio || c - Cima || d - Direita || b - Baixo || e - Esquerda || X - Posicao sem saida\n\n");
    
    for (i=0; i<(x_campo*y_campo)/3; i++){
        do{
            x_obstaculo = rand() % x_campo;
            y_obstaculo = rand() % y_campo;
            
        }while (campo[x_obstaculo][y_obstaculo] == 1 || (x_obstaculo == x_inicial && y_obstaculo == y_inicial) || (x_obstaculo == x_final && y_obstaculo == y_final));
      
        campo[x_obstaculo][y_obstaculo] = 1;
    }
    
    if(searchPath(campo, x_inicial-1, y_inicial-1, x_final-1, y_final-1, 0)){
        printf("\nCaminho Encontrado!\n");
        imprimirCampo(campo);
    }
    
    else
        printf("\nCaminho Inexistente");
    
    return 0;
}

