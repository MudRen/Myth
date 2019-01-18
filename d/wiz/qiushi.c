// qiushi.c ���������ͷ�����ƻ����ɵ�
//player prison
//idea@yqyl

#include <ansi.h>
void takeout(object who);

inherit ROOM;

void wizchannel(string result);

void create()
{
        set("short",HIW"����"NOR);
        set("long", @LONG

������ר��������Ѻ������å�ĵط������������ֻ������ʵʵ
�Ĵ��š����ܺ������һƬ����ĿԶ���Կ������κ����£��
����ȴ�������κ����졣

LONG );
	set("objects", ([
// 23                  __DIR__"npc/yuzu":1
	]) );
	set("no_fight", 1);
	set("no_magic",1);
	set("no_kill",1);
        set("no_move",1);

        set("valid_startroom", 1);
        set("alternative_unc",1);
        set("channel_id", "����");
        set("name", "����");
        set("id", "qiushi");
        setup();

  call_other("/obj/board/heiban_b", "???");

        remove_call_out("check_in");
        call_out("check_in",60);
}


void init()
{
        object me;
        int mudage;
        string ttime,temp;
        
        me = this_player();
	if (userp(me))
        if( !wizardp(me) )
        {
        	if (me->query("startroom")!="/d/wiz/qiushi")
        	{
        	ttime=ctime(time())[8..strlen(ctime(time()))];

        	me->add("qiushi/times",1);
		me->add("qiushi/totaltime",me->query("qiushi/howlong"));
		me->set("qiushi/inage",me->query("mud_age"));
        	me->set("startroom","/d/wiz/qiushi");
        	temp = me->query("qiushi/temp");
        	me->delete("qiushi/temp");
        	if (temp) {
        	me->set("qiushi/note",ttime+"  "+temp);}
        	else { me->set("qiushi/note",sprintf("%s  %s(%s)�������ң�ԭ���ꡣ\n",
        		ttime,me->query("name"),me->query("id")));
        		}
        	
        	me->save();
        	
        	wizchannel(me->query("qiushi/note"));
                log_file("qiushi",me->query("qiushi/note"));
        	}
		add_action("block_cmd","",1);  

        	message("vision",
        	HIY "ֻ�����ſ��һ�죬һ���һﱻ���˽�����\n\n" NOR, environment(me), me);
        	tell_object( me, HIR "��Ϊ���������Ϊ�Ա�MUD����˲���Ӱ�죬"
        		+"���Թ������������ú÷�ʡ��ʡ��\n\n" NOR);
        }
        
}

int block_cmd1()
{
	string verb = query_verb();
	if (verb=="quit") return 0;
	tell_object( this_player(),"\n\n�Բ������ܵ�����������������������ֻ���������Σ������˳�" NOR);
	return 1;
}

int block_cmd()
{
  	string verb = query_verb();
  	if (verb=="say") return 0; 
  	if (verb=="help") return 0;
  	if (verb=="who") return 0;
  	if (verb=="look") return 0;
  	if (verb=="quit") return 0;
  	if (verb=="skills") return 0;
        if (verb=="score") return 0;
        if (verb=="give") return 0;
        if (verb=="eat") return 0;
  	if (verb=="hp") return 0;
  	tell_object( this_player(),"Ȱ�㻹�Ǿ�˼����ɣ���Ҫ�ٶ�ʲô�������ˣ���������ʲô�������ˣ�\n\n" NOR);
  	return 1;
}

void check_in()
{
	object *criminal = all_inventory(this_object()),yuzu;
	int i,howlong,inage,mudage;
	string cname,result,old,ttime;
	
	remove_call_out("check_in");

	for(i=0; i<sizeof(criminal); i++)
	{
		if (userp(criminal[i]) && !wizardp (criminal[i]))
		{	
                        if (criminal[i]->query("kee")<150 || criminal[i]->query("sen")<150)
                         {
                                tell_object(criminal[i],"����ȵ��ɹŴ�����ˣ��ɹŴ���ó���Ƥ��ҩӲ���������һ����\n��о��������ˣ��赹�ڵ�!\n");
                      criminal[i]->set("kee",criminal[i]->query("max_kee")/3);
                      criminal[i]->set("sen",criminal[i]->query("max_sen")/3);
                      criminal[i]->set("eff_sen",criminal[i]->query("max_sen")/3);
                      criminal[i]->set("eff_kee",criminal[i]->query("max_kee")/3);
                  }
			if (criminal[i]->query("food")<50 || criminal[i]->query("water")<50)
			{
				tell_object(criminal[i],"������ԳԷ��ˣ���������һ��ʣ����"+
					"�������̻��ʵĸɹ��ˡ�\n");
				criminal[i]->set("food",150);
				criminal[i]->set("water",150);
			}
			
			howlong = criminal[i]->query("qiushi/howlong");
			inage = criminal[i]->query("qiushi/inage");
			mudage = criminal[i]->query("mud_age");
			
			if (howlong)
			{
				if( (inage+howlong*60)<mudage )
				{
					ttime=ctime(time())[8..strlen(ctime(time()))];
					
					cname = criminal[i]->query("name") + "("+criminal[i]->query("id")+")";
					
					result = sprintf("%s  %s��������(%d����)���Զ��ͷš�\n",
							ttime,cname,howlong);
							
					old=criminal[i]->query("qiushi/note")+result;
					criminal[i]->set("qiushi/note",old);
                                        log_file("qiushi",result);
		
					wizchannel(result);
					takeout(criminal[i]);
				}
			}
		}
	}
	
	call_out("check_in",60);
}

void takeout(object who)
{
	who->move("/d/city/kezhan");
	who->set("startroom", "/d/city/kezhan");
	who->save();
	message_vision("$N�����η�������˳�����\n",who);
	message("system","\n\n  [1;32m "+who->name(1)+"������, ϣ�����ܸĹ�����, �´β�Ҫ�ٷ����ˡ�[0m\n\n",users());

}


void wizchannel(string result)
{
        CHANNEL_D->do_channel(this_object(),"wiz",result);
/*
        message("channel:wiz", HIY "����ͥͨ�桿" +
                result);
*/
}

void alternative_unc(object who)
{
	if (userp(who))	who->die();
}
