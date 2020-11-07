// Copyright 2020 Frédéric Wang. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "wx/webview.h"

const char* default_url = "https://aecs.webnode.fr/_files/200000239-8411584117/deco-halloween.jpg";

class Frame : public wxFrame {
public:
  Frame();
private:
  void OnExit(wxCommandEvent& event);
  wxWebView* m_browser;
};

Frame::Frame()
  : wxFrame(NULL, wxID_ANY, "Mon Application") {
  // Create File menu.
  wxMenu* menuFile = new wxMenu;
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  Bind(wxEVT_MENU, &Frame::OnExit, this, wxID_EXIT);

  // Create menu bar.
  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&Fichier");
  SetMenuBar(menuBar);

  // Create status bar.
  CreateStatusBar();
  SetStatusText("Bienvenue !");

  // Create WebView
  wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);
  m_browser = wxWebView::New(this, wxID_ANY, default_url);
  topsizer->Add(m_browser, wxSizerFlags().Expand().Proportion(1));
  SetSizer(topsizer);

  // Set the windows size.
  SetSize(wxSize(800, 600));
}

void Frame::OnExit(wxCommandEvent& event) {
  Close(true);
}

class Application : public wxApp {
public:
  virtual bool OnInit();
};

wxIMPLEMENT_APP(Application);

bool Application::OnInit() {
  Frame *frame = new Frame;
  frame->Show(true);
  return true;
}
