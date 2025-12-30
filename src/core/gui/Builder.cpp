#include "Builder.h"

#include "util/StringUtils.h"

#include "GladeSearchpath.h"  // for GladeSearchpath
#include "filesystem.h"       // for path

Builder::Builder(GladeSearchpath* gladeSearchPath, const std::string& uiFile):
        builder(gtk_builder_new_from_file(gladeSearchPath->findFile("", uiFile).c_str()), xoj::util::adopt) {}
