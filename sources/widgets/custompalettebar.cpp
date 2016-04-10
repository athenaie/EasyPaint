/*
 * This source file is part of EasyPaint.
 *
 * Copyright (c) 2016 EasyPaint <https://github.com/Gr1N/EasyPaint>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "custompalettebar.h"

#include <QColorDialog>

CustomPaletteBar::CustomPaletteBar(ToolBar *toolbar) :
        AbstractPaletteBar(toolbar)
{
    initializeItems();
}

void CustomPaletteBar::initializeItems()
{
    QColorDialog::setCustomColor(0, 0xffffffff);
}

void CustomPaletteBar::updateColors()
{
    clearAllColors();
    addCustomColors();
}

void CustomPaletteBar::clearAllColors()
{
    mColorButtons.clear();
}

void CustomPaletteBar::addCustomColors()
{
    for (int i = 0; i < QColorDialog::customCount(); i++)
    {
        QRgb color = QColorDialog::customColor(i);
        // add new button to toolbar if color is not default (white)
        if (color != 0xffffffff)
        {
            ButtonPtr colorButton(new PaletteButton(color));    // create new button
            mColorButtons.push_back(colorButton);               // store button pointer in vector
            connect(colorButton.data(), SIGNAL(colorPicked()), this, SLOT(colorClicked()));
            addWidget(colorButton.data());                      // add button to toolbar
        }
    }
}