// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������˴��СС��ʯ��ʯ�ʣ�����֧����һ�ڴ��������
˳�Ŷ��ڴ���ʯ���⡣����������һС�ţ�������һ����Ȼ��
��Ѩ�ֿ⡣

LONG);

  set("exits", ([
        "west"   : __DIR__"shimen",
        "northeast"   : __DIR__"cang",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



