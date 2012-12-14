#include "../src/../include/JSONHandler/RPC2Objects/NsRPC2Communication/UI/DeleteSubMenu.h"
#include "../src/../include/JSONHandler/RPC2Objects/Marshaller.h"

/*
  interface	NsRPC2Communication::UI
  version	1.2
  generated at	Fri Dec 14 06:14:25 2012
  source stamp	Fri Dec 14 06:14:23 2012
  author	robok0der
*/

using namespace NsRPC2Communication::UI;


DeleteSubMenu& DeleteSubMenu::operator =(const DeleteSubMenu& c)
{
  menuId=c.menuId;
  appId=c.appId;
  return *this;
}


DeleteSubMenu::~DeleteSubMenu(void)
{
}


DeleteSubMenu::DeleteSubMenu(void) : 
  RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__DELETESUBMENU)
{
}


DeleteSubMenu::DeleteSubMenu(const DeleteSubMenu& c) : RPC2Request(Marshaller::METHOD_NSRPC2COMMUNICATION_UI__DELETESUBMENU,c.getId())
{
  *this=c;
}


unsigned int DeleteSubMenu::get_menuId(void)
{
  return menuId;
}

bool DeleteSubMenu::set_menuId(unsigned int menuId_)
{
  menuId=menuId_;
  return true;
}

int DeleteSubMenu::get_appId(void)
{
  return appId;
}

bool DeleteSubMenu::set_appId(int appId_)
{
  appId=appId_;
  return true;
}

bool DeleteSubMenu::checkIntegrity(void)
{
  return DeleteSubMenuMarshaller::checkIntegrity(*this);
}
