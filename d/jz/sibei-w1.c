//Cracked by Roath

inherit ROOM;

void create ()
{
 
      set ("short", "������");
        set ("long", @LONG

    �����������ֵ�ʯ���ϣ����ϵ��˴Ҵ�ææ�����ţ�������
�ܶ����£������ϵ��̷���Ҳ����������ߺ���ţ����ⲻ�Ǻ���
¡��������һ������Բ��.��������������ˡ�

LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"sibei-w2",
                "west" : __DIR__"center",
                "north": __DIR__"tangyuan",
      ]));
      set("objects", ([
                                __DIR__"npc/people" :1,
                ]));

      set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
