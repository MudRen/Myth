inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
ɽ·����������һֱ�����Զ����·�Գ������Ӳݡ�
��ʱ�м��������ӲݴԼ䴫������
LONG);

    set("exits", ([
          "east"      : __DIR__"shandao2",
          "west"      : __DIR__"shandao3",
          "north"      : __DIR__"shandao4",
          "southeast"      : __DIR__"lin7",
        ]));

  set("outdoors", __DIR__);

    setup();
}

