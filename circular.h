#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        bool empty() {
          Node<T>* tmp = this->head;

          if (tmp == NULL) {
            return true;
          }

          else {
            return false;
          }
        }

        T front() {
          Node<T>* tmp = this->head;

          return tmp->data;
        }

        T back() {
          Node<T>* tmp = this->head;

          while (tmp->next != this->head) {
            tmp = tmp->next;
          }

          return tmp->data;
        }

        void push_front(T value) {
          Node<T>* tmp = this->head;
          Node<T>* node = new Node<T>;

          node->data = value;
          node->next = this->head;
          node->prev = this->tail;

          if (tmp != NULL) {
            while (tmp->next != this->head) {
              tmp = tmp->next;
            }
            tmp->next = node;
          }

          else {
            node->next = node;
          }

          this->head = node;
        }

        void push_back(T value) {
          if (empty()) {
            push_front(value);
          }

          else {
            Node<T>* node = new Node<T>;

            node->data = value;
            node->next = this->head;
            node->prev = this->tail;

            Node<T>* tmp = this->head;

            while (tmp->next != this->head) {
              tmp = tmp->next;
            }

            tmp->next = node;
            node->prev = tmp;
            this->tail = node;
          }
        }

        void pop_front() {
          Node<T>* tmp = this->head;
          Node<T>* node = this->head;
          while(tmp->next != this->head) {
            tmp = tmp->next;
          }

          this->head = node->next;
          tmp->next = this->head;
          free(node);
        }

        void pop_back() {
          Node<T>* tmp = this->head;
          Node<T>* aux;

          while (tmp->next->next != this->head) {
            tmp = tmp->next;
          }

          aux = tmp->next;
          tmp->next = this->head;
          free(tmp);
        }

        T operator[](int index) {
          int i = 0;
          Node<T>* node = this->head;

          for (node; node != NULL; node = node->next) {
            if (i == index) {
              return node->data;
            }

            i++;
          }
        }

        int size() {
          int count = 0;
          Node<T>* tmp = this->head;

          if (tmp == NULL) {
            return count;
          }
          count ++;

          while (tmp->next != this->head) {
            count ++;
            tmp = tmp->next;
          }

          return count;
        }

        void clear() {
          Node<T>* tmp = this->head;
          Node<T>* aux;

          do {
            aux = tmp;
            tmp = tmp->next;
            free(aux);
          } while (tmp != this->head);

          this->head = NULL;
        }

        void sort() {
          int count = size();
          int min;
          Node<T>* tmp = this->head;

          for (int i = 0; i < count; i++) {
            while (tmp->next !=this->head) {
              if (tmp->data > tmp->next->data) {
                min = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = min;
                tmp = tmp->next;
              }

              else {
                tmp = tmp->next;
              }
            }

            tmp = this->head;
          }

        }

        void reverse() {
          Node<T>* tmp = this->head;
          Node<T>* bef = NULL;
          Node<T>* next;

          do {
            next = tmp->next;
            tmp->next = bef;
            bef = tmp;
            tmp = next;
          } while (tmp != this->head);

          this->head->next = bef;
          this->head = bef;
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
          return BidirectionalIterator<T>(this->head->next);
        }

	       BidirectionalIterator<T> end() {
           return BidirectionalIterator<T>(this->tail);
        }

        void merge(CircularLinkedList<T> list) {
        //   CircularLinkedList<T>* aux_list = new CircularLinkedList<T>;
        //   Node<T>* tmp_list = this->head;
        //   Node<T>* tmp_list1 = list.head;
        //
        //   while (tmp_list !=  && tmp_list1 != NULL) {
        //     if (tmp_list1->data > tmp_list->data) {
        //       aux_list->push_back(tmp_list->data);
        //       tmp_list = tmp_list->next;
        //     }
        //
        //     else {
        //       aux_list->push_back(tmp_list1->data);
        //       tmp_list1 = tmp_list1->next;
        //     }
        //   }
        //
        // while (tmp_list != NULL) {
        //   aux_list->push_back(tmp_list->data);
        //   tmp_list = tmp_list->next;
        // }
        //
        // while (tmp_list1 != NULL) {
        //   aux_list->push_back(tmp_list1->data);
        //   tmp_list1 = tmp_list1->next;
        // }
        // this->head = aux_list->head;
        }
};

#endif
