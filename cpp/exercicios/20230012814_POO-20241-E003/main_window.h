#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QInputDialog>
#include <QMessageBox>
#include <string>

#include "predio_comercial.h"
#include "sala_privativa.h"
#include "sala_compartilhada.h"
#include "empresa.h"

/**
 * @class main_window
 * @brief Classe responsável por exibir o menu interativo para gerenciar salas e empresas.
 */
class main_window : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Construtor da classe Menu.
     * @param parent Ponteiro para o widget pai, padrão nullptr.
     */
    explicit main_window(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Slot para adicionar uma nova sala.
     */
    void adicionar_sala();

    /**
     * @brief Slot para remover uma sala existente.
     */
    void remover_sala();

    /**
     * @brief Slot para adicionar uma empresa a uma sala.
     */
    void adicionar_empresa();

    /**
     * @brief Slot para remover uma empresa de uma sala.
     */
    void remover_empresa();

    /**
     * @brief Slot para listar todas as salas e empresas.
     */
    void listar_salas();

private:
    predio_comercial predio; // Objeto responsável por gerenciar as salas do prédio.

    QPushButton *btnAdicionarSala; // Botão para adicionar uma nova sala.
    QPushButton *btnRemoverSala;   // Botão para remover uma sala.
    QPushButton *btnAdicionarEmpresa; // Botão para adicionar uma empresa a uma sala.
    QPushButton *btnRemoverEmpresa;   // Botão para remover uma empresa de uma sala.
    QPushButton *btnListarSalas;    // Botão para listar todas as salas e empresas.
};

#endif // MAINWINDOW_H
