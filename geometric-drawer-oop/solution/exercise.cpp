#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Figure {
   public:
    virtual void draw() = 0;
};

class HorizontalSegment : public Figure {
   private:
    int x, y, l;

   public:
    HorizontalSegment(int x, int y, int l) {
        this->x = x;
        this->y = y;
        this->l = l;
    }
    void draw() {
        for (int i = 0; i < x; i++) {
            cout << endl;
            for (int j = 0; j < y; j++) {
                cout << "  ";
            }
        }
        for (int i = 0; i < l; i++) cout << "* ";
        cout << endl;
    }
};

// class Line : public Figure {
//    private:
//     int a;
//     int b;
//     int c;

//    public:
//     Line(int a, int b, int c) {
//         this->a = a;
//         this->b = b;
//         this->c = c;
//     }
//     void draw() {
//         for (int i = -5; i < 5; i++) {
//             for (int j = -5; j < 5; j++) {
//                 if (i == -(b * j + c) / a && j == -(a * i + c) / b) {
//                     cout << "* ";
//                 } else {
//                     cout << "  ";
//                 }
//             }
//             cout << endl;
//         }
//     }
// };

class Circle : public Figure {
   private:
    int x;
    int y;
    int r;

   public:
    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    void draw() {
        for (int i = -x; i < r + 1; i++) {
            for (int j = -y; j < r + 1; j++) {
                if (i * i + j * j <= r * r)
                    cout << "* ";
                else
                    cout << "  ";
            }
            cout << endl;
        }
    }
};

int main() {
    Circle* c1 = new Circle(7, 7, 7);
    Circle* c2 = new Circle(0, 0, 7);
    HorizontalSegment* s1 = new HorizontalSegment(1, 1, 5);

    vector<Figure*> ff;
    ff.push_back(c1);
    ff.push_back(c2);
    ff.push_back(s1);

    // for (Figure* f : ff) {
    //     f->draw();
    //     cout << "-------------------------------------------------" << endl;
    // }

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