// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�ڹ�");
  set ("long", @LONG

�ڹ���һ�������������������ݣ�������ʯǽ�Ϲ��Ų�ɫ��
β����ǽ�·���һ��ľ��ױ̨��̨�������澵���ڹ���������
һ����ͨ����ͤ�ӡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"huating",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 4,
      ]));

  setup();
}



