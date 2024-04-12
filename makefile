CC = g++
CFLAGS = -Wall
SRC_DIR = src
BUILD_DIR = build
EXECUTABLE = App

# Definição dos diretórios alvo
TARGET_DIRS = datasets datasets/algOrdenado datasets/algDesordenado datasets/Matrix_Dados

# Obter a lista de arquivos .cpp no diretório SRC_DIR
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Gerar os nomes dos arquivos .o correspondentes no diretório BUILD_DIR
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Regra para compilar cada arquivo .cpp em um arquivo .o correspondente
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

# Regra para compilar todos os objetos em um executável
$(BUILD_DIR)/$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra padrão para compilar tudo e criar os diretórios alvo, se necessário
all: $(BUILD_DIR)/$(EXECUTABLE) | $(TARGET_DIRS)

# Regra para criar os diretórios alvo se não existirem
$(TARGET_DIRS):
	mkdir -p $@
	chmod +w $@

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/$(EXECUTABLE)

run: all
	@echo "=== Running $(EXECUTABLE) ==="
	./$(BUILD_DIR)/$(EXECUTABLE)

# Regra para executar o script Gnuplot para os dados de 1000
plotgraph_1000:
	gnuplot vet1000_gnuplotScript.gp

# Regra para executar o script Gnuplot para os dados de 10000
plotgraph_10000:
	gnuplot vet10000_gnuplotScript.gp

# Regra para executar o script Gnuplot para os dados de 100000
plotgraph_100000:
	gnuplot vet100000_gnuplotScript.gp

# Regra para executar o script Gnuplot para os dados de 500000
plotgraph_500000:
	gnuplot vet500000_gnuplotScript.gp

# Regra para executar todos os scripts Gnuplot
plotgraph: plotgraph_1000 plotgraph_10000 plotgraph_100000 plotgraph_500000

.PHONY: clean run plotgraph plotgraph_1000 plotgraph_10000 plotgraph_100000 plotgraph_500000

