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

#include "ins_names.h"

const char *MidiInsName[128] =
{
    "Acoustic Grand Piano",
    "Bright Acoustic Piano",
    "Electric Grand Piano",
    "Honky-Tonk Piano",
    "Rhodes Piano",
    "Chorused Piano",
    "Harpsichord",
    "Clavinet",
    "Celesta",
    "Glockenspiel",
    "Music box",
    "Vibraphone",
    "Marimba",
    "Xylophone",
    "Tubular Bells",
    "Dulcimer",
    "Hammond Organ",
    "Percussive Organ",
    "Rock Organ",
    "Church Organ",
    "Reed Organ",
    "Accordion",
    "Harmonica",
    "Tango Accordion",
    "Acoustic Guitar (nylon)",
    "Acoustic Guitar (steel)",
    "Electric Guitar (jazz)",
    "Electric Guitar (clean)",
    "Electric Guitar (muted)",
    "Overdrive Guitar",
    "Distorton Guitar",
    "Guitar Harmonics",
    "Acoustic Bass",
    "Electric Bass (finger)",
    "Electric Bass (pick)",
    "Fretless Bass",
    "Slap Bass 1",
    "Slap Bass 2",
    "Synth Bass 1",
    "Synth Bass 2",
    "Violin",
    "Viola",
    "Cello",
    "Contrabass",
    "Tremolo Strings",
    "Pizzicato String",
    "Orchestral Harp",
    "Timpany",
    "String Ensemble 1",
    "String Ensemble 2",
    "Synth Strings 1",
    "Synth Strings 2",
    "Choir Aahs",
    "Voice Oohs",
    "Synth Voice",
    "Orchestra Hit",
    "Trumpet",
    "Trombone",
    "Tuba",
    "Muted Trumpet",
    "French Horn",
    "Brass Section",
    "Synth Brass 1",
    "Synth Brass 2",
    "Soprano Sax",
    "Alto Sax",
    "Tenor Sax",
    "Baritone Sax",
    "Oboe",
    "English Horn",
    "Bassoon",
    "Clarinet",
    "Piccolo",
    "Flute",
    "Recorder",
    "Pan Flute",
    "Bottle Blow",
    "Shakuhachi",
    "Whistle",
    "Ocarina",
    "Lead 1 (Square)",
    "Lead 2 (Sawtooth)",
    "Lead 3 (Сalliope)",
    "Lead 4 (Сhiff)",
    "Lead 5 (Charang)",
    "Lead 6 (Voice)",
    "Lead 7 (Fifths)",
    "Lead 8 (Lead+Bass)",
    "Pad 1 (New age)",
    "Pad 2 (Warm)",
    "Pad 3 (Polysynth)",
    "Pad 4 (Choir)",
    "Pad 5 (Bowed)",
    "Pad 6 (Metallic)",
    "Pad 7 (Halo)",
    "Pad 8 (Sweep)",
    "FX 1 (Rain)",
    "FX 2 (Soundtrack)",
    "FX 3 (Crystal)",
    "FX 4 (Atmosphere)",
    "FX 5 (Brightness)",
    "FX 6 (Goblins)",
    "FX 7 (Echoes)",
    "FX 8 (Sci-fi)",
    "Sitar",
    "Banjo",
    "Shamisen",
    "Koto",
    "Kalimba",
    "Bagpipe",
    "Fiddle",
    "Shanai",
    "Tinkle Bell",
    "Agogo Bells",
    "Steel Drums",
    "Woodblock",
    "Taiko Drum",
    "Melodic Tom",
    "Synth Drum",
    "Reverse Cymbal",
    "Guitar Fret Noise",
    "Breath Noise",
    "Seashore",
    "Bird Tweet",
    "Telephone",
    "Helicopter",
    "Applause/Noise",
    "Gunshot"
};

