//����̨
//by junhyun@SK
inherit ROOM;
void create ()
{
        set ("short", "����̨");
        set ("long", @LONG
     ���������������������� 
         ��������  ��  ̨������ 
         ���������������������� 

�������ǧ�����̨���������������ħ������
�ڴ˽���ϴ����ȥ����������硣
LONG);

        set("exits", 
        ([ //sizeof() == 4
      "down": __DIR__"fsl6", 
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/gumu/npc/jiang" : 1,
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
        return notify_fail("����������ס��˵��:����̨����ʲô�˶���ȥ��,�㻹�ǻ�ͷ�ɡ�\n");
        }   
        return ::valid_leave(me, dir);
}

