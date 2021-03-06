
#include "utils.hpp"
#include "Gem.hpp"

Gem::Gem(GemType type)
: _type(type)
{
    _colorType[LINEMATE] 	= glm::vec4(1, 0, 0, ALPHA); // Red
    _colorType[DERAUMERE] 	= glm::vec4(0, 1, 0, ALPHA); // Green
    _colorType[SIBUR] 		= glm::vec4(0, 0, 1, ALPHA); // Blue
    _colorType[MENDIANE] 	= glm::vec4(1, 1, 0, ALPHA); // Yellow
    _colorType[PHIRAS] 		= glm::vec4(1, 0, 1, ALPHA); // Pink
    _colorType[THYSTAME] 	= glm::vec4(0, 1, 1, ALPHA); // Cyan

    _model = new Model;
    _model->loadObj("res/models/gem/gem.obj", "res/models/gem/gem.png");

}

Gem::Gem(const Gem &gem, GemType type, const glm::vec2 &position)
{
    _model = new Model(*gem._model);
    _type = type;
    _colorType = gem._colorType;
    _position = position;

    _position.x += ((rand() % 6) / 10.0f) - 0.25f;
    _position.y += ((rand() % 6) / 10.0f) - 0.25f;

    _model->translate(glm::vec3(_position.x, 0.5f, _position.y));
}

Gem::~Gem()
{
    
}

void	Gem::draw(Shader *shader) const
{
    shader->setUniform("gColor", _colorType.find(_type)->second);
    shader->setUniform("ambientLight", glm::vec4(0.02, 0.02, 0.02, 1));
    _model->draw(shader);
}

void	Gem::update(UNUSED const sf::Clock &clock, UNUSED float serverSpeed)
{
    _model->rotate(glm::vec3(0, 1, 0), 1.0f);
}

void	Gem::destroyModel()
{
    if (_model != NULL)
        _model->destroyGeometry();
}

void Gem::setRecourse(UNUSED const std::list<int> &recourse)
{

}

void Gem::setPosition(const glm::vec2 &pos)
{
  _position = pos;
}

const glm::vec2 &Gem::getPosition() const
{
    return (_position);
}

const std::list<int> &Gem::getRecourse() const
{
  return (_recourse);
}

GemType	Gem::getType() const
{
    return (_type);
}

const glm::vec4 &Gem::getColor()
{
    return (_colorType[_type]);
}
