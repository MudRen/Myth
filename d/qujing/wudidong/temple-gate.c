// Room: /d/qujing/wudidong/temple-gate.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG

ת����������ɽ�����������ƣ����������ɾ��� ��ǰ��һ��
��Ժ�εض���������һ����ң����顸�����¡�������֪
Ϊ�Σ����Ž��գ����ұ�أ��ƺ��ܾ�û���˳����ˡ� ��ǰ
һ��С·������������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
