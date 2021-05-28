/*---------------------------------------------------------------------------------*/
/*  NOMAD - Nonlinear Optimization by Mesh Adaptive Direct Search -                */
/*                                                                                 */
/*  NOMAD - Version 4.0 has been created by                                        */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  The copyright of NOMAD - version 4.0 is owned by                               */
/*                 Charles Audet               - Polytechnique Montreal            */
/*                 Sebastien Le Digabel        - Polytechnique Montreal            */
/*                 Viviane Rochon Montplaisir  - Polytechnique Montreal            */
/*                 Christophe Tribes           - Polytechnique Montreal            */
/*                                                                                 */
/*  NOMAD v4 has been funded by Rio Tinto, Hydro-Québec, Huawei-Canada,            */
/*  NSERC (Natural Sciences and Engineering Research Council of Canada),           */
/*  InnovÉÉ (Innovation en Énergie Électrique) and IVADO (The Institute            */
/*  for Data Valorization)                                                         */
/*                                                                                 */
/*  NOMAD v3 was created and developed by Charles Audet, Sebastien Le Digabel,     */
/*  Christophe Tribes and Viviane Rochon Montplaisir and was funded by AFOSR       */
/*  and Exxon Mobil.                                                               */
/*                                                                                 */
/*  NOMAD v1 and v2 were created and developed by Mark Abramson, Charles Audet,    */
/*  Gilles Couture, and John E. Dennis Jr., and were funded by AFOSR and           */
/*  Exxon Mobil.                                                                   */
/*                                                                                 */
/*  Contact information:                                                           */
/*    Polytechnique Montreal - GERAD                                               */
/*    C.P. 6079, Succ. Centre-ville, Montreal (Quebec) H3C 3A7 Canada              */
/*    e-mail: nomad@gerad.ca                                                       */
/*                                                                                 */
/*  This program is free software: you can redistribute it and/or modify it        */
/*  under the terms of the GNU Lesser General Public License as published by       */
/*  the Free Software Foundation, either version 3 of the License, or (at your     */
/*  option) any later version.                                                     */
/*                                                                                 */
/*  This program is distributed in the hope that it will be useful, but WITHOUT    */
/*  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or          */
/*  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License    */
/*  for more details.                                                              */
/*                                                                                 */
/*  You should have received a copy of the GNU Lesser General Public License       */
/*  along with this program. If not, see <http://www.gnu.org/licenses/>.           */
/*                                                                                 */
/*  You can find information on the NOMAD software at www.gerad.ca/nomad           */
/*---------------------------------------------------------------------------------*/
/**
 \file   ArrayOfPoint.cpp
 \brief  Vector of NOMAD::Points (implementation)
 \author Viviane Rochon Montplaisir
 \date   August 2019
 \see    ArrayOfPoint.hpp
 */
#include "../Math/ArrayOfPoint.hpp"



std::ostream& NOMAD::operator<< (std::ostream& out, const NOMAD::ArrayOfPoint& aop)
{
    for (size_t i = 0; i < aop.size(); i++)
    {
        if (i > 0)
        {
            out << " ";
        }
        out << aop[i].display();
    }
    return out;
}


std::istream& NOMAD::operator>>(std::istream& in, ArrayOfPoint& aop)
{
    // Patch: The ArrayOfPoint must contain 1 Point with the right dimension.
    if (0 == aop.size() || 0 == aop[0].size())
    {
        throw NOMAD::Exception(__FILE__,__LINE__,"Input ArrayOfPoint should have a point of nonzero value");
    }

    size_t n = aop[0].size();
    aop.clear();
    NOMAD::ArrayOfDouble aod(n);
    NOMAD::Point point(n);

    // Usually, point files do not have parenthesis in them, so read
    // points as ArrayOfDouble. If Point parentesis is needed, we can add it.
    while (in >> aod && in.good() && !in.eof())
    {
        point = aod;
        aop.push_back(point);
    }
    if (!in.eof() || !point.isComplete())
    {
        throw NOMAD::Exception(__FILE__,__LINE__,"Error while reading point file");
    }

    return in;
}

