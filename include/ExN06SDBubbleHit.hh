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
// $Id: ExN06SDBubbleHit.hh,v 1.5 2006-06-29 16:31:12 gunter Exp $
// --------------------------------------------------------------
//
#ifndef ExN06SDBubbleHit_h
#define ExN06SDBubbleHit_h 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4Transform3D.hh"
#include "G4RotationMatrix.hh"

class G4AttDef;
class G4AttValue;

class ExN06SDBubbleHit : public G4VHit
{
  public:

      ExN06SDBubbleHit();
      ExN06SDBubbleHit(G4int iCol,G4int iRow);
      virtual ~ExN06SDBubbleHit();
      ExN06SDBubbleHit(const ExN06SDBubbleHit &right);
      const ExN06SDBubbleHit& operator=(const ExN06SDBubbleHit &right);
      int operator==(const ExN06SDBubbleHit &right) const;

      inline void *operator new(size_t);
      inline void operator delete(void *aHit);

      virtual void Draw();
      virtual const std::map<G4String,G4AttDef>* GetAttDefs() const;
      virtual std::vector<G4AttValue>* CreateAttValues() const;
      virtual void Print();

  private:
      G4int totalPE;

  public:
      inline void SetTotalPE(G4int pe) { totalPE = pe; }
      inline void AddTotalPE(G4int pe) { totalPE += pe; }
      inline G4int GetTotalPE() const { return totalPE; }

};

typedef G4THitsCollection<ExN06SDBubbleHit> ExN06SDBubbleHitsCollection;

extern G4Allocator<ExN06SDBubbleHit> ExN06SDBubbleHitAllocator;

inline void* ExN06SDBubbleHit::operator new(size_t)
{
  void* aHit;
  aHit = (void*)ExN06SDBubbleHitAllocator.MallocSingle();
  return aHit;
}

inline void ExN06SDBubbleHit::operator delete(void* aHit)
{
  ExN06SDBubbleHitAllocator.FreeSingle((ExN06SDBubbleHit*) aHit);
}

#endif


