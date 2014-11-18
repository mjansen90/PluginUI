
#include "PluginUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);

   PluginUI window;
   window.show();
   
   return app.exec();
}