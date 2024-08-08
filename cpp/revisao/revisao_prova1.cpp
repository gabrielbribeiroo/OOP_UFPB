/*
                        LISTA DE REVISÃO - PROVA 1 - POO - 2024.1

    QUESTÃO 1: Considere um sistema de gerenciamento bancário. 
    Neste sistema, temos duas entidades principais: `conta` e `transacao`. 
    a) A entidade `conta` tem atributos como numero_da_conta, saldo e tipo (corrente ou poupança). 
    Além disso, a entidade conta tem métodos como depositar(double valor) (que adiciona o valor ao saldo da conta) e 
    sacar(double valor) (que subtrai o valor do saldo da conta, se houver saldo suficiente). 
    b) A entidade `transacao` representa uma transação financeira. Ela tem atributos como conta_origem, conta_destino e valor. 
    A entidade `transacao` tem um método executar() que transfere o valor da conta_origem para a conta_destino.
    Explique os conceitos de classes e objetos usando as entidades `conta` e `transacao` como exemplos. 
    Além disso, forneça um esboço de uma implementação em C++ dessas duas classes, incluindo a declaração de seus atributos e métodos, e como estas classes poderiam ser instanciadas.

    RESPOSTA:
        Classes: conta e transacao.
        Objetos: conta e transacao.
        Atributos: conta: numero_da_conta, saldo e tipo (corrente ou poupança).
        Atributos: transacao: conta_origem, conta_destino e valor.
        Métodos: conta: depositar(double valor) (que adiciona o valor ao saldo da conta) e sacar(double valor) (que subtrai o valor do saldo da conta, se houver) 
        Métodos: transacao: executar() que transfere o valor da conta_origem para a conta_destino. 
        Implementação em C++: 
            class conta { int num; char tipo;
                double saldo;
            public:
                int depositar(double d);
                int sacar(double s);
                conta(int n, char t, double s);
                ~conta();
            };

            class transacao {
                double valor;
                conta *origem;
                conta *destino;
            public:
                int executar();
                transacao(double v, conta *o, conta *d);
                ~transacao();
            };

            int main(void) {
                conta c1(1011, 'p', 1000);
                conta c2(1012, 'p', 3000);
                transacao t1(100, &c1, &c2);
            }




    QUESTÃO 2: Defina agregação e composição em programação orientada a objetos. 
    Explique porque e como utilizar um ou outro.

    RESPOSTA:
        Agregação: classe agregadora pode existir fora do contexto da associação; as partes (objetos agregados) podem existir fora da classe agregadora.
        (Ex: biblioteca/livros(parte) ou turma/alunos(parte).)
        Agregação: é uma relação entre duas classes, onde uma classe é uma parte integrante de outra classe.

        Composição: classe composta não existe sem objetos que são parte dela; objetos parte (compostos) não podem existir fora da classe composta.
        (Ex: carro/motor,chassi,roda)
        Composição: é uma relação entre duas classes, onde uma classe é uma parte de outra classe.
    



    QUESTÃO 3: Para que servem os métodos construtores e destrutores, e como declará-los em C++?

    RESPOSTA:
        Construtor: inicializar os atributos do objeto; realiza todas as ações necessárias para a existência/criação do objeto.
        Construtor: nome da classe, recebe parâmetros, não tem retorno, inicializa os atributos do objeto.
        Destrutor: desalocar memória alocada dinamicamente; libera todos os recursos usados pelo objeto.
        Destrutor: ~nome da classe, não recebe parâmetros, não tem retorno, desaloca memória alocada dinamicamente.




    QUESTÃO 4: Explique o que você entende por encapsulamento e como usar em classes C++.

    RESPOSTA:
        Encapsulamento: é o processo de ocultar os detalhes de implementação de uma mecanismo que viabiliza a definição de níveis de visibilidade/acesso aos atributos e métodos de uma classe; 
        podem se definir diferentes níveis através de etiquetas como: public e private (acesso padrão).
        Public: atributos e métodos membro são acessíveis através dos objetos da classe (acesso irrestrito).
        Private: atributos e métodos membro são acessíveis apenas dentro do escopo da classe (acesso restrito).

        


    QUESTÃO 5: Qual é a saída (na saída padrão/tela) da execução do seguinte programa em C++:
    #include <iostream> 
    #include <memory> 
    #include <string> 
    class endereco { 
    private: 
        std::string rua; 
        int numero; 
    public: 
        endereco(const std::string &rua, int numero) : rua(rua), numero(numero) { 
            std::cout << "Construtor de endereco chamado.\n";
        }
        ~endereco() {
            std::cout << "Destrutor de endereco chamado.\n";
        }
        void mostrar_endereco() const {
            std::cout << "Endereco: " << rua << ", " << numero << '\n';
        }
    };
    class pessoa {
    private:
        std::string nome;
        int idade;
        std::shared_ptr<endereco> endereco_;
    public:
        pessoa(const std::string &nome, int idade, std::shared_ptr<endereco> endereco_) : nome(nome), idade(idade), endereco_(endereco_) { 
            std::cout << "Construtor de pessoa chamado.\n";
        }
        ~pessoa() {
            std::cout << "Destrutor de pessoa chamado.\n";
        }
        void mostrar_pessoa() const {
            std::cout << "Nome: " << nome << ", Idade: " << idade << '\n';
            endereco_->mostrar_endereco();
        }
    };
    class empresa {
    private:
        std::string nome;
        std::unique_ptr<endereco> endereco_;
    public:
        empresa(const std::string &nome, std::unique_ptr<endereco> endereco_) : nome(nome), endereco_(std::move(endereco_)) { 
            std::cout << "Construtor de empresa chamado.\n";
        }
        ~empresa() {
            std::cout << "Destrutor de empresa chamado.\n";
        }
        void mostrar_empresa() const {
            std::cout << "Empresa: " << nome << '\n';
            endereco_->mostrar_endereco();
        }
    };
    int main() {
        std::string nome_rua_1 = "Rua A";
        auto endereco_pessoa = std::make_shared<endereco>(nome_rua_1, 123);
        nome_rua_1 = "Rua C";
        pessoa pessoa_("João", 30, endereco_pessoa);
        std::string nome_empresa_2 = "ACMECorp";
        empresa empresa_(nome_empresa_2, std::make_unique<endereco>("Rua B", 456));
        nome_empresa_2 = "ACMECorp Inc.";
        std::cout << "Dados da pessoa:\n";
        pessoa_.mostrar_pessoa();
        std::cout << "\nDados da empresa:\n";
        empresa_.mostrar_empresa();
        return 0;
    }

    RESPOSTA:
        Construtor de endereco chamado.
        Construtor de pessoa chamado.
        Construtor de endereco chamado.
        Construtor de empresa chamado.
        Dados da pessoa:
        Nome: João, Idade: 30
        Endereco: Rua A, 123
        Dados da empresa:
        Empresa: ACMECorp
        Endereco: Rua B, 456
        Destrutor de empresa chamado.
        Destrutor de endereco chamado.
        Destrutor de pessoa chamado.
        Destrutor de endereco chamado.
    */

    /*
                            ANOTAÇÕES EXTRAS
    // Classes definem atributos e métodos possíveis de um objeto.
    // Objetos são instâncias de classes.
    // Atributos são as características de um objeto.
    // Métodos são as ações que um objeto pode realizar.
    // Construtores são métodos especiais que são chamados quando um objeto é criado. 
    // Destrutores são métodos especiais que são chamados quando um objeto é destruído.
    // Atributos e métodos podem ser declarados em classes ou em objetos.
    // Agregação é uma relação entre duas classes, onde uma classe é uma parte integrante de outra classe.
    // Agregação é uma relação de dependência entre duas classes, onde uma classe é uma parte de outra classe.
    // Composição é uma relação entre duas classes, onde uma classe é uma parte de outra classe.
    // Composição pode ser usada em unique pointer.
    // Métodos construtores: são métodos que são chamados automaticamente quando um objeto é criado.
    // Métodos construtores: são métodos especiais que são executados quando um objeto é criado.
    // Os métodos construtores podem ser invocados diretamente ou através de uma variável ponteiro.
    // Métodos destrutores: realiza todas as ações necessárias para a destruição do objeto.
    // Métodos destrutores: são métodos especiais que são executados quando um objeto é destruído.
    // Os métodos construtores podem ser invocados com new, precisando de um delete (método destrutor) ao final do código.
    // Encapsulamento private: atributos e métodos membro são acessíveis apenas dentro da classe.
    // Encapsulamento public: atributos e métodos membro são acessíveis fora da classe (acesso indiscriminado).
    // Os métodos destrutores acontecem de maneira inversa à ordem dos construtores.
*/