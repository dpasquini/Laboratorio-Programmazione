"""
Leggere un input intero da tastiera
e determinare e visualizzare se l'intero
è pari o dispari
"""

# lettura dell'input e conversione a intero
numero = int(input("Inserisci un numero: "))

if numero % 2 == 0: # caso è pari
    print("E' numero pari")
else: # caso è dispari
    print("E' numero dispari")