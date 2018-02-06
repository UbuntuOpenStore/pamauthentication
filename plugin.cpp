#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "pamauthentication.h"

void PamAuthenticationPlugin::registerTypes(const char *uri) {
    //@uri PamAuthentication
    qmlRegisterType<PamAuthentication>(uri, 0, 1, "PamAuthentication");
}
