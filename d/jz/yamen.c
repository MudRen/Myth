//Cracked by Roath
inherit ROOM;
void create ()
{
        set ("short", "����֪��");
        set ("long", @LONG

����Զ��Ϳ���һ���ң�

[31m        ������������������������������������������
        ��                                      ��
        ��  [1;37m    ��      ��      ֪      ��   [0;31m   ��
        ��                                      ��
        ������������������������������������������[m
LONG);
        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"xw-2",
                "west"  : __DIR__"datang",
        ]));
        set("objects",
        ([ //sizeof() == 1
                __DIR__"npc/yayi" : 4,
        ]));
   set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{       if (dir == "west") {
        if (objectp(present("yayi", environment(me)))) {
  if(!present("zhuang zhi", me) && me->query("office_number") < 300 )
return notify_fail("���ۺȵ���û��״ֽ��zhuang zhi����Ϊ���Ҵ���������ȥ��\n");
                }
        return ::valid_leave(me, dir);
        }
        return 1;
}
