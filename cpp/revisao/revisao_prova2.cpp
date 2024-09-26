/*
                        LISTA DE REVISÃO - PROVA 2 - POO - 2024.1

  QUESTÃO 1: Considere um sistema de gerenciamento de biblioteca que implementa
as classes `Pessoa` e `Livro`. A classe `Pessoa` possui atributos como nome,
data de nascimento e endereço. A classe `Livro` possui título, autor, data de
publicação e gênero. Uma classe `Aluno` herda da classe `Pessoa` e possui
atributos como matrícula e data de matrícula. Uma classe `Professor` também
herda da classe `Pessoa` e possui atributos como titulação e área de pesquisa.

a) Qual tipo de herança você usaria na relação entre as classes `Pessoa`,
`Aluno` e `Professor`? Explique sua resposta.

  RESPOSTA:
    Herança apropriada para a relação apresentada é a herança pública (public),
pois tanto a classe 'Aluno' e 'Professor' são subtipos de 'Pessoa', então
necessitando de subtipagem e da interface pública, propriedades da herança do
tipo public.


b) Suponha que a classe `Aluno` precisa acessar um atributo privado da classe
`Pessoa` para calcular a idade do aluno. Qual modificador de acesso deve ser
utilizado para permitir esse acesso sem violar o encapsulamento? Explique como
essa escolha protege a integridade dos dados.

  RESPOSTA:
    O modificador de acesso (encapsulamento) deve ser protegido (protected),
para poder realizar o acesso aos métodos e atributos através das classes, e não
por objetos.


  QUESTÃO 2: Considere uma hierarquia de classes para modelar diferentes formas
geométricas e animais em C++. A hierarquia inclui as seguintes classes: ● Shape:
Uma classe base que representa uma forma geométrica. Ela possui um método
virtual chamado `area()` que pode ser sobrescrito pelas classes derivadas. ●
Circle: Uma classe derivada de `Shape` que representa um círculo. Ela tem um
atributo `radius` e sobrescreve o método `area()` para calcular a área do
círculo. ● Rectangle: Outra classe derivada de `Shape` que representa um
retângulo. Ela possui atributos `width` e `height` e também sobrescreve o método
`area()` para calcular a área do retângulo. ● Animal: Uma classe base que
representa um animal. Ela possui um método virtual puro chamado `speak()`, que
deve ser implementado pelas classes derivadas. ● Dog: Uma classe derivada de
`Animal` que representa um cachorro. Ela implementa o método `speak()` para
fazer o cachorro latir. ● Cat: Outra classe derivada de `Animal` que representa
um gato. Ela implementa o método `speak()` para fazer o gato miar.

a) Explique os conceitos de função virtual e função virtual pura em C++ e
forneça exemplos de uso desses conceitos na hierarquia de classes acima.

  RESPOSTA:
    Função virtual: mecanismo através do qual podemos sobescrever métodos de
classes ascendentes e permitir que a implementação definida nas classes
descendentes seja invocada através de ponteiros para a classe ascendente, pois o
comportamento de uma classe pode variar de acordo com a classe derivada.

    Função virtual pura: não possui implementação na classe ascendente
(abstrata).


b) Explique brevemente o que significa ter um atributo ou método como estático
em C++ e dê um exemplo de utilização de um atributo e um método estático (na
classe Shape ou na classe Animal).

  RESPOSTA:
    Atributo estático: é um atributo que é compartilhado por todas as instâncias
da classe.
    Ex: contador de objetos.


  QUESTÃO 3: Considere que você está desenvolvendo um sistema para modelar
diferentes tipos de dispositivos eletrônicos em C++. Você deseja usar herança
múltipla para criar uma classe SmartDevice que herda de duas classes base:
WiFiEnabled e BluetoothEnabled. Ambas as classes base têm uma função chamada
connect(). Complete o código abaixo:

  class WiFiEnabled {
    double range;
  public:
    void connect() {
      cout << "Wi-Fi!" << endl;
    }
    //Sobrecarregar operador + para somar
    //valores double no atributo range
    WifiEnabled operator+(double v) {
      WifiEnabled temp = &this;
      temp.range += v;
      return temp;
    }
    //Sobrecarregar operador de subtração -
    //para subtrair valores double no range
    WifiEnabled operator-(double v) {
      WifiEnabled temp = &this;
      temp.range -= v;
      return temp;
    }
  };

  class BluetoothEnabled {
  public:
    void connect() {
      cout << "Bluetooth!" << endl;
    }
  };

  class SmartDevice : public WiFiEnabled,
    public BluetoothEnabled {
      public:
        // Complete esta função para resolver a
        // colisão de funções herdadas
        void connect() override {
        //Resolva a colisão aqui
          WiFiEnabled::connect();
          BluetoothEnabled::connect();
        }
  };

  int main() {
    SmartDevice sd1(...);
    BluetoothDevice *pbt = &sd1;
    pbt->bt.config();
    return 0;
  }
*/

/*
                        IMPLEMENTAÇÕES
class shape {
public:
  virtual double area() const {
    return 0.0;
  }
};

class circle : public shape {
private:
  double radius;
public:
  circle(double r) : radius(r) {}
  double get_radius() const {
    return radius;
  }
  void set_radius(double r) {
    radius = r;
  }
  double area() const override {
    return 3.14 * radius * radius;
  }
};

class rectangle : public shape {
private:
  double width, height;
public:
  rectangle(double w, double h) : width(w), height(h) {}
  double get_width() const {
    return width;
  }
  void set_width(double w) {
    width = w;
  }
  double get_height() const {
    return height;
  }
  void set_height(double h) {
    height = h;
  }
  double area() const override {
    return width * height;
  }
};

class animal {
  static int count;
public:
  animal() {
    count++;
  }
  ~animal() {
    count--;
  }
  virtual void speak() const = 0; // virtual void speak() = 0;
  static int get_count() {
    return count;
  }
};

static int animal::count = 0;

class dog : public animal {
public:
  // void speak()
  void speak() const override {
    cout << "au au" << endl;
  }
};

class cat : public animal {
public:
  // void speak()
  void speak() const override {
    cout << "miau" << endl;
  }
};

int main() {
  circle c1(10.5);
  shape *s1;
  s1 = &c1;
  double x = s1->area();
  dog d1;
  animal *a1;
  a1 = &d1;
  a1->speak();
  return 0;
}

*/

/*
                        ANOTAÇÕES EXTRAS
// Caso a classe descendente também não implemente o método virtual puro que foi
herdado da classe base (abstrata), também será uma classe abstrata.

// Na subtipagem, presente somente na herança pública, é permitido um ponteiro
da classe base apontar para um objeto da classe derivada.

// Pode ser criado ponteiros para a classe abstrata, porém não é possível criar
objetos/instâncias dela.

// Const é uma palavra-chave que indica que um método não pode ser modificado.

// Atributo estático é inicializado fora da classe.

// Atributo membro é acessado somente através do objeto.

// Para herança "diamante", as duas classes que herdam da classe mais ascendente
devem possuir heranças virtuais.
*/