//2001.2.2

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ������ߺ����и����ԡ�Զ��ż������һ��
��С�������һƬ�һ��֣�����ԶԶ������ֻ���ӡ�
LONG );
       set("exits", ([
           "south" : "/d/dntg/hgs/houshan3",
           "north" : __DIR__"tao_out",
           "east" : __DIR__"taob",
           "west" : __DIR__"taoa",
       ]));
	   set("objects",([
		__DIR__"npc/xiang" : 1,
		__DIR__"obj/guo" : 3,
	]));


       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
/*
void init()
{
        object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/north")) 
			 myfam = (mapping)ob->query("family");
			if(myfam && myfam["family_name"] == "��˿��")
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_out");
	return ;
        }       
        if ((int)ob->query_skill("spells",1) >= 100 )
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_out");
	return ;
        }
	delete("exits/north");
    set("exits/north", __DIR__"tao0");
}
*/
