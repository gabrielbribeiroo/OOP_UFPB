# Sistema de Controle de Locação de Salas Comerciais

## Descrição do Projeto

O **Sistema de Controle de Locação de Salas Comerciais** é um projeto em C++ que gerencia a locação de salas comerciais em um prédio. O sistema permite associar empresas locatárias a salas, calcular preços de locação e exibir as informações organizadas. Este projeto implementa conceitos de orientação a objetos, incluindo herança, composição, polimorfismo e sobrecarga de operadores.

### Funcionalidades Principais
- **Cadastro de empresas**: Associar empresas locatárias a uma sala, com controle do nome e idade (anos de mercado) de cada empresa.
- **Gerenciamento de salas**: Adicionar e remover salas no prédio, definindo seu andar, número e tipo.
- **Cálculo de preços**: Cada tipo de sala (privativa ou compartilhada) possui um cálculo específico de preço de locação.
- **Organização de dados**:
  - Ordenação de salas por andar (salas em andares inferiores aparecem primeiro).
  - Ordenação de empresas por idade (empresas mais antigas aparecem primeiro).

## Estrutura do Projeto

O projeto está dividido nos seguintes arquivos:

- `main.cpp`: Arquivo principal que gerencia o fluxo do programa.
- `Empresa.h / Empresa.cpp`: Define e implementa a classe **Empresa**, que representa uma empresa locatária, com nome e idade.
- `Sala.h / Sala.cpp`: Define e implementa a classe abstrata **Sala**, que representa uma sala e inclui o número, andar e empresas associadas.
- `SalaPrivativa.h / SalaPrivativa.cpp`: Implementa a classe **SalaPrivativa**, uma sala com capacidade máxima de pessoas.
- `SalaCompartilhada.h / SalaCompartilhada.cpp`: Implementa a classe **SalaCompartilhada**, uma sala com número de estações de trabalho disponíveis.
- `PredioComercial.h / PredioComercial.cpp`: Define e implementa a classe **PredioComercial**, responsável por gerenciar as salas e exibir suas informações.

## Como Compilar e Executar

### Compilação
Para compilar o projeto, certifique-se de que todos os arquivos `.cpp` estão incluídos. Se você estiver usando o **g++**, use o seguinte comando:

```bash
g++ -o sistema main.cpp Empresa.cpp Sala.cpp SalaPrivativa.cpp SalaCompartilhada.cpp PredioComercial.cpp

### Execução
Após a compilação, execute o sistema com o comando:

```bash
./sistema


## Exemplo de Saída
Sala 101 no andar 1:
 - Empresa: Tech Corp, Idade: 15 anos
Sala 102 no andar 2:
 - Empresa: Health Solutions, Idade: 5 anos

## Estrutura de Diretórios
├── include/            # Arquivos de cabeçalho (.h)
│   ├── empresa.h
│   ├── sala.h
│   ├── sala_privativa.h
│   ├── sala_compartilhada.h
│   └── predio_comercial.h
├── src/                # Arquivos de implementação (.cpp)
│   ├── empresa.cpp
│   ├── sala.cpp
│   ├── sala_privativa.cpp
│   ├── sala_compartilhada.cpp
│   └── predio_comercial.cpp
├── main.cpp            # Arquivo principal
└── README.md           # Documentação do projeto

## Autor
- *Gabriel Ribeiro*

### Pontos a Considerar:
- O README inclui uma descrição clara do projeto, suas funcionalidades e instruções detalhadas de como compilar e rodar o programa.
- A estrutura do projeto está descrita de forma organizada, com exemplos de saída e o layout do diretório.
- Há também instruções de como contribuir para o projeto.

Você pode modificar conforme achar necessário, especialmente se houver alterações no fluxo ou no uso do sistema. Se precisar de mais alguma coisa, estou à disposição!