/*
 * OPL Bank Editor by Wohlstand, a free tool for music bank editing
 * Copyright (c) 2016 Vitaly Novichkov <admin@wohlnet.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "common.h"

#include <QMessageBox>

qint64 readLE(QFile &file, unsigned short &out)
{
    uchar bytes[2] = {0, 0};
    qint64 len = file.read(char_p(bytes), 2);
    out =  (quint16(bytes[0])&0x00FF)
          |((quint16(bytes[1])<<8)&0xFF00);
    return len;
}


qint64 readLE(QFile &file, unsigned int &out)
{
    uchar bytes[4] = {0, 0, 0, 0};
    qint64 len = file.read(char_p(bytes), 4);
    out =  (quint32(bytes[0])&0x00FF)
          |((quint32(bytes[1])<<8)&0xFF00)
          |((quint32(bytes[2])<<16)&0xFF0000)
          |((quint32(bytes[2])<<24)&0xFF000000);
    return len;
}

qint64 writeLE(QFile &file, unsigned short &out)
{
    uchar bytes[2] = {uchar(out&0x00FF), uchar((out>>8)&0x00FF) };
    qint64 len = file.write(char_p(bytes), 2);
    return len;
}


qint64 writeLE(QFile &file, unsigned int &out)
{
    uchar bytes[4] = { uchar(out&0x000000FF),
                       uchar((out>>8)&0x000000FF),
                       uchar((out>>16)&0x000000FF),
                       uchar((out>>24)&0x000000FF) };
    qint64 len = file.write(char_p(bytes), 4);
    return len;
}


qint64 readBE(QFile &file, unsigned short &out)
{
    uchar bytes[2] = {0, 0};
    qint64 len = file.read(char_p(bytes), 2);
    out =  (quint16(bytes[1])&0x00FF)
         |((quint16(bytes[0])<<8)&0xFF00);
    return len;
}

qint64 writeBE(QFile &file, unsigned short &out)
{
    uchar bytes[2] = {uchar((out>>8)&0x00FF), uchar(out&0x00FF)};
    qint64 len = file.write(char_p(bytes), 2);
    return len;
}

short toSint16LE(uchar *arr)
{
    short num = *(signed char *)(&arr[1]);
    num *= 1 << 8;
    num |= arr[0];
    return num;
}

unsigned short toUint16LE(uchar *arr)
{
    unsigned short num = arr[0];
    num |= ( (arr[1]<<8) & 0xFF00 );
    return num;
}

short toSint16BE(uchar *arr)
{
    short num = *(signed char *)(&arr[0]);
    num *= 1 << 8;
    num |= arr[1];
    return num;
}

unsigned int toUint32LE(uchar *arr)
{
    unsigned int num = arr[0];
    num |= ( (arr[1]<<8) & 0xFF00 );
    num |= ( (arr[2]<<16) & 0xFF0000 );
    num |= ( (arr[3]<<24) & 0xFF000000 );
    return num;
}


void fromSint16LE(short in, uchar *arr)
{
    arr[0] =  in & 0x00FF;
    arr[1] = (in>>8) & 0x00FF;
}

void fromUint16LE(unsigned short in, uchar *arr)
{
    arr[0] =  in & 0x00FF;
    arr[1] = (in>>8) & 0x00FF;
}

void fromSint16BE(short in, uchar *arr)
{
    arr[1] =  in & 0x00FF;
    arr[0] = (in>>8) & 0x00FF;
}

void fromUint32LE(unsigned int in, uchar *arr)
{
    arr[0] = (in)     & 0x00FF;
    arr[1] = (in>>8)  & 0x00FF;
    arr[2] = (in>>16) & 0x00FF;
    arr[3] = (in>>24) & 0x00FF;
}


void getMagic(QString filePath, char *bytes, int count)
{
    QFile file(filePath);
    memset(bytes, 0, count);
    if(file.open(QIODevice::ReadOnly))
    {
        file.read(bytes, count);
        file.close();
    }
}

bool hasExt(const QString &file, const char*ext)
{
    return file.endsWith(ext, Qt::CaseInsensitive);
}


void ErrMessageO(QWidget *parent, QString errStr)
{
    QMessageBox::warning(parent,
                        QObject::tr("Can't open bank file!"),
                        QObject::tr("Can't open bank file because %1.").arg(errStr),
                        QMessageBox::Ok);
}

void ErrMessageS(QWidget *parent, QString errStr)
{
    QMessageBox::warning(parent,
                        QObject::tr("Can't save bank file!"),
                        QObject::tr("Can't save bank file because %1.").arg(errStr),
                        QMessageBox::Ok);
}
