// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ӫ");
  set ("long", @LONG

һ���ٽֶ�����Ӫ��������¥�м���֮ң�������ǻ��Ǳ�ʿ��
��֮����ż���ɼ���ʿ�������ڡ�������һ��ͨ�̣��ſ���һ
�տյı����ܡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie1",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 3,
      ]));

  setup();
}



