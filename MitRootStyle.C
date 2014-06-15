//--------------------------------------------------------------------------------------------------
// MitRootStyle
//
// This class implements MitRootStyle which defines most relevant plot properties to give a
// reasonable plot. Of course every plot needs fine tuning, which has to be done by hand, as needed.
//
// Authors: C.Paus
//--------------------------------------------------------------------------------------------------
#ifndef MITROOTSTYLE_H
#define MITROOTSTYLE_H

#include <TCanvas.h>
#include <TPad.h>
#include <TH1.h>
#include <TStyle.h>
#include <TText.h>

class MitRootStyle
{
public:
  MitRootStyle() { Init(); }
  
  static void     Init();
  static TCanvas* MakeCanvas  (const char* name, const char *title);
  static void     InitSubPad  (TPad *pad, int i);
  static void     InitHistWide(TH1 *h, const char *xtit, const char *ytit  = "Number of Entries",
                               EColor color = kBlack);
  static void     InitHist    (TH1 *h, const char *xtit, const char *ytit  = "Number of Entries",
                               EColor color = kBlack);
  static void     SetStyleWide();
  static void     SetStyle    ();
  static void     OverlayFrame(Double_t xMax=1.0, Double_t yMax=1.0);
  static void     AddText     (TString text, Double_t x=0.01, Double_t y=0.01);
};

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::Init()
{
  // Initialization with proper defaults is the start

  const char* author   = "$Author: paus $$";
  const char* modified = "$Modified: Wed Mar 19 00:19:30 2014 by paus $$";
  printf(" MIT root style (%s,%s).\n",author,modified);
  printf("\n");
  printf(" Use: MitRootStyle::MakeCanvas(name,title)\n");
  printf("      MitRootStyle::InitSubPad(pad,nPad)\n");
  printf("      MitRootStyle::InitHist(hist,xTitle,yTitle,color)\n");
  printf("\n");
  SetStyle();
}

//--------------------------------------------------------------------------------------------------
inline TCanvas* MitRootStyle::MakeCanvas(const char* name, const char *title)
{
  // Make a canvas with good initial settings

  TCanvas *canvas = new TCanvas(name,title);

  return canvas;
}

inline void MitRootStyle::InitSubPad(TPad* pad, int i)
{
  // Initializing a sub pad

  pad->cd(i);
  TPad *tmpPad = (TPad*) pad->GetPad(i);
  tmpPad->SetLeftMargin  (0.20);
  tmpPad->SetTopMargin   (0.05);
  tmpPad->SetRightMargin (0.07);
  tmpPad->SetBottomMargin(0.15);

  return;
}

