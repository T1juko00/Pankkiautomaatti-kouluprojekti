#include "myurl.h"

MyUrl::MyUrl()
{
    base_url="http://localhost:3001";
    //base_url="htpp://ipv4.fiddler:3001";
}


QString MyUrl::getBase_url() const
{
    return base_url;
}


