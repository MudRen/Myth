// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�⹬");
  set ("long", @LONG

�⹬��������룬���ﱾ�ǽӴ����˵ĵط�����������ķ�ʯ
���Լ�ʯ�輸�����߼���̫ʦ���ϵ�����Ƥ��Զ��š������
��յ���͵ơ�

LONG);

  set("exits", ([
        "northwest"   : __DIR__"zhong",
        "east"   : __DIR__"guo",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



