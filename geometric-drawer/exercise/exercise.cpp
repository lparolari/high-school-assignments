#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Figure {
   public:
    virtual void draw() = 0;
};

class HorizontalSegment : public Figure {
    // DA FARE
};

class Circle : public Figure {
    // DA FARE
};

int main() {
    Circle* c1 = new Circle(7, 7, 7);
    Circle* c2 = new Circle(0, 0, 7);
    HorizontalSegment* s1 = new HorizontalSegment(1, 1, 5);

    vector<Figure*> ff;
    ff.push_back(c1);
    ff.push_back(c2);
    ff.push_back(s1);

    for (int i = 0; i < ff.size(); i++) {
        Figure* f = ff[i];
        f->draw();
        cout << "-------------------------------------------------" << endl;
    }

    return 0;
}

/*
OUTPUT:

              *               
        * * * * * * *         
      * * * * * * * * *       
    * * * * * * * * * * *     
  * * * * * * * * * * * * *   
  * * * * * * * * * * * * *   
  * * * * * * * * * * * * *   
* * * * * * * * * * * * * * * 
  * * * * * * * * * * * * *   
  * * * * * * * * * * * * *   
  * * * * * * * * * * * * *   
    * * * * * * * * * * *     
      * * * * * * * * *       
        * * * * * * *         
              *               
------------------------
* * * * * * * * 
* * * * * * *   
* * * * * * *   
* * * * * * *   
* * * * * *     
* * * * *       
* * * *         
*               
------------------------

  * * * * * 
------------------------

*/