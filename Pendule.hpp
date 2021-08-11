#ifndef H_Pendule
#define H_Pendule 
	
	#include <stdlib.h>
	#include <math.h>
	#include <SFML/Graphics.hpp>
	#include "Node.hpp"

	class Pendule
	{
	private:
		Node m_nodes[3];
		float m_arm[2];
		float m_theta[2];
		float m_Op[2];

		sf::Color m_color;
		sf::RenderWindow *m_app;

	public:
		Pendule(sf::RenderWindow *app, sf::Color color);
		void draw();
		void miseAjour();
		
	};


#endif
