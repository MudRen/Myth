//���� ��Ժ

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","������" );
        set ("long", @LONG
�����������ֵ���Ψһ��һ���������Ժ,��Ϊ������ʢԶ
�����ⳣ�������Զ��������������Ů,�����˻ʵ����ո�
����ɽ�˺���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "north" : "/d/calvin/milin/milin4",    
                "east" : "/d/calvin/milin/jiangjitang",
       "south" : "/d/calvin/milin/changjige",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
