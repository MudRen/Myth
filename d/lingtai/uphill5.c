// Room: some place in ��ţ����
// uphill5.c

inherit ROOM;

void create()
{
  set ("short", "��ʯ��");
  set ("long", @LONG

һ��������ʯ������ɽ���ģ�ʯ��⻬���ƺ����������߹�������
�����������£��������˱�����ȴ������һ����Ӱ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill6",
"southwest": __DIR__"uphill4",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


