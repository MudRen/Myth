// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "��Ĺ����");
        set ("long", @LONG
����ͨ����Ĺ�����Ψһ���,��ڴ�����
ֻ��������ĺ�������š�
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "down" :  __DIR__"zhongting",
        "north" :  __DIR__"mishi",     
        ]));

        set("objects", 
        ([ //sizeof() == 1
        __DIR__"npc/fox" : 2,
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
                if(objectp(a=present("hubao yaohu", environment(me))) &&
living(a) )
        return notify_fail("�������Ĺ�ļһ�õ��˹������Ҿ������ȥ!\n");
        }   
        return ::valid_leave(me, dir);
}

