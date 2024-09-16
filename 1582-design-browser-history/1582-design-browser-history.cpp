class Node{
public:
    string val;
    Node* next;
    Node* prev;
    
    Node(string val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
       
         curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps--&&curr->prev)
        {
            curr=curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps--&&curr->next)
        {
            curr=curr->next;
        }return curr->val;
    }
};
