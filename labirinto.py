from random import randint

dicionario = [' ', '#', 'X', 'G', 'I', 'c', 'b', 'e', 'd']

def procurar_Caminho(campo, x_atual, y_atual, x_final, y_final, sem_retorno, x_campo, y_campo):
    sem_saida = 1
    
    if (x_atual == x_final and y_atual == y_final):
        return 1

    if (not sem_retorno):
        campo[x_atual][y_atual] = 4
        campo[x_final][y_final] = 3
    
    else:
        campo[x_atual][y_atual] = sem_retorno + 4;

    if (x_atual > 0 and sem_retorno != 2):
        if (campo[x_atual-1][y_atual] == 0 or campo[x_atual-1][y_atual] == 3):
            sem_saida = 0
        
            if(procurar_Caminho(campo, x_atual-1, y_atual, x_final, y_final, 1, x_campo, y_campo)):
                return 1
    
    if (x_atual < x_campo-1 and sem_retorno != 1):
        if (campo[x_atual+1][y_atual] == 0 or campo[x_atual+1][y_atual] == 3):
            sem_saida = 0
            
            if(procurar_Caminho(campo, x_atual+1, y_atual, x_final, y_final, 2, x_campo, y_campo)):
                return 1
    
    if (y_atual > 0 and sem_retorno != 4):
        if (campo[x_atual][y_atual-1] == 0 or campo[x_atual][y_atual-1] == 3):
            sem_saida = 0
            
            if(procurar_Caminho(campo, x_atual, y_atual-1, x_final, y_final, 3, x_campo, y_campo)):
                return 1
    
    if (y_atual < y_campo-1 and sem_retorno != 3):
        if (campo[x_atual][y_atual+1] == 0 or campo[x_atual][y_atual] == 3):
            sem_saida = 0
            
            if(procurar_Caminho(campo, x_atual, y_atual+1, x_final, y_final, 4, x_campo, y_campo)):
                return 1
        
    
    if (sem_saida):
        campo[x_atual][y_atual] = 2
        imprimir_Campo(campo, x_campo, y_campo);
    
    if (sem_retorno):
        campo[x_atual][y_atual] = 0
    
    return 0


def imprimir_Campo(campo, x_campo, y_campo):
    for i in range(0, x_campo+2):
        for j in range(0, y_campo+2):
            if (i == 0 or i == x_campo+1):
                if (j == y_campo+1):
                    print("#")
                    
                else:
                    print("#", end="")
    
            else:
                if (j == y_campo+1):
                    print("#")
                
                elif (j == 0):
                    print("#", end="")
                    
                else:
                    print(dicionario[campo[i-1][j-1]], end="")

    print("")

def inicio():
    x_campo, y_campo = [int(x) for x in input("Dimensao do campo (X & Y): ").split()]
    
    while(x_campo <= 0 or y_campo <= 0):
        x_campo, y_campo = [int(x) for x in input("Dimensao do campo devera ser maior que 0: ").split()]
    
    campo = [[0 for x in range(x_campo)] for y in range(y_campo)] 
    
    x_inicial, y_inicial = [int(x) for x in input("Posicao inicial (X & Y): ").split()]
    
    while(x_inicial < 1 or y_inicial < 1 or x_inicial > x_campo or y_inicial > y_campo):
        x_inicial, y_inicial = [int(x) for x in input("Posicao invalida, entre 1 e (", x_campo, "para X e ", y_campo, " para Y): ").split()]
    
    x_final, y_final = [int(x) for x in input("Posicao final (X & Y): ").split()]
    
    while((x_final == x_inicial and y_inicial == y_final) or x_final < 1 or y_final < 1 or x_final > x_campo or y_final > y_campo):
        x_final, y_final = [int(x) for x in input("Posicao invalida, entre 1 e (", x_campo, "para X e ", y_campo, " para Y) (cuidado para nao por posicao inicial e final igual): ").split()]
    
    print("I - Posicao inicial || G - Chegada || # - Bloqueio || c - Cima || d - Direita || b - Baixo || e - Esquerda || X - Posicao sem saida\n");
    
    for i in range (0, int((x_campo*y_campo)/3)):
        x_obstaculo = randint(0, x_campo-1)
        y_obstaculo = randint(0, y_campo-1)
            
        while (campo[x_obstaculo][y_obstaculo] == 1 or (x_obstaculo == x_inicial and y_obstaculo == y_inicial) or (x_obstaculo == x_final and y_obstaculo == y_final)):
            x_obstaculo = randint(0, x_campo-1)
            y_obstaculo = randint(0, y_campo-1)
            
        campo[x_obstaculo][y_obstaculo] = 1
    
    if(procurar_Caminho(campo, x_inicial-1, y_inicial-1, x_final-1, y_final-1, 0, x_campo, y_campo)):
        print("\nCaminho Encontrado!\n")
        imprimir_Campo(campo, x_campo, y_campo)
    
    else:
        print("\nCaminho Inexistente")

inicio()

