/*
** PlayableEntity.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 23:51:06 2017 sshSupreme
** Last update Sat Jun 17 23:37:54 2017 Florent Sebag
*/

#ifndef _PLAYABLEENTITY_HPP_
# define _PLAYABLEENTITY_HPP_

#include "EnnemyEntity.hpp"
#include "Projectil.hpp"
#include "RessourcesManager.hpp"

namespace NsEntity
{
class PlayableEntity : public NsEntity::Entity
{
protected:
  size_t                            Keys_;
  size_t                            Gold_;
  bool                              Ranger_;
  bool 				    _isDying;

public:

  virtual void                      HappyAnim() = 0;

 public:
  void                              Jump();
  void                              Moveback();
  void                              Move(irr::f32, irr::f32);
  void                              AutoShot(std::vector<std::shared_ptr<NsEntity::EnnemyEntity>>, std::vector<std::shared_ptr<NsProjectil::Projectil>>&); // CLOSE
  virtual void                      Move() = 0;
  virtual void                      Death() = 0;
  virtual void                      takeDamage(size_t);
  virtual void                      Static() = 0;
  virtual void                      AutoShot() = 0; // RANGE
  virtual void                      AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>&) = 0; // RANGE
  virtual void                      StopShot() = 0;
  virtual void                      Spell_1() = 0;
  virtual void                      Spell_2() = 0;
  virtual void                      Spell_3() = 0;

public:
  size_t                            getGold() const;
  size_t                            getKeys() const;
  void                              setGold(size_t);
  void                              setKeys(size_t);
  bool				    getIsDying() const;
  void 				    setIsDying(bool isDying);

private:
  virtual void                      MoveAnim() = 0;
  virtual void                      ShotAnim() = 0;
  virtual void                      StaticAnim() = 0;
  virtual void                      DeathAnim() = 0;

  virtual void                      AngryAnim() = 0;
  virtual void                      MoveShotAnim() = 0;

public:
  PlayableEntity(Model3D&);
  virtual ~PlayableEntity();
};

class Archer : public PlayableEntity
{
public:
  void                               Move();
  void                               Static();
  void                               Death();
  void                               AutoShot() {}
  void                               AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>&);
  void                               StopShot();
  void                               Spell_1();
  void                               Spell_2();
  void                               Spell_3();

private:
  void                               MoveAnim();
  void                               ShotAnim();
  void                               StaticAnim();
  void                               DeathAnim();
  void                               HappyAnim();
  void                               AngryAnim();
  void                               MoveShotAnim();

public:
  Archer(Model3D&);
  virtual ~Archer();
  void PushProjectil(std::shared_ptr<NsProjectil::Fireball> entity, const irr::core::vector3df &pos,
		     std::vector<std::shared_ptr<NsProjectil::Projectil>> &vProjectil_);
};

class Warrior : public PlayableEntity
{
public:
  void                               Move();
  void                               Static();
  void                               Death();
  void                               AutoShot();
  void                               AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>&) {}
  void                               StopShot();
  void                               Spell_1();
  void                               Spell_2();
  void                               Spell_3();

private:
  void                               MoveAnim();
  void                               ShotAnim();
  void                               StaticAnim();
  void                               DeathAnim();
  void                               HappyAnim();
  void                               AngryAnim();
  void                               MoveShotAnim();

public:
  Warrior(Model3D&);
  virtual ~Warrior();
};

class Wizard : public PlayableEntity
{
public:
  void                               Move();
  void                               Static();
  void                               Death();
  void                               AutoShot() {}
  void                               AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>&);
  void                               StopShot();
  void                               Spell_1();
  void                               Spell_2();
  void                               Spell_3();

private:
  void                               MoveAnim();
  void                               ShotAnim();
  void                               StaticAnim();
  void                               DeathAnim();
  void                               HappyAnim();
  void                               AngryAnim();
  void                               MoveShotAnim();

public:
  Wizard(Model3D&);
  virtual ~Wizard();

  void PushProjectil(std::shared_ptr<NsProjectil::Fireball> entity, const irr::core::vector3df &pos,
		     std::vector<std::shared_ptr<NsProjectil::Projectil>> &vProjectil_);
};

class Guardian : public PlayableEntity
{
public:
  void                               Move();
  void                               Static();
  void                               Death();
  void                               AutoShot();
  void                               AutoRangeShot(std::vector<std::shared_ptr<NsProjectil::Projectil>>&) {}
  void                               StopShot();
  void                               Spell_1();
  void                               Spell_2();
  void                               Spell_3();

private:
  void                               MoveAnim();
  void                               ShotAnim();
  void                               StaticAnim();
  void                               DeathAnim();
  void                               HappyAnim();
  void                               AngryAnim();
  void                               MoveShotAnim();

public:
  Guardian(Model3D&);
  virtual ~Guardian();
};
}

#endif
