//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����繬��Ĵ����������м������ʯ��ʯ�Σ�����ʯ����
��������ͭ�ơ����������洫���������ζ��������һͨ����
���ͨ����������������һʯ�ȡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"canting",
        "northeast"   : __DIR__"shilang",
        "southeast"   : __DIR__"woshi",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
      ]));

  setup();
}



