def printArr(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n+1):
            print("["+str(arr[i][j])+"]" ,end='')
        print()
    print()

def vetorSoma(arr1, arr2):
    r = [None]*len(arr1)
    for i in range(len(arr1)):
        r[i] = arr1[i] + arr2[i]
    return r

def vetorSub(arr1, arr2):
    r = [None]*len(arr1)
    for i in range(len(arr1)):
        r[i] = arr1[i] - arr2[i]
    return r

def vetorMult(arr , const ):
    r = [None]*len(arr)
    for i in range(len(arr)):
        r[i] = arr[i] * const
    return r

def pivotamento(n, matriz):
    #pivotamento
    for i in range(n): 
        p = 0
        #incrementa p de 1 em 1 ate que p satisfaca a condicao i<=p<=n, matriz[p][i] != 0
        while (True):
            if (i<=p and p<n and matriz[p][i] != 0):
                break
            if (p>i or p>=n):
                print("nao ha solucao unica (pivo)")
                return "err"
            else:
                p+=1
        
        if p!=i:
            #troca linhas
            matriz[p], matriz[i] = matriz[i], matriz[p]
            
        for j in range(i+1, n):
            m = matriz[j][i]/matriz[i][i]
            matriz[j] = vetorSub(matriz[j],(vetorMult(matriz[i], m) ) )
        printArr(matriz)

    return matriz

def gauss(n, matriz):

    m = pivotamento(n,matriz)
    if m == "err":
        return "err"

    #Substituicao
    if (m[n-1][n-1] == 0):
        print("nao ha solucao unica")
        return "err"
    
    x = [None]* n
    x[n-1] = m[n-1][n]/m[n-1][n-1]
    for i in range(n-2,-1,-1):
        soma = 0
        for j in range(i+1,n):
            soma += m[i][j]*x[j]
        x[i] = (m[i][n] - soma)/m[i][i]
    return x
           
    
incognitas = int(input("Numero de Incognitas: "))
matriz = [] 
print("Digite os coeficientes")   
for i in range(incognitas):          
    temp = [] 
    for j in range(incognitas+1):
        print("digite A[%d][%d]" %(i,j))
        temp.append(float(input()))
    matriz.append(temp) 
printArr(matriz)
xarr = gauss(incognitas, matriz)
if xarr != "err":
    for indice, resposta in enumerate(xarr):
        print("x[%d] = %f" %(indice+1, resposta))
    print ("\n\n")

