/*-------------------------------------------------------------------------------------------------------------
                                 |
          CWWWWWWWW              | Copyright (C) 2009-2016  Christoph Guillermet
       WWWWWWWWWWWWWWW           |
     WWWWWWWWWWWWWWWWWWW         | This file is part of White Cat.
    WWWWWWWWWWWWWWWWWCWWWW       |
   WWWWWWWWWWWWWWWWW tWWWWW      | White Cat is free software: you can redistribute it and/or modify
  WWWW   WWWWWWWWWW  tWWWWWW     | it under the terms of the GNU General Public License as published by
 WWWWWt              tWWWWWWa    | the Free Software Foundation, either version 2 of the License, or
 WWWWWW               WWWWWWW    | (at your option) any later version.
WWWWWWWW              WWWWWWW    |
WWWWWWWW               WWWWWWW   | White Cat is distributed in the hope that it will be useful,
WWWWWWW               WWWWWWWW   | but WITHOUT ANY WARRANTY; without even the implied warranty of
WWWWWWW      CWWW    W WWWWWWW   | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
WWWWWWW            aW  WWWWWWW   | GNU General Public License for more details.
WWWWWWWW           C  WWWWWWWW   |
 WWWWWWWW            CWWWWWWW    | You should have received a copy of the GNU General Public License
 WWWWWWWWW          WWWWWWWWW    | along with White Cat.  If not, see <http://www.gnu.org/licenses/>.
  WWWWWWWWWWC    CWWWWWWWWWW     |
   WWWWWWWWWWWWWWWWWWWWWWWW      |
    WWWWWWWWWWWWWWWWWWWWWW       |
      WWWWWWWWWWWWWWWWWWa        |
        WWWWWWWWWWWWWWW          |
           WWWWWWWWt             |
                                 |
---------------------------------------------------------------------------------------------------------------*/

/**

* \file whc_hk_connector.h
* \brief {header file for hotkeys service }
* \author Rui Serge Azevedo Brooks
* \version {1.0.0}
* \date {14/08/2016}

 White Cat - gui - keyboard - hotkeys

*   Variables et fonctions g�rant les liens entre hotkeys et fonctions � d�clencher
*   Fonctions de gestion d'initialisation, mises � jour sur demande de l'utilisateur
*
*
*/

#ifndef whc_hk_connector_H
#define whc_hk_connector_H

//Allegro
#include <allegro/keyboard.h>
//Container C compatible
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
// gestion de base de donn�es d�sactiv�e #include <sqlite3.h>
//
#include <./hotkey/whc_hk_input.h>
#include <./hotkey/whc_hk_apply.h>
// objet non termin� #include <whc_report.h>

#include <./toolbox/whc_toolbox.h>

class whc_hk_connector
{
    typedef void (*ptrMthd)(void);  // les fonctions � fournir pour la connection doivent �tre du type "void nom_fct ()"

public:
    int 						static c_nbr;
    std::vector<whc_hk_connector> 	static c_list;		/**<  liste de toutes les fonctions avec leurs hotkeys associ�es */
    std::vector<whc_hk_connector> 	static c_catlist;  	/**<  liste limit�e � la cat�gorie s�lectionn�e */
    std::vector <char*> 		static c_filter ;	/**<  liste des cat�gories - TODO : � initialiser � la lecture du fichier de d�claration des hotkeys */
    whc_hk_input 				static c_user_signature ; /**<  derni�re touche lue et interpr�t�e */
    whc_hk_apply 				static c_trigger_fired ; /**< fonction correspondant � la derni�re touche lue et interpr�t�e */

    bool 						static * c_ptr_inputIsOn; /**< (variable associ�e par r�f�rence de la variable externe) la zone de saisie texte est ouverte : elle est prioritaire */

//	objet non termin�	whc_report static c_report;

    /** Default constructor */
    whc_hk_connector();
    whc_hk_connector(whc_hk_apply fonctionality, whc_hk_input signature);
    /** Default destructor */
    virtual ~whc_hk_connector();

