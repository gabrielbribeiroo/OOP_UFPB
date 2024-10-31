# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11

# Diretórios dos arquivos fonte e cabeçalho
SRC_DIR = .
INCLUDE_DIR = .

# Bibliotecas Qt necessárias
QT_LIBS = `pkg-config --cflags --libs Qt5Widgets Qt5Core`

# Arquivos fonte
SRCS = $(SRC_DIR)/empresa.cpp \
       $(SRC_DIR)/main_window.cpp \
       $(SRC_DIR)/menu.cpp \
       $(SRC_DIR)/predio_comercial.cpp \
       $(SRC_DIR)/sala_compartilhada.cpp \
       $(SRC_DIR)/sala_privativa.cpp \
       $(SRC_DIR)/sala.cpp

# Arquivos objeto (gerados a partir dos fontes)
OBJS = $(SRCS:.cpp=.o)

# Executável final
TARGET = sistema_predial

# Regras do Makefile
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(QT_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJS) $(TARGET)

# Rodar o programa
run: $(TARGET)
	./$(TARGET)