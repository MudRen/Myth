inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
ɽ·����������һֱ�����Զ����·�Գ������Ӳݡ�
��ʱ�м��������ӲݴԼ䴫������
LONG);


    set("exits", ([
          "west"      : __DIR__"shandao1",
          "south"      : __DIR__"lin7",
        ]));

  set("outdoors", __DIR__);

    setup();
}

