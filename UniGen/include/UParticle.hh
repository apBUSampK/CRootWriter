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

#ifndef UPARTICLE_H
#define UPARTICLE_H

#include "TObject.h"
#include "TLorentzVector.h"
#include "TMath.h"

class TParticle;


class UParticle : public TObject {

 private:
  Int_t f_index_;         // index of this particle
  Int_t f_pdg_;           // PDG code
  Int_t f_status_;        // Status
  Int_t f_parent_;        // Index of parent
  Int_t f_parent_decay_;  // Parent decay index
  Int_t f_mate_;          // index of last collision partner
  Int_t f_decay_;         // decay index (-1 if not decayed)
  Int_t f_child_[2];      // index of first and last child
  Double32_t f_px_;       // px (GeV)
  Double32_t f_py_;       // py (GeV)
  Double32_t f_pz_;       // pz (GeV)
  Double32_t f_e_;        // Energy (GeV)
  Double32_t f_x_;        // x (fm)
  Double32_t f_y_;        // y (fm)
  Double32_t f_z_;        // z (fm)
  Double32_t f_t_;        // t (fm)
  Double32_t f_weight_;   // weight

 public:
  UParticle();
  UParticle(Int_t index, Int_t pdg, Int_t status, Int_t parent, Int_t parent_decay, Int_t mate, Int_t decay,
            Int_t child[2], Double_t px, Double_t py, Double_t pz, Double_t e, Double_t x, Double_t y, Double_t z,
            Double_t t, Double_t weight);
  UParticle(Int_t index, Int_t pdg, Int_t status, Int_t parent, Int_t parent_decay, Int_t mate, Int_t decay,
            Int_t child[2], TLorentzVector mom, TLorentzVector pos, Double_t weight);
  UParticle(const UParticle& right);
  explicit UParticle(const TParticle& right);
  ~UParticle() override;
  const UParticle& operator =  (const UParticle& right);
  const UParticle& operator =  (const TParticle& right);
  const Bool_t     operator == (const UParticle& right) const;
  void Print(Option_t* option = "") const override;
  Int_t GetIndex() const { return f_index_; }
  Int_t GetPdg() const { return f_pdg_; }
  Int_t GetStatus() const { return f_status_; }
  Int_t GetParent() const { return f_parent_; }
  Int_t GetParentDecay() const { return f_parent_decay_; }
  Int_t GetMate() const { return f_mate_; }
  Int_t GetDecay() const { return f_decay_; }
  Int_t GetFirstChild() const { return f_child_[0]; }
  Int_t GetLastChild() const { return f_child_[1]; }
  Double_t Px() const { return f_px_; }
  Double_t Py() const { return f_py_; }
  Double_t Pz() const { return f_pz_; }
  Double_t E() const { return f_e_; }
  TLorentzVector GetMomentum() const { return TLorentzVector(f_px_, f_py_, f_pz_, f_e_); }
  void Momentum(TLorentzVector& mom) const { mom.SetPxPyPzE(f_px_, f_py_, f_pz_, f_e_); }
  Double_t X() const { return f_x_; }
  Double_t Y() const { return f_y_; }
  Double_t Z() const { return f_z_; }
  Double_t T() const { return f_t_; }
  TLorentzVector GetPosition() const { return TLorentzVector(f_x_, f_y_, f_z_, f_t_); }
  void Position(TLorentzVector& pos) const { pos.SetXYZT(f_x_, f_y_, f_z_, f_t_); }
  Double_t GetWeight() const { return f_weight_; }
  void SetIndex(Int_t index) { f_index_ = index; }
  void SetPdg(Int_t pdg) { f_pdg_ = pdg; }
  void SetStatus(Int_t status) { f_status_ = status; }
  void SetParent(Int_t parent) { f_parent_ = parent; }
  void SetParentDecay(Int_t parent_decay) { f_parent_decay_ = parent_decay; }
  void SetMate(Int_t mate) { f_mate_ = mate; }
  void SetDecay(Int_t decay) { f_decay_ = decay; }
  void SetChild(const Int_t child[2]) {
    f_child_[0] = child[0];
    f_child_[1] = child[1];
  }
  void SetFirstChild(Int_t child) { f_child_[0] = child; }
  void SetLastChild(Int_t child) { f_child_[1] = child; }
  void SetPx(Double_t px) { f_px_ = px; }
  void SetPy(Double_t py) { f_py_ = py; }
  void SetPz(Double_t pz) { f_pz_ = pz; }
  void SetE(Double_t e) { f_e_ = e; }
  void SetMomentum(Double_t px, Double_t py, Double_t pz, Double_t e) {
    f_px_ = px;
    f_py_ = py;
    f_pz_ = pz;
    f_e_ = e;
  }
  void SetMomentum(const TLorentzVector& mom) {
    f_px_ = mom.Px();
    f_py_ = mom.Py();
    f_pz_ = mom.Pz();
    f_e_ = mom.E();
  }
  void SetX(Double_t x) { f_x_ = x; }
  void SetY(Double_t y) { f_y_ = y; }
  void SetZ(Double_t z) { f_z_ = z; }
  void SetT(Double_t t) { f_t_ = t; }
  void SetPosition(Double_t x, Double_t y, Double_t z, Double_t t) {
    f_x_ = x;
    f_y_ = y;
    f_z_ = z;
    f_t_ = t;
  }
  void SetPosition(const TLorentzVector& pos) {
    f_x_ = pos.X();
    f_y_ = pos.Y();
    f_z_ = pos.Z();
    f_t_ = pos.T();
  }
  void SetWeight(Double_t weight) { f_weight_ = weight; }

  ClassDef(UParticle, 1);
};


#endif
