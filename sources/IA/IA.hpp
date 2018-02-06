#ifndef IA_HPP_
# define IA_HPP_

#include "PlayableEntity.hpp"
#include "EnnemyEntity.hpp"
#include <Python.h>
#include <iostream>

class IA
{
  protected:
    PyObject *TlistMob;
    PyObject *TlistPlayer;
    PyObject *pFunc;
    PyObject *pName;
    PyObject *pModule;
    PyObject *pDict;
    PyObject *pResult;
    PyObject *xStr;
    PyObject *yStr;
    PyObject *zStr;
    int      index_focus;
  public:
    IA();
    ~IA();
    // void defMobList(std::vector<Character> &);
    void defPlayerList(std::vector<std::shared_ptr<NsEntity::PlayableEntity>> &vPlayer_);
    irr::core::vector3df LaunchIA(float x, float y, float z);
    PyObject *convertPosDict(float x, float y, float z);
    const PyObject *getTlistPlayer();
    irr::core::vector3df convertResult();
    void attack(std::shared_ptr<NsEntity::EnnemyEntity> &, std::vector<std::shared_ptr<NsEntity::PlayableEntity>> &, irr::core::vector3df &);
};

#endif
