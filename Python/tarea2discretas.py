def funcion():
    alfabeto=[[10,"A"],[11,"B"],[12,"C"],[13,"D"],[14,"E"],[15,"F"],[16,"G"],[17,"H"],[19,"I"]]
    numero=int(input("digite un numero\n"))
    j=True
    while j==True:
        base=int(input("digite la base en la que desea saber el numero\n"))
        if base>=2 and base<=20:
            print(alfabeto)
            
            j=False
        else:
            print("digite una base entre 2 y 20")
    lista=[]
    cociente=numero//base
    residuo=numero%base

    if cociente==0:
        print(numero)
        

    else:
        
    
        lista.append(residuo)
        while cociente!=0:
            residuo=cociente%base
            
            cociente=cociente//base
            
            lista.append(residuo)

    lista.reverse()
    #print(lista)
    #3214923987
    if base>10:
        h=0
        while h< len(lista):
            m=0
            
            
            while m < len(alfabeto):
                if lista[h]==alfabeto[m][0]:
                    lista[h]=alfabeto[m][1]
                else:
                    m+=1
            h+=1

    print(lista,"base",base)
                
                
                

                    


funcion()
    
