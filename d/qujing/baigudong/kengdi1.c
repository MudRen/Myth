// Room: create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "�ӵ�");
  set ("long", @LONG

    �ӵ׸�ʬɢ����һ���ȳ�ζ����Χ�ӱڽ���Ѫ�ۣ���
��ʱ�С��������ĺ�������
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "up": __DIR__"wangukeng",
  ]));
  set("objects",([
        __DIR__"npc/jiangshi":4,
                ]));
  set("outdoors", __DIR__"");                   
  setup();
}
