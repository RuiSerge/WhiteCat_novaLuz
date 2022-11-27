int window_bring_to_front(int num_window)
{
int temp_window[64];
for(int i=0;i<63;i++)
{
temp_window[i]=window_opened[i];
}
int pos=1;
for(int i=0;i<63;i++)
{
if(temp_window[i]>=900 && temp_window[i]!=num_window)
{
 window_opened[pos]=temp_window[i];
 pos++;
}
else{window_opened[pos]=0;}//enlevage des doublons

if( window_opened[pos]==num_window)   {window_opened[pos]=0;}//enlevement des doublons sur vauban
}
window_opened[0]=num_window;
window_focus_id=num_window;
return(num_window);
}
