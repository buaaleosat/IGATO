/*****************************************************************************
 *   IGATO - Interplanetary Gravity Assist Trajectory Optimizer              *
 *   Copyright (C) 2012 Jason Bryan (Jmbryan10@gmail.com)                    *
 *                                                                           *
 *   IGATO is free software; you can redistribute it and/or modify           *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   IGATO is distributed in the hope that it will be useful,                *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with IGATO; if not, see http://www.gnu.org/licenses/              *
 *****************************************************************************/

#pragma once
#include "Base.h"

class Orbit
{
public:
    Orbit(double mu);
    Orbit(const StateVector& stateVector, double mu);
    Orbit(const Vector3& position, const Vector3& velocity, double mu);
    Orbit(const OrbitalElements& orbitalElements, double mu);

    void SetStateVector(const StateVector& stateVector);
    void SetStateVector(const Vector3& position, const Vector3& velocity);
    void SetOrbitalElements(const OrbitalElements& orbitalElements);

    const StateVector& GetStateVector() const;
    const OrbitalElements& GetOrbitalElements() const;
    double GetMu() const;
    OrbitType GetType() const;

    bool IsInit() const;
    
    void Propagate(double timeOfFlight);

private:
    Orbit(); /// Standard ctor;
    void UpdateStateVector() const;
    void UpdateOrbitalElements() const;

private:
    bool _init;
    double _mu;
    double _radius;
    OrbitType _type;   

    mutable StateVector _stateVector;
    mutable OrbitalElements _orbitalElements;

    mutable State _stateVectorState;
    mutable State _orbitalElementsState;
};

// Inline Methods
inline double Orbit::GetMu() const
{
    return _mu;
}

inline bool Orbit::IsInit() const
{
    return _init;
}