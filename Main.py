
numTentativas = 0
senhaSecreta = "abcd"
ponteiroCasa = 0
ponteiroRegressor = 0
limiteCasa = 4
conjunto = "abcdefghijklmnoprstuvwxyz1234567890"
senhaTentativa = ""
posicoesSenha = [0,-1,-1,-1]

#transforma posicoes dadas em palavras
def numParaPalavra(posicoesLetras):
    palavra = ""
    for i in range(limiteCasa):
        if posicoesLetras[i] != -1:
            palavra = palavra + str(conjunto[posicoesLetras[i]])
        else:
            break
    return palavra
#vê se a palavra é a senha secreta
def isResposta(palavraTentativa):
    return senhaSecreta == palavraTentativa


#verrifica bruteforce
while(ponteiroCasa < limiteCasa):
    
    for interator in range(len(conjunto)):
        posicoesSenha[ponteiroCasa] = interator
        senhaTentativa = numParaPalavra(posicoesSenha)
        numTentativas += 1
        if isResposta(senhaTentativa): 
            print("senha encontrada: "+senhaTentativa+" tentativas: "+str(numTentativas))
            exit()
        if interator == (len(conjunto) - 1):
            ponteiroRegressor = ponteiroCasa
            while(ponteiroRegressor >= 0):
                posicoesSenha[ponteiroRegressor] += 1
                if posicoesSenha[ponteiroRegressor] >= (len(conjunto) - 1):
                    posicoesSenha[ponteiroRegressor] = 0
                    ponteiroRegressor -= 1
                    senhaTentativa = numParaPalavra(posicoesSenha)
                    numTentativas += 1
                    if isResposta(senhaTentativa): 
                        print("senha encontrada: "+senhaTentativa+" tentativas: "+str(numTentativas))
                        exit()
                    continue
                else:
                    senhaTentativa = numParaPalavra(posicoesSenha)
                    numTentativas += 1
                    if isResposta(senhaTentativa): 
                        print("senha encontrada: "+senhaTentativa+" tentativas: "+str(numTentativas))
                        exit()
                    break
            senhaTentativa = numParaPalavra(posicoesSenha)
            if ponteiroRegressor < 0:
                ponteiroCasa += 1
            numTentativas += 1
            if isResposta(senhaTentativa): 
                print("senha encontrada: "+senhaTentativa+" tentativas: "+str(numTentativas))
                exit()
        senhaTentativa = numParaPalavra(posicoesSenha)
        if isResposta(senhaTentativa): 
            print("senha encontrada: "+senhaTentativa+" tentativas: "+str(numTentativas))
            exit()
       
    
    
  
         
        