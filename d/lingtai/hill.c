// Room: some place in ��ţ����
// hill.c

inherit ROOM;

void create()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

̧ͷ��ȥ������һ��ɽ�¡�ɽ�䲻�ߣ���ȥȴ������ǧ����ȶ�
�ˡ�һ�����бб�Ŀ���ɽ����Ϊɽƽ����������������ԼԼ��
����ɽ���Է򳪵�ɽ�裬��ֻС��Ҳ��֮һ��һ�͡�
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill1",
"southeast" : "/d/gao/road4",
]));

        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

