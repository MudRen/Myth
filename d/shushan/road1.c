inherit ROOM;

void create()
{
  set ("short", "��·");
  set ("long", @LONG

��Χ��һƬ���һЩũ��������������ڸ��֣�����һЩ������
�������ˣ��Զ���Ĵ�����Լ�������������ģ�һ������̫ƽ�ľ�
��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"shanjiao",
"east" : "/d/gao/road4",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
