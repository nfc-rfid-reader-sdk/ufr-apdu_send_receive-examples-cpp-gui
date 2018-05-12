/***************************************************************
 * Name:      apdu_commandMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2018-05-07
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef APDU_COMMANDMAIN_H
#define APDU_COMMANDMAIN_H

//(*Headers(apdu_commandFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class apdu_commandFrame: public wxFrame
{
    public:

        apdu_commandFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~apdu_commandFrame();

    private:

        //(*Handlers(apdu_commandFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnCommandText(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnButton3Click1(wxCommandEvent& event);
        void OnbReaderOpenClick(wxCommandEvent& event);
        void OnbReaderResetClick(wxCommandEvent& event);
        void OnbReaderCloseClick(wxCommandEvent& event);
        void OnbSetISOClick(wxCommandEvent& event);
        void OnbSendClick(wxCommandEvent& event);
        void OnbDeselectClick(wxCommandEvent& event);
        void OnbClearClick(wxCommandEvent& event);
        void OnButton2Click1(wxCommandEvent& event);
        //*)

        //(*Identifiers(apdu_commandFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON8;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON5;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(apdu_commandFrame)
        wxButton* Button2;
        wxButton* bClear;
        wxButton* bDeselect;
        wxButton* bReaderClose;
        wxButton* bReaderOpen;
        wxButton* bReaderReset;
        wxButton* bSend;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* Command;
        wxTextCtrl* Response;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // APDU_COMMANDMAIN_H
