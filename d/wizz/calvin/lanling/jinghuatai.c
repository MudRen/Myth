//shulin ����

#include <ansi.h>
inherit ROOM;

void create ()

{
        set ("short", HIB"����̨"NOR);
        set ("long", @LONG

������ǧ������������Ķ���,��������,һ������ô��
��С,�����������ı���,��ϧ��Ҫ�ܴ�ı���ſ��Դ�����
Щ����,���е�һ��"ǧ����(qianjue cao)"��˵�������ȥ
�Ļ�������Լ�����Ϊ���������� ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
        ]));

        set("objects", 
        ([ //sizeof() == 8
             "/u/calvin/npc/shouhu.c" : 1,
           "/d/calvin/npc/dcz.c" : 1,
//               "/d/calvin/obj/feng.c" : 1,
//               "/d/calvin/obj/hou.c" : 1,
//               "/d/calvin/obj/shuei.c" : 1,
//               "/d/calvin/obj/tu.c" : 1,
//               "/d/calvin/obj/lei.c" : 1,
              "/d/calvin/npc/gueiwei.c" : 1,
        ]));

//        set("outdoors", "lanling");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
}

int do_error(string arg)
{
object who = this_player();
message_vision("������󲻿��������ۼ���!\n",who);
return 1;
}

