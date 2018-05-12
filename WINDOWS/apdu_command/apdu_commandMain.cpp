/***************************************************************
 * Name:      apdu_commandMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2018-05-07
 * Copyright:  ()
 * License:
 **************************************************************/

#include "apdu_commandMain.h"
#include <wx/msgdlg.h>
#include "lib/include/uFCoder.h"
#include <string>
#include <sstream>
#include <string.h>
#include <cstring>
using namespace std;
//(*InternalHeaders(apdu_commandFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(apdu_commandFrame)
const long apdu_commandFrame::ID_BUTTON1 = wxNewId();
const long apdu_commandFrame::ID_BUTTON2 = wxNewId();
const long apdu_commandFrame::ID_BUTTON3 = wxNewId();
const long apdu_commandFrame::ID_BUTTON8 = wxNewId();
const long apdu_commandFrame::ID_STATICTEXT1 = wxNewId();
const long apdu_commandFrame::ID_BUTTON5 = wxNewId();
const long apdu_commandFrame::ID_TEXTCTRL1 = wxNewId();
const long apdu_commandFrame::ID_TEXTCTRL2 = wxNewId();
const long apdu_commandFrame::ID_BUTTON6 = wxNewId();
const long apdu_commandFrame::ID_BUTTON7 = wxNewId();
const long apdu_commandFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(apdu_commandFrame,wxFrame)
    //(*EventTable(apdu_commandFrame)
    //*)
END_EVENT_TABLE()

apdu_commandFrame::apdu_commandFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(apdu_commandFrame)
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1 = new wxGridSizer(2, 1, wxDLG_UNIT(this,wxSize(-185,0)).GetWidth(), 0);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, wxEmptyString);
    bReaderOpen = new wxButton(this, ID_BUTTON1, _("ReaderOpen"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticBoxSizer1->Add(bReaderOpen, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bReaderReset = new wxButton(this, ID_BUTTON2, _("ReaderReset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticBoxSizer1->Add(bReaderReset, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    bReaderClose = new wxButton(this, ID_BUTTON3, _("ReaderClose"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    StaticBoxSizer1->Add(bReaderClose, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer2 = new wxGridSizer(5, 3, -150, -610);
    GridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON8, _("SetISO14443_4_Mode"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    GridSizer2->Add(Button2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Command :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    bSend = new wxButton(this, ID_BUTTON5, _("Send"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    GridSizer2->Add(bSend, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Command = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(450,-1), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridSizer2->Add(Command, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP|wxSHAPED, 5);
    Response = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(700,200), wxTE_MULTILINE|wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridSizer2->Add(Response, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    GridSizer2->Add(-1,-1,1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2->Add(-1,-1,1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    bDeselect = new wxButton(this, ID_BUTTON6, _("s_block_deselect"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    GridSizer2->Add(bDeselect, 1, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
    bClear = new wxButton(this, ID_BUTTON7, _("Clear"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
    GridSizer2->Add(bClear, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    GridSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
    SetSizer(GridSizer1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridSizer1->Fit(this);
    GridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbReaderOpenClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbReaderResetClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbReaderCloseClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnButton2Click1);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbSendClick);
    //Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&apdu_commandFrame::OnCommandText);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbDeselectClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&apdu_commandFrame::OnbClearClick);
    //*)
}

apdu_commandFrame::~apdu_commandFrame()
{
    //(*Destroy(apdu_commandFrame)
    //*)
}

void apdu_commandFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void apdu_commandFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void apdu_commandFrame::OnbReaderOpenClick(wxCommandEvent& event)
{

    ReaderOpen();

    ReaderUISignal(1,1);

}

void apdu_commandFrame::OnbReaderResetClick(wxCommandEvent& event)
{

    ReaderReset();

    ReaderUISignal(1,1);
}

void apdu_commandFrame::OnbReaderCloseClick(wxCommandEvent& event)
{

    ReaderClose();

}

void apdu_commandFrame::OnbSendClick(wxCommandEvent& event)
{


    UFR_STATUS status;

    wxString wxc_apduStr = Command -> GetValue();

    string c_apduStr;

    c_apduStr = string(wxc_apduStr.mb_str());

    char *c_apdu;

    c_apdu = (char *)malloc(266);

    strcpy(c_apdu, c_apduStr.c_str());

    char *r_apdu = NULL;

    r_apdu = (char *)malloc(266);

    status = APDUHexStrTransceive(c_apdu, &r_apdu);

    wxString response = (char *)r_apdu;

    int position = strlen(r_apdu) - 4;

    wxString sw_stream;

    sw_stream << r_apdu[position] << r_apdu[position+1] << r_apdu[position+2] << r_apdu[position+3];

    response = response.substr(0, response.length()-4);

    wxString resp_length_str = "";
    uint32_t resp_len = response.length()/2;
    resp_length_str << resp_len;

    if(status != UFR_OK){

        Response -> SetValue("Error");

    }else{

        Response -> SetValue("Response -> " + response + "\n\nLength -> " + resp_length_str + "\n\nSw -> " + sw_stream);

    }

    free(c_apdu);
    free(r_apdu);



}

void apdu_commandFrame::OnbDeselectClick(wxCommandEvent& event)
{

     s_block_deselect(100);
}

void apdu_commandFrame::OnbClearClick(wxCommandEvent& event){

 Response -> SetValue("");

}

void apdu_commandFrame::OnButton2Click1(wxCommandEvent& event)
{
        UFR_STATUS status;
    wxString Status = "";

    status = SetISO14443_4_Mode();

    Status = UFR_Status2String(status);

    wxString msg = "Error while trying to set ISO mode, status is \n" + Status;

    if(status != UFR_OK){

         wxMessageBox(msg, _("ERROR"));

    }


}
