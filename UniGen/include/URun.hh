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

#ifndef URUN_H
#define URUN_H

#include "TNamed.h"
#include "TString.h"

#include <utility>

class URun : public TNamed {

 private:
  TString f_generator_;   // Generator description
  TString f_comment_;     // Run comment
  TString f_decayer_;     // Decayer description
  Int_t f_a_proj_;        // Projectile mass number
  Int_t f_z_proj_;        // Projectile charge
  Double32_t f_p_proj_;   // Projectile momentum per nucleon (GeV)
  Int_t f_a_targ_;        // Target mass number
  Int_t f_z_targ_;        // Target charge
  Double32_t f_p_targ_;   // Target momentum per nucleon (GeV)
  Double32_t f_b_min_;    // Minimum impact parameter
  Double32_t f_b_max_;    // Maximum impact parameter
  Int_t f_b_weight_;      // Impact parameter weighting
                          // 0 for geometrical weights (bdb)
                          // 1 for flat distribution
  Double32_t f_phi_min_;  // Event plane minimum angle (rad)
  Double32_t f_phi_max_;  // Event plane maximum angle (rad)
  Double32_t f_sigma_;    // Cross-section (mb)
  Int_t f_n_events_;      // Requested number of events

 public:
  URun();
  URun(const char* generator, const char* comment, Int_t a_proj, Int_t z_proj, Double_t p_proj, Int_t a_targ,
       Int_t z_targ, Double_t p_targ, Double_t b_min, Double_t b_max, Int_t b_weight, Double_t phi_min,
       Double_t phi_max, Double_t sigma, Int_t n_events);
  ~URun() override;
  void Print(Option_t* option = "") const override;
  void GetGenerator(TString& generator) { generator = f_generator_; }
  void GetComment(TString& comment) { comment = f_comment_; }
  void GetDecayer(TString& decayer) { decayer = f_decayer_; }
  Int_t GetAProj() const { return f_a_proj_; }
  Int_t GetZProj() const { return f_z_proj_; }
  Double_t GetPProj() const { return f_p_proj_; }
  Int_t GetATarg() const { return f_a_targ_; }
  Int_t GetZTarg() const { return f_z_targ_; }
  Double_t GetPTarg() const { return f_p_targ_; }
  Double_t GetBMin() const { return f_b_min_; }
  Double_t GetBMax() const { return f_b_max_; }
  Int_t GetBWeight() const { return f_b_weight_; }
  Double_t GetPhiMax() const { return f_phi_max_; }
  Double_t GetPhiMin() const { return f_phi_min_; }
  Double_t GetSigma() const { return f_sigma_; }
  Int_t GetNEvents() const { return f_n_events_; }
  Double_t    GetSqrtS();
  Double_t    GetNNSqrtS();
  Double_t    GetProjectileEnergy();
  Double_t    GetTargetEnergy();
  Double_t    GetBetaCM();
  Double_t    GetGammaCM();
  void SetNEvents(Int_t n_events) { f_n_events_ = n_events; }
  void SetPProj(Double_t p_proj) { f_p_proj_ = p_proj; }
  void SetPTarg(Double_t p_targ) { f_p_targ_ = p_targ; }
  void SetDecayer(TString decayer) { f_decayer_ = std::move(decayer); }

  ClassDef(URun,1);
};


#endif
