    pessoa(const string &n, int i);
    ~pessoa();

    string get_nome() const {
        return nome;
    }

    void set_nome(const string &n) {
        nome = n;
    }

    int get_idade() const {
        return idade;
    }

    void set_idade(int i) {
        idade = i;
    }