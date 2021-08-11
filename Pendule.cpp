#include "Pendule.hpp"

Pendule::Pendule(sf::RenderWindow *app, sf::Color color){
	float px(620),
		  py(300);
	float theta(0),
		  delta_x(0),
		  delta_y(0);

	m_app = app;
	m_color = color;

	m_arm[0] = 0.24;
	m_arm[1] = 0.24;

	m_Op[0] = 0;
	m_Op[1] = 0;

	m_nodes[0].setPosition(px, py);

	for (int i = 1; i < 3; i++)
	{
		theta = ((rand() % 6283) / 1000.f) - 3.141;
		delta_y = cos(theta) * 1000*m_arm[i-1];
		delta_x = sin(theta) * 1000*m_arm[i-1];

		m_nodes[i-1].getPosition(px, py);

		m_nodes[i].setPosition(px + delta_x, py + delta_y);
		m_theta[i-1] = theta;
	}


	for (int i = 0; i < 3; ++i)
		m_nodes[i].initGraphic();
}

void Pendule::miseAjour(){
	float delta_x, delta_y, px, py;

	float m1 = m_nodes[1].getMasse(),
		  m2 = m_nodes[2].getMasse();

	float Opp1 = (m2*m_arm[0]*pow(cos(m_theta[0] - m_theta[1]),2) - m2*m_arm[1]*pow(m_Op[1],2)*sin(m_theta[0] - m_theta[1])-
				(m1 + m2)*sin(m_theta[0])*10 - m2*cos(m_theta[0] - m_theta[1])*m_arm[0]*pow(m_Op[0],2)*sin(m_theta[0] - m_theta[1])+
				10*sin(m_theta[1])*m2*cos(m_theta[0] - m_theta[1])
			)/((m1+m2) * m_arm[0]);

	float Opp2 = (m_arm[0]*pow(m_Op[0],2)*sin(m_theta[0] - m_theta[1]) - 10*sin(m_theta[1]) - m_arm[0]*Opp1*cos(m_theta[0]-m_theta[1])
	)/m_arm[1];	

	m_Op[0] += 0.0001*Opp1;
	m_Op[1] += 0.0001*Opp2;

	m_theta[0] += m_Op[0];		 
	m_theta[1] += m_Op[1];		 


	for (int i = 1; i < 3; i++)
	{
		delta_y = cos(m_theta[i-1]) * 1000*m_arm[i-1];
		delta_x = sin(m_theta[i-1]) * 1000*m_arm[i-1];

		m_nodes[i-1].getPosition(px, py);

		m_nodes[i].setPosition(px + delta_x, py + delta_y);
	}

}

void Pendule::draw(){
	sf::Vertex line[2][2];

	float px(0),
		  py(0);


	for (int i = 0; i < 2; ++i)// Pour chaque paire de noeuds
	{
		for (int j = 0; j < 2; ++j)// Pour chaque bord du segment
		{
			m_nodes[i+j].getPosition(px, py);
			px += m_nodes[i+j].getRaduis();
			py += m_nodes[i+j].getRaduis();

			line[i][j] = sf::Vertex(sf::Vector2f(px, py), m_color);
		}

		m_app->draw(line[i], 2, sf::Lines);
	}

	for (int i = 0; i < 3; ++i)
		m_app->draw(m_nodes[i].getShape());

	
}