// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������ΰ������߸���̨�ϡ���ǰ��һ���㰸��������һ
Щ�Ҳ����š��㰸����ľ��ľ������ȵȡ�����Ͷ���ĵ���
�󿪣������ǻ�԰��

LONG);

  set("exits", ([
        "west"   : __DIR__"qian",
        "north"   : __DIR__"huayuan1",
        "east"   : __DIR__"huayuan3",
      ]));
  set("objects", ([
        __DIR__"npc/monk" : 2,
      ]));

  setup();
}



