
#pragma once

#include <QtCore/qglobal.h>

#ifdef SamplePage_EXPORTS
#   define SAMPLEPAGE_EXPORT Q_DECL_EXPORT
#else
#   define SAMPLEPAGE_EXPORT Q_DECL_IMPORT
#endif