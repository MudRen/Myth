//Cracked by Roath
inherit ROOM;

void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

ɽ����������Ұ���࣬�������Ĵ���ɽ��ɽ��
ԶԶ��ȥ��ɽ�ϰ�ѩ������ɽ��һ��ֱ�����Ƶ�
������˵��Ѻ�Ŵ�˵�е���Ů.
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road1",
"northup" : __DIR__"path1",
"east" : "/d/quest/m_weapon/lianjianshi",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
