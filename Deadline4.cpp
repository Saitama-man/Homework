#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
    private:
        string desc;
        bool status;

    public:

        Task() : desc(""), status(false) {}

        void complete() {
            status = 1;
        }

        bool is_completed() const {
            return status;
        }
        void describe() const {
            cout<<desc<<endl;
        }
        void input() {
            getline(cin, desc);
        }
};

class TodoList {
    private:

    vector<Task> list;

    public:

    void add_task(Task &task) {
        list.push_back(task);
    }

    void show_list() const {
        if (list.empty()) {
            cout << "Список задач пуст.\n";
            return;
        }

        for (size_t i = 0; i < list.size(); ++i) {
            cout << "Задание №" << i + 1 << ": ";
            list[i].describe();
            cout << "\nСтатус: " << boolalpha << list[i].is_completed() << "\n\n";
        }
    }

    void complete_task(int index) {
        if (index >= 0 && index < (int)list.size()) {
            list[index].complete();
        } else {
            cout << "Неверный номер задачи.\n";
        }
    }
};


class Notification {
    public: 
        virtual void send() {
            cout<<"Sending smth"<<endl;
        }
        virtual ~Notification() {}
};

class SMSNotification: public Notification { 
    public:
        void send() override {
        cout<<"SMS"<<endl;
    }

};

class EmailNotification: public Notification {
    public:
        void send() override {
            cout<<"Email"<<endl;
        }

};


void send_message (Notification *nott) {
    nott->send();
}
int main ( ) {
    SMSNotification smsnot;
    EmailNotification eml;
    Notification *nott = new SMSNotification;



    Notification *arr[] = {&smsnot, &eml, &nott, nullptr};

    Notification **p = arr;
    
    // int i = 0;
    // while(i < sizeof(arr)/sizeof(p)) {
    //     send_message(*p);
    //     p++;
    //     i++;
    // }

    // for(Notification * n : arr) {
    //     send_message(n);
    // }

    while( *p != nullptr) {
        send_message(*p);
        p++;
    }

    TodoList todo;

    cout<<"введите кол-во заданий: "<<endl;
    int n;
    cin>>n;
    cin.ignore();
    // Task bibaarr[n];

    for(int i = 0; i < n; ++i) {
        Task temp;
        cout<<"добавьте задание: "<<endl;
        temp.input();
        todo.add_task(temp);
    }   
    cout<<endl;

    cout << "\nСписок задач:\n";
    todo.show_list();
    
    cout << "Введите номер выполненной задачи: ";
    int num;
    cin >> num;

    todo.complete_task(num - 1);

    // for(int i = 0; i < n; ++i) {
    //     cout<<"Задание №"<<i+1<<": ";
    //     bibaarr[i].describe();
    //     cout<<"статус: ";
    //     cout<<boolalpha<<bibaarr[i].is_completed()<<endl<<endl;
    // }  
    cout << "\nОбновленный список задач:\n";

    todo.show_list();


    return 0;
}