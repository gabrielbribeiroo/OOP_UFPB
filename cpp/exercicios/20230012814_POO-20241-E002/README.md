# Sistema de Gerenciamento de Campeonato de Futebol

## Descrição do Projeto

O **Sistema de Gerenciamento de Campeonato de Futebol** é um projeto em C++ que simula a organização de um campeonato de futebol. O sistema permite o cadastro de times, jogadores, técnicos, juízes e jogos, bem como o registro de resultados e a exibição da tabela de classificação final com base nas pontuações.

### Funcionalidades Principais
- Cadastro de **times**, cada um com um técnico e uma lista de jogadores.
- Registro de **técnicos**, incluindo técnicos-jogadores, que atuam tanto como jogadores quanto como técnicos.
- Cadastro de **juízes**, responsáveis por arbitrar os jogos.
- Registro de **jogos** entre os times, com a possibilidade de inserir os resultados dos jogos.
- **Cálculo automático da pontuação** dos times (3 pontos para vitória, 1 ponto para empate e 0 para derrota).
- **Exibição da tabela de classificação** final dos times, ordenada de acordo com a pontuação.

## Estrutura do Projeto
O projeto está dividido nos seguintes arquivos:
- `main.cpp`: Arquivo principal que gerencia o fluxo do programa.
- `campeonato.h / campeonato.cpp`: Define e implementa a classe **campeonato**, responsável por organizar os times, jogos e exibir a classificação.
- `time.h / time.cpp`: Define e implementa a classe **time**, que representa um time de futebol, incluindo seus jogadores e técnico.
- `jogador.h / jogador.cpp`: Define e implementa a classe **jogador**, que mantém informações sobre os jogadores e seu desempenho.
- `tecnico.h / tecnico.cpp`: Define e implementa a classe **tecnico**, que gerencia os técnicos dos times.
- `tecnico_jogador.h / tecnico_jogador.cpp`: Implementa a classe **tecnico_jogador**, que herda tanto de técnico quanto de jogador.
- `juiz.h / juiz.cpp`: Define e implementa a classe **juiz**, responsável pela arbitragem dos jogos.
- `pessoa.h / pessoa.cpp`: Classe base abstrata que define atributos comuns a todas as pessoas no sistema (nome e idade).
- `membro_clube.h / membro_clube.cpp`: Classe intermediária entre `pessoa` e os membros de um clube (jogadores e técnicos).

## Como Compilar e Executar
### Compilação
Para compilar o projeto, certifique-se de que todos os arquivos `.cpp` estão incluídos. Se você estiver usando o **g++**, use o seguinte comando:
``bash
g++ -o main main.cpp campeonato.cpp time.cpp jogador.cpp tecnico.cpp tecnico_jogador.cpp juiz.cpp pessoa.cpp membro_clube.cpp jogo.cpp

## Exemplo de Saída
Tabela: Campeonato Quadrangular
1. Time D - 5 pontos
2. Time C - 5 pontos
3. Time A - 4 pontos
4. Time B - 1 pontos

## Estrutura de Diretórios
├── include/            # Arquivos de cabeçalho (.h)
│   ├── campeonato.h
│   ├── jogador.h
│   ├── tecnico.h
│   ├── tecnico_jogador.h
│   ├── juiz.h
│   ├── pessoa.h
│   └── membro_clube.h
├── src/                # Arquivos de implementação (.cpp)
│   ├── campeonato.cpp
│   ├── jogador.cpp
│   ├── tecnico.cpp
│   ├── tecnico_jogador.cpp
│   ├── juiz.cpp
│   ├── pessoa.cpp
│   └── membro_clube.cpp
├── main.cpp            # Arquivo principal
├── Makefile            # Arquivo Makefile para facilitar a compilação
└── README.md           # Documentação do projeto

## Autor
- *Gabriel Ribeiro*
### Pontos a Considerar:
- O README inclui uma descrição clara do projeto, suas funcionalidades e instruções detalhadas de como compilar e rodar o programa.
- A estrutura do projeto está descrita de forma organizada, com exemplos de saída e o layout do diretório.
- Há também instruções de como contribuir para o projeto.

Você pode modificar conforme achar necessário, especialmente se houver alterações no fluxo ou no uso do sistema. Se precisar de mais alguma coisa, estou à disposição!
