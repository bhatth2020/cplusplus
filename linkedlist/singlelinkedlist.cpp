#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class LinkedList {
private:

     typedef struct _node {
	 int value;
	 struct _node *next;
	} node, *pnode;
    pnode head, tail;
public:
    LinkedList() {
        pnode tmp = new node;
        tmp->value = -1;
        head = tail = tmp;
    }

    int get(int index) {
        int curidx = 0;
        pnode tmp = head->next;
        while(curidx != index && tmp != nullptr)
        {
            tmp = tmp->next;
            ++curidx;
        }
        if(tmp)
        {
            return tmp->value;
        }
        else
        {
            return -1;
        }
    }

    void insertHead(int val) {
        pnode tmp = new node;
        if(tmp)
        {
            tmp->value = val;
            tmp->next = head->next;
            head->next = tmp;
            if(tmp->next == nullptr)
            {
                tail = head->next;
            }
        }

    }
 
    void traverseList()
    {
        pnode tmp = head->next;
        while(tmp)
        {
            cerr << tmp->value << endl;
            tmp = tmp->next;
        }
    }

    void insertTail(int val) {
        pnode tmp = new node;
        if(tmp)
        {
            tmp->value = val;
            tmp->next = nullptr;
        }
        tail->next = tmp;
        tail = tail->next;
    }


    bool remove(int index) {
        int i = 0;
        pnode curr = head;
        while (i < index && curr != nullptr) {
            i++;
            curr = curr->next;
        }

        // Remove the node ahead of curr
        if (curr != nullptr && curr->next != nullptr) {
            if (curr->next == tail) {
                tail = curr;
            }
            pnode toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> result;
        pnode tmp = head->next;
        while(tmp)
        {
            result.push_back(tmp->value);
            tmp = tmp->next;
        }        
        return result;
    }
};

int main()
{
    LinkedList llist;

    // test case - 1
    cerr << "test case 1" << endl;
    cerr << llist.get(0) << endl;
    // test case - 2
    cerr << "test case 2" << endl;
    llist.insertHead(2);
    cerr << llist.get(0) << endl;
    cerr << llist.remove(0) << endl;
    cerr << llist.get(0) << endl;
    cerr << "test case 3" << endl;
    // test case - 3
    llist.insertTail(1);
    llist.insertTail(2);
    vector<int> res = llist.getValues();
    cerr << "getting values in the list" << endl;
    for(int i = 0; i < res.size(); i++)
    {
        cerr << res[i] << endl;
    }
    cerr << llist.get(0) << endl;
    cerr << llist.get(1) << endl;
    cerr << llist.remove(1) << endl;
    llist.insertTail(2);
    cerr << llist.get(0) << endl;
    cerr << llist.get(1) << endl;
    cerr << "test case 4" << endl;
    // test case - 4
    llist.traverseList();
    // llist.insertHead(3);
    llist.traverseList();
    // llist.insertHead(4);
    llist.traverseList();
    // res = llist.getValues();
    for(int i = 0; i < res.size(); i++)
    {
        cerr << res[i] << endl;
    }

	return 0;
}
