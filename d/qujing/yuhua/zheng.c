// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ׯ�����£����������ľ��ɣ�ǽ���ж�����̺����
���̵��ǻ�Ƥ��̺������Ϊһ������̨�ף�����һ����������
����������˫�������

LONG);

  set("exits", ([
        "north"   : __DIR__"dayuan",
        "southwest"   : __DIR__"ting",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince"  : 1,
      ]));

  setup();
}



