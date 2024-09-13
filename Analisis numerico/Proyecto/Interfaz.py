
from tkinter import *
 
from tkinter import Menu
 
window = Tk()

#Configuracion de la ventana
window.title("Recorte de Imagenes")
window.config(bg = '#353232')
window.geometry('1200x700')

#Configuracion del menu
menu = Menu(window)
new_item = Menu(menu)
new_item.add_command(label='New')
menu.add_cascade(label='Archivo', menu=new_item)
window.config(menu=menu)


miFrame = Frame()
miFrame.config(width="150")
miFrame.config(bg = 'blue')
miFrame.pack(side='left', fill='y')

miFrame.grid(row=0, column=0, rowspan=2, sticky="nsew")

## BOTONES
# Cargar Imagen
boton_cargar_imagen = Button(miFrame, text="Cargar Imagen", bg = 'red')



window.mainloop()

