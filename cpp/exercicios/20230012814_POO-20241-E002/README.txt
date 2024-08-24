Projeto POO - Gestão de Atletas e Medalhas
Este projeto implementa um sistema para gerenciar atletas, modalidades esportivas, países e medalhas, utilizando conceitos de Programação Orientada a Objetos (POO) em C++. 
O sistema faz uso de ponteiros inteligentes (std::unique_ptr) para gerenciar recursos de memória de forma segura e eficiente.

Estrutura do Projeto

Headers:
pais.h: Declaração da classe Pais.
modalidade.h: Declaração da classe Modalidade.
atleta.h: Declaração da classe Atleta.
medalha.h: Declaração da classe Medalha.

Implementações:
pais.cpp: Implementação dos métodos da classe Pais.
modalidade.cpp: Implementação dos métodos da classe Modalidade.
atleta.cpp: Implementação dos métodos da classe Atleta.
medalha.cpp: Implementação dos métodos da classe Medalha.

Principal:
main.cpp: Contém o ponto de entrada do programa e realiza a criação e manipulação dos objetos.


3. Resultado Esperado
Ao executar o programa, as mensagens de criação e destruição dos objetos serão exibidas, mostrando a gestão de memória e a ordem de execução dos destrutores.

Exemplo de saída:
Pais: United States of America criado!
Modalidade: Basquete criada!
Atleta: Lebron James criado!
Medalha: Ouro criada!
Medalha: Ouro, Ano: 2024
Atleta: Lebron James
Pais: United States of America
Continente: America do Norte
Modalidade: Basquete
Tipo: Coletiva
Modalidade: Basquete destruída!
Atleta: Lebron James destruído!
Pais: United States of America destruído!
Modalidade: Basquete destruída!
Medalha: Ouro destruída!
Fim do programa.

Movimentação de Ponteiros: Certifique-se de não mover um std::unique_ptr mais de uma vez, para evitar a perda de acesso ao objeto original.
Gerenciamento de Recursos: O uso de std::unique_ptr garante que os destrutores sejam chamados automaticamente, mas requer atenção à ordem em que os objetos são criados e destruídos.


Autor
Nome: [Gabriel Barbosa Ribeiro de Oliveira]
Contato: [gabriel.ribeiro@academico.ufpb.br]