inline void MitRootStyle::InitHistWide(TH1 *hist, const char *xtit, const char *ytit, EColor color)
{
  InitHist(hist,xtit,ytit,color);
  hist->SetTitleOffset(1.100,"Y");
}

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::InitHist(TH1 *hist, const char *xtit, const char *ytit, EColor color)
{
  // Initializing a histogram

  hist->SetTitle      ("");  
  hist->SetXTitle     (xtit);
  hist->SetYTitle     (ytit);

  hist->SetLineColor  (color);
  hist->SetLineWidth  (2.0);

  hist->SetMarkerStyle(20);
  hist->SetMarkerColor(color);
  hist->SetMarkerSize (0.6);

  hist->SetTitleFont  (42   ,"X");
  hist->SetTitleSize  (0.055,"X");
  hist->SetTitleOffset(1.100,"X");
  hist->SetLabelOffset(0.010,"X");
  hist->SetLabelSize  (0.050,"X");
  hist->SetLabelFont  (42   ,"X");
  hist->SetTickLength (-0.01,"X");

  hist->SetTitleFont  (42   ,"Y");
  hist->SetTitleSize  (0.055,"Y");
  hist->SetTitleOffset(1.700,"Y");
  hist->SetLabelOffset(0.010,"Y");
  hist->SetLabelSize  (0.050,"Y");
  hist->SetLabelFont  (42   ,"Y");
  hist->SetTickLength (-0.01,"Y");

  return;
}

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::SetStyleWide()
{
  SetStyle();
  TStyle *MitRootStyle = gStyle;
  MitRootStyle->SetCanvasDefW (1100);
  MitRootStyle->SetPadLeftMargin(0.12);
}

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::SetStyle()
{
  // Setting style parameters
  TStyle *MitRootStyle = gStyle;

  // Canvas
  MitRootStyle->SetCanvasColor     (0);
  MitRootStyle->SetCanvasBorderSize(10);
  MitRootStyle->SetCanvasBorderMode(0);
  MitRootStyle->SetCanvasDefH      (700);
  MitRootStyle->SetCanvasDefW      (700);
  MitRootStyle->SetCanvasDefX      (100);
  MitRootStyle->SetCanvasDefY      (100);

  // Pads
  MitRootStyle->SetPadColor       (0);
  MitRootStyle->SetPadBorderSize  (10);
  MitRootStyle->SetPadBorderMode  (0);
  MitRootStyle->SetPadBottomMargin(0.13);
  MitRootStyle->SetPadTopMargin   (0.04);
  MitRootStyle->SetPadLeftMargin  (0.18);
  MitRootStyle->SetPadRightMargin (0.04);
  MitRootStyle->SetPadGridX       (0);
  MitRootStyle->SetPadGridY       (0);
  MitRootStyle->SetPadTickX       (0);
  MitRootStyle->SetPadTickY       (0);

  // Frames
  MitRootStyle->SetFrameFillStyle ( 0);
  MitRootStyle->SetFrameFillColor ( 0);
  MitRootStyle->SetFrameLineColor ( 1);
  MitRootStyle->SetFrameLineStyle ( 0);
  MitRootStyle->SetFrameLineWidth ( 1);
  MitRootStyle->SetFrameBorderSize(10);
  MitRootStyle->SetFrameBorderMode( 0);

  // Histograms
  MitRootStyle->SetHistFillColor(2);
  MitRootStyle->SetHistFillStyle(0);
  MitRootStyle->SetHistLineColor(1);
  MitRootStyle->SetHistLineStyle(0);
  MitRootStyle->SetHistLineWidth(2);
  MitRootStyle->SetNdivisions(505);

  // Functions
  MitRootStyle->SetFuncColor(1);
  MitRootStyle->SetFuncStyle(0);
  MitRootStyle->SetFuncWidth(2);

  // Various
  MitRootStyle->SetMarkerStyle(20);
  MitRootStyle->SetMarkerColor(kBlack);
  MitRootStyle->SetMarkerSize (1.2);

  MitRootStyle->SetTitleSize  (0.055,"X");
  MitRootStyle->SetTitleOffset(1.200,"X");
  MitRootStyle->SetLabelOffset(0.005,"X");
  MitRootStyle->SetLabelSize  (0.050,"X");
  MitRootStyle->SetLabelFont  (42   ,"X");
  MitRootStyle->SetTickLength (-0.03,"X");

  MitRootStyle->SetStripDecimals(kFALSE);

  MitRootStyle->SetTitleSize  (0.055,"Y");
  MitRootStyle->SetTitleOffset(1.800,"Y");
  MitRootStyle->SetLabelOffset(0.010,"Y");
  MitRootStyle->SetLabelSize  (0.050,"Y");
  MitRootStyle->SetLabelFont  (42   ,"Y");
  MitRootStyle->SetTickLength (-0.03,"Y");

  MitRootStyle->SetTextSize   (0.055);
  MitRootStyle->SetTextFont   (42);

  MitRootStyle->SetStatFont   (42);
  MitRootStyle->SetTitleFont  (42);
  MitRootStyle->SetTitleFont  (42,"X");
  MitRootStyle->SetTitleFont  (42,"Y");

  MitRootStyle->SetOptStat    (0);

  return;
}

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::OverlayFrame(Double_t xMax, Double_t yMax)
{
  // Overlay a linear frame from user coordinates (0->xMax, 0->yMax) and put the frame text

  // create new transparent pad for the text
  TPad *transPad = new TPad("transPad","Transparent Pad",0,0,xMax,yMax);
  transPad->SetFillStyle(4000);
  transPad->Draw();
  transPad->cd();

  return;
}

//--------------------------------------------------------------------------------------------------
inline void MitRootStyle::AddText(TString text, Double_t x, Double_t y)
{
  // Add text with unified styles

  // overlay the text in a well defined frame
  TText *plotText = new TText(x,y,text.Data());
  plotText->SetTextSize(0.02);
  plotText->SetTextColor(kBlue);
  plotText->Draw();

  return;
}
#endif
