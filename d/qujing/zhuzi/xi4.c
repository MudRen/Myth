// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "Ϧ�ֽ�");
  set ("long", @LONG

Ϧ�ֽ�Ϊ���Ϲ�ʳƷ���У����ݾ�¥��������ζ�˱ǡ�һȺȺʳ��
���ؽֽ������ҡ��ϱ���һ��רӪ�ӻ���С�꣬�����ǹҳ�������
��һ����ݡ�

LONG);

  set("exits", ([ 
    "north" : __DIR__"mianguan",
    "south" : __DIR__"zahuo",
    "west" : __DIR__"xi3",
    "east" : __DIR__"gulou",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
