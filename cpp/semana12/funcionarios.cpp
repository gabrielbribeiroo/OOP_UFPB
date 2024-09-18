#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// Classe base
class employee {
private:
    string name;
    int id;
    double base_salary;
    static int total_employees; // Variável estática para contar o total de funcionários
public:
    // Construtor
    employee(const string &n, int i, double s): name(n), id(i), base_salary(s) {
        total_employees++; // Incrementa o contador de funcionários
    }

    // Destrutor
    virtual ~employee() {
        total_employees--; // Decrementa o contador de funcionários
    }

    // Métodos getters e setters
    string get_name() const {
        return name;
    }

    void set_name(const string &n) {
        name = n;
    }

    int get_id() const {
        return id;
    }

    void set_id(int i) {
        id = i;
    }

    double get_base_salary() const {
        return base_salary;
    }

    void set_base_salary(double s) {
        base_salary = s;
    }

    virtual string get_role() const = 0; // Método virtual puro para obter o cargo

    // Método virtual para calcular o salário (pode ser sobrescrito nas subclasses)
    virtual double calculate_salary() const {
        return base_salary;
    }

    // Método estático para obter o total de funcionários
    static int get_total_employees() {
        return total_employees;
    }

    // Método para exibir informações do funcionário
    virtual void show_info() const {
        cout << "-----------------------" << endl;
        cout << "Funcionario" << endl;
        cout << "Nome: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salario base: " << base_salary << endl;
        cout << "Cargo: " << get_role() << endl;
    }
};

int employee::total_employees = 0; // Inicializa o contador estático

// Classe developer herda virtualmente a classe employee
class developer : virtual public employee {
private:
    string programming_language;
public:
    developer(const string &n, int i, double s, const string &p): employee(n, i, s), programming_language(p) {} // Construtor
    ~developer() {} // Destrutor

    string get_programming_language() const {
        return programming_language;
    }

    void set_programming_language(const string &p) {
        programming_language = p;
    }

    virtual string get_role() const override {
        return "Developer";
    }

    // Usamos get_base_salary() para acessar o salário base
    virtual double calculate_salary() const override {
        return get_base_salary() * 1.10; // Bônus de 10%
    }

    void show_info() const override {
        employee::show_info();
        cout << "Linguagem de programacao: " << programming_language << endl;
        cout << "Salario total: " << calculate_salary() << endl;
    }
};

// Classe manager herda virtualmente a classe employee
class manager : virtual public employee {
private:
    int team_size;
public:
    manager(const string &n, int i, double s, int t): employee(n, i, s), team_size(t) {} // Construtor
    ~manager() {} // Destrutor

    int get_team_size() const {
        return team_size;
    }

    void set_team_size(int t) {
        team_size = t;
    }

    virtual string get_role() const override {
        return "Manager";
    }

    // Usamos get_base_salary() para acessar o salário base
    virtual double calculate_salary() const override {
        return get_base_salary() + (100.0 * team_size); // $100 por membro da equipe
    }

    void show_info() const override {
        employee::show_info();
        cout << "Tamanho da equipe: " << team_size << endl;
        cout << "Salario total: " << calculate_salary() << endl;
    }
};

// Classe tech_lead com herança múltipla das classes developer e manager
class tech_lead : public developer, public manager {
public:
    tech_lead(const string &n, int i, double s, const string &p, int t)
        : employee(n, i, s), developer(n, i, s, p), manager(n, i, s, t) {
    } // Construtor
    ~tech_lead() {} // Destrutor

    // Implementa o método get_role
    virtual string get_role() const override {
        return "Tech Lead";
    }

    // Sobrescreve calculate_salary para somar os bônus de manager e developer
    virtual double calculate_salary() const override {
        return developer::calculate_salary() + (100.0 * get_team_size());
    }

    // Sobrescreve show_info para exibir as informações do tech lead
    void show_info() const override {
        employee::show_info();
        cout << "Linguagem de programacao: " << developer::get_programming_language() << endl;
        cout << "Tamanho da equipe: " << manager::get_team_size() << endl;
        cout << "Salario total: " << calculate_salary() << endl;
    }
};

int main() {
    // Cadastro dos funcionários
    manager m1("Pedro", 1111, 3000, 5);
    tech_lead tl1("João", 2222, 5000, "C++", 10);
    tech_lead tl2("Lucas", 3333, 5000, "Java", 10);
    developer d1("Paulo", 4444, 2500, "Python");
    developer d2("Mateus", 5555, 2500, "C#");
    developer d3("Ana", 6666, 2500, "PHP");
    developer d4("Maria", 7777, 2500, "JavaScript");
    developer d5("Carol", 8888, 2500, "C");

    // Exibindo informações dos funcionários
    cout << "\n=== Informacoes dos Funcionarios ===\n" << endl;
    m1.show_info();
    cout << endl;
    tl1.show_info();
    cout << endl;
    tl2.show_info();
    cout << endl;
    d1.show_info();
    cout << endl;
    d2.show_info();
    cout << endl;
    d3.show_info();
    cout << endl;
    d4.show_info();
    cout << endl;
    d5.show_info();
    cout << endl;

    cout << "Total de funcionarios cadastrados: " << employee::get_total_employees() << endl << endl; // Exibindo total de funcionários cadastrados
    
    return 0;
}