// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ƽ��ɽ");
  set ("long", @LONG

ɽ��Ρ��������嶥���ƻ�ƽ����߷���һ���ϼ������֮��
��Ұ�ֺ����������Բԡ��������·ƽ̹��·����С��ľһ��
һ�ԣ�����������

LONG);

  set("exits", ([
        "north"   : __DIR__"ping3",
        "northwest"   : __DIR__"ping2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



