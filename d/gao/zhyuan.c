// zhyuan.c

inherit ROOM;

void create()
{
  set ("short", "��Ժ");
  set ("long", @LONG

Ժ��һ�þ޴���������������������ɫ��С�����������������㣬
�����м���������˵�Ǹ�ׯ����үү���µģ���������һ�˺ϱ�
��ϸ��������һЩ����ס�ĵط��������Ǹ߼ҵ���ͥ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"zhting",
"south" : __DIR__"gate",
"east" : __DIR__"pianfang",
"west" :__DIR__"zhangfang",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


