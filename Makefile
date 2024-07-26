# Makefile para Algoritmos de Ordenação

CC = gcc
CFLAGS = -Wall -O2
TARGET = Algoritmos_Ordenacao
OBJS = Algoritmos_Ordenacao.o

# Alvo principal
all: $(TARGET)

# Compilação do alvo principal
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilação dos arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJS) $(TARGET)

# Execução do programa
run: $(TARGET)
	./$(TARGET) input.txt