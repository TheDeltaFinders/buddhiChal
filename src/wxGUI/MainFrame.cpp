/***************************************************************
 * Purpose:   Code for Application Frame
 * Author:    Prakash Gautam (pranphy@gmail.com)
 * Copyright: Prakash Gautam (http://pranphy.com/)
 * License:
 **************************************************************/

#include <wx/msgdlg.h>

//(*InternalHeaders(MainFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include "wxGUI/MainFrame.h"

//(*IdInit(MainFrame)
const long MainFrame::ID_ChessPanel = wxNewId();
const long MainFrame::ID_PlayerNameSText = wxNewId();
const long MainFrame::ID_TEXTCTRL1 = wxNewId();
const long MainFrame::ID_STATICTEXT1 = wxNewId();
const long MainFrame::ID_COMBOBOX1 = wxNewId();
const long MainFrame::ID_STATICTEXT2 = wxNewId();
const long MainFrame::ID_TEXTCTRL2 = wxNewId();
const long MainFrame::ID_PANEL2 = wxNewId();
const long MainFrame::ID_AboutHelpSubItem = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainFrame,wxFrame)
    //(*EventTable(MainFrame)
    //*)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,wxWindowID id)
{

    //(*Initialize(MainFrame)
    Create(parent, id, _("Welcome Chess 15.04.0.2"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,439));
    SetMinSize(wxSize(400,300));
    BaseAManager = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    ChessPanel = new wxPanel(this, ID_ChessPanel, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_ChessPanel"));
    OutermostGBSizer = new wxGridBagSizer(0, 0);
    OutermostGBSizer->AddGrowableCol(0);
    OutermostGBSizer->AddGrowableCol(1);
    OutermostGBSizer->AddGrowableRow(0);
    OutermostGBSizer->AddGrowableRow(1);
    ChessSBSizer = new wxStaticBoxSizer(wxHORIZONTAL, ChessPanel, _("Move Cards"));
    OutermostGBSizer->Add(ChessSBSizer, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ChessPanel->SetSizer(OutermostGBSizer);
    OutermostGBSizer->Fit(ChessPanel);
    OutermostGBSizer->SetSizeHints(ChessPanel);
    BaseAManager->AddPane(ChessPanel, wxAuiPaneInfo().Name(_T("PaneName")).CenterPane().Caption(_("Chess Play Area")).CaptionVisible().Row(1));
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetMinSize(wxSize(180,0));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Controls"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    PlayerNameSText = new wxStaticText(Panel2, ID_PlayerNameSText, _("Player Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_PlayerNameSText"));
    FlexGridSizer1->Add(PlayerNameSText, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(Panel2, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel2, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox1 = new wxComboBox(Panel2, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(70,27), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    FlexGridSizer1->Add(ComboBox1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel2, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(StaticBoxSizer1);
    StaticBoxSizer1->Fit(Panel2);
    StaticBoxSizer1->SetSizeHints(Panel2);
    BaseAManager->AddPane(Panel2, wxAuiPaneInfo().Name(_T("PaneName")).DefaultPane().Caption(_("Chess Controls")).CaptionVisible().Position(-2).Left().MinSize(wxSize(180,0)));
    BaseAManager->Update();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_AboutHelpSubItem, _("About\tCtrl+H"), _("Show details of this application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("Help"));
    SetMenuBar(MenuBar1);
    //*)


    ChessObject= new ChessCanvas(ChessPanel);

    ChessSBSizer->Add(ChessObject,1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL,5);
    ChessObject->Initialize();
}

MainFrame::~MainFrame()
{
}

void MainFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxT("This is a message ");
    wxMessageBox(msg, _("Welcome to..."));
}



