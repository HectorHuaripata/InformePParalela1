#include <iostream>

int main(){
    int MAX = 4;
    double A[MAX][MAX], x[MAX], y[MAX];

    //Inicializar A, Y y X

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++){
            A[i][j] = j * MAX + i + 1;
        }          

        x[i] = i + 1;
        y[i] = 0;
    }
    
    //First pair of loops
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
                y[i] += A[i][j]*x[j];
                //std::cout << y[i] << " ";
        }
        //std::cout << std::endl;
    }
            

        /*Assign y = 0*/

    //Second pair of loops
    /*
    for (int j = 0; j < MAX; j++){
        for (int i = 0; i < MAX; i++){
                y[i] += A[i][j]*x[j];
                //std::cout << y[i] << " ";
        }
        //std::cout << std::endl;
    }  
    */
    return 0;
}