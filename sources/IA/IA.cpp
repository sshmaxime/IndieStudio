#include "IA.hpp"

// A créer au tout début

IA::IA()
{
  Py_Initialize();
  if (PyRun_SimpleString("import sys") == -1)
    std::cerr << "Error PyRun_SimpleString" << std::endl;
  if (PyRun_SimpleString("sys.path.insert(0, 'sources/IA/')") == -1)
    std::cerr << "Error Import directory" << std::endl;
  if ((pName = PyString_FromString((char*)"IA")) == NULL)
    std::cerr << "Error convert String" << std::endl;
  if ((pModule = PyImport_Import(pName)) == NULL)
    std::cerr << "Error import file" << std::endl;
  if ((pDict = PyModule_GetDict(pModule)) == NULL)
    std::cerr << "Error GetDict" << std::endl;
  if ((pFunc = PyDict_GetItemString(pDict, "IA_Astar")) == NULL)
    std::cerr << "Error getFunc" << std::endl;
  if ((xStr = PyString_FromString("x")) == NULL)
    std::cerr << "Error convert string" << std::endl;
  if ((yStr = PyString_FromString("y")) == NULL)
    std::cerr << "Error convert string" << std::endl;
  if ((zStr = PyString_FromString("z")) == NULL)
    std::cerr << "Error convert string" << std::endl;
}

IA::~IA()
{
  Py_DECREF(pModule);
  Py_DECREF(pName);
  Py_DECREF(pFunc);
  Py_DECREF(xStr);
  Py_DECREF(yStr);
  Py_DECREF(zStr);
  Py_Finalize();
}

PyObject *IA::convertPosDict(float x, float y, float z)
{
  PyObject *res;

  res = PyDict_New();
  if ((PyDict_SetItem(res, xStr, PyFloat_FromDouble((double)x))) == -1)
    std::cerr << "Error SetItem Dico" << std::endl;
  if ((PyDict_SetItem(res, yStr, PyFloat_FromDouble((double)y))) == -1)
    std::cerr << "Error SetItem Dico" << std::endl;
  if ((PyDict_SetItem(res, zStr, PyFloat_FromDouble((double)z))) == -1)
    std::cerr << "Error SetItem Dico" << std::endl;
  return (res);
}

void IA::defPlayerList(std::vector<std::shared_ptr<NsEntity::PlayableEntity>> &vPlayer_)
{
  PyObject *pDTo_add;
  irr::core::vector3df pos;
  int i = 0;

  for (auto it = vPlayer_.begin(); it < vPlayer_.end(); ++it)
    {
      if ((*it)->isAlive() == true)
        i = i + 1;
    }
  if ((TlistPlayer = PyList_New(i)) == NULL)
    std::cerr << "error create list Player" << std::endl;
  i = 0;
  for (auto it = vPlayer_.begin(); it < vPlayer_.end(); ++it)
  {
    if ((*it)->isAlive())
      {
    pos = (*it)->getNode()->getPosition();
    pDTo_add = convertPosDict((float)pos.X, (float)pos.Y, (float)pos.Z);
    if ((PyList_SetItem(TlistPlayer, i, pDTo_add)) == -1)
      std::cerr << "error setItem PlayerList" << std::endl;
    i = i + 1;
    }
  }
}

const PyObject *IA::getTlistPlayer()
{
  return (TlistPlayer);
}

irr::core::vector3df IA::convertResult()
{
  irr::core::vector3df res;
  PyObject *pItemX, *pItemY, *pItemZ, *pDictRes, *pIndex;

  pDictRes = PyTuple_GetItem(pResult, 0);
  pIndex = PyTuple_GetItem(pResult, 1);
  index_focus = PyInt_AsLong(pIndex);
  pItemX = PyDict_GetItem(pDictRes, xStr);
  pItemY = PyDict_GetItem(pDictRes, yStr);
  pItemZ = PyDict_GetItem(pDictRes, zStr);
  res.X = PyInt_AsLong(pItemX);
  res.Y = PyInt_AsLong(pItemY);
  res.Z = PyInt_AsLong(pItemZ);
  Py_DECREF(pIndex);
  Py_DECREF(pDictRes);
  return (res);
}

//A Lancer pour chaque mob

irr::core::vector3df IA::LaunchIA(float x, float y, float z)
{
  PyObject *toSend;
  PyObject *pDPosIA;

  pDPosIA = convertPosDict(x, y, z);
  if ((toSend = Py_BuildValue("(OO)", TlistPlayer, pDPosIA)) == NULL)
    std::cerr << "Error building tuple param" << std::endl;
  if ((pResult = PyObject_CallObject(pFunc, toSend)) == NULL)
    std::cerr << "Error Call Func" << std::endl;
  PyErr_Print();
  Py_DECREF(pDPosIA);
  Py_DECREF(toSend);
  return (convertResult());
}

void IA::attack(std::shared_ptr<NsEntity::EnnemyEntity> &mob, std::vector<std::shared_ptr<NsEntity::PlayableEntity>> &vPlayer_, irr::core::vector3df &focus)
{
  double diff_x;
  double diff_z;

  diff_x = focus.X - mob->getNode()->getPosition().X;
  diff_z = focus.Z - mob->getNode()->getPosition().Z;
  if (diff_x < 0)
    diff_x *= -1;
  if (diff_z < 0)
    diff_z *= -1;
  if (diff_x + diff_z < 5)
    mob->AutoShot(vPlayer_[index_focus]);
}
