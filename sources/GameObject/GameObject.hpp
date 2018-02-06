//
// Created by chauvin on 31/05/17.
//

#ifndef CPP_INDIE_STUDIO_GAMEOBJECT_HPP
#define CPP_INDIE_STUDIO_GAMEOBJECT_HPP

class ISceneNodeAnimator;

#include "../include.h"
#include "../RessourceManager/Model3D.hpp"
#include "../Entity/PlayableEntity.hpp"

using namespace irr;

namespace NsGameObject
{
  class GameObject
  {
    std::string EntityName;
    irr::scene::IAnimatedMeshSceneNode *node_;
    Model3D &Model3D_;
   public:
    //! constructor
    GameObject(Model3D &model) : Model3D_(model)
    { node_ = NULL; };

    //! destructor
    virtual ~GameObject() {};

    //! action the Object
    virtual void Take(std::shared_ptr<NsEntity::PlayableEntity> & entity) = 0;

    //! returns the Entity Name
    const std::string &getEntityName() const {return EntityName;}

    //! returns the Irrlicht Node
    irr::scene::IAnimatedMeshSceneNode *getNode() const {return node_;}

    //! sets the irrlicht node
    void setNode_(irr::scene::IAnimatedMeshSceneNode *node_) {GameObject::node_ = node_;}

    //! returns the 3Dmodel
    Model3D &getModel3D_() const {return Model3D_;}

    //! initializes the GameObject
    void	Initialization(){};
  };
  class Key : public GameObject
  {
   public:
    //! constructor
    Key(Model3D &model) : GameObject(model) {};

    //! destructor
    ~Key(){};

    //! action the Object
    void		Take(std::shared_ptr<NsEntity::PlayableEntity> & entity);
  };
  class Gold : public GameObject
  {
   public:
    //! constructor
    Gold(Model3D &model) : GameObject(model){};

    //! desctructor
    ~Gold(){};

    //! action the Object
    void		Take(std::shared_ptr<NsEntity::PlayableEntity> & entity);
  };
  class Door : public GameObject
  {
    int	open;
    int	type;
    std::vector<irr::scene::ISceneNodeAnimator*> pAnimator;

   public:
    //! constructor
    Door(Model3D &model) : GameObject(model){open = false;};

    //! destructor
    ~Door(){};

    //! action the object
    void 		Take(std::shared_ptr<NsEntity::PlayableEntity>& entity);

    int 					isOpen() const;
    void 					setOpen(int open);
    void 					checkFrame();
    std::vector<scene::ISceneNodeAnimator *> 	&getPAnimator();
    void 					setPAnimator(const std::vector<scene::ISceneNodeAnimator *> &pAnimator);
    int 					getType() const;
    void 					setType(int type);
  };
}

#endif //CPP_INDIE_STUDIO_GAMEOBJECT_HPP
