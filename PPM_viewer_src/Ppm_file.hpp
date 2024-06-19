#ifndef PPM_FILE_HPP_
#define PPM_FILE_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Color.hpp"

using namespace std;

class Ppm_file {
    private:
        string mode;
        int height;
        int width;
        int color_depth;
        vector<Color> grid;
        sf::Image image;

    public:
    Ppm_file(const string& filename);
    void createImage();

    const sf::Image& getImage() const { return image; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
};

#endif /* !PPM_FILE_HPP_ */
