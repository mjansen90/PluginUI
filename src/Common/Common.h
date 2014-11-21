
#pragma once

#include <QtCore/qglobal.h>

#ifdef Common_EXPORTS
#   define COMMON_EXPORT Q_DECL_EXPORT
#else
#   define COMMON_EXPORT Q_DECL_IMPORT
#endif