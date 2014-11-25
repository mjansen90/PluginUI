
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
   void LoadAllPlugins();
   void LoadPlugin(const QString& plugin);

protected slots:
   void OnActionAddTabs();
   void OnActionInitPages();
   void OnActionLoadPlugin();

private:
   Ui_PluginUI*               m_pUI;
   QMap<QString, BasePage*>   m_PageMap;
};