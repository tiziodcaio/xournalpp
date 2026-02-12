/*
 * Xournal++
 *
 * This file is part of the Xournal UnitTests
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#include <filesystem>

#include <config-test.h>
#include <gtest/gtest.h>

#include "model/Document.h"
#include "model/DocumentHandler.h"
#include "util/StringUtils.h"
#include "util/utf8_view.h"

TEST(DocumentName, testUTF8) {
    DocumentHandler dh;
    Document doc(&dh);
    const fs::path p = u8"ùèçüûin/ë€ds测试q.xopp";
    bool failed = false;
    auto trything = [&](Document::DocumentType t) {
        try {
            p = doc.createSaveFilename(t, u8"%% %Y %EY %B %A", u8"%{name} %Y %EY %B %A");
            std::cout << "Resulting path: " << char_cast(p.u8string()) << std::endl;
            if (!g_utf8_validate(char_cast(p.u8string().c_str()), -1, nullptr)) {
                failed = true;
                std::cout << "This path yields an invalid UTF8 string" << std::endl;
            }
        } catch (const std::exception& e) {
            failed = true;
            std::cout << e.what() << std::endl;
        }
    };
    trything(Document::PDF);
    trything(Document::XOPP);
    doc.setFilepath(p);
    trything(Document::PDF);
    trything(Document::XOPP);

    /*try {
        std::cout << "Try \"p.native()\": ";
        auto a = p.native();
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }*/
    try {
        std::cout << "Try \"p.string()\"  : ";
        auto a = p.string();
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    /*try {
        std::cout << "Try \"std::cout << p.native()\": ";
        std::cout << p.native() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }*/
    try {
        std::cout << "Try \"std::cout << p\"           : ";
        std::cout << p << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"std::cout << p.string()\"  : ";
        std::cout << p.string() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    p = fs::path(L"ùèçüûin/ë€ds测试q.xopp");
    /*try {
        std::cout << "Try \"p.native()\": ";
        auto a = p.native();
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }*/
    try {
        std::cout << "Try \"p.string()\"  : ";
        auto a = p.string();
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"char_cast(xoj::util::utf8(p.string()))\"  : ";
        auto a = char_cast(xoj::util::utf8(p.string()).str());
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"char_cast(xoj::util::utf8(p.u8string()))\"  : ";
        auto a = char_cast(xoj::util::utf8(p.u8string()).str());
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"char_cast(xoj::util::utf8(p.native()))\"  : ";
        auto a = char_cast(xoj::util::utf8(p.native()).str());
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"char_cast(p.u8string())\"  : ";
        auto a = char_cast(p.u8string());
        std::cout << "done: " << std::flush;
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    /*try {
        std::cout << "Try \"std::cout << p.native()\": ";
        std::cout << p.native() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }*/
    try {
        std::cout << "Try \"std::cout << p\"           : ";
        std::cout << p << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Try \"std::cout << p.string()\"  : ";
        std::cout << p.string() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }


    if (failed) {
        FAIL();
    }
}
