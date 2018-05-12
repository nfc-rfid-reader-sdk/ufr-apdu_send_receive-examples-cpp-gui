/***************************************************************
 * Name:      apdu_commandApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-05-12
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#include "apdu_commandApp.h"

//(*AppHeaders
#include "apdu_commandMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(apdu_commandApp);

bool apdu_commandApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	apdu_commandFrame* Frame = new apdu_commandFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
