// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�͵�");
  set ("long", @LONG

�͵��������Ŵ����ӣ��˰�ľ�Σ�ǽ�߻����������������ʣ�
������Ъ�š��������һ��̨���������һЩС��֮���ʳ
Ʒ���걱�ٽ֣���ʱ�пͽ�����

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie5",
      ]));
  set("objects", ([
"/obj/boss/jinping_dianzhu"   : 1,
      ]));
  set("valid_startroom",1);

  setup();
}


