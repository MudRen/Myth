// Room: /d/ourhome/kedian.c

inherit ROOM;

void reset();
void create()
{
	set("short", "�Ľ�С��");
	set("long", @LONG

����һ�Ҳ�֪���ĻĽ�С�꣬�ı������ưܣ���֪��Ϊʲô����
��Ȼ�ǳ���¡��һ��ƿ��ڴ��ĵ��컨��׹����С������������
��æ������ת���Ӵ�����ǻ�����Ŀ��ˡ�    
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
//	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kedian2",
]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_clean_up", 0);

	setup();
	"obj/board/common_a"->foo();
	replace_program(ROOM);
}
