#include <iostream>

template <class T>
class CircularList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    CircularList() : head(nullptr) {}

    CircularList(const CircularList& other) {
        if (other.head == nullptr) {
            head = nullptr;
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
        }
        delete head;
    }

    void insert(const T& data) {
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

    void remove() {
        if (head == nullptr) return;
        Node* to_remove = head->next;
        if (to_remove == head) {
            delete to_remove;
            head = nullptr;
        }
        else {
            head->next = to_remove->next;
            delete to_remove;
        }
    }

    T& operator[](int index) {
        if (head == nullptr) throw std::out_of_range("List is empty");
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
            if (current == head) throw std::out_of_range("Index out of range");
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

    CircularList<int> list2(list1);  

    std::cout << list2[0] << std::endl;  
    std::cout << list2[1] << std::endl;  
    std::cout << list2[2] << std::endl; 

    list2.remove();

    std::cout << list2[0] << std::endl;  
    std::cout << list2[1] << std::endl;  

    return EXIT_SUCCESS;
}