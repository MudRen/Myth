//restroom.c

inherit ROOM;

void create ()
{
  set ("short", "��ѩ����Ϣ��");
  set ("long", @LONG

���ǹ���ѩ��ػ�ĳ�Ա�������Ϣ�ĵط�����ǽ����һ��
��ª��ľ����
LONG);

  set("sleep_room", 1);
  set("if_bed", 1);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"living",
]));

  setup();
}

