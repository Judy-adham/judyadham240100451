# include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left =NULL;
        right = NULL;
    }
};

class BST{
    public:
    Node* root;
    BST() {
        root = NULL;
    }
    Node*insert(Node*r, int item){
        if(r==NULL){
            Node* newnode = new Node(item);
            r= newnode;
        }
        else if(item<=r->data){
            r->left= insert(r->left,item);
        }
        else{
            r->right= insert(r->right,item);
        }
        return r;
    }
    void insert (int item){
        root= insert(root,item);
    }
    void preorder(Node* r){
        if(r==NULL){
            return;
        }
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
    void inorder(Node* r)
    {
        if(r==NULL){
            return;
        }
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }

    Node* search(Node* r, int key){
        if(r==NULL )
        return NULL;
        else if(r->data==key){
            return r;
        }
        else if(key<r->data){
            return search(r->left,key);
        }
        else{
            return search(r->right,key);
        }
    }

    bool search(int key)
    {
        Node* result= search(root,key);
        if(result==NULL){
            return false;
        }
        else{
            return true;
        }
    }

    Node*FindMin(Node*r){
       if (r==NULL){
        return NULL;
       }
       else if(r->left==NULL){
        return r;
       }
       else{
        return FindMin(r->left);
       }
    }

    Node* FindMax(Node*r){
        if(r==NULL){
            return NULL;
        }
        else if(r->right==NULL){
            return r;
        }
        else{
            return FindMax(r->right);
        }
    }


    Node* Delete(Node* r, int key){
        if(r==NULL){
            return NULL;
        }
        else if(key<r->data){
            r->left= Delete(r->left,key);
        }
        else if(key>r->data){
            r->right= Delete(r->right,key);
        }
        else{
            if(r->left==NULL && r->right!=NULL){
                delete r;
                r=NULL;
            }
            else if(r->left==NULL){
                Node* max= r;
                r=r->right;
                delete max  ;
            }
            else if(r->right==NULL){
                Node* max= r;
                r=r->left;
                delete max;
            }
            else{
                Node* max= FindMax(r->right);
                r->data= max->data;
                r->right= Delete(r->right,max->data);
            }
        }
        return r;
    }
};

int main(){
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout<< "display the tree content\n: ";
    tree.inorder(tree.root);
    cout<<endl;

    cout<<"Preorder traversal: ";
    tree.preorder(tree.root);
    cout<<endl;

    int key = 40;
    if(tree.search(key)){
        cout<<key<<" found in the tree."<<endl;
    }
    else{
        cout<<key<<" not found in the tree."<<endl;
    }

    cout<<"Deleting 20\n";
    tree.root= tree.Delete(tree.root,20);
    cout<<"Inorder traversal after deletion: ";
    tree.inorder(tree.root);
    cout<<endl;

    cout<<"Minimum value in the tree: "<<tree.FindMin(tree.root)->data<<endl;
    cout<<"Maximum value in the tree: "<<tree.FindMax(tree.root)->data<<endl;

    return 0;
}


