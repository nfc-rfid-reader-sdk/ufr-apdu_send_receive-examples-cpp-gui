/***************************************************************
 * Name:      apdu_commandApp.h
 * Purpose:   Defines Application Class
 * Author:    Aleksandar Krstic (aleksandar.krstic@d-logic.rs)
 * Created:   2018-05-12
 * Copyright: Aleksandar Krstic (www.d-logic.net)
 * License:
 **************************************************************/

#ifndef APDU_COMMANDAPP_H
#define APDU_COMMANDAPP_H

#include <wx/app.h>

class apdu_commandApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // APDU_COMMANDAPP_H
