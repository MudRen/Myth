
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ȥ��孵��ıؾ�֮�أ������������˲����࣬
ż�����ܿ���һЩ������孺�������������ˣ�
�������������۴�(chuan) ʮ�ַ��㡣
LONG );
	set("exits", ([
                "west" : "/d/southern/wutai/guandao3",
	]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
	set("objects", ([
		__DIR__"npc/chuanfu": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", 1);
	setup();
//	replace_program(ROOM);
}
