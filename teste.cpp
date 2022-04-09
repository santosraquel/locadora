
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 10;

string EmpName[maxrow] = {};
string EmpID[maxrow] = {};

void createEmployee()
{
    char name[50];
    char empno[5];

    cin.ignore();

    cout << "ID do Funcionário: ";
    cin.getline(empno, 5);
    cout << "Nome do Funcionário: ";
    cin.getline(name, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            EmpID[x] = empno;
            EmpName[x] = name;
        }
    }
}

void listEmployee()
{
    system("CLS");
    cout << "LISTA DE FUNCIONÁRIOS" << endl;
    cout << "================================" << endl;

    int cont = 0;
    cout << "No |   ID   |         NOME      " << endl
         << "------------------------------------\n";

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] != "\0")
        {
            cont++;
            cout << "   " << cont << "     " << EmpID[x] << "             " << EmpName[x] << endl;
        }
    }
    if (cont == 0)
    {
        cout << "Funcionário não encontrado!" << endl;
    }

    cout << "===========================================" << endl;
}

void searchEmployee(string search)
{
    system("CLS");
    cout << "Pesquisa funcionário" << endl;
    cout << "=========================" << endl;

    int cont = 0;
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            cont++;
            cout << "   " << cont << "    " << EmpID[x] << "        " << EmpName[x] << endl;
            break;
        }
    }
    if (cont == 0)
    {
        cout << "Funcionário não encontrado!" << endl;
    }

    cout << "===========================================" << endl;
}

void updateEmployee(string search)
{
    char name[50];
    char empno[5];

    int cont = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            cont++;

            cout << "Nome do Funcionário: " << endl;
            cin.getline(name, 50);

            EmpName[x] = name;

            cout << "Funcionário atualizado com sucesso!" << endl;
            break;
        }
    }
}

int main()
{
    std::cout << "MENU\n";

    int option;
    string EmpID;
    system("CLS");

    do
    {
        cout << "1-Cadastrar Funcionário" << endl;
        cout << "2-Editar Funcionário" << endl;
        cout << "3-Listar Funcionário" << endl;
        cout << "4-Excluir Funcionário" << endl;
        cout << "5-Pesquisar Funcionário" << endl;
        cout << "6-Sair e salvar arquivo de texto" << endl;
        cout << "==================================" << endl;

        cout << "Opção:";
        cin >> option;

        switch (option)
        {
        case 1:
            createEmployee();
            system("CLS");
            break;
        case 2:
            cin.ignore();
            cout << "ID do funcionário";
            getline(cin, EmpID);
            updateEmployee();
            system("CLS");
            break;
        case 3:
            listEmployee();
            system("CLS");
            break;
        case 5:
            cin.ignore();
            cout << "ID do funcionario" << endl;
            getline(cin, EmpID);
            searchEmployee(EmpID);
            system("CLS");
            break;
        }
    } while (option != 6);

    return 0;
}