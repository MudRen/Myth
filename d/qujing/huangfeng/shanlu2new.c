//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

�ߵ�ɽ·�ϣ�����Զ���Ĵ�ɽ������ô�ɽ���Ǹ��հ���ɽ�����
���ϣ�ɽ·����᫣�·�Ծ���Щ��ʯ��ľ��ԶԶ�Ŀ�������ӰӰ
���еƻ������ֻ����ָղ���ôû�п�������·��

LONG);

  set("exits", ([
        "westup"  : __DIR__"shanlu3",
        "east"  : __DIR__"shanpo",
	"north" : __DIR__"outdoor",
      ]));
  set("outdoors","hfd");
  setup();
}
