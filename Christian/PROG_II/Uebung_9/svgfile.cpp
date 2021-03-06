/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "svgfile.h"
#include <iostream>
#include <cassert> // <> Diese Include-Datei ist notwendig, um Zusicherungen mit Hilfe von `assert` schreiben zu kÃ¶nnen.
// Beginn Klassenvariablen
std::string SVGFile::header1 = R"(<?xml version="1.0" standalone="no"?>)"; // <> Definition des statischen Datenelements (Klassenvariable)
std::string SVGFile::header2 = R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)";
std::string SVGFile::header3 = R"(<svg xmlns="http://www.w3.org/2000/svg"  width="100" height="100">)";
std::string SVGFile::footer1 = R"(</svg>)";
// Ende Klassenvariablen
SVGFile::SVGFile(std::string filename) :
    mFile(filename) // <> Initialisierung des Datenelements `mFile` mit dem Dateinamen -> Erzeugen und Ã–ffnen
{
    assert(mFile.is_open()); // <> Sicherstellen des geÃ¶ffneten Zustands
    mFile << header1 << std::endl; // <> EinfÃ¼gen des XML-Prologs
    mFile << header2 << std::endl;
    mFile << header3 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
SVGFile::~SVGFile()
{
    assert(mFile.is_open()); // <> Sicherstellen eines validen Zustands
    mFile << footer1 << std::endl; // <> EinfÃ¼gen des XML-Epilogs
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
void SVGFile::add(std::string svgElement)
{
    assert(mFile.is_open()); // <> Sicherstelen eines validen Zustands
    mFile << svgElement << std::endl; // <> EinfÃ¼gen eines SVG-Strings
}

