#include <iostream>
#include <string>

#define PI 3.1416

using std::cout;
using std::endl;
using std::string;

class Poligono {
protected:
    string cor;
public:
    /*
    Poligono(const string &c): cor(c) {} // Construtor
    ~Poligono() {} // Destrutor
    */

    string get_cor() const {
        return cor;
    }

    void set_cor(const string &c) {
        cor = c;
    }

    virtual double get_area() = 0;
};

class Circulo : public Poligono {
private:
    double raio;
public:
    Circulo(const string &c, double r): raio(r) {
        cor = c;
    } // Construtor

    ~Circulo() {} // Destrutor

    double get_raio() const {
        return raio;
    }

    void set_raio(double r) {
        raio = r;
    }

    virtual double get_area() {
        return (PI*raio*raio);
    }
};

class Retangulo : public Poligono {
private:
    double base;
    double altura;
public:
    Retangulo(const string &c, double b, double a): base(b), altura(a) {
        cor = c;
    } // Construtor

    ~Retangulo() {} // Destrutor

    double get_base() const {
        return base;
    }

    void set_base(double b) {
        base = b;
    }

    double get_altura() const {
        return altura;
    }

    void set_altura(double a) {
        altura = a;
    }

    virtual double get_area() {
        return base*altura;
    }
};

class Triangulo : public Poligono {
private:
    double base;
    double altura;
public:
    Triangulo(const string &c, double b, double a): base(b), altura(a) {
        cor = c;
    } // Construtor

    ~Triangulo() {} // Destrutor

    double get_base() const {
        return base;
    }

    void set_base(double b) {
        base = b;
    }

    double get_altura() const {
        return altura;
    }

    void set_altura(double a) {
        altura = a;
    }

    virtual double get_area() {
        return (base*altura)/2;
    }
};

class Trapezio : public Poligono {
private:
    double base_maior;
    double base_menor;
    double altura;
public:
    Trapezio(const string &c, double bma, double bme, double a): base_maior(bma), base_menor(bme), altura(a) {
        cor = c;
    } // Construtor

    ~Trapezio() {} // Destrutor

    double get_base_maior() const {
        return base_maior;
    }

    void set_base_maior(double bma) {
        base_maior = bma;
    } 

    double get_base_menor() const {
        return base_menor;
    }

    void set_base_menor(double bme) {
        base_menor = bme;
    } 

    double get_altura() const {
        return altura;
    }

    void set_altura(double a) {
        altura = a;
    }

    virtual double get_area() {
        return ((base_maior+base_menor)*altura)/2;
    }
};

int main() {
    Circulo cir1("AZUL", 10);
    Retangulo ret1("AMARELO", 10, 20);
    Triangulo tri1("VERMELHO", 20, 5);
    Trapezio tra1("VERDE", 20, 10, 7);

    Poligono *p1 = &cir1;
    Poligono *p2 = &ret1;
    Poligono *p3 = &tri1;
    Poligono *p4 = &tra1;

    double soma_area = 0;

    soma_area = cir1.get_area() + ret1.get_area() + tri1.get_area() + tra1.get_area();

    cout << "Soma das areas = " << soma_area << endl;

    soma_area = p1->get_area() + p2->get_area() + p3->get_area() + p4->get_area();

    cout << "Soma das areas = " << soma_area << endl;

    return 0;
}