// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����Ϊ�������ĵط����������ڹ������������������ϳ���
һ������̦�������ڵĵط����������ʻ��ɲݡ�����������
��һ���ȣ����ϱ��Ƕ��ڡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"zou",
        "southeast"   : __DIR__"shimen",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