const char *MidiPercName[128] =
{
    "<Reserved 0>",
    "<Reserved 1>",
    "<Reserved 2>",
    "<Reserved 3>",
    "<Reserved 4>",
    "<Reserved 5>",
    "<Reserved 6>",
    "<Reserved 7>",
    "<Reserved 8>",
    "<Reserved 9>",
    "<Reserved 10>",
    "<Reserved 11>",
    "<Reserved 12>",
    "(XG) Surdo Mute",
    "(XG) Surdo Open",
    "(XG) High Q",
    "(XG) Whip Slap",
    "(XG) Scratch Push",
    "(XG) Scratch Pull",
    "(XG) Finger Snap",
    "(XG) Click Noise",
    "(XG) Metronome Click",
    "(XG) Metronome Bell",
    "(XG) Seq Click L",
    "(XG) Seq Click H",
    "(XG) Brush Tap",
    "(XG) Brush Swirl L",
    "(GS) High Q, (XG) Brush Slap",
    "(GS) Slap, (XG) Brush Swirl H",
    "(GS) Scratch Push, (XG) Snare Roll",
    "(GS) Scratch Pull, (XG) Castanet",
    "(GS) Sticks, (XG) Snare L",
    "(GS) Square Click, (XG) Sticks",
    "(GS) Metronome Click, (XG) Bass Drum L",
    "(GS) Metronome Bell, (XG) Open Rim Shot",
    "Acoustic Bass Drum",
    "Bass Drum 1",
    "Side Stick",
    "Acoustic Snare",
    "Hand Clap",
    "Electric Snare",
    "Low Floor Tom",
    "Closed High Hat",
    "High Floor Tom",
    "Pedal High Hat",
    "Low Tom",
    "Open High Hat",
    "Low-Mid Tom",
    "High-Mid Tom",
    "Crash Cymbal 1",
    "High Tom",
    "Ride Cymbal 1",
    "Chinese Cymbal",
    "Ride Bell",
    "Tambourine",
    "Splash Cymbal",
    "Cow Bell",
    "Crash Cymbal 2",
    "Vibraslap",
    "Ride Cymbal 2",
    "High Bongo",
    "Low Bongo",
    "Mute High Conga",
    "Open High Conga",
    "Low Conga",
    "High Timbale",
    "Low Timbale",
    "High Agogo",
    "Low Agogo",
    "Cabasa",
    "Maracas",
    "Short Whistle",
    "Long Whistle",
    "Short Guiro",
    "Long Guiro",
    "Claves",
    "High Wood Block",
    "Low Wood Block",
    "Mute Cuica",
    "Open Cuica",
    "Mute Triangle",
    "Open Triangle",
    "(GS&XG) Shaker",
    "(GS&XG) Jingle Bell",
    "(GS&XG) Bell Tree",
    "(GS) Castanets",
    "(GS) Mute Surdu",
    "(GS) Open Surdu",
    "<Reserved 88>",
    "<Reserved 89>",
    "<Reserved 90>",
    "<Reserved 91>",
    "<Reserved 92>",
    "<Reserved 93>",
    "<Reserved 94>",
    "<Reserved 95>",
    "<Reserved 96>",
    "<Reserved 97>",
    "<Reserved 98>",
    "<Reserved 99>",
    "<Reserved 100>",
    "<Reserved 101>",
    "<Reserved 102>",
    "<Reserved 103>",
    "<Reserved 104>",
    "<Reserved 105>",
    "<Reserved 106>",
    "<Reserved 107>",
    "<Reserved 108>",
    "<Reserved 109>",
    "<Reserved 110>",
    "<Reserved 111>",
    "<Reserved 112>",
    "<Reserved 113>",
    "<Reserved 114>",
    "<Reserved 115>",
    "<Reserved 116>",
    "<Reserved 117>",
    "<Reserved 118>",
    "<Reserved 119>",
    "<Reserved 120>",
    "<Reserved 121>",
    "<Reserved 122>",
    "<Reserved 123>",
    "<Reserved 124>",
    "<Reserved 125>",
    "<Reserved 126>",
    "<Reserved 127>"
};

QString getMidiInsNameM(int index)
{
    return index < 128 ? MidiInsName[index] : QString("INS_%1").arg(index, 3);
}

QString getMidiInsNameP(int index)
{
    return index < 128 ? MidiPercName[index] : QString("INS_%1").arg(index, 3);
}
