// create by snowcat.c 4/20/1997
// room: /d/eastway/xyt.c

inherit ROOM;

void create ()
{
  set ("short", "С����");
  set ("long", @LONG

С������һ��ͨ�߼�ʮ�ɵ�ש�����ӵ������Ͽ�ȥ��ׯ�϶����磬
�����ܽ��ܲ���һ����ʮ���֮�ߣ��붫�ߵĴ�����ңң��������
�����Ŷ�ͨ�����ڣ�������·ͨ���ʿ����
LONG);

  set("exits", ([
        "enter"     : __DIR__"xyt1",
        "east" : __DIR__"jinshi",
      ]));
  set("outdoors", __DIR__);

  setup();
}






