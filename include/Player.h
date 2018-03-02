#ifndef PLAYER_DEF
#define PLAYER_DEF
#include "VisibleGameObject.h"
#include "Animation.h"

class Player : public VisibleGameObject{
public:
    Player(const std::string &fName, sf::Keyboard::Key _u, sf::Keyboard::Key _l, sf::Keyboard::Key _r);
    ~Player();


    void Update(float elapsedTime,sf::Event& _event) override;
    bool checkCollision(VisibleGameObject* other, float e);

    float GetVelocity() const;


private:
    sf::Keyboard::Key u;
    sf::Keyboard::Key l;
    sf::Keyboard::Key r;
    bool isUpPressed;
    bool isLPressed;
    bool isRPressed;
    //! \brief is It falling down after ataining max distance it can jump? Not if it is actually jumping
    bool isJumping;
    //! \brief The distance it jumped before falling down.
    float dJump;
    //! \brief Velocity for Jump.
    float _upVel;
    //! \brief Velocity to move left/right.
    float _xVal;
    float _velocity;  // -- Downward Velocity..
    float _maxVelocity;
    Animation animation;
};
#endif // PLAYER_H
