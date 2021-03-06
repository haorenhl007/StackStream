// The MIT License (MIT)
//
// Copyright (c) 2016 Erik Hvatum
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// Authors: Erik Hvatum <ice.rikh@gmail.com>

#include "SSQmlPlugin.h"
#include "SSImage.h"
#include "SSImageItem.h"
#include "SSView.h"

SSQmlPlugin::SSQmlPlugin(QObject* parent)
  : QQmlExtensionPlugin(parent)
{
    qDebug() << "SSQmlPlugin loaded";
}

void SSQmlPlugin::registerTypes(const char* uri)
{
    Q_ASSERT(uri == QLatin1String("StackStream"));
    qDebug() << "SSQmlPlugin::registerTypes(..)";

    const char ss[] = "StackStream";
    const int ver[] = {1, 0};
    qmlRegisterType<SSImage>(ss, ver[0], ver[1], "SSImage");
    qRegisterMetaType<SSImage::DType>("DType");
    qRegisterMetaType<SSImage::Components>("Components");
    qRegisterMetaType<std::size_t>("std::size_t");
    qmlRegisterType<SSImageItem>(ss, ver[0], ver[1], "SSImageItem");
    qmlRegisterType<SSView>(ss, ver[0], ver[1], "SSView");
}
