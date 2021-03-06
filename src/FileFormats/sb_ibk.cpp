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

#include "sb_ibk.h"
#include "../common.h"

static const char* sbi_magic = "SBI\x1A";
static const char* ibk_magic = "IBK\x1A";

bool SbIBK::detect(char *magic)
{
    return (strncmp(magic, ibk_magic, 4) == 0);
}

bool SbIBK::detectInst(char *magic)
{
    return (strncmp(magic, sbi_magic, 4) == 0);
}

int SbIBK::loadFile(QString filePath, FmBank &bank)
{
    char magic[4]; memset(magic, 0, 4);

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
        return ERR_NOFILE;

    bank.reset();

    if( file.read(magic, 4) != 4 )
        return ERR_BADFORMAT;

    if( strncmp(magic, ibk_magic, 4) != 0 )
        return ERR_BADFORMAT;

    bool drumFlags[128];
    memset(drumFlags, 0, sizeof(bool)*128);

    for(unsigned short i=0; i<128; i++)
    {
        unsigned char   idata[16];
        if( file.read(char_p(idata), 16) != 16 )
        {
            bank.reset();
            return ERR_BADFORMAT;
        }
        char tempName[10];
        sprintf(tempName, "NONAME%03d", i);
        strncpy(bank.Ins_Melodic[i].name, tempName, 9 );
        strncpy(bank.Ins_Percussion[i].name, tempName, 9 );

        FmBank::Instrument &ins = (idata[11]==0x00) ? bank.Ins_Melodic[i] : bank.Ins_Percussion[i];
        drumFlags[i] = ( idata[11] != 0x00);
//        typedef struct {        /* 16 Bytes each */
//            BYTE modchar;   /* AM, VIB, SUS, KSR, MUL */
//            BYTE carchar;
        ins.setAVEKM(MODULATOR1,    idata[0]);
        ins.setAVEKM(CARRIER1,      idata[1]);
//            BYTE modscal;   /* KSL, TL */
//            BYTE carscal;
        ins.setKSLL(MODULATOR1,     idata[2]);
        ins.setKSLL(CARRIER1,       idata[3]);
//            BYTE modad;     /* Attack/Decay */
//            BYTE carad;
        ins.setAtDec(MODULATOR1,    idata[4]);
        ins.setAtDec(CARRIER1,      idata[5]);
//            BYTE modsr;     /* Sustain/Release */
//            BYTE carsr;
        ins.setSusRel(MODULATOR1,   idata[6]);
        ins.setSusRel(CARRIER1,     idata[7]);
//            BYTE modwave;   /* Wave Select */
//            BYTE carwave;
        ins.setWaveForm(MODULATOR1, idata[8] );
        ins.setWaveForm(CARRIER1,   idata[9] );
//            BYTE feedback;  /* FB, Connection *(inverse of Adlib)* <- not true? */
//                            /* The following was originally reserved...CL uses  */
//                            /* the next byte the same way we do: BD=6,SD=7,TT=8 */
//                            /* CY=9,HH=10                                       */
        ins.setFBConn1(idata[10]);
//            BYTE percvoc;   /* Percussion voice number                    : JWO */
        ins.adlib_drum_number  = idata[11];
//            char transpos;  /* Number of notes to transpose timbre, signed: JWO */
        ins.note_offset1 = char_p(idata)[12];
//            BYTE dpitch;    /* percussion pitch: MIDI Note 0 - 127        : JWO */
        ins.percNoteNum  = idata[13];
//            BYTE rsv[2];    /* unsused - so far */
//            } SBTIMBRE;
    }

    //fetch bank names
    for(unsigned short i=0; i<128; i++)
    {
        FmBank::Instrument &ins = drumFlags[i] ?
                                    bank.Ins_Percussion[i] :
                                    bank.Ins_Melodic[i];
        if(file.read(ins.name, 9) != 9)
        {
            bank.reset();
            return ERR_BADFORMAT;
        }
    }

    file.close();
//    typedef struct {                     /* 3204 Bytes (0x0C83) */
//            char     sig[4];             /* signature: "IBK\x1A"  */
//            SBTIMBRE snd[128];           /* Instrument block */
//            char     name[128][9];       /* name block: NUL terminated strings */
//            } IBKFMT;
    return ERR_OK;
}

