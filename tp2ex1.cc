#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <queue>

using namespace std;

void calcul(int c){
    float a = 0;
    int factorial = 0;
    if(c<0){
        cout<< "Erreur, fatoriel de 0";
    }
    else{
        for (int i = 1; i <= c; i++){
            factorial *= i; 
        }
        
    }
    a = ((-1)^c)/factorial;
}

class ThreadPool{
    private:
        queue <int> q;
        int k = 5;
        int current = 0;
        int n = 200;
    public:
        void add_to_queue(int i, queue <int> q){
            cout << "Pushing " << i << endl;
            q.push(i);
            //return q;
        }
        void showq(queue <int> q){
            while (!q.empty()){
                cout << q.front() << " ";
                q.pop();
            }
        }   
        void start(){
            while(!q.empty()){
                if (current < k){
                    auto t = [this](){
                        current++;
                        //calcul();
                        current--;
                    };
                }
            }
        }
        
};


int main(int ac, char** av){
    ThreadPool threadpool;
    queue <int> q;
    int n = 20;
    for (int i = 0; i < n; i++){
        threadpool.add_to_queue(i, q);
    }

    threadpool.showq(q);

            
}