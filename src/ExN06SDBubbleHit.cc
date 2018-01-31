//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: ExN06SDBubbleHit.cc,v 1.11 2006-11-14 07:11:19 perl Exp $
// --------------------------------------------------------------
//

#include "ExN06SDBubbleHit.hh"
#include "G4RunManager.hh"
#include "G4RotationMatrix.hh"
#include "G4Box.hh"
#include "G4VVisManager.hh"
#include "G4Colour.hh"
#include "G4AttDefStore.hh"
#include "G4AttDef.hh"
#include "G4AttValue.hh"
#include "G4UIcommand.hh"
#include "G4UnitsTable.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"
#include "G4ios.hh"

G4Allocator<ExN06SDBubbleHit> ExN06SDBubbleHitAllocator;

ExN06SDBubbleHit::ExN06SDBubbleHit()
{
  totalPE = 0;
}

ExN06SDBubbleHit::~ExN06SDBubbleHit()
{;}

ExN06SDBubbleHit::ExN06SDBubbleHit(const ExN06SDBubbleHit &right)
    : G4VHit() {
  totalPE = right.totalPE;
}

const ExN06SDBubbleHit& ExN06SDBubbleHit::operator=(const ExN06SDBubbleHit &right)
{
  totalPE = right.totalPE;
  return *this;
}

int ExN06SDBubbleHit::operator==(const ExN06SDBubbleHit &right) const
{
  return (totalPE == right.totalPE);
}

void ExN06SDBubbleHit::Draw()
{
}

const std::map<G4String,G4AttDef>* ExN06SDBubbleHit::GetAttDefs() const
{
  std::map<G4String,G4AttDef>* store;
  return store;
}

std::vector<G4AttValue>* ExN06SDBubbleHit::CreateAttValues() const
{
  std::vector<G4AttValue>* values = new std::vector<G4AttValue>;

  return values;
}

void ExN06SDBubbleHit::Print()
{
  G4cout <<  totalPE << G4endl;
}


