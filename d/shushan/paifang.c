#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ӭ���Ʒ�");
        set("long", 
"���ϵ�ʯ�Ʒ�����֪��ʲôʱ���޽���\n"+
"ʯ�������ۣ�����̨��ȴһ����Ⱦ��\n"+
"�ߴ���Ʒ���������ţ�\n"+
HIG"    ��      ɽ      ��      ��  \n"NOR
);
        set("exits", ([ /* sizeof() == 2 */
 "north" : "/d/shushan/square",
  "southdown" : __DIR__"path1",
]));

        set("objects",([
        __DIR__"npc/zhike" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
