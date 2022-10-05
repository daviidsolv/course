
# Activitat 01: Eliminació segura UNIX (Mòdul 1)

*Instructor*: [Jordi Mateo Fornés](http:jordimateofornes.com)

*Course*: [Grau en Tècniques d'Interacció Digital i de Computació](http://www.grauinteraccioicomputacio.udl.cat/ca/index.html)

*University*: University of Lleida - Campus Igualada - Escola Politècnica Superior

*Estudiants*: Paula Silland, David Argente

## Part practica: Desenvolupament rmsf  

### Enunciat
La vostra tasca és implementar en C aquesta funcionalitat.

### Resposta
rmsf.c al directory / de GitHub.

## Part practica: Instal·lant la comanda al sistema rmsf    

### Enunciat
Expliqueu quin és el procediment per instal·lar aquesta commanda al sistema. Volem que un usuari la
pugui utilitzar directament com rmsf.

### Resposta
su
cp ./rmsf /usr/bin

## Part practica: Test    

### Enunciat
La vostra tasca és prepar un fitxer test.sh que contingui totes les comandes que heu fet anar per testejar
la vostra solució.

### Resposta
#!/bin/sh
echo "Testing RMSF app.."
echo "Creating dummy files and directories."
touch testFile1.txt
touch testFile2.txt
mkdir testFolder
touch ./testFolder/testFile3.c
1s -la
echo "Created 3 dummy files and 1 folder." 
echo "Removing files.."
rmsf testFilel.txt testFile2.txt
rmsf testFolder 
echo "Removed!"
ls -la
cd $HOME/.trash
echo "Showing trash folder..."
ls -la

## Part practica: Automatització amb Make    

### Enunciat
La vostra tasca és revisar el funcionament dels Makefiles. Heu de preparar un Makefile que sigui
capaç de compilar, executar, testejar amb el fitxer test.sh i instal·lar l’executable al sistema.

### Resposta
Per poder instal·lar directament desde el makefile s'ha d'executar com superuser.

rmsf: rmsf.c
	gcc rmsf.c -o rmsf
	echo "RMSF Compiled!"
	./test.sh
	cp ./rmsf /usr/bin
	echo "Successfully installed RMSF in /usr/bin!"
