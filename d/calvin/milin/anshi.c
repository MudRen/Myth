//shulin ���ְ���

inherit ROOM;

void create ()
{
        set ("short", "���ְ���");
        set ("long", @LONG

�������ܶ���ʯͷ,ֻ�е�������ϡ�ɼ�һЩ���̳���ͼ��...
�������и������С��,������Կ���һЩ����...
����һЩ��ʿϲ������������˯��,��˵����ʹ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "enter" : "/d/calvin/milin/anshi1",
                "out" : "/d/calvin/milin/milin",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//              "/d/shulin/npc/����ʹ��":1,
        ]));

        set("outdoors", "changan");
  set("if_bed", 1);
  set("sleep_room", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
