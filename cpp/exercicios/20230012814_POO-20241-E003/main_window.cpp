#include "main_window.h"

/**
 * @brief Construtor da classe main_window, inicializa a interface do menu.
 * @param parent Ponteiro para o widget pai, padrão nullptr.
 */
main_window::main_window(QWidget *parent) : QMainWindow(parent), predio() {
    // Configuração do layout e criação dos botões
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    btnAdicionarSala = new QPushButton("Adicionar Sala", this);
    btnRemoverSala = new QPushButton("Remover Sala", this);
    btnAdicionarEmpresa = new QPushButton("Adicionar Empresa a uma Sala", this);
    btnRemoverEmpresa = new QPushButton("Remover Empresa de uma Sala", this);
    btnListarSalas = new QPushButton("Listar Salas e Empresas", this);

    layout->addWidget(btnAdicionarSala);
    layout->addWidget(btnRemoverSala);
    layout->addWidget(btnAdicionarEmpresa);
    layout->addWidget(btnRemoverEmpresa);
    layout->addWidget(btnListarSalas);

    setCentralWidget(centralWidget);

    // Conexão dos botões com seus respectivos slots
    connect(btnAdicionarSala, &QPushButton::clicked, this, &Menu::adicionarSala);
    connect(btnRemoverSala, &QPushButton::clicked, this, &Menu::removerSala);
    connect(btnAdicionarEmpresa, &QPushButton::clicked, this, &Menu::adicionarEmpresa);
    connect(btnRemoverEmpresa, &QPushButton::clicked, this, &Menu::removerEmpresa);
    connect(btnListarSalas, &QPushButton::clicked, this, &Menu::listarSalas);
}

/**
 * @brief Slot que exibe um diálogo para adicionar uma nova sala ao prédio.
 */
void main_window::adicionar_sala() {
    bool ok;
    int tipo = QInputDialog::getInt(this, "Tipo de Sala", "Escolha o tipo de sala [1 - Privativa, 2 - Compartilhada]:", 1, 1, 2, 1, &ok);
    if (!ok) return;

    int numero = QInputDialog::getInt(this, "Número da Sala", "Digite o número da sala:", 0, 0, 1000, 1, &ok);
    if (!ok) return;

    int andar = QInputDialog::getInt(this, "Andar da Sala", "Digite o andar:", 0, 0, 50, 1, &ok);
    if (!ok) return;

    if (tipo == 1) {
        int capacidade = QInputDialog::getInt(this, "Capacidade", "Digite a capacidade máxima de pessoas:", 0, 0, 100, 1, &ok);
        if (!ok) return;
        sala_privativa *sala = new sala_privativa(numero, andar, capacidade);
        predio + sala;
    } 
    else if (tipo == 2) {
        int estacoes = QInputDialog::getInt(this, "Estações de Trabalho", "Digite o número de estações de trabalho disponíveis:", 0, 0, 100, 1, &ok);
        if (!ok) return;
        sala_compartilhada *sala = new sala_compartilhada(numero, andar, estacoes);
        predio + sala;
    }
}

/**
 * @brief Slot que exibe um diálogo para remover uma sala específica.
 */
void main_window::remover_sala() {
    bool ok;
    int numero = QInputDialog::getInt(this, "Remover Sala", "Digite o número da sala a ser removida:", 0, 0, 1000, 1, &ok);
    if (!ok) return;

    sala *sala_a_remover = predio.buscar_sala_por_numero(numero);
    if (sala_a_remover) {
        predio - sala_a_remover;
        QMessageBox::information(this, "Sucesso", "Sala removida com sucesso.");
    } 
    else {
        QMessageBox::warning(this, "Erro", "Sala não encontrada.");
    }
}

/**
 * @brief Slot que exibe um diálogo para adicionar uma empresa a uma sala.
 */
void main_window::adicionar_empresa() {
    bool ok;
    int numero = QInputDialog::getInt(this, "Adicionar Empresa", "Digite o número da sala:", 0, 0, 1000, 1, &ok);
    if (!ok) return;

    sala *sala = predio.buscar_sala_por_numero(numero);
    if (sala) {
        QString nome = QInputDialog::getText(this, "Nome da Empresa", "Digite o nome da empresa:", QLineEdit::Normal, "", &ok);
        if (!ok || nome.isEmpty()) return;

        int idade = QInputDialog::getInt(this, "Idade da Empresa", "Digite a idade da empresa (em anos):", 0, 0, 100, 1, &ok);
        if (!ok) return;

        empresa nova_empresa(nome.toStdString(), idade);
        *sala + nova_empresa;
    } 
    else {
        QMessageBox::warning(this, "Erro", "Sala não encontrada.");
    }
}

/**
 * @brief Slot que exibe um diálogo para remover uma empresa de uma sala.
 */
void main_window::remover_empresa() {
    bool ok;
    int numero = QInputDialog::getInt(this, "Remover Empresa", "Digite o número da sala:", 0, 0, 1000, 1, &ok);
    if (!ok) return;

    sala *sala = predio.buscar_sala_por_numero(numero);
    if (sala) {
        QString nome = QInputDialog::getText(this, "Nome da Empresa", "Digite o nome da empresa:", QLineEdit::Normal, "", &ok);
        if (!ok || nome.isEmpty()) return;

        auto empresas = sala->get_empresas();
        auto it = std::find_if(empresas.begin(), empresas.end(),
            [&nome](const empresa &e) { return e.get_nome() == nome.toStdString(); });

        if (it != empresas.end()) {
            *sala - *it;
            QMessageBox::information(this, "Sucesso", "Empresa removida com sucesso.");
        } 
        else {
            QMessageBox::warning(this, "Erro", "Empresa não encontrada na sala.");
        }
    } 
    else {
        QMessageBox::warning(this, "Erro", "Sala não encontrada.");
    }
}

/**
 * @brief Slot que exibe todas as salas e empresas em uma mensagem.
 */
void main_window::listar_salas() {
    QString resultado;

    for (const auto &sala : predio.get_salas()) {
        resultado += QString::fromStdString(sala->toString()) + "\n";
    }

    QMessageBox::information(this, "Lista de Salas e Empresas", resultado);
}