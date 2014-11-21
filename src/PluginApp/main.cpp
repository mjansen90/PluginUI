
#include "PluginApp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   PluginApp window;
   window.show();
   
   return app.exec();
}