// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "�������");
        set ("long", @LONG

��������������������������������������������������������������������
������   ����ͨ�������Թ���Ψһ���,��ڴ����������������š�  ������
��������������������������������������������������������������������

LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/n1",   
       "north" : "/d/milin/qy/scc",   
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/guard" : 2,
       "/d/wizz/calvin/longzhu/zhu4" : 1,
        ]));

//       set("outdoors", "changan");
//        set("no_clean_up", 0);
        setup();
//       replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
//     object me = this_player();
        object a;
   if (dir == "north" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("����������ס��˵��:���������Թ���������ȥ�޻�,�㻹�ǻ�ͷ�ɡ�\n");
        }   
        return ::valid_leave(me, dir);
}