    whc_hk_apply fonctionality()
    {
        return m_fonctionality;
    }
    void Setfonctionality(const whc_hk_apply &val)
    {
        m_fonctionality = val;
    }

    whc_hk_input signature()
    {
        return m_signature;
    }
    void Setsignature(const whc_hk_input &val)
    {
        m_signature = val;
    }

    static whc_hk_input user_signature()
    {
        return c_user_signature;
    }
    static void Setuser_signature(const whc_hk_input &val)
    {
        c_user_signature = val;
    }
    static int user_hasSelectThisFunc()
    {
        return c_hk_user_hasSelect_applyId;
    }

    //static std::string last_hk_wording() ; //{c_user_signature.wording();}
	static void changeDescription(whc_hk_connector * ptr_hk_manage, std::string newdescription );
	static int filterIdx(){return c_filter_idx;}
	static void setfilterIdx(int val){c_filter_idx=val;}

    static void reset_user_choice()
    {
        c_hk_user_hasSelect_applyId=0;
    }

    static bool waiting_user_confirmation_on_a_choice ()
    {
        return c_hk_user_hasToConfirmChoice;
    }

    static whc_hk_apply user_conflictfunc()
    {
        return c_user_other_func_allready_link_to_hotkey;
    }

    std::string current_choice_fct_description ()
    {
        if (c_hk_user_hasSelect_applyId >0)
        {
            return this->c_list[this->user_hasSelectThisFunc()-1].fonctionality().description();
        }
        else
        {
            return " ## none ##";
        }
    }

    std::string current_choice_fct_accessible_with ()
    {
        if (c_hk_user_hasSelect_applyId >0)
        {
            return this->c_list[this->user_hasSelectThisFunc()-1].signature().wording();
        }
        else
        {
            return " ## unset ##";
        }

    }

    static std::string other_func_allready_link_to_hotkey()
    {
        return c_user_other_func_allready_link_to_hotkey.description();
    }

    static bool hk_user_update_isOn()
    {
        return c_hk_user_update_isOn ;
    }

    static bool hk_user_madeChanges()
    {
        return c_hk_user_madeChanges;
    }

    static void user_redefine_hk_link_init();

    static void link_keyFocusIndicator(bool * ptr_val)
    {
        c_ptr_inputIsOn = ptr_val ;
    }
    // c_ptr_inputIsOn devient "synonyme" de la variable pass�e par r�f�rence : elles lisent et modifient le m�me contenu m�moire

    int collect();
    void user_start_update_link(int val);

    void updateFilter();

    int shortcutprocess(int isreadkey);
    whc_hk_apply search_fct(whc_hk_input signature);
    static bool hk_service_isInit()
    {
        return c_hk_service_isInit;
    }
    void init(std::string fic_name);
    void load(std::string fic_name);
    void save(std::string fic_name);
    void connect_fct(int fctid, ptrMthd fctptr);
    void link_fct_hk(int fctid, whc_hk_input signature);
    void replace_link_fct_hk();

    void load_db(std::string fic_name);
    static int read_db_row(void *NotUsed, int argc, char **argv, char **azColName);

protected:
private:
    whc_hk_apply m_fonctionality ;
    whc_hk_input m_signature ;
//static = (une seule fois ne m�moire) en commun � toutes les instances (objets) de hotkey - idem pour les fonctions static aussi bien priv�, public etc.
    whc_hk_apply static c_user_other_func_allready_link_to_hotkey ; // in case of conflict for a signature
    bool static c_hk_service_isInit;
    bool static c_hk_user_madeChanges;
    bool static c_hk_user_update_isOn ; // on lit pour mettre � jour un lien : ne rien d�clencher en attendant confirmation ou ESC
    bool static c_hk_user_hasToConfirmChoice ; // on demande confirmation, si signature d�j� attribu�e � une autre fonction
    int static c_hk_user_hasSelect_applyId ; // fonctionality->id() = l'utilisateur a s�lectionn� une fonction pour lui associer une nouvelle hotkey
    int static c_filter_idx;
    int static c_nbr_category ;
};

#endif // whc_hk_connector_H
