# Shortest Commom Superstring (exato)

## Introdução  

Nesta pasta contém a implementação de dois algoritmos exatos que resolvem o problema da menor superstring comum onde um faz uso da técnica denominada bactracking e o outro faz uso de outra técnia, programação dinâmica juntamente com bitmasking.

- [Requisitos](#requisitos) - Requisitos de software necessarios para executar o projeto.
- [Compilacao e execucao](#compilacao-e-execucao) - Explicao das etapas de compilacao e execucao do projeto.
- [Autores](#autores) - Autores do projeto.

## Requisitos    

Compilador C++ 14 (__g++__).
	
	Obs.: Para usuários Linux, o g++ eh nativo, faltando apenas atualiza-lo para a versao 14.  
	Porém, caso deseje usar o g++ no Windows será necessário instalar-lo por meio do MinGW. 

## Compilação e execução

	Obs.: Todos os códigos digitados no terminal deverão ser na respectiva pasta raiz do programa.  

Execute na linha de terminal para a compilação e criação do objetos

```
$ make
```  
Ou, caso deseje apagar os objetos e os executáveis, digite  

```
$ make clean
```  
Em seguida, serão criados os seguintes arquivos binários (executáveis):

| Nome do executável: | Descrição: | 
| ---------- | ------------- |
|`backtracking` 	| Algoritmo exato que usa backtracking.  
|`dynamicPrograming` 	|Algoritmo exato que usa programação dinâmica com bitmasking.  
  
Diante disso, para executar o arquivo binário `servidor` basta:

```
$ ./bin/backtracking
```
E, para executar o arquivo binário `dynamicPrograming` basta: 

```
$ ./bin/dynamicPrograming
```
  
## Autores 

| Name: | Github: | Email: |  
| ---------- | ------------- | ------------- |
|`Daniel Henrique` 	| https://github.com/Danhfg |_danhfg@ufrn.edu.br_  
|`Samuel Lucas` 	| https://github.com/Samuellucas97 |_samuellucas97@ufrn.edu.br_  

