// rewritten by snowcat on 4/11/1997
// room: qujinglu

inherit ROOM;

void create ()
{
  set ("short", "ȡ��·");
  set ("long", @LONG

������һ��Ƭ��ɳĮ�����磬�������ܣ��Ĵ����ǻ�ɳ���߸ߵ͵ͣ�
���Ѵ����ҳ�·�����������е���š�

LONG);

  set("exits", ([
        "northwest" : __DIR__"luzhou3",
        "southeast" : "/d/qujing/dudi/shanlu6",
      ]));
  set("outdoors", "firemount");

  setup();
}
