// Room: /d/qujing/wudidong/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG

�Ĵ��ڳ����ģ�ʲôҲ�����壬ֻ��������ǰ����������Ϊ��ʪ��ù
���˱ǡ����߱��϶��ǰ�͹��ƽ�ļ�ʯ������Ҳ��ʱ��ʱ�͡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"temple-houdian",
  "southwest" : __DIR__"shanlu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
