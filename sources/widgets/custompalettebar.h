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

#ifndef CUSTOMPALETTEBAR_H
#define CUSTOMPALETTEBAR_H

#include "abstractpalettebar.h"

class CustomPaletteBar : public AbstractPaletteBar
{
    Q_OBJECT

public:
    CustomPaletteBar(ToolBar *toolBar);

public slots:
    /**
     * @brief Refresh colors in palette bar to match custom colors.
     *
     */
    virtual void updateColors();

protected:
    /**
      * @brief Reset custom colors to default (white).
      *
      */
    virtual void initializeItems();

    /**
      * @brief Remove all custom color buttons.
      *
      */
    virtual void clearAllColors();

    /**
     * @brief Create a button for each custom color.
     *
     */
    virtual void addCustomColors();

    typedef QSharedPointer<PaletteButton> ButtonPtr;
    QVector<ButtonPtr> mColorButtons;
};

#endif // CUSTOMPALETTEBAR_H
