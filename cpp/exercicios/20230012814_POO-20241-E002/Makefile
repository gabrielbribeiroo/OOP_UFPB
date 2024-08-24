# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -g

# Nome do executável
TARGET = meu_programa

# Lista dos arquivos objeto
OBJS = main.o atleta.o medalha.o modalidade.o pais.o

# Regra padrão, para criar o executável
all: $(TARGET)

# Regras para compilar cada arquivo objeto
main.o: main.cpp atleta.h medalha.h modalidade.h pais.h
	$(CXX) $(CXXFLAGS) -c main.cpp

atleta.o: atleta.cpp atleta.h pais.h modalidade.h
	$(CXX) $(CXXFLAGS) -c atleta.cpp

medalha.o: medalha.cpp medalha.h atleta.h modalidade.h
	$(CXX) $(CXXFLAGS) -c medalha.cpp

modalidade.o: modalidade.cpp modalidade.h
	$(CXX) $(CXXFLAGS) -c modalidade.cpp

pais.o: pais.cpp pais.h
	$(CXX) $(CXXFLAGS) -c pais.cpp

# Regra para criar o executável a partir dos arquivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)
