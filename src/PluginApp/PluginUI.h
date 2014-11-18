
#pragma once

#include <QMainWindow>

class PluginUI : public QMainWindow
{
   Q_OBJECT
public:
   PluginUI(QWidget* pParent = 0);
   ~PluginUI();
};