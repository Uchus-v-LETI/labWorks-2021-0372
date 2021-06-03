#include <iostream>
using namespace std;

using T = int;

class List {

    public:

    List();
	List(unsigned size);
	List(unsigned size, const T& val);
    List(const List& list);
    ~List();

    void push_back(const T& val);
    void pop_back();
    void pop_front();
    void resize(unsigned new_size);
    bool insert(unsigned pos, const T& val);
    int find(const T &val);
    bool contains(const T& val);
    unsigned get_size(){return size;}
    T& operator[](unsigned index);
    void print(List& list);

    private:

    class Node{

        public:

        Node* next;//указатель на следующий элемент  
        T val;//данные

        Node( T val = T(), Node* next = nullptr ){//конструктор ноды
            this -> val = val;
            this -> next = next;
        }
    };

    Node* head;//начало списка
    unsigned size;//размер списка
};

List::List(){//дефолтный конструктор
    head = nullptr;
    size = 0;
}

List::List(unsigned size){//создаёт список размером size и заполняет его дефолтными значениями, т.е. T()
	resize(size);
    for (unsigned i = 0; i < size - 1; i++){
        push_back(T());
	}
}

List::List (unsigned size , const T& val){//создаёт список размером size и заполняет его значением val
    resize(size);
    for (int i = 0; i < size - 1; i++){
        push_back(val);
    }
}

List::~List(){//деструктор
    resize(0);
}

List::List(const List& lst) {//конструктор копирования
	Node* temp = lst.head;
	size = 0;
	for (int i = 0; i < lst.size; i++) {
		insert(i, temp->val);
		temp = temp->next;
	}
}

void List::push_back(const T& val){//добавление элемента со значением val в конец списка
    if (head == nullptr){//если нод еще нет
        head = new Node(val);//создаем ноду, которая будет первой в списке
    }
    else{
        Node* temp = this->head;//начинаем идти по списку с начальной ноды
        while ( temp->next != nullptr ){//пока не дойдем до ноды со значением nullptr
            temp = temp->next;//записываем в temp указатель на следующую ноду
        }
        temp->next = new Node(val);//создаем новую ноду и записываем ее адрес в next предпоследней ноды
    }
    size++;
}

void List::pop_back(){//добавление элемента со значением val в конец списка
    if (head == nullptr){//если нод нет
        cout<<"List is empty"<<endl;
    }

    else if(head->next == nullptr){//если нода 1
        Node* temp = head;
        delete temp;
        head = nullptr;
        size--;
    }

    else{//если ноды 2 и более
        Node* one = head;
        Node* two = head->next;
        while(two->next != nullptr){
            two = two->next;
            one = one->next;
        }
        one->next = nullptr;
        delete two;
        size--;
    }
}

bool List::insert(unsigned pos, const T& val){//вставляет val в позицию pos; возвращает true | false в зависимости от успеха операции
    if (pos == 0){
        head = new Node(val, head);
        size++;
        return true;
    }
    else if (pos <= get_size())
    {
        Node* temp = this->head;
        for (int i = 0; i<pos - 1; i++){
            temp = temp->next;
        }
        temp->next = new Node(val, temp->next);
        size++;

        return true;
    }
    else {
        return false;
    }

}

void List::resize(unsigned new_size){//изменение размера списка
    if(new_size>size){
        for(unsigned i = size; i<new_size; i++){
            push_back(0);
        }
    }
    else if(new_size<size){
        for(unsigned i = new_size; i<size; i++){
            pop_back();
        }
    }
    else{
        cout<<"The new value is the same as the old one"<<endl;
    }  
}

int List::find(const T &val){//возвращает индекс первого вхождения val в список или -1 в случае его отсутствия
    Node* temp = head;
    int pos = 0;
    while (temp != nullptr){
        if (temp->val == val)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

bool List::contains(const T& val){ //возвращает true если val присуствует в списоке и false в противном случае
    Node* temp = head;
    while (temp != nullptr){
        if (temp->val == val)
            return true;
        temp = temp->next;
    }
    return false;
}

void print(List& lst){
    for (int i = 0; i < lst.get_size(); i++) {
        cout << lst[i] << " ";
    }
}

T& List::operator[](unsigned index){//обращение к элементу с индексом index
    if ((index < 0) || (index >= size)){
		cout << "Out of range."<<endl;
	} 
    else{
		Node* temp = head;
		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->val;
	}
}

int main()
{
    cout<<"1st constructor"<<endl;
    List List_1;
    cout<<"2nd constructor"<<endl;
    List List_2(6);
    print(List_2);
    /*cout<<"3rd constructor"<<endl;
    List List_4(5, 6);*/
    
    cout<<"Size of lists:"<<endl;
    cout<<"Size_1: " <<List_1.get_size()<<endl;
    print(List_1);
    cout<<"Size_2: " <<List_2.get_size()<<endl;
    print(List_2);
    /*cout<<"Size_3: " <<List_3.get_size()<<endl;
    print(List_3);*/

    cout<<endl;
    cout<<"Resize(10) List_1: "<<endl;
    List_1.resize(10);
    print(List_1);
    cout<<endl;

    cout<<"Resize(15) List_2: "<<endl;
    List_2.resize(15);
    print(List_2);
    cout<<endl;

    cout<<"Push_back(9) List_1: "<<endl;
    List_1.push_back(9);

    cout<<"Insert(4, 2) List_1: ";
    List_1.insert(4, 2);
    print(List_1);
    cout<<endl;

    cout << "Find(9) List_1: "<<endl;
    cout << List_1.find(9) <<endl;

    cout<<"Contains(3) List_1: "<<endl;
    cout<< List_1.contains(3) <<endl;

    cout << "Operator [7] List_1: ";
    cout << List_1[7] <<endl;

    cout << "Copy List_1 to List_3: "<<endl;
    List List_3(List_1);
    print(List_3);
    
    /*cout << " operator = ( list_2 = list_1)\n";
    list_2 = list_1;*/

    system("pause");
    return 0;
}