
#pragma once

#include <QMainWindow>

class Ui_PluginUI;

class PluginApp : public QMainWindow
{
   Q_OBJECT
public:
   PluginApp(QWidget* pParent = 0);
   ~PluginApp();

private:
   Ui_PluginUI*   m_pUI;
};