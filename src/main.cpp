#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    tgui::Gui gui{ window };
    
    window.setFramerateLimit(144);

    auto button = tgui::Button::create("Kliknij mnie!");
    button->setPosition(300, 250);
    button->setSize(200, 50);

    button->onClick([]() {
        std::cout << "Przycisk zostal klikniety!" << std::endl;
        });

	gui.add(button);

	gui.mainLoop();
}
