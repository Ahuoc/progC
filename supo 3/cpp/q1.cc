#include <iostream>
using namespace std;

class LinkList {
    public:
        LinkList(int* array, int lengthToGet) {
            this->value = new int(array[0]);
            if (lengthToGet > 1) {
                this->next = new LinkList(array+1, lengthToGet-1);
            }
            else {
                this->next = NULL;
            }
        }
        LinkList(int value, LinkList *next) {
            this->value = new int(value);
            this->next = next;
        }
        LinkList() {
            value = NULL;
            next = NULL;
        }
        LinkList(const LinkList &other) {
            if (other.value != NULL) {
                this->value = new int(*other.value);
            } else {
                this->value = NULL;
            }
            if (other.next != NULL) {
                this->next = new LinkList(*other.next);
            } else {
                this->next = NULL;
            }
        }
        LinkList& operator=(const LinkList &other) {
            if (this != &other) {
                if (next != NULL) {
                    delete next;
                }
                if (value != NULL) {
                    delete value;
                }
                if (other.value != NULL) {
                    this->value = new int(*other.value);
                } else {
                    this->value = NULL;
                }
                if (other.next != NULL) {
                    this->next = new LinkList(*other.next);
                } else {
                    this->next = NULL;
                }
            }
            return *this;
        }
        ~LinkList() {
            if (next != NULL) {
                delete next;
            }
            if (value != NULL) {
                delete value;
            }
        }
        int pop() {
            // As long as the next value exists, replace the current node's stuff with the next node's stuff, then clean up the next node
            if (value == NULL) {
                return -1;
            }
            int toReturn = *value;
            if (next == NULL) {
                delete value;
                value = NULL;
                return toReturn;
            }
            LinkList *toFree = next;
            delete value;
            value = toFree->value;
            next = toFree->next;
            // Stop the deleting of the next node from deleting all future nodes
            toFree->value = NULL;
            toFree->next = NULL;
            delete toFree;
            return toReturn;
        }
    private:
        int *value;
        LinkList *next;
};


int main() {
    int test[] = {1,2,3,4,5};
    LinkList l1(test+1,4), l2(test,5);
    LinkList l3=l2, l4;
    l4=l1;
    printf("%d %d %d\n",l1.pop(),l3.pop(),l4.pop());
    return 0;
}
