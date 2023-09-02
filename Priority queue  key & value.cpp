

///Max Heap

#include<bits/stdc++.h>
using namespace std;

class nodee{
public:
    int key;
    int val;
};

class Heap{
private:
    nodee node[101];
    int size;

public:
    Heap(){
        size = 0;
    }

private:
    void bottomTopAdjust(int i){
        while(i!=1)
        {
            if( node[i].key > node[i/2].key )
                swap(node[i],node[i/2]);
            else
                break;
            i=i/2;
        }

    }

    void topBottomAdjust(int i){    /// HEAPIFY!
        while(i<=size/2)
        {
            int largest= i;
            int l=2*i;
            int r=2*i+1;

            if(node[largest].key < node[l].key && l<=size ) largest=l;
            if(node[largest].key < node[r].key && r<=size ) largest=r;

            if(largest!=i)
            {
                swap(node[largest],node[i]);
            }

            i++;
        }

    }

public:
    bool insert(int k,int v){
        if(size==101) return false;
        else
        {
            size++;
            node[size].key=k;
            node[size].val=v;

            bottomTopAdjust(size);

            return true;
        }
    }
    bool increaseKey(int x, int k)
    {
        if(node[x].key >= k) return false;  //decrese holee heapify use hotoo
        else
        {
            node[x].key=k;
            bottomTopAdjust(x);
            return true;
        }
    }
    int showMax(){
        return node[1].val;
    }

    int showSize(){
    }

    int extractMax(){
        int m= node[1].val;
        swap(node[1],node[size]);
        size--;

        for(int i=size/2;i>0;i--) topBottomAdjust(i);

        return m;

    }

    void bfs(){
        if(size==0) return;
        int level = 2;
        queue<int>q;
        q.push(1);

        while(!q.empty()){
            int parent = q.front();
            q.pop();
            if(parent==level){
                cout<<endl;
                level = level * 2;
            }
            cout<<"("<<node[parent].key<<","<<node[parent].val<<") ";
            if(2*parent <= size) q.push(2*parent);
            if(2*parent + 1 <= size) q.push(2*parent + 1);
        }
    }
};

int main(){

    Heap heap;

    while(1){
        cout<<"1. Insert    2. Increase Key    3. Show Max    4. Extract Max  5. Level Order Traversal 6. End"<<endl<<endl;
        int choice;
        cin>>choice;

        if(choice==1){
            cout<<"Insert Key: ";
            int y,x;
            cin>>x;
            cout<<"Insert Value: ";
            cin>>y;
            bool b = heap.insert(x,y);

            if(b)   cout<<y<<" is inserted in the heap"<<endl;
        }
        else if(choice==2){
            cout<<"Which node you want to increase?"<<endl;
            int nodeNo;
            cin>>nodeNo;
            cout<<"What will be the new key?"<<endl;
            int value;
            cin>>value;
            bool b=heap.increaseKey(nodeNo,value);
            if(b) cout<<"Node value increased successfully!"<<endl;
            else cout<<"Unsuccessful Operation :("<<endl;
        }
        else if(choice==3){
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the heap"<<endl;
        }

        else if(choice==3){
            if(heap.showSize()!=0)  cout<<"Max Element: "<<heap.showMax();
            else    cout<<"No element in the queue"<<endl;
        }

        else if(choice==4){
            if(heap.showSize()!=0)  cout<<"Max element extracted: "<<heap.extractMax();
            else    cout<<"No element in the queue"<<endl;
        }

        else if(choice==5){
           cout<<"Level Wise Traversal of the Queue:"<<endl;
           heap.bfs();
           cout<<endl;
        }
        else if(choice==6)
            break;
        else{
            cout<<"Invalid Choice"<<endl;
        }
        cout<<endl;
    }
}

/*
1 2 5
1 9 4
1 8 1
1 16 9
1 3 14
1 7 4
1 10 6
1 1 74
1 4 11
1 14 54
*/



