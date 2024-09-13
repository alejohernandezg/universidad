def contains(lst,a):
    i=0
    while(i<len(lst)):
        if(lst[i]==a):
            return True
        print("s")
        i+=1
    return False

def funcion(lst):
    c=0
    lstResult=[]
    while c<len(lst):
        if(not contains(lst,lst[c])):
            lstResult.append(lst[c])
            print("Hola")
        c+=1
    print(lst)
    print(lstResult)
lst=["Dado", "Hoja", "Ficha", "Dado", "Reloj"]
funcion(lst)


    
            
        


            
    
    
