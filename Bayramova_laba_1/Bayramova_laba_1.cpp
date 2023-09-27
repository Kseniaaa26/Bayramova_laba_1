#include <iostream>
#include <string>

using namespace std;

inline int CorrectNumber(int min, int max) {
    int x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << "до " << max << endl;
    }
    return x;
}

inline double CorrectNumber(double min, double max) {
    double x;
    while ((cin >> x).fail()
        || cin.peek() != '\n'
        || x < min || x > max)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << min << "до " << max << endl;
    }
    return x;
}

struct Pipe {
    string name_p;
    double length;
    int diameter;
    bool in_repairing;
};

struct CS {
    string name_CS;
    int number_of_workshops;
    int workshops_in_operation;
    int effectiveness;
};

void inputPipeInfo(Pipe& pipe) {

    cout << "Введите название трубы: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, pipe.name_p);

    cout << "Введите длину трубы: ";
    pipe.length = CorrectNumber(0.0, DBL_MAX);

    cout << "Введите диаметр трубы: ";
    pipe.diameter = CorrectNumber(0, INT_MAX);
    
    cout << "Введите состояние трубы(0 - в ремонте, 1 - в работе):" << pipe.in_repairing << endl;
    if (CorrectNumber(0, 1)) {
        pipe.in_repairing = true;
    }
    else {
        pipe.in_repairing = false;
    }
}

void inputCSInfo(CS& cs) {

    cout << "Введите название КС: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, cs.name_CS);

    cout << "Введите количество цехов КС: ";
    cs.number_of_workshops = CorrectNumber(0, 50);

    cout << "Введите количество цехов в работе: ";
    cs.workshops_in_operation = CorrectNumber(0, cs.number_of_workshops);

    cout << "Укажите эффективность(1,2,3)" << endl;
    cs.effectiveness = CorrectNumber(1, 3);
}

void printPipeInfo(const Pipe& pipe) {
    cout << "Труба: " << pipe.name_p << std::endl;
    cout << "Длина: " << pipe.length << std::endl;
    cout << "Диаметр: " << pipe.diameter << std::endl;
    cout << "Состояние(0 - в ремонте, 1 - в работе): " << (pipe.in_repairing ? "true" : "false") << std::endl;
    cout << endl;
}

void printCSInfo(const CS& cs) {
    cout << "КС: " << cs.name_CS << std::endl;
    cout << "Количество цехов: " << cs.number_of_workshops << std::endl;
    cout << "Количество цехов в работе: " << cs.workshops_in_operation << std::endl;
    cout << "Эффективность: " << cs.effectiveness << std::endl;
    cout << endl;
}

void editInRepairStatus(Pipe& pipe) {
    cout << "Изменить признак в ремонте(0 - оставить, 1 - изменить): " << endl;
    if (CorrectNumber(0, 1)) {
        pipe.in_repairing = !pipe.in_repairing;
    }
    cout << endl;
}

void editCS(CS& cs) {
    cout << "Изменить количество цехов в работе: " << endl;
    cs.workshops_in_operation = CorrectNumber(0, cs.number_of_workshops);
}

void View(Pipe& pipe, CS& cs)
{

    while (1) {
        
        cout << "0. Назад\n" <<
            "1. Список труб\n" <<
            "2. Список КС" << endl;


        switch (CorrectNumber(0, 2)) {
        case 1: {
            printPipeInfo(pipe);
            break;
        }
        case 2: {
            printCSInfo(cs);
            break;
        }

        case 0: {
            return;
        }

        }
    }
}


int main() {
    setlocale(LC_ALL, "ru");

    Pipe pipe;
    CS cs;
    //int choice;

    while (true) {
        cout << "\n1. Добавить трубу\n" <<
            "2. Добавить КС\n" <<
            "3. Просмотр всех объектов\n" <<
            "4. Редактировать трубу\n" <<
            "5. Редактировать КС\n" <<
            "6. Сохранить\n" <<
            "7. Загрузить\n" <<
            "0. Выход\n" << endl;

        switch (CorrectNumber(0, 7)) {
        case 1:
            inputPipeInfo(pipe);
            break;
        case 2:
            inputCSInfo(cs);
            break;
        case 3:
            View(pipe, cs);
            break;
        case 4:
            editInRepairStatus(pipe);
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}