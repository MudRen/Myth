inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
ɽ·����������һֱ�����Զ����·�Գ������Ӳݡ�
��ʱ�м��������ӲݴԼ䴫������
LONG);

    set("exits", ([
          "south"      : __DIR__"shandao4",
          "west"      : __DIR__"shandao6",
        ]));

  set("outdoors", __DIR__);

    setup();
}

