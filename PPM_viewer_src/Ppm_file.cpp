#include "Ppm_file.hpp"

Ppm_file::Ppm_file(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file");
    }
    string line;
    getline(file, mode); // Read the magic number
    if (mode != "P3") {
        throw runtime_error("Unsupported PPM mode: " + mode);
    }
    // Skip comments
    while (getline(file, line)) {
        if (line[0] == '#') continue;
        istringstream iss(line);
        iss >> width >> height;
        break;
    }
    file >> color_depth;
    grid.reserve(width * height);
    int r, g, b;
    while (file >> r >> g >> b) {
        grid.push_back(Color(r, g, b));
    }
    createImage();
}

void Ppm_file::createImage()
{
    image.create(width, height);
    for (int i = 0; i < width * height; i++) {
        int x = i % width;
        int y = i / width;
        sf::Color sf_color(grid[i].r, grid[i].g, grid[i].b);
        image.setPixel(x, y, sf_color);
    }
}
