//Cracked by Roath
//jiangzhou 
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

    �����������ֵ�ʯ���ϣ����ϵ��˴Ҵ�ææ�����ţ�������
�ܶ����£������ϵ��̷���Ҳ����������ߺ���ţ����ⲻ�Ǻ���
¡��������һ������Ǻ�«�ġ�

LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"egate",
                "west" : __DIR__"sibei-w1",
                "south": __DIR__"tanghulu",
      ]));
      set("objects", ([
				__DIR__"npc/people" :1,
		]));
        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
