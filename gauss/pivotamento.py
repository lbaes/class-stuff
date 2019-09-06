    #pivotamento
    for i in range(n): 
        p = 0
        #incrementa p de 1 em 1 ate que p satisfaca a condicao i<=p<=n, matriz[p][i] != 0
        while (True):
            if (i<=p and p<n and matriz[p][i] != 0):
                break
            if (p>i or p>=n):
                return print("nao ha solucao unica (pivo)")
            else:
                p+=1
        
        if p!=i:
            #troca linhas
            matriz[p], matriz[i] = matriz[i], matriz[p]
            
        for j in range(i+1, n):
            m = matriz[j][i]/matriz[i][i]
            matriz[j] = vetorSub(matriz[j],(vetorMult(matriz[i], m) ) )
        printArr(matriz)