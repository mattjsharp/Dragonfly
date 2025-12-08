#include <SFML/Window/Keyboard.hpp>

#include "InputManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"

#include "LogManager.h"

namespace df {

    namespace { // Anonymous namespace for helper functions.
        Keyboard::Key keyFromSFMLKey(sf::Keyboard::Key key) {
            switch (key) {
                case sf::Keyboard::Key::Unknown:
                    LM.writeLog("UNDEFINED_KEY");
                    return Keyboard::Key::UNDEFINED_KEY;
                case sf::Keyboard::Key::Space:
                    LM.writeLog("space");
                    return Keyboard::Key::SPACE;
                case sf::Keyboard::Key::Enter:
                    LM.writeLog("return");
                    return Keyboard::Key::RETURN;
                case sf::Keyboard::Key::Escape:
                    LM.writeLog("escape");
                    return Keyboard::Key::ESCAPE;
                case sf::Keyboard::Key::Tab:
                    LM.writeLog("tab");
                    return Keyboard::Key::TAB;
                case sf::Keyboard::Key::Left:
                    LM.writeLog("left arrow");
                    return Keyboard::Key::LEFTARROW;
                case sf::Keyboard::Key::Right:
                    LM.writeLog("right arrow");
                    return Keyboard::Key::RIGHTARROW;
                case sf::Keyboard::Key::Up:
                    LM.writeLog("up arrow");
                    return Keyboard::Key::UPARROW;
                case sf::Keyboard::Key::Down:
                    LM.writeLog("down arrow");
                    return Keyboard::Key::DOWNARROW;
                case sf::Keyboard::Key::Pause:
                    LM.writeLog("puase");
                    return Keyboard::Key::PAUSE;
                case sf::Keyboard::Key::Subtract:
                    LM.writeLog("minus");
                    return Keyboard::Key::MINUS;
                case sf::Keyboard::Key::Add:
                    LM.writeLog("plus");
                    return Keyboard::Key::PLUS;
                case sf::Keyboard::Key::Grave:
                    LM.writeLog("tilde");
                    return Keyboard::Key::TILDE;
                case sf::Keyboard::Key::Period:
                    LM.writeLog("period");
                    return Keyboard::Key::PERIOD;
                case sf::Keyboard::Key::Comma:
                    LM.writeLog("comma");
                    return Keyboard::Key::COMMA;
                case sf::Keyboard::Key::Slash:
                    LM.writeLog("slash");
                    return Keyboard::Key::SLASH;
                case sf::Keyboard::Key::LControl:
                    LM.writeLog("left control");
                    return Keyboard::Key::LEFTCONTROL;
                case sf::Keyboard::Key::RControl:
                    LM.writeLog("right control");
                    return Keyboard::Key::RIGHTCONTROL;
                case sf::Keyboard::Key::LShift:
                    LM.writeLog("left shift");
                    return Keyboard::Key::LEFTSHIFT;
                case sf::Keyboard::Key::RShift:
                    LM.writeLog("right shift");
                    return Keyboard::Key::RIGHTSHIFT;
                case sf::Keyboard::Key::F1:
                    LM.writeLog("F1");
                    return Keyboard::Key::F1;
                case sf::Keyboard::Key::F2:
                    LM.writeLog("F2");
                    return Keyboard::Key::F2;
                case sf::Keyboard::Key::F3:
                    LM.writeLog("F3");
                    return Keyboard::Key::F3;
                case sf::Keyboard::Key::F4:
                    LM.writeLog("F4");
                    return Keyboard::Key::F4;
                case sf::Keyboard::Key::F5:
                    LM.writeLog("F5");
                    return Keyboard::Key::F5;
                case sf::Keyboard::Key::F6:
                    LM.writeLog("F6");
                    return Keyboard::Key::F6;
                case sf::Keyboard::Key::F7:
                    LM.writeLog("F7");
                    return Keyboard::Key::F7;
                case sf::Keyboard::Key::F8:
                    LM.writeLog("F8");
                    return Keyboard::Key::F8;
                case sf::Keyboard::Key::F9:
                    LM.writeLog("F9");
                    return Keyboard::Key::F9;
                case sf::Keyboard::Key::F10:
                    LM.writeLog("F10");
                    return Keyboard::Key::F10;
                case sf::Keyboard::Key::F11:
                    LM.writeLog("F11");
                    return Keyboard::Key::F11;
                case sf::Keyboard::Key::F12:
                    LM.writeLog("F12");
                    return Keyboard::Key::F12;
                case sf::Keyboard::Key::A:
                    LM.writeLog("A");
                    return Keyboard::Key::A;
                case sf::Keyboard::Key::B:
                    LM.writeLog("B");
                    return Keyboard::Key::B;
                case sf::Keyboard::Key::C:
                    LM.writeLog("C");
                    return Keyboard::Key::C;
                case sf::Keyboard::Key::D:
                    LM.writeLog("D");
                    return Keyboard::Key::D;
                case sf::Keyboard::Key::E:
                    LM.writeLog("E");
                    return Keyboard::Key::E;
                case sf::Keyboard::Key::F:
                    LM.writeLog("F");
                    return Keyboard::Key::F;
                case sf::Keyboard::Key::G:
                    LM.writeLog("G");
                    return Keyboard::Key::G;
                case sf::Keyboard::Key::H:
                    LM.writeLog("H");
                    return Keyboard::Key::H;
                case sf::Keyboard::Key::I:
                    LM.writeLog("I");
                    return Keyboard::Key::I;
                case sf::Keyboard::Key::J:
                    LM.writeLog("J");
                    return Keyboard::Key::J;
                case sf::Keyboard::Key::K:
                    LM.writeLog("K");
                    return Keyboard::Key::K;
                case sf::Keyboard::Key::L:
                    LM.writeLog("L");
                    return Keyboard::Key::L;
                case sf::Keyboard::Key::M:
                    LM.writeLog("M");
                    return Keyboard::Key::M;
                case sf::Keyboard::Key::N:
                    LM.writeLog("N");
                    return Keyboard::Key::N;
                case sf::Keyboard::Key::O:
                    LM.writeLog("O");
                    return Keyboard::Key::O;
                case sf::Keyboard::Key::P:
                    LM.writeLog("P");
                    return Keyboard::Key::P;
                case sf::Keyboard::Key::Q:
                    LM.writeLog("Q");
                    return Keyboard::Key::Q;
                case sf::Keyboard::Key::R:
                    LM.writeLog("R");
                    return Keyboard::Key::R;
                case sf::Keyboard::Key::S:
                    LM.writeLog("S");
                    return Keyboard::Key::S;
                case sf::Keyboard::Key::T:
                    LM.writeLog("T");
                    return Keyboard::Key::T;
                case sf::Keyboard::Key::U:
                    LM.writeLog("U");
                    return Keyboard::Key::U;
                case sf::Keyboard::Key::V:
                    LM.writeLog("V");
                    return Keyboard::Key::V;
                case sf::Keyboard::Key::W:
                    LM.writeLog("W");
                    return Keyboard::Key::W;
                case sf::Keyboard::Key::X:
                    LM.writeLog("X");
                    return Keyboard::Key::X;
                case sf::Keyboard::Key::Y:
                    LM.writeLog("Y");
                    return Keyboard::Key::Y;
                case sf::Keyboard::Key::Z:
                    LM.writeLog("Z");
                    return Keyboard::Key::Z;
                case sf::Keyboard::Key::Num1:
                    LM.writeLog("1");
                    return Keyboard::Key::NUM1;
                case sf::Keyboard::Key::Num2:
                    LM.writeLog("2");
                    return Keyboard::Key::NUM2;
                case sf::Keyboard::Key::Num3:
                    LM.writeLog("3");
                    return Keyboard::Key::NUM3;
                case sf::Keyboard::Key::Num4:
                    LM.writeLog("4");
                    return Keyboard::Key::NUM4;
                case sf::Keyboard::Key::Num5:
                    LM.writeLog("5");
                    return Keyboard::Key::NUM5;
                case sf::Keyboard::Key::Num6:
                    LM.writeLog("6");
                    return Keyboard::Key::NUM6;
                case sf::Keyboard::Key::Num7:
                    LM.writeLog("7");
                    return Keyboard::Key::NUM7;
                case sf::Keyboard::Key::Num8:
                    LM.writeLog("8");
                    return Keyboard::Key::NUM8;
                case sf::Keyboard::Key::Num9:
                    LM.writeLog("9");
                    return Keyboard::Key::NUM9;
                case sf::Keyboard::Key::Num0:
                    LM.writeLog("0");
                    return Keyboard::Key::NUM0;

            }

            return Keyboard::Key::UNDEFINED_KEY;
        }
    }

    InputManager::InputManager() {
        setType("LogManager");
    }

    InputManager &InputManager::getInstance() {
        static InputManager instance;
        return instance;
    }

    int InputManager::startUp() {
        if (!(DM.isStarted())) {
            return -1;
        }

        sf::RenderWindow* p_window = DM.getWindow();

        p_window->setKeyRepeatEnabled(false);

        Manager::startUp();

        return 0;
    }

    void InputManager::shutDown() {
        sf::RenderWindow* p_window = DM.getWindow();

        p_window->setKeyRepeatEnabled(true);

        Manager::shutDown();
    }

    void InputManager::getInput() const {
        sf::RenderWindow* p_window = DM.getWindow();

        while (const std::optional<sf::Event> p_event = p_window->pollEvent()) {
            sf::Event e = p_event.value();

            if (p_event->is<sf::Event::KeyPressed>()) {
                sf::Event::KeyPressed* p_kb_event = reinterpret_cast<sf::Event::KeyPressed*>(&e);

                sf::Keyboard::Key key;
                key = p_kb_event->code;

                Keyboard::Key df_key= keyFromSFMLKey(key);

            }
        }
    }
}
