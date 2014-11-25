
#include "PluginApp.h"

#include "ui_PluginApp.h"

#include "Common/BasePage.h"

#include <QDir>
#include <QFileDialog>
#include <QPluginLoader>

// Constructor
PluginApp::PluginApp(QWidget* pParent) :
   QMainWindow(pParent),
   m_pUI(new Ui_PluginUI),
   m_pSignalMapper(new QSignalMapper(this))
{
   m_pUI->setupUi(this);

   connect(m_pUI->m_pActionInitializePages, SIGNAL(triggered()), this, SLOT(OnActionInitPages()));
   connect(m_pUI->m_pActionLoadPlugin, SIGNAL(triggered()), this, SLOT(OnActionLoadPlugin()));
   connect(m_pUI->m_pTabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(OnTabClosed(int)));

   connect(m_pSignalMapper, SIGNAL(mapped(QString)), this, SLOT(OnActionAddTab(QString)));
}

// Destructor
PluginApp::~PluginApp()
{
}

void PluginApp::InitPages()
{
   QMap<QString, BasePage*>::const_iterator it = m_PageMap.begin();
   QMap<QString, BasePage*>::const_iterator itEnd = m_PageMap.end();
   for (; it != itEnd; ++it)
   {
      (*it)->Initialize();
   }
}

void PluginApp::LoadPlugin(const QString& plugin)
{
   QPluginLoader loader(plugin);
   if (QObject* pPlugin = loader.instance())
   {
      if (BasePage* pPage = qobject_cast<BasePage*>(pPlugin))
      {
         if (!m_PageMap.contains(pPage->Description()))
         {
            qWarning("Loaded %s", pPage->Description().toAscii().constData());
            m_PageMap[pPage->Description()] = pPage;
            m_pUI->m_pMenuAddTabs->removeAction(m_pUI->m_pActionEmpty);
            QAction* pAction = m_pUI->m_pMenuAddTabs->addAction(pPage->Description(), m_pSignalMapper, SLOT(map()));
            m_pSignalMapper->setMapping(pAction, pPage->Description());
         }
         else
         {
            qWarning("%s plugin already loaded!", pPage->Description().toLatin1().constData());
         }
      }
      else
      {
         qWarning("%s is not a BasePage", plugin.toLatin1().constData());
      }
   }
   else
   {
      qWarning("%s is not a Qt Plugin", plugin.toLatin1().constData());
   }
}

void PluginApp::LoadAllPlugins()
{
   QDir pluginsDir(qApp->applicationDirPath());
   qWarning("Plugin Dir %s", pluginsDir.absolutePath().toAscii().constData());
   pluginsDir.cdUp();
   pluginsDir.cdUp();
   pluginsDir.cd("plugins");
   foreach (QString file, pluginsDir.entryList(QDir::Files))
   {
      LoadPlugin(file);
   }
}

void PluginApp::AddAllTabs()
{
   QMap<QString, BasePage*>::const_iterator it = m_PageMap.begin();
   QMap<QString, BasePage*>::const_iterator itEnd = m_PageMap.end();
   for (; it != itEnd; ++it)
   {
      AddTab(it.key());
   }

   m_pUI->m_pActionInitializePages->setEnabled(m_pUI->m_pTabWidget->count() > 0);
}

void PluginApp::AddTab(const QString& pageName)
{
   QMap<QString, BasePage*>::const_iterator it = m_PageMap.find(pageName);
   if (it != m_PageMap.end())
   {
      if (m_pUI->m_pTabWidget->indexOf(it.value()) == -1)
      {
         m_pUI->m_pTabWidget->addTab(it.value(), it.key());
      }
      else
      {
         qWarning("%s tab already added!",  it.key().toLatin1().constData());
      }
   }
   else
   {
      qWarning("Could not find tab with name %s", it.key().toLatin1().constData());
   }
}

void PluginApp::OnActionAddTab(QString pageName)
{
   AddTab(pageName);
}

void PluginApp::OnActionInitPages()
{
   InitPages();
}

void PluginApp::OnActionLoadPlugin()
{
   LoadPlugin(QFileDialog::getOpenFileName(0, "Select plugin to load", qApp->applicationDirPath(), "Base Pages (*.dll)"));
}

void PluginApp::OnTabClosed(int index)
{
   m_pUI->m_pTabWidget->removeTab(index);
}