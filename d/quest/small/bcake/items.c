#include <ansi.h>
#include "items.h"


//write by summer
//modify by bird
		
int create_item(object owner)
{
	object me,it,it1;
	mixed* ifiles,ifiles2;
	int i,j,k;
	string prop;
	int level;
	me=this_object();
	j=random(sizeof(idirs));
	ifiles=get_dir(idirs[j]+"*.c",-1);
	if( !sizeof(ifiles) )             return 0;
	i=random(sizeof(ifiles));
	 if( ifiles[j][1] > 0 ) { 
	it = new(idirs[j]+ ifiles[i][0]);
	if(it)
	{     	        
	it->move(environment(me));
          tell_room(environment(me),me->name()+"����һ"+it->query("unit")+it->query("name")+"\n"); 
        MONITOR_D->report_system_object_msg(owner,"�õ�һ"+it->query("unit")+it->query("name")+"\n"); 
// 27        MONITOR_D->report_system_object_msg(me,"�õ�һ"+it->query("unit")+it->query("name")+"\n"); 
       log_file("users/BCAKE",
          owner->query("id") +" "+owner->name()+ " got "+it->query("unit")+"  "+it->query("name")+log_time()+"\n"); 
	 }
        }
        
}
