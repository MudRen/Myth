//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","����������");
        set ("long", @LONG

�����ǳ����ǵ����š�����͵��˳��У�Զ����ɽ�˺����������˳�
������������һ����·ͨ��Զ������������һЩִ�ڵı�ʿ��ʱ����
������̫ƽ����һ�ɱ�������Ӣ�˲���������Ķ���������ʿ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/westway/west1",
                "east" : __DIR__"baihu-w3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 3,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
       set("tsj_exst","west");
        setup();
	replace_program(ROOM);
}



