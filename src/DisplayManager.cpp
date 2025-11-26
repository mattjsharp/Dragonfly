#include "DisplayManager.h"

namespace df {

    namespace { // Anonymous namespace for helper functions.
        // Compute character height in pixels, based on window size.
        float charHeight() {
            return
                static_cast<float>(DM.getVerticalPixels()) /
                static_cast<float>(DM.getVertical());
        }

        // Compute character width in pixels, based on window size.
        float charWidth() {
            return
                static_cast<float>(DM.getHorizontalPixels()) /
                static_cast<float>(DM.getHorizontal());
        }

        // Convert ASCII spaces (x, y) to window pixels (x, y);
        Vector spacesToPixels(Vector spaces) {
            return
                Vector(
                    spaces.getX() * charWidth(),
                    spaces.getY() * charHeight()
                );
        }

        // Convert window pixels (x, y) to ASCII spaces (x, y).
        Vector pixelsToSpaces(Vector pixels) {
            return
                Vector(
                    pixels.getX() / charWidth(),
                    pixels.getY() / charHeight()
                );
        }

    } // End of anonymous namespace.

    DisplayManager::DisplayManager() {
        setType("DisplayManager");

        m_p_window = NULL;
        m_window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
        m_window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
        m_window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
        m_window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
    }

    DisplayManager &DisplayManager::getInstance() {
        static DisplayManager instance;
        return instance;
    }

    int DisplayManager::startUp() {

        // If window already created, do nothing.
        if (m_p_window != NULL)
            return 0;

        // Create window.
        m_p_window =
            new sf::RenderWindow(
                sf::VideoMode({
                    m_window_horizontal_pixels, // TODO: Do something about these warnings.
                    m_window_vertical_pixels
                }),
                WINDOW_TITLE_DEFAULT
            );

        // Turn of mouse cursor for window.
        m_p_window->setMouseCursorVisible(false);

        // Synchronize refresh rate with monitor.
        m_p_window->setVerticalSyncEnabled(true);

        // Open font.
        if (m_font.openFromFile(FONT_FILE_DEFAULT) == false) {
            return -1;
        }

        Manager::startUp(); // Call base class method to set m_is_started to true.

        return 0;
    }

    void DisplayManager::shutDown() {
        Manager::shutDown();  // Call base class method to set m_is_started to false.
    }

    int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {
        // Make sure window is allocated.
        if (m_p_window == NULL)
            return -1;

        // Convert spaces (x, y) to pixels (x, y).
        Vector pixel_pos = spacesToPixels(world_pos);

        // Draw background rectange since text is "see through" in SFML.
        static sf::RectangleShape rectange;
        rectange.setSize(sf::Vector2f(charWidth(), charHeight()));
        rectange.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
        rectange.setPosition({
            pixel_pos.getX() - charWidth()/10,
            pixel_pos.getY() + charHeight()/5
        });

        m_p_window->draw(rectange);

        // Create character text to draw.
        static sf::Text text(m_font);
        text.setString(ch);
        text.setStyle(sf::Text::Bold);  // Make bold, since looks better.

        // Scale to right size.
        if (charWidth() < charHeight())
            text.setCharacterSize(charWidth() * 2);
        else
            text.setCharacterSize(charHeight() * 2);

        // Set SFML color based on Dragonfly color.
        switch (color) {
            case BLACK:
                text.setFillColor(sf::Color::Black);
                break;
            case RED:
                text.setFillColor(sf::Color::Red);
                break;
            case GREEN:
                text.setFillColor(sf::Color::Green);
                break;
            case YELLOW:
                text.setFillColor(sf::Color::Yellow);
                break;
            case BLUE:
                text.setFillColor(sf::Color::Blue);
                break;
            case MAGENTA:
                text.setFillColor(sf::Color::Magenta);
                break;
            case CYAN:
                text.setFillColor(sf::Color::Cyan);
                break;
            case WHITE:
            default:
                text.setFillColor(sf::Color::White);
                break;
        }

        // Set position in window (in pixels).
        text.setPosition({pixel_pos.getX(), pixel_pos.getY()});

        // Draw character.
        m_p_window->draw(text);

        return 0; // Success.
    }

    int DisplayManager::swapBuffers() {
        // Make sure window is allocated.
        if (m_p_window == NULL)
            return -1;

        // Display current window.
        m_p_window->display();

        // Clear other window to get ready for next draw.
        m_p_window->clear();

        return 0; // Success.
    }

    int DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) const {
        // Get starting position.
        Vector starting_pos = pos;
        switch (just) {
            case CENTER_JUSTIFIED:
                starting_pos.setX(pos.getX() - str.size()/2);
                break;
            case RIGHT_JUSTIFIED:
                starting_pos.setX(pos.getX() - str.size());
                break;
            case LEFT_JUSTIFIED:
            default:
                break;
        }

        // Draw string character by character.
        for (int i = 0; i < str.size(); i++) {
            Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
            drawCh(temp_pos, str[i], color);
        }

        // All is well.
        return 0;
    }

    int DisplayManager::getHorizontal() const {
        return m_window_horizontal_chars;
    }

    int DisplayManager::getVertical() const  {
        return m_window_vertical_chars;
    }

    int DisplayManager::getHorizontalPixels() const {
        return m_window_horizontal_pixels;
    }

    int DisplayManager::getVerticalPixels() const {
        return m_window_vertical_pixels;
    }

    sf::RenderWindow* DisplayManager::getWindow() const {
        return m_p_window;
    }
}
