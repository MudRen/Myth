// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥����ż������ӣ������м���С�˼��̳�������̨�Ϸ���
��̳�Ͼƣ������˱����˴��ѡ��ݽ���һľ̿���ܣ������ϵ�
��Ѭ���Ϻ��Ϻ졣

LONG);

  set("exits", ([
        "southeast"    : __DIR__"jie4",
      ]));
  set("objects", ([
        __DIR__"npc/kanduli"    : 1,
      ]));
  setup();
}

