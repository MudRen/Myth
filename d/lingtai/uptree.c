// Room: some place in ��ţ����
// uptree.c

inherit ROOM;

void create()
{
  set ("short", "��������");
  set ("long", @LONG

վ�ڴ������Ķ��ˣ�ɽ�����󣬿������£���ɽ����������
Լ����һƬ������һ�ɵ�������������֮�£�
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"uphill2"
]));
set("objects", ([
		__DIR__"obj/guo": 1]));
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


