// rewritten by snowcat on 4/11/1997
// room: shalu

inherit ROOM;

void create ()
{
  set ("short", "ɰ����");
  set ("long", @LONG

С�����˷ֲ�����ͨ�����ɽ�����ϵ�С���������ۣ���֪ͨ��
�δ���ɽ�ϵ�����һ�����ӿ����

LONG);

  set("exits", ([
        "westup"    : __DIR__"shanbian",
        "east"      : __DIR__"shalu2",
        "southwest" : __DIR__"wuming1",
      ]));
  set("outdoors", "firemount");

  setup();
}
