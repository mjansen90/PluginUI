
#pragma once

#include <QMainWindow>
#include <QMap>
#include <QSignalMapper>

class BasePage;
class Ui_PluginUI;

class PluginApp : public QMainWindow
{
   Q_OBJECT
public:
   PluginApp(QWidget* pParent = 0);
   ~PluginApp();

protected:
   void AddAllTabs();
   void AddTab(const QString& pageName);
   void InitPages();
   void LoadAllPlugins();
   void LoadPlugin(const QString& plugin);

protected slots:
   void OnActionAddTab(QString pageName);
   void OnActionInitPages();
   void OnActionLoadPlugins();
   void OnTabClosed(int index);

private:
   Ui_PluginUI*               m_pUI;
   QMap<QString, BasePage*>   m_PageMap;
   QSignalMapper*             m_pSignalMapper;
};