#include <iostream>
#include <string>

using namespace std;

class Image {
public:
    void GetImageInfo() {
        for (int i = 0; i < leight; i++) {
            cout << pixels[i].GetInfo() << endl;
        }
    }
private:
    class Pixel {
    public:
        Pixel(int r, int g, int b) {
            this->r = r; this->g = g; this->b = b;
            GetInfo();
        };
        string GetInfo() {
            return "Pixel: r = " + to_string(r) + "   Pixel: g = " + to_string(g) + "   Pixel: b = " + to_string(b);
        }
    private:
        int r = 0, g = 0, b = 0;
    };

    static const int leight = 5;
    Pixel pixels[leight]{
        Pixel(5, 12, 100),
        Pixel(122, 2000, 2),
        Pixel(1, 222, 9),
        Pixel(100, 200, 300),
        Pixel(999, 1, 2)
    };
};
signed main() {
    Image pik;
    pik.GetImageInfo();

    return 0;
}