#include "myurl.h"

MyURL::MyURL()
{
    base_url="http://localhost:3001";
    //base_url="htpp://ipv4.fiddler:3001";
}

// "Generate getter (voi olla väärä)"
const QString &MyURL::getBase_url() const
{
    return base_url;
}



