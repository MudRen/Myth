//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ȸ���");
        set ("long", @LONG

��ȸ������̼��ڶ࣬���СС�ĵ��̱��ڶ��������������൱�ĺ�
�����㡣������ʯ��·ֱͨ�ϱ�����ͨ���ʹ��ĳ����ţ����Ͽ�ң
�������������ɽ�������ǳ����ַ�����������˿������뻶Ц����
�ǳ������е�һ�������ڡ������Ǽ����ֺŵ�ҩ�̡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"zhuque-s3",
                "north" : __DIR__"zhuque-s1",
                "west" : __DIR__"club",
                "east" : __DIR__"yaopu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/d/nanhai/npc/bonze" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

