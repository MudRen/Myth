// hill.c

inherit ROOM;

void create()
{
  set ("short", "��԰");
  set ("long", @LONG

��԰�䲻�󣬻���ȴ���ࡣ������ɫ������̺졣��һ��ȴ����
�ϵģ���ֻ��ɫ��С��������ȥ�����ǹ������޹����ϱ��ǹ�
��ƽʱ����ĵط���
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"girl1",
"east" : __DIR__"girl3",
"south" : __DIR__"girl4",
"north" : __DIR__"wolongrest",
]));
set("objects", ([
                __DIR__"npc/gongnu": 1]) );

        set("no_clean_up", 0);
	set("outdoors", 1);
//      
        set("water", 1);
//  
        setup();
}

int valid_leave(object me, string dir)
{
    if((string)me->query("family/family_name")=="����") return 1;
   if((string)me->query("family/family_name")=="��������") return 1;


    if (dir == "north" ) {

        return notify_fail("����ֻ�������ĵ��Ӳ��ܽ�ȥ��\n");
    }

return 1;
}

