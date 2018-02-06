/*
** EnnemyEntity.hpp for cpp_indie_studio in /home/sshsupreme/tek2/cpp_indie_studio/sources/newEntity
**
** Made by sshSupreme
** Login   <sshsupreme@epitech.net>
**
** Started on  Fri Jun 02 23:19:05 2017 sshSupreme
** Last update Sun Jun 18 17:59:02 2017 Florent Sebag
*/

#ifndef _ENNEMYENTITY_HPP_
# define _ENNEMYENTITY_HPP_

#include "Entity.hpp"

namespace NsEntity
{
  class PlayableEntity;

  class EnnemyEntity : public NsEntity::Entity
  {
   private:
    irr::scene::HealthSceneNode		         *Healthbar_;
    int						Room_id_;
    irr::core::vector3df           PrevPos;
    int           nb_loop;

   protected:
    irr::core::vector3df			Speed_;

   public: // UNUSED
    void                                    Move(irr::f32, irr::f32) {}
    void                                    Jump() {}

   public:
    virtual void                           Death() = 0;
    virtual void                           Static() = 0;

   public:
    int                                    Move(irr::core::vector3df, int, std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> &);
    virtual void                           takeDamage(size_t);
    void                                   AutoShot(std::shared_ptr<NsEntity::PlayableEntity> &focus);
    void                                   CheckWall(irr::core::vector3df, irr::core::vector3df, int, std::vector<std::shared_ptr<NsEntity::EnnemyEntity>> &);

   public:
    irr::scene::HealthSceneNode            *getHealthbar() const;
    void                                   setHealthbar(irr::scene::HealthSceneNode*);
    int					getRoom_id_() const;
    void 				setRoom_id_(int Room_id_);

   public:
    EnnemyEntity(Model3D&);
    virtual ~EnnemyEntity();
  };

  class BasicMonster : public EnnemyEntity
  {
  public:
   void              Death();
   void              Static();
   void              AutoShot();

  public:
   BasicMonster(Model3D&);
   virtual ~BasicMonster();
  };

  class Boss : public EnnemyEntity
  {
   protected:
     irr::core::vector3df ToGo;
     bool                 isGoing;
     bool                 isBacking;
     int                  loop_follow;
     enum BossStrat
       {
         GOFIRST   = 0,
         GOSECOND  = 1,
         FOLLOW    = 2,
         RIGHTLEFT = 3,
       };
      BossStrat strat;
   public:
    void              Death();
    void              Static();
    void              AutoShot();
    void              BossHandler(irr::core::vector3df &focus);
    void              newStrat();
    void              setPosBacking();
    int               CheckPos();
    void              BossBegin();
    void              MoveBoss();

   public:
    Boss(Model3D&);
    virtual ~Boss();
  };
}

#endif
