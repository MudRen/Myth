// ���ֱ��� by Calvin

inherit ROOM;
void create ()
{
        set ("short", "����̨���");
        set ("long", @LONG
     ���������������������� 
         ��������  ��  ̨������ 
         ���������������������� 

����ͨ������̨��Ψһ���,��ڴ����������������š�
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "up": __DIR__"fst1",  
      "southdown": __DIR__"fsl5", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/jz/npc/guard.c" : 2,
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
   if (dir == "up" ) {
                if(objectp(a=present("guard", environment(me))) &&
living(a) )
        return notify_fail("����������ס��˵��:����̨����ʲô�˶���ȥ��,�㻹�ǻ�ͷ�ɡ�\n");
        }   
        return ::valid_leave(me, dir);
}

