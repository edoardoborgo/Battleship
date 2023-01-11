#include <vector>
#include <iostream>

using namespace std;

int main(){
        // Initializing the vector of vectors
        vector<vector<int> > vec;

        // Elements to insert in column
        int num = 10;

        // Inserting elements into vector
        for (int i = 0; i < ROW; i++) {
            // Vector to store column elements
            vector<int> v1;

            for (int j = 0; j < COL; j++) {
                v1.push_back(num);
                num += 5;
            }

            // Pushing back above 1D vector
            // to create the 2D vector
            vec.push_back(v1);
        }

        // Displaying the 2D vector
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].size(); j++)
                cout << vec[i][j] << " ";
            cout << endl;
        }
        return 0;
    }
    /*
    Produzione:
    10 15 20 25 30
    35 40 45 50 55
    60 65 70 75 80
    85 90 95 100 105
    */
}
