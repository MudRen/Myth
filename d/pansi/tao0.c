#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣�����Զ��ңң�������¡¡��ˮ��,�ƺ��и��ٲ���
LONG );

       set("exits", ([
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
       ]));
       set("no_clean_up", 0);
       setup();
}

/*void init()
{
    this_player()->receive_damage("kee", 10);
    this_player()->receive_wound("kee",  10);
	this_player()->receive_damage("sen", 10);
    this_player()->receive_wound("sen",  10);
    message_vision(HIM"ͻȻһ���һ��������㼲��$N��\n"NOR, this_player());
}
*/
int valid_leave(object me, string dir)
{
        int total_steps;
        if( me->query_skill("spells",1) >100) total_steps = 1 ; 
           else total_steps = 10;
	if ( dir == "north")
            me->add_temp("taohua/steps",1);
	if ( dir == "south")
            me->add_temp("taohua/steps",-1);
	if (me->query_temp("taohua/steps") == total_steps)
        {
     	    me->move(__DIR__"tao_in");
            me->delete_temp("taohua/steps");
            return notify_fail("�����˰��죬�����߳����һ�����\n");
        } 
        if (me->query_temp("taohua/steps") == - total_steps )
        {  
            me->move(__DIR__"tao_out");
            me->delete_temp("taohua/steps");
            return notify_fail("�����˰��죬�����߳����һ�����\n");
     	}
        return ::valid_leave(me,dir);
}
/*
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/south")) 
        if ((int)ob->query_skill("spells",1) > 100 )
        {
            delete("exits/south");
            set("exits/south", __DIR__"tao_in");
            return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "��˿��")
        {
            delete("exits/south");
            set("exits/south", __DIR__"tao_in");
            return ;
        }       
        delete("exits/south");
        set("exits/south", __DIR__"tao0");
}
*/
