//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","�ش�ҩ��" );
        set ("long", @LONG

���ǳ�����һ�����ֺŵ�ҩ�̣��ഫԭ�����ϰ��ǻʹ��е���ҽ����
�ο�֪һ����ҩ���еİ���Ҳʮ�ֿ��������α��ڿ�Ļ�Ʋ��ĸɸ�
������ǽ�Ϲ����˱���������л�ҡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"zhuque-s2",
                "east" : __DIR__"yaopu1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/obj/boss/city_yang" : 1,
        ]));
	set("no_clean_up", 0);
        set("no_fight",1);
        set("no_magic",1);
        setup();
	replace_program(ROOM);
}