int SbIBK::loadFileInst(QString filePath, FmBank::Instrument &inst, bool *isDrum)
{
    char magic[4]; memset(magic, 0, 4);

    memset(&inst, 0, sizeof(FmBank::Instrument));

    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
        return ERR_NOFILE;

    bool isExtended = file.bytesAvailable() > 52;
    Q_UNUSED(isExtended);

    if( file.read(magic, 4) != 4 )
        return ERR_BADFORMAT;

    if( strncmp(magic, sbi_magic, 4) != 0 )
        return ERR_BADFORMAT;

    //char tempName[32];
    //sprintf(tempName, "NONAME%03d", 0);
    //strncpy(inst.name, tempName, 32 );
    if(file.read(inst.name, 32) != 32)
    {
        return ERR_BADFORMAT;
    }

    bool drumFlag = false;
    unsigned char   idata[16];
    if( file.read(char_p(idata), 16) != 16 )
    {
        memset(&inst, 0, sizeof(FmBank::Instrument));
        return ERR_BADFORMAT;
    }
    FmBank::Instrument &ins = inst;
    drumFlag = ( idata[11] != 0x00);
    ins.setAVEKM(MODULATOR1,    idata[0]);
    ins.setAVEKM(CARRIER1,      idata[1]);
    ins.setKSLL(MODULATOR1,     idata[2]);
    ins.setKSLL(CARRIER1,       idata[3]);
    ins.setAtDec(MODULATOR1,    idata[4]);
    ins.setAtDec(CARRIER1,      idata[5]);
    ins.setSusRel(MODULATOR1,   idata[6]);
    ins.setSusRel(CARRIER1,     idata[7]);
    ins.setWaveForm( MODULATOR1, idata[8] );
    ins.setWaveForm( CARRIER1,   idata[9] );
    ins.setFBConn1(idata[10]);
    ins.adlib_drum_number  = idata[11];
    ins.note_offset1 = char_p(idata)[12];
    ins.percNoteNum  = idata[13];
    if(isDrum)
        *isDrum = drumFlag;

    file.close();
    return ERR_OK;
}

int SbIBK::saveFile(QString filePath, FmBank &bank)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly))
        return ERR_NOFILE;

    bool drumFlags[128];
    memset(drumFlags, 0, sizeof(bool)*128);

    //Write header
    file.write(char_p(ibk_magic), 4);

    for(unsigned short i=0; i<128; i++)
    {
        drumFlags[i] = (bank.Ins_Percussion[i].adlib_drum_number != 0);
        FmBank::Instrument &ins = drumFlags[i] ?
                                   bank.Ins_Percussion[i] :
                                   bank.Ins_Melodic[i];
        unsigned char   odata[16];
        memset(odata, 0, 16);

        odata[0] = ins.getAVEKM(MODULATOR1);
        odata[1] = ins.getAVEKM(CARRIER1);
        odata[2] = ins.getKSLL(MODULATOR1);
        odata[3] = ins.getKSLL(CARRIER1);
        odata[4] = ins.getAtDec(MODULATOR1);
        odata[5] = ins.getAtDec(CARRIER1);
        odata[6] = ins.getSusRel(MODULATOR1);
        odata[7] = ins.getSusRel(CARRIER1);
        odata[8] = ins.getWaveForm(MODULATOR1);
        odata[9] = ins.getWaveForm(CARRIER1);

        odata[10] = ins.getFBConn1();

        odata[11] = ins.adlib_drum_number;

        char* sodata = char_p(odata);
        sodata[12]  = char(ins.note_offset1);
        odata[13]   = ins.percNoteNum;
        //Two reserved bytes!
        odata[14] = 0;
        odata[15] = 0;
        if( file.write(char_p(&odata), 16) != 16 )
            return ERR_BADFORMAT;
    }

    //store bank names
    for(unsigned short i=0; i<128; i++)
    {
        FmBank::Instrument &ins = drumFlags[i] ?
                                   bank.Ins_Percussion[i] :
                                   bank.Ins_Melodic[i];
        if( file.write(ins.name, 9) != 9 )
            return ERR_BADFORMAT;
    }

    file.close();

    return ERR_OK;
}
