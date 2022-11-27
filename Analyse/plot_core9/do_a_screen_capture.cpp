int do_a_screen_capture()
{
Bitmap MySnapshot( SCREEN_W, SCREEN_H);
MySnapshot.CopyFromScreen( 0, 0 );
MySnapshot.Save( "mysnapshot.png" );
 return(0);
}
