// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "С�ӳ�");
  set ("long", @LONG

С�ӳ���һ������ʯ�㳡��ʮ�ֿ����г����ж���������Χ
��¥�������ϸ��������������ڣ����Ʈ����Ǳ����
�������ڡ�

LONG);

  set("exits", ([
        "northeast"    : __DIR__"jie9",
        "south"    : __DIR__"zhaomen",
        "north"    : __DIR__"jitan",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

