// mofengd.c
// writed for sanjie-lib 12-20-2002,stey


#include <ansi.h>


inherit F_DBASE;


int total=0;
int start=123;
string *player_list=({});
mapping record_data = ([]);

void clear_all();
void start_mofeng();
void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "ħ����");
        CHANNEL_D->do_channel( this_object(), "sys", "ħ�����Ѿ�������\n"NOR);
        set_heart_beat(30);
}
private void heart_beat()
{
	mixed *local;
	
	local = localtime(time());
        if(local[2]==6 && local[1] > 45)
        clear_all();
        if(local[2]==19 && local[1]> 45)
        start_mofeng();

}

void start_mofeng()
{
   start=888;
   //call_out("soundss",1);
}

void clear_all()
{
	total=0;
        player_list=({});
        record_data = ([]);
        start=123;
	
}
void add_player_list(object who)
{
	if (!userp(who)) return;
	if (start==123) 
	{
	tell_object(who,"ħ�����ѪѨδ�����ȵ������ˣ�\n");
		return ;
	}
	if(member_array(who->query("id"),player_list)==-1)
	{
       if(sizeof(player_list) > 20 )
	{
		tell_object(who,"�μ�����̫���ˣ�\n");
		return ;
	}
	player_list +=({ who->query("id") });
                    tell_object(who,"ħ������ħʢ�У�ȫ���������ˣ�\n");
	}
	who->set_temp("allow_tudi",1);
        
                     tell_object(who,"��ౣ�أ�\n");
}

void record_damage(object obj,string killer,int ratio,int type)
{
	string name;
	mapping killer_record;
        killer_record=([]);
	name=obj->query("name");
	
	if(member_array(killer,player_list)==-1) return;
	if(undefinedp(record_data[name]))
	 {
	 	killer_record[killer]=ratio* type;
	        record_data[name]=killer_record;
	        return;
	 }
	
	killer_record=record_data[name];
	 
	if(undefinedp(killer_record[killer]))
	{ 
		killer_record[killer]=ratio* type;
	        record_data[name]=killer_record;
	        return;
	}
	
	killer_record[killer]+=ratio* type;
	total +=ratio* type;
	record_data[name]=killer_record;
	return;
}

int get_bouns(string killer)
{
	string *list;
	int i,ra,bouns;
	mapping killer_record;
	
	ra=0;
       list=keys(record_data);

	for(i=0;i<sizeof(list);i++)
	{
                killer_record=([]);
                killer_record=record_data[list[i]];
                if(undefinedp(killer_record[killer])) continue;

                ra +=killer_record[killer];
	}

        bouns=(ra*1000)/total;
        return bouns;         
}	
	 	
void total_reward()
{
	object who;
	string msg;
	int i,bouns,exp;
	
	for(i=0;i<sizeof(player_list);i++)
	{
		if(!find_player(player_list[i])) continue;
		
		if((bouns=get_bouns(player_list[i])) < 2) continue;
		
		who=find_player(player_list[i]);
		
		
		
		exp=bouns*100;
		who->add("combat_exp",exp);
		tell_object(who,"��õ���"+ exp + " ��ѧ��\n");
		CHANNEL_D->do_channel( this_object(), "sys",  sprintf(who->name()+"�õ�" + exp + " ��ѧ��"));
	}
}
