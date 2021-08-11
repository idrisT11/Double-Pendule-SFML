
#include "Node.hpp"

Node::Node(): m_px(0), m_py(0), m_raduis(10), m_masse(0.3), m_vx(0), m_vy(0)  {
	m_shape.setPosition(0, 0);
}

Node::Node(float p_x, float p_y): m_px(p_x), m_py(p_x), m_raduis(10), m_masse(0.3), m_vx(0), m_vy(0)  {
	m_shape.setPosition(p_x, p_y);
}


void Node::initGraphic(){
	m_shape.setRadius(m_raduis);
	m_shape.setPointCount(40);

    m_shape.setFillColor(sf::Color(100, 150, 255));

    m_shape.setOutlineThickness(4.f);
    m_shape.setOutlineColor(sf::Color(100, 150, 255));
}

void Node::getPosition(float &p_x, float &p_y){
	p_x = m_px;
	p_y = m_py;
}

float Node::getRaduis(){
	return m_raduis;
}

void Node::setPosition(float p_x, float p_y){
	m_px = p_x;
	m_py = p_y;
	m_shape.setPosition(p_x, p_y);

}

sf::CircleShape Node::getShape(){
	return m_shape;
}
float Node::getMasse(){
	return m_masse;
}