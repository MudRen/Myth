// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�й�");
  set ("long", @LONG

һ�������ںڰ��б����ܶ����ϵĻ������������Ϊ�����Σ�
��������ʮ�ˡ�������������һʯͷͨ��ͨ��ƫ�������ϱ�Ҳ
һʯͷͨ��ͨ���⹬��

LONG);

  set("exits", ([
        "west"   : __DIR__"pian",
        "southeast"   : __DIR__"wai",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 2,
      ]));

  setup();
}



