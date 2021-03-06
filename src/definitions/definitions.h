// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <QtGlobal>

#define MARGIN_LINE_NUMBERS 0
#define MARGIN_FOLDING      1

#define MARGIN_WIDTH_NUMBERS  48
#define MARGIN_WIDTH_FOLDING  16

#define FORMAT_DATETIME_OUTPUT                      "yyyy-MM-dd HH:mm:ss"
#define FILE_CHUNK_LENGTH_FOR_ENCODING_DETECTION    2048
#define DEFAULT_TEXT_FILE_ENCODING            "UTF-8"
#define BIG_TEXT_FILE_SIZE                    qint64(50000000)
#define MAX_TEXT_FILE_SIZE                    qint64(INT_MAX)
#define ARGUMENTS_LIST_SEPARATOR              "\n"
#define RELEASES_LIST                         "https://api.github.com/repos/martinrotter/textilosaurus/releases"
#define DEFAULT_LOCALE                        "en"
#define ICON_SIZE_SETTINGS                    16
#define DOWNLOAD_TIMEOUT                      20000
#define ELLIPSIS_LENGTH                       3
#define FLAG_ICON_SUBFOLDER                   "flags"
#define SPACER_ACTION_NAME                    "spacer"
#define SEPARATOR_ACTION_NAME                 "separator"
#define DOWNLOADER_ICON_SIZE                  48
#define MAX_RECENT_FILES                      15
#define ENCRYPTION_FILE_NAME                  "key.private"

#define EXT_TOOLS_CONFIG                      "external_tools.ini"
#define EXT_TOOL_INTERPRETER                  "bash"

#define PASTEBIN_GITHUB   "https://api.github.com/gists"
#define PASTEBIN_SPRUNGE  "http://sprunge.us/"
#define PASTEBIN_CLBIN    "https://clbin.com"
#define PASTEBIN_IXIO     "http://ix.io"

#define HTTP_HEADERS_ACCEPT         "Accept"
#define HTTP_HEADERS_CONTENT_TYPE   "Content-Type"
#define HTTP_HEADERS_AUTHORIZATION  "Authorization"
#define HTTP_HEADERS_USER_AGENT     "User-Agent"

#define APP_CFG_PATH        "config"
#define APP_CFG_FILE        "config.ini"

#define APP_QUIT_INSTANCE   "-q"
#define APP_IS_RUNNING      "app_is_running"
#define APP_STYLE_DEFAULT   "Fusion"
#define APP_THEME_DEFAULT   "Faenza"
#define APP_NO_THEME        ""
#define APP_THEME_SUFFIX    ".png"

#ifndef QSL

// Thin macro wrapper for literal strings.
// They are much more memory efficient and faster.
// Use it for all literals except for two cases:
//  a) Methods which take QLatin1String (use QLatin1String for literal argument too),
//  b) Construction of empty literals "", use QString() instead of QStringLiteral("").
#define QSL(x) QStringLiteral(x)
#endif

#ifndef QL1S

// Macro for latin strings. Latin strings are
// faster than QStrings created from literals.
#define QL1S(x) QLatin1String(x)
#endif

#ifndef QL1C

// Macro for latin chars.
#define QL1C(x) QLatin1Char(x)
#endif

#if defined(Q_OS_LINUX)
#define OS_ID   "Linux"
#elif defined(Q_OS_OSX)
#define OS_ID   "Mac OS X"
#elif defined(Q_OS_WIN)
#define OS_ID   "Windows"
#elif defined(Q_OS_ANDROID)
#define OS_ID   "Android"
#else
#define OS_ID   ""
#endif

// Paths.
#define APP_THEME_PATH QSL(":/graphics")
#define APP_INFO_PATH QSL(":/text")
#define APP_ICON_PATH QSL(":/graphics/textilosaurus.png")
#define APP_LANG_PATH QSL(":/localization")

#if defined(Q_OS_LINUX)
#define APP_DESKTOP_ENTRY_FILE "com.github.textilosaurus.desktop"

#define APP_DESKTOP_ENTRY_PATH QSL(":/desktop")
#endif

#endif // DEFINITIONS_H
