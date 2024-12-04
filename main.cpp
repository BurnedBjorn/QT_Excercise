#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"
#include<math.h>
const double pi = 3.14159265; 
using namespace Graph_lib;
int main(int /*argc*/, char* /*argv*/[])
{
    Application app;//хз
    Simple_window w({ 100,100 }, 1200, 700, "window"); 
    Point centre{ w.x_max() / 2,w.y_max() / 2 };
    vector<unique_ptr<Polygon>> ngons; 
    int scale = 100; 
    for (int i = 3; i < 9; i++) 
    {
        //ag
        auto ngon = std::make_unique<Polygon>();
        for (int ii = 0; ii < i; ii++)
        {
            double angle = (360 / i) * ii; 
            double radian = angle * pi / 180; 
            ngon->add({ static_cast<int>(centre.x + scale*sin(radian)),static_cast<int>(centre.y + scale*cos(radian)) });
            
        } 
        w.attach(*ngon); 
        ngons.push_back(std::move(ngon)); 
    }
    app.gui_main(); 
}
