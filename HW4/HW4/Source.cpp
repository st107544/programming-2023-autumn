#include <iostream>

template <class T>
class CircularList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    int size;
public:
    CircularList() : head(nullptr), size(0) {}

    CircularList(const CircularList& other) {
        if (other.head == nullptr) {
            head = nullptr;
            size = 0;
            return;
        }

        Node* current = other.head;
        do {
            insert(current->data);
            current = current->next;
        } while (current != other.head);
    }

    ~CircularList() {
        if (head == nullptr) return;
        Node* current = head->next;
        while (current != head) {
            Node* next = current->next;
            delete current;
            current = next;
            size--;
        }
        delete head;
    }

    void insert(const T& data) {
        size++;
        Node* new_node = new Node{ data, nullptr };
        if (head == nullptr) {
            new_node->next = new_node;
            head = new_node;
        }
        else {
            new_node->next = head->next;
            head->next = new_node;
        }
    }

    void remove(int index)
    {
        index %= size;
        if (head == nullptr)
        {
            return;
        }

        Node* current = head;

        if (current->next == head && index == 0)
        {
            head = nullptr;
            delete current;
            size--;
            return;
        }

        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        else
        {
            int count = 0;
            while (count != index - 1)
            {
                current = current->next;
                count++;
            }
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
        }
    }

    T& operator[](int index) 
    {
        index %= size;
        if (head == nullptr) throw std::out_of_range("List is empty");
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
            
        }
        return current->data;
    }
};

int main()
{
    CircularList<int> list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);

    CircularList<int> list2(list1);

    std::cout << list2[0] << std::endl;
    std::cout << list2[1] << std::endl;
    std::cout << list2[6] << std::endl;

    list2.remove(1);

    std::cout << list2[0] << std::endl;
    std::cout << list2[1] << std::endl;
    std::cout << list2[2] << std::endl;

    return EXIT_SUCCESS;
}