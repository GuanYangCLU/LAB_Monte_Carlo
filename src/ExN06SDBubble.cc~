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
// $Id: ExN06SDBubble.cc,v 1.6 2006-06-29 16:32:43 gunter Exp $
// --------------------------------------------------------------
//
#include "ExN06SDBubble.hh"
#include "ExN06SDBubbleHit.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

ExN06SDBubble::ExN06SDBubble(G4String name)
:G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="BubbleCol");
  HCID = -1;
}

ExN06SDBubble::~ExN06SDBubble(){;}

void ExN06SDBubble::Initialize(G4HCofThisEvent*HCE)
{
  hitsCollection = new ExN06SDBubbleHitsCollection
                   (SensitiveDetectorName,collectionName[0]);
  if(HCID<0)
  { HCID = G4SDManager::GetSDMpointer()->GetCollectionID(hitsCollection); }
  HCE->AddHitsCollection(HCID,hitsCollection);

}

G4bool ExN06SDBubble::ProcessHits(G4Step*aStep,G4TouchableHistory* /*ROhist*/)
{
  //G4cout << "one more hit." << G4endl;
  ExN06SDBubbleHit* aHit = new ExN06SDBubbleHit();
  int pe = aHit -> GetTotalPE();
  aHit -> SetTotalPE(pe+1);
  hitsCollection -> insert(aHit);
  aStep -> GetTrack() -> SetTrackStatus(fStopAndKill);
  return true;
}

void ExN06SDBubble::EndOfEvent(G4HCofThisEvent* /*HCE*/)
{
  G4cout << hitsCollection -> entries() // "size of HC:" <<
	    << G4endl;
}

