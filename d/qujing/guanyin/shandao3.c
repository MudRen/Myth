inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
ɽ·����������һֱ�����Զ����·�Գ������Ӳݡ�
��ʱ�м��������ӲݴԼ䴫������
LONG);

    set("exits", ([
          "east"      : __DIR__"shandao1",
        ]));

  set("outdoors", __DIR__);

    setup();
}

