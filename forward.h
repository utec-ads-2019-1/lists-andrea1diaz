#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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

          while (tmp->next != NULL) {
            tmp = tmp->next;
          }

          return tmp->data;
        }

        void push_front(T value) {
          Node<T>* node = new Node<T>;
          node->data = value;
          node->next = this->head;
          this->head = node;
        }

        void push_back(T value) {
          if (empty()) {
            push_front(value);
          }

          else {
            Node<T>* node = new Node<T>;

            node->data = value;
            node->next = NULL;

            Node<T>* tmp = this->head;

            while (tmp->next != NULL) {
              tmp = tmp->next;
            }

            tmp->next = node;
          }
        }

        void pop_front() {
          Node<T>* tmp = this->head;
          this->head = tmp->next;
          free(tmp);
        }

        void pop_back() {
          Node<T>* tmp = this->head;
          Node<T>* aux;

          while (tmp->next != NULL) {
            aux = tmp;
            tmp = tmp->next;
          }

          aux->next = NULL;
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

          while (tmp != NULL) {
            count ++;
            tmp = tmp->next;
          }

          return count;
        }

        void clear() {
          Node<T>* tmp = this->head;

          while (tmp != NULL) {
            this->head = tmp->next;
            tmp->next = NULL;
            free(tmp);
            tmp = this->head;
          }
        }

        void sort() {
          int count = size();
          int min;
          Node<T>* tmp = this->head;

          for (int i = 0; i < count; i++) {
            while (tmp->next != NULL) {
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
          Node<T>* next = NULL;

          while (tmp != NULL) {
            next = tmp->next;
            tmp->next = bef;
            bef = tmp;
            tmp = next;
          }

          this->head = bef;
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
          return ForwardIterator<T>(this->head);
        }

	       ForwardIterator<T> end() {
          return ForwardIterator<T>(this->tail);
        }

        void merge(ForwardList<T> list) {
          ForwardList<T>* aux_list = new ForwardList<T>;
          Node<T>* tmp_list = this->head;
          Node<T>* tmp_list1 = list.head;

          while (tmp_list != NULL && tmp_list1 != NULL) {
            if (tmp_list1->data > tmp_list->data) {
              aux_list->push_back(tmp_list->data);
              tmp_list = tmp_list->next;
            }

            else {
              aux_list->push_back(tmp_list1->data);
              tmp_list1 = tmp_list1->next;
            }
          }

        while (tmp_list != NULL) {
          aux_list->push_back(tmp_list->data);
          tmp_list = tmp_list->next;
        }

        while (tmp_list1 != NULL) {
          aux_list->push_back(tmp_list1->data);
          tmp_list1 = tmp_list1->next;
        }

        this->head = aux_list->head;
        }
};

#endif
