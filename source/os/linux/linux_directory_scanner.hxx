///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Arthur N. Klassen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////
//
// 2017.03.26 - First version
//
//    May you do good and not evil.
//    May you find forgiveness for yourself and forgive others.
//    May you share freely, never taking more than you give.
//
///////////////////////////////////////////////////////////////////////////
//
// linux_directory_scanner.hxx -- Linux directory scanner declaration
//
///////////////////////////////////////////////////////////////////////////

#include <string.hxx>
#include <file_path.hxx>

#include <operating_system_primitives.hxx>

#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

namespace ansak
{

class LinuxDirectoryScanner : public DirectoryListPrimitive
{
    LinuxDirectoryScanner(const FilePath& directory, DIR* osDir) : m_path(directory), m_dir(osDir) {}

public:

    ~LinuxDirectoryScanner();

    static LinuxDirectoryScanner* newIterator(const FilePath& directory);

    FilePath operator()() override;
    FilePath directoryPath() const { return m_path; }
    unsigned int lastError() const { return m_lastError; }

private:
    FilePath            m_path;
    unsigned int        m_lastError;
    DIR*                m_dir = nullptr;

};

}
