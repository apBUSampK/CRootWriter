/**
* UniGen - Common Format for Event Generators in High-energy and Nuclear Physics
* Copyright (C) 2006 - 2019 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH
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
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef UEVENT_H
#define UEVENT_H

#include "TString.h"
#include "TObject.h"
#include "TLorentzVector.h"

class TClonesArray;
class UParticle;


class UEvent : public TObject {

 private:
  Int_t f_event_nr_;           // Event number
  Double_t f_b_;               // Impact parameter (fm)
  Double_t f_phi_;             // Reaction plane angle
  Int_t f_nes_;                // Number of event steps
  Int_t f_step_nr_;            // Event step number
  Double_t f_step_t_;          // Event step time
  Int_t f_npa_;                // Number of particles
  TString f_comment_;          // Generator-specific information
  TClonesArray* f_particles_;  // Array of particles

 public:
  UEvent();
  UEvent(const UEvent& right);
  UEvent& operator =  (const UEvent& right);
  ~UEvent() override;
  void Print(Option_t* option = "") const override;
  Int_t GetEventNr() const { return f_event_nr_; }
  Double_t GetB() const { return f_b_; }
  Double_t GetPhi() const { return f_phi_; }
  Int_t GetNes() const { return f_nes_; }
  Int_t GetStepNr() const { return f_step_nr_; }
  Double_t GetStepT() const { return f_step_t_; }
  Int_t GetNpa() const { return f_npa_; }
  TClonesArray* GetParticleList() const { return f_particles_; }
  void GetComment(TString& comment) const { comment = f_comment_; }
  UParticle* GetParticle(Int_t index) const;
  void SetParameters(Int_t event_nr, Double_t b, Double_t phi, Int_t nes, Int_t step_nr, Double_t step_t,
                     const char* comment = "");
  void SetEventNr(Int_t event_nr) { f_event_nr_ = event_nr; }
  void SetB(Double_t b) { f_b_ = b; }
  void SetPhi(Double_t phi) { f_phi_ = phi; }
  void SetNes(Int_t nes) { f_nes_ = nes; }
  void SetStepNr(Int_t step_nr) { f_step_nr_ = step_nr; }
  void SetStepT(Double_t step_t) { f_step_t_ = step_t; }
  void SetComment(const char* comment) { f_comment_ = comment; }
  void AddParticle(Int_t index, Int_t pdg, Int_t status, Int_t parent, Int_t parent_decay, Int_t mate, Int_t decay,
                   Int_t child[2], Double_t px, Double_t py, Double_t pz, Double_t e, Double_t x, Double_t y,
                   Double_t z, Double_t t, Double_t weight);
  void AddParticle(Int_t index, Int_t pdg, Int_t status, Int_t parent, Int_t parent_decay, Int_t mate, Int_t decay,
                   Int_t child[2], TLorentzVector mom, TLorentzVector pos, Double_t weight);
  void AddParticle(const UParticle& particle);
  void Clear(Option_t* option = "") override;
  void RemoveAt(Int_t i);

  ClassDef(UEvent, 2);
};


#endif
