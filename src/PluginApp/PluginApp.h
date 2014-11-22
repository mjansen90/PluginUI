
#pragma once

#include <QMainWindow>
#include <QMap>

class BasePage;
class Ui_PluginUI;

class PluginApp : public QMainWindow
{
   Q_OBJECT
public:
   PluginApp(QWidget* pParent = 0);
   ~PluginApp();

protected:
   void AddTabs();
   void InitPages();
   void LoadPlugins();

protected slots:
   void OnActionAddTabs();
   void OnActionInitPages();
   void OnActionLoadPlugins();

private:
   Ui_PluginUI*               m_pUI;
   QMap<QString, BasePage*>   m_PageMap;
};