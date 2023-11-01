#include <iostream>
#include <string>
#include <fstream>




using namespace std;

 int CorrectNumber(int min, int max) {
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

 double CorrectNumber(double min, double max) {
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

    cout << "Введите состояние трубы(0 - в ремонте, 1 - в работе): " << endl;
    pipe.in_repairing = CorrectNumber(0, 1);
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
    cout << "Труба: " << pipe.name_p << endl;
    cout << "Длина: " << pipe.length << endl;
    cout << "Диаметр: " << pipe.diameter << endl;
    cout << "Состояние(0 - в ремонте, 1 - в работе): " << (pipe.in_repairing ? "true" : "false") << endl;
    cout << endl;
}

void printCSInfo(const CS& cs) {
    cout << "КС: " << cs.name_CS << endl;
    cout << "Количество цехов: " << cs.number_of_workshops << endl;
    cout << "Количество цехов в работе: " << cs.workshops_in_operation << endl;
    cout << "Эффективность: " << cs.effectiveness << endl;
    cout << endl;
}



void editInRepairStatus(Pipe& pipe) {
    if (pipe.name_p.size() != 0) {

        cout << "Изменить признак в ремонте(0 - оставить, 1 - изменить): " << endl;
        if (CorrectNumber(0, 1)) {
            pipe.in_repairing = !pipe.in_repairing;
        }
    }
    else {
        cout << "Добавьте трубу";
    }
    cout << endl;
}

void editCS(CS& cs) {
    if (cs.name_CS.size() != 0) {
        cout << "Изменить количество цехов в работе: " << endl;
        cs.workshops_in_operation = CorrectNumber(0, cs.number_of_workshops);
    }
    else {
        cout << "Добавьте КС";
    }
}

void View(Pipe& pipe, CS& cs)
{

    while (1) {
        
        cout << "0. Назад\n" <<
            "1. Просмотр трубы\n" <<
            "2. Просмотр КС\n" << 
            "3. Просмотр трубы и КС\n" << endl;


        switch (CorrectNumber(0, 3)) {
        case 1: {
            if (pipe.name_p.size() != 0){
                printPipeInfo(pipe);
                break;
            }
            else {
                cout << "Нет трубы, сначала добавьте её\n" << endl;
                break;
                
            }
        }
        case 2: {
            if (cs.name_CS.size() != 0) {
                printCSInfo(cs);
                break;
            }
            else {
                cout << "Нет КС, сначала добавьте её\n" << endl;
                break;
            }
        }
        case 3: {
            if (cs.name_CS.size() != 0 && pipe.name_p.size() != 0) {
                printPipeInfo(pipe);
                printCSInfo(cs);
                break;
            }
            else {
                cout << "Нет КС и/или трубы\n" << endl;
                break;
            }
        }

        case 0: {
            return;
        }

        }
    }
}


void saveData(Pipe& pipe, CS& cs) {
    ofstream file("data.txt");
    if (pipe.name_p.size() != 0) {
        if (file.is_open()) {
            file << "Pipe" << endl;
            file << pipe.name_p << endl;
            file << pipe.length << endl;
            file << pipe.diameter << endl;
            file << pipe.in_repairing << endl;

        }
        else {
            cout << "Не удалось открыть файл" << endl;
        }
    }
    if (cs.name_CS.size() != 0) {
        if (file.is_open()) {
            file << "CS" << endl;
            file << cs.name_CS << endl;
            file << cs.number_of_workshops << endl;
            file << cs.workshops_in_operation << endl;
            file << cs.effectiveness << endl;

        }
        else {
            cout << "Не удалось открыть файл" << endl;
        }
    }
    file.close();
    if (cs.name_CS.size() == 0 && pipe.name_p.size() == 0) {
        cout << "Введите данные для сохранения" << endl;
    }
}

void loadData(Pipe& pipe, CS& cs) {
    string line;
    ifstream file("data.txt");
    if (file.is_open()) {
        getline(file, line);
        if (line == "Pipe") {
            getline(file, pipe.name_p);

            getline(file, line);
            pipe.length = stod(line);

            getline(file, line);
            pipe.diameter = stoi(line);

            getline(file, line);
            pipe.in_repairing = stoi(line);

            getline(file, line);
            if (line == "CS") {
                getline(file, cs.name_CS);

                getline(file, line);
                cs.number_of_workshops = stoi(line);

                getline(file, line);
                cs.workshops_in_operation = stoi(line);

                getline(file, line);
                cs.effectiveness = stoi(line);
            }
            cout << "Данные успешно загрузились" << endl;
        }
        else if (line == "CS") {
            getline(file, cs.name_CS);

            getline(file, line);
            cs.number_of_workshops = stoi(line);

            getline(file, line);
            cs.workshops_in_operation = stoi(line);

            getline(file, line);
            cs.effectiveness = stoi(line);
            cout << "Данные успешно загрузились" << endl;
        }
        else {
            cout << "Файл пуст" << endl;
        }
    }
    else {
        cout << "Не удалось открыть файл" << endl;
    }
    file.close();
}

int main() {
    
    setlocale(LC_ALL, "ru");

    Pipe pipe;
    CS cs;

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

        case 5:
            editCS(cs);
            break;

        case 6:
            saveData(pipe, cs);
            break;

        case 7:
            loadData(pipe, cs);
            break;

        case 0:
            return 0;

        }
    }

    return 0;
}