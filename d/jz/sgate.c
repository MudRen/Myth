//Cracked by Roath

inherit ROOM;
void create()
{
  set ("short", "[1;33m����̨[m");
  set ("long", @LONG

��ǰ�����Ǵ�ٹ����ǵ������ֵĵط�������ݳ�˥���ˣ�
����ط�������û�˿����ˣ���ʹ������Ҳ������������̨
���Ա��и�С����(paizi)���������дЩʲô���ݡ�
LONG);
        set("exits", ([
        "north":__DIR__"dingan-3",
        "southdown":__DIR__"diaoyu1",
]));
        set("objects", ([
                __DIR__"npc/waiter": 1,
                ]));
        set("item_desc", ([
                "paizi": @TEXT
������������������������������������������������������������������������
                    ���㣺���ÿ����������
������������������������������������������������������������������������
TEXT
        ]) );
    set("outdoors", __DIR__);
  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north"&& me->query("fish") )
        me->delete("fish"); 
        return 1;
}
/*
void say()
{
        object me=this_player();
         write("����͵Ķ���˵������~~��Ҫ���ű��˵��㡣\n");
        return 0;
}
*/
