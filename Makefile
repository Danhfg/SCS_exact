RM = rm -rf
#Compilador
CC=g++

#Variaveis para os subdiretorios
#LIB_DIR=./lib Não haverá pois nenhuma biblioteca será usada
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin

#Opcoes de compilacao 
CFLAGS=	-Wall -pedantic -ansi -std=c++11 

#Garante que os alvos desta lista não sejam confundidos com arquivos de mesmo nome 
.PHONY:	all	clean	debug	

#Ao final da compilacão, remove os arquivos objetos
all: init dynamicProgramming backtracking

debug:	CFLAGS += -g -O0
debug:	dynamicProgramming backtracking

# Cria a pasta/diretório bin e a obj
init:
	@mkdir -p $(OBJ_DIR)/
	@mkdir -p $(BIN_DIR)

# Alvo (target) para a construcao do executavel questao01
# Define os arquivos dynamicProgramming.o, calcula.o, perimetro.o, volume.o e main.o como dependencias
dynamicProgramming: CFLAGS+= -I$(INC_DIR)/
dynamicProgramming: $(OBJ_DIR)/dynamicProgramming.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel dynamicProgramming criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto dynamicProgramming.o
# Define os arquivos dynamicProgramming.cpp e dynamicProgramming.h como dependencias.
$(OBJ_DIR)/dynamicProgramming.o: $(SRC_DIR)/dynamicProgramming.cpp $(INC_DIR)/dynamicProgramming.h
	$(CC) -c $(CFLAGS) -o $@ $<


# Alvo (target) para a construcao do executavel questao01
# Define os arquivos dynamicProgramming.o, calcula.o, perimetro.o, volume.o e main.o como dependencias
backtracking: CFLAGS+= -I$(INC_DIR)/
backtracking: $(OBJ_DIR)/backtracking.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel backtracking criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto dynamicProgramming.o
# Define os arquivos dynamicProgramming.cpp e dynamicProgramming.h como dependencias.
$(OBJ_DIR)/backtracking.o: $(SRC_DIR)/backtracking.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

#removendo os .o e os binários
clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

#FIM DO MAKEFILE
