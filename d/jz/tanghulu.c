//Cracked by Roath
//tanghulu happ@yszz
inherit ROOM;
void create ()
{
        set ("short", "���Ǻ�«��");
        set ("long", @LONG

  ��ұ��Ǻ�«��������ֺ��ˣ��Դ������ܲٳԹ���λ����ɩ
�������Ƶ��Ǻ�«һֱ�������֣����ʱ����Ǩ����������ǿ�
���ƻ���������һ����
[1;33m              ��������������������������
              ��     ���ڱ��Ǻ�«     ��
              ��������������������������[m
LONG);

        set("exits",
        ([ //sizeof() == 4
            "north" : __DIR__"sibei-w2",
      ]));
        set("objects", ([
            __DIR__"npc/wang": 1,
                        ]));
        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
 replace_program(ROOM);
}
