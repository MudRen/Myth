// zhting.c

inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

��ǰ����һ�Ű����������������Ŵ�Ƥ���̫ʦ�Ρ�����ү��������
�������Ų�ˮ������ǽ�Ϲ��ż����ֻ�����ϸ��������û��ʲô��
��������������ƫ����
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"houyuan",
"south": __DIR__"zhyuan",
"west" : __DIR__"pianting",
"east" :__DIR__"fanting",
]));
set("objects", ([
                __DIR__"npc/gao": 1,
		__DIR__"npc/yahuan2": 2 ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


