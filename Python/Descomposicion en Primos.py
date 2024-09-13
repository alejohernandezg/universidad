import math
def PedirNumero():
    global num
    print("Ingrese un entero Positivo <= 10000")

    while True:
        try:
            num=input(" ")
            num=int(num)
            if num > 10000:
                raise ValueError ("¡Alejandro es marica! el entero ingresado no cumple, intente de nuevo")
            break
        except:
            print("¡Alejandro es marica! ¡No cumple con las condiciones! Intente de nuevo")
       
    return num
    
def DescomposicionEnPrimos():
    global num
    while PedirNumero():
        lista =[]
        while num%2==0:
            num = num // 2
            lista.append(2)

        i = 3
        raiz = (num)**(1/2)
        while i <= raiz:
            print(i)
            print(raiz)
            if num % i == 0:
                lista.append(i)
                num = num // i
            else:
                i = i + 2
        if num > 1:
            lista.append(num)

        print(lista)

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
    
def expcantor(n):
    i=0
    while n >= factorial(i):
        i += 1
    i-=1

    

expcantor(35)
    
