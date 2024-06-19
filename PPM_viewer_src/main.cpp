#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Color.hpp"
#include "Ppm_file.hpp"

using namespace std;

int main(int ac, char *av[]) {
    if (ac != 2) {
        cout << "Usage: ./PPM_viewer [file.ppm]" << endl;
        return 1;
    }
    try {
        Ppm_file imageFile(av[1]);
        sf::Texture texture;
        texture.loadFromImage(imageFile.getImage());

        sf::Sprite sprite;
        sprite.setTexture(texture);

        sf::RenderWindow window(sf::VideoMode(imageFile.getWidth(), imageFile.getHeight()), av[1]);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}
