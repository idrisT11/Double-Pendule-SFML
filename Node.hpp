#ifndef H_NODE
#define H_NODE 

	#include <SFML/Graphics.hpp>

	class Node
	{
	private:
		float m_px;
		float m_py;
		float m_vx;
		float m_vy;
		float m_raduis;
		float m_masse;
		sf::CircleShape m_shape;


	public:
		Node();
		Node(float p_x, float p_y);
		void initGraphic();
		void setPosition(float p_x, float p_y);
		void getPosition(float &p_x, float &p_y);
		float getRaduis();
		float getMasse();
		sf::CircleShape getShape();
		
	};

#endif
