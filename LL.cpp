#include <iostream>
using namespace std;
template <typename datatype>
class node{
    public:
        datatype element;
        node* pointer=NULL;
    node(){
     //   cout<<"node is created"<<endl;
    }
    node(datatype var){
        element=var;
        pointer =NULL;
       // cout<<"element is:"<<var<<endl;
    }
};
template <typename datatype>
class linkedList{
    private:
    node<datatype>* root=NULL;
    node<datatype>* temp=root;
    public:
    void insert(datatype element);
    void deleteElement(datatype element);
    bool find(datatype element);
    void display();
    void deleteEnd();
    void deletefront();
};
template<typename datatype> void linkedList<datatype>::deleteEnd(){
	if(root ==NULL){
		cout<<"List is empty"<<endl;
	}
	else{
		if(root->pointer ==NULL)
		{
			root=NULL;
		}
		else{
			node<datatype>* temp1;
			temp=root;
			while(temp->pointer != NULL){
				temp1=temp;
				temp=temp->pointer;
			}
			temp1->pointer = NULL;
			free(temp);
		}
	}
}
template<typename datatype> void linkedList<datatype>::deletefront(){
	if(root==NULL)
	{
		cout<<"List is empty\n";
	}
	else{
		if(root->pointer ==NULL){
			root=NULL;
		}
		else{
		root=root->pointer;
		}
	}

}
template<typename datatype> void linkedList<datatype>::deleteElement(datatype element){
    if(root==NULL){
        cout<<"List is empty"<<endl;
    }
    if(find(element)){
        if(root->pointer==NULL){
        root=NULL;
        }
        else{
        temp=root;
        node<datatype>* temp1;
        while(temp->element != element){
            temp1=temp;
            temp=temp->pointer;
        }
        temp1->pointer = temp->pointer;
        free(temp);
        //cout<<element<<" is deleted from the list"<<endl;
    }
    }
    else{
        cout<<"element is not present in the list"<<endl;
    }
}
template<typename datatype> bool linkedList<datatype>::find(datatype element){
    if(root==NULL){
        cout<<"empty list"<<endl;
        return 0;
    }
    else{
        temp=root;
        while(temp!=NULL){
            if(temp->element == element){
                return 1;
                
            }temp=temp->pointer;
        }
    }
    return 0;
}
template<typename datatype>void linkedList<datatype>::display(){
    if(root==NULL){
        cout<<"empty list"<<endl;
    }
    else{
        temp=root;
        while(temp != NULL){
            cout<<temp->element<<endl;
            temp=temp->pointer;
        }
    }
}

template<typename datatype> void linkedList<datatype>::insert(datatype element){
    node<datatype>* newNode=new node<datatype>(element);
    if(root==NULL){
        root=newNode;
        //cout<<"root updated"<<endl;
    }
    else{
        temp=root;
        while(temp->pointer != NULL){
            temp=temp->pointer;
        }
        temp->pointer =newNode;
        //cout<<"new node created"<<endl;
    }
}
/*int main()
{
linkedList<int> test1;
linkedList<char> test2;
test1.insert(1);
test1.insert(2);
test1.insert(3);
test1.display();
test1.deleteElement(2);
test1.display();
test2.insert('a');
test2.insert('b');
test2.insert('c');
test2.insert('d');
test2.display();
test2.deleteElement('b');
test2.deleteElement('b');
test2.display();
test1.display();
cout<<"deleting at end\n";
test1.deleteEnd();
test1.display();
test1.insert(2);
test1.insert(3);
test1.display();
cout<<"delete at front\n";
test1.deletefront();
test1.deletefront();
test1.deletefront();
test1.deletefront();
test1.display();
    return 0;
}
*/
