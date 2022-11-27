END_OF_FUNCTION(ticker_artnet);
{
   doom.Load( "Fonts/doom.ttf",25,25, CouleurLigne );
   if( !doom )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }
   doomblanc.Load( "Fonts/doom.ttf",20,20, CouleurLigne);
   if( !doomblanc )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }
   doomrouge.Load( "Fonts/doom.ttf",25,25, CouleurBlind);
   if( !doomrouge )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }
   petitdoomblanc.Load( "Fonts/doom.ttf",18,18, CouleurLigne);
   if( !doomrouge )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }
   petitdoomInspekt.Load( "Fonts/doom.ttf",10,10, CouleurFader );
   if( !petitdoomInspekt )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }

   petitdoomrouge.Load( "Fonts/doom.ttf",10,10, CouleurBlind );
   if( !petitdoomrouge )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }

   minidoomblanc.Load( "Fonts/doom.ttf",8,8, CouleurLigne );
   if( !minidoomblanc )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }

   axaxax12.Load( "Fonts/axaxax.ttf",12,12, CouleurLigne );
   if( !axaxax12 )
   {  allegro_message( "Couldn't load Fonts/doom.ttf!" );
      exit( -1 );
   }


   neuro.Load( "Fonts/prototype.ttf",20,20, CouleurLigne );
   if( !neuro )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
    neuromoyen.Load( "Fonts/prototype.ttf",14,14, CouleurLigne );
   if( !neuromoyen )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   petitchiffre.Load( "Fonts/prototype.ttf",12,12, CouleurLigne );
   if( !petitchiffre )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   petitpetitchiffre.Load( "Fonts/prototype.ttf",10,10, CouleurLigne );
   if( !petitpetitchiffre )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   minichiffre.Load( "Fonts/prototype.ttf",8,8, CouleurLigne );
   if( !minichiffre )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
    petitpetitchiffregris.Load( "Fonts/prototype.ttf",9,9, CouleurLigne.WithAlpha(0.7) );
   if( !petitpetitchiffre )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   minichiffregris.Load( "Fonts/prototype.ttf",8,8, CouleurLigne.WithAlpha(0.7) );
   if( !minichiffre )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
    minichiffrenoir.Load( "Fonts/prototype.ttf",8,8, CouleurNoir );
   if( !minichiffrenoir )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
    petitpetitchiffrerouge.Load( "Fonts/prototype.ttf",10,10, CouleurBlind );
   if( !petitpetitchiffrerouge )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   petitchiffrerouge.Load( "Fonts/prototype.ttf",12,12, CouleurBlind );
   if( !petitchiffrerouge)
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
    minichiffrerouge.Load( "Fonts/prototype.ttf",8,8, CouleurBlind );
   if( !minichiffrerouge )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   petitchiffrenoir.Load( "Fonts/prototype.ttf",12,12, CouleurFond );
   if( !petitchiffrenoir )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   circuitlevel.Load( "Fonts/prototype.ttf",10,10, CouleurLevel);
   if( !circuitlevel )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   circuitfaderlevel.Load( "Fonts/prototype.ttf",10,10, CouleurFader);
   if( !circuitfaderlevel )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   circuitblindlevel.Load( "Fonts/prototype.ttf",10,10, CouleurBlind);
   if( !circuitblindlevel )
   {  allegro_message( "Couldn't load Fonts/prototype.ttf!" );
      exit( -1 );
   }
   neuroTitle.Load( "Fonts/neuropol.ttf",70,70, CouleurLigne);
   if( !neuroTitle )
   {  allegro_message( "Couldn't load Fonts/neuropol.ttf!" );
      exit( -1 );
   }


}
