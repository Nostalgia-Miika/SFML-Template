#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window{ sf::VideoMode(800, 640), "SFML Template" };
	sf::CircleShape circle(100.0f);
	circle.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f);
	circle.setFillColor(sf::Color::Green);
	float _speed{ 500.0f };
	sf::Vector2f speed{ _speed, _speed };
	sf::Vector2f velocity{};

	sf::Clock clock;
	sf::Time deltaTime = clock.restart();
	sf::Event sfEvent;

	// Initialize the view to match the window size
	sf::View view(sf::FloatRect(0, 0, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));

	while (window.isOpen())
	{
		// Check events
		while (window.pollEvent(sfEvent))
		{
			if (sfEvent.type == sf::Event::Closed)
				window.close();
		}

		// Update dynamic objects
		velocity = { speed.x * deltaTime.asSeconds(), speed.y * deltaTime.asSeconds() };
		circle.move(velocity);

		// Use the view's dimensions for collision detection
		sf::Vector2f viewSize = view.getSize();
		sf::Vector2f viewCenter = view.getCenter();
		sf::FloatRect viewRect(viewCenter.x - viewSize.x / 2, viewCenter.y - viewSize.y / 2, viewSize.x, viewSize.y);

		// Basic collision detection
		sf::Vector2f position = circle.getPosition();
		float radius = circle.getRadius();
		sf::Vector2f circleSize{ radius * 2.0f, radius * 2.0f };

		if (position.x <= viewRect.left || position.x + circleSize.x >= viewRect.left + viewRect.width)
			speed.x = -speed.x;

		if (position.y <= viewRect.top || position.y + circleSize.y >= viewRect.top + viewRect.height)
			speed.y = -speed.y;

		// Do rendering
		window.clear(sf::Color(45, 45, 45));
		window.draw(circle);
		window.display();

		// Get frametime
		deltaTime = clock.restart();
	}
